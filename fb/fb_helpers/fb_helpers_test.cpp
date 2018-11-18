#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "fb_helpers.h"
#include "generated\cpp\simpleObj_generated.h"
#include "bin_buffer.h"

namespace fb_helpers
{		
	TEST_CLASS(BorrowedBufferTests)
	{
	public:
		
		TEST_METHOD(BorrowedBufferHappyPath)
		{
			char buf[256];
			BorrowedBuffer bb(buf, sizeof(buf));
			auto o = CreateSimpleObj(bb.fbb(), 1, 2);
			bb.fbb().Finish(o);

			uint8_t* b = bb.fbb().GetBufferPointer();

			auto s = GetSimpleObj(b);
			Assert::IsTrue(s->a() == 1);
			Assert::IsTrue(s->b() == 2);
		}

		TEST_METHOD(borrowed_bin_buffer)
		{
			gc_ns::bin_buffer binbuf(256);
			BorrowedBinBuffer bb(binbuf);
			auto o = CreateSimpleObj(bb.fbb(), 1, 2);
			bb.finish(o);

			const unsigned char* h = binbuf.get_data();
			std::string copied_buf(h, h + binbuf.get_size());
			auto s = GetSimpleObj(copied_buf.c_str());
			Assert::IsTrue(s->a() == 1);
			Assert::IsTrue(s->b() == 2);
		}

	};
}