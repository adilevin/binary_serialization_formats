#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "fb_helpers.h"
#include "generated\cpp\simpleObj_generated.h"

namespace fb_helpers
{		
	TEST_CLASS(BorrowedBufferTests)
	{
	public:
		
		TEST_METHOD(BorrowedBufferHappyPath)
		{
			char buf[256];
			BorrowedBuffer bb(buf, sizeof(buf));
			auto o = CreateSimpleObj(bb.get_fbb(), 1, 2);
			bb.get_fbb().Finish(o);

			uint8_t* b = bb.get_fbb().GetBufferPointer();

			auto s = GetSimpleObj(b);
			Assert::IsTrue(s->a() == 1);
			Assert::IsTrue(s->b() == 2);
		}

	};
}