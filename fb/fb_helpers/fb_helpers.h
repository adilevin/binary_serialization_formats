#pragma once

#include "flatbuffers/flatbuffers.h"
#include "Ibin_buffer.h"

namespace fb_helpers {

	class ReallocNotAllowedException { public: ReallocNotAllowedException() {} };
	class BufferInsufficientException { public: BufferInsufficientException() {} };

	// A custom allocator for flatbuffers, that simply returns a pointer to a pre-allocated buffer.
	// It does not allocate and does not deallocate. In case the original buffer's size is not enough, it will throw an exception.
	class CustomAllocator : public flatbuffers::Allocator {

	protected:
		CustomAllocator(char* _buf, size_t _buf_size) : buf(_buf), buf_size(_buf_size) {}
		virtual ~CustomAllocator() {}

		virtual uint8_t *allocate(size_t size) {
			if (size>buf_size)
				throw BufferInsufficientException();
			return reinterpret_cast<uint8_t*>(buf);
		}

		virtual void deallocate(uint8_t *p, size_t size) {

		}

		virtual uint8_t *reallocate_downward(uint8_t *old_p, size_t old_size,
			size_t new_size, size_t in_use_back,
			size_t in_use_front) {
			throw ReallocNotAllowedException();
		}

	private:

		char* buf;
		size_t buf_size;
	};

	// A FlatBufferBuilder, bundles with a custom allocator
	class BorrowedBuffer : public CustomAllocator {
	public:

		static const size_t buffer_minalign = 8U;

		BorrowedBuffer(char* buf, size_t _buf_size) :
			CustomAllocator(buf, roundDownToAlignment(_buf_size)),
			_fbb(roundDownToAlignment(_buf_size), this, false, buffer_minalign) {}

		flatbuffers::FlatBufferBuilder& fbb() { return _fbb; }

		template<typename T> const char* finish(flatbuffers::Offset<T> root) {
			_fbb.Finish(root);
			return (const char*)_fbb.GetBufferPointer();
		}

	private:

		static size_t roundDownToAlignment(size_t size) {
			return size & ~(buffer_minalign - 1);
		}

	private:
		flatbuffers::FlatBufferBuilder _fbb;
	};

	// A FlatBufferBuilder, bundles with a custom allocator
	class BorrowedBinBuffer : public BorrowedBuffer {
	public:

		static const size_t buffer_minalign = 8U;

		BorrowedBinBuffer(gc_ns::Ibin_buffer& _bin_buffer) :
			BorrowedBuffer((char*)_bin_buffer.data(), _bin_buffer.get_capacity()),
			bin_buffer(_bin_buffer) {}

		template<typename T> void finish(flatbuffers::Offset<T> root) {
			bin_buffer.set_start(BorrowedBuffer::finish(root));
		}
		
	private:
		gc_ns::Ibin_buffer& bin_buffer;
	};
}
