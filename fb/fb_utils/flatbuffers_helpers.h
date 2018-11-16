#pragma once

#include "flatbuffers/flatbuffers.h"

namespace flatbuffers_helpers {

	// A custom allocator for flatbuffers, that simply returns a pointer to a pre-allocated buffer.
	// It does not allocate and does not deallocate. In case the original buffer's size is not enough, it will throw an exception.
	class PreallocatedAllocator : public flatbuffers::Allocator {

	protected:
		PreallocatedAllocator(char* _buf, size_t _buf_size) : buf(_buf), buf_size(_buf_size) {}
		virtual ~PreallocatedAllocator() {}

		virtual uint8_t *allocate(size_t size) {
			if (size>buf_size)
				throw "given buffer is not big enough";
			return reinterpret_cast<uint8_t*>(buf);
		}

		virtual void deallocate(uint8_t *p, size_t size) {

		}

		virtual uint8_t *reallocate_downward(uint8_t *old_p, size_t old_size,
			size_t new_size, size_t in_use_back,
			size_t in_use_front) {
			throw "reallocate not allowed";
		}

	private:

		char* buf;
		size_t buf_size;
	};

	// A FlatBufferBuilder, bundles with a custom allocator
	class Preallocated : public PreallocatedAllocator {
	public:

		static const size_t buffer_minalign = 8U;

		Preallocated(char* buf, size_t _buf_size) :
			PreallocatedAllocator(buf, roundDownToAlignment(_buf_size)),
			fbb(roundDownToAlignment(_buf_size), this, false, buffer_minalign) {}

		flatbuffers::FlatBufferBuilder& get_fbb() { return fbb; }

		static size_t roundDownToAlignment(size_t size) {
			return size & ~(buffer_minalign - 1);
		}

	private:
		flatbuffers::FlatBufferBuilder fbb;
	};
}
