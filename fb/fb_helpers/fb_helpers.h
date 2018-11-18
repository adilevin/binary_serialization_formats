#pragma once

#include "flatbuffers/flatbuffers.h"
#include "Ibin_buffer.h"

namespace fb_helpers {

	class ReallocNotAllowedException { public: ReallocNotAllowedException() {} };
	class BufferInsufficientException { public: BufferInsufficientException() {} };

	// A custom allocator for flatbuffers, that simply returns a pointer to a pre-allocated buffer.
	// It does not allocate and does not deallocate. In case the original buffer's size is not enough, it will throw an exception.
	class CustomAllocator : public flatbuffers::Allocator {

	public:
		CustomAllocator(void* _ptr, std::size_t _capacity) : ptr(_ptr), capacity(_capacity) {}
		virtual ~CustomAllocator() {}

		virtual uint8_t *allocate(size_t size) {
			if (size>capacity)
				throw BufferInsufficientException();
			return reinterpret_cast<uint8_t*>(ptr);
		}

		virtual void deallocate(uint8_t *p, size_t size) {}

		virtual uint8_t *reallocate_downward(uint8_t *old_p, size_t old_size,
			size_t new_size, size_t in_use_back,
			size_t in_use_front) {
			throw ReallocNotAllowedException();
		}

	private:

		void* ptr;
		std::size_t capacity;
	};

	// A FlatBufferBuilder, bundles with a custom allocator
	class BuilderFromBinBuffer {
	public:

		BuilderFromBinBuffer(gc_ns::Ibin_buffer& _bin_buffer) :
			bin_buffer(_bin_buffer),
			custom_allocator(bin_buffer.data(), bin_buffer.get_capacity()),
			_fbb(bin_buffer.get_capacity(), &custom_allocator) {}

		flatbuffers::FlatBufferBuilder& fbb() { return _fbb; }

		template<typename T> void finish(flatbuffers::Offset<T> root) {
			_fbb.Finish(root);
			const char* start = reinterpret_cast<const char*>(_fbb.GetBufferPointer());
			const char* end = ((const char*)bin_buffer.data() + bin_buffer.get_capacity());
			bin_buffer.set_start(start);
			bin_buffer.set_size((gc_ns::Ibin_buffer::size_type)(end - start));
		}

	private:
		gc_ns::Ibin_buffer& bin_buffer;
		int aligned_capacity;
		CustomAllocator custom_allocator;
		flatbuffers::FlatBufferBuilder _fbb;
	};
}
