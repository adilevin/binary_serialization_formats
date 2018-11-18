#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "flatbuffers/flatbuffers.h"
#include "image_generated.h"

using namespace generated_code;
using namespace flatbuffers;

namespace fbtests
{		
	TEST_CLASS(ImageTest)
	{

	private:

		const int w = 10;
		const int h = 20;
		const int timestamp = 225;
		const int const_pixels_value = 17;

		Offset<Vector<uint8_t>> fillImageData(FlatBufferBuilder& fbb) {
			unsigned char* pixels_buf;
			auto pixels = fbb.CreateUninitializedVector(w * h, &pixels_buf);
			for (int i = 0;i < w * h; ++i)
				pixels_buf[i] = const_pixels_value;
			return pixels;
		}

		void validate(const Image* img) {
			Assert::IsTrue(img->dim()->width() == w);
			Assert::IsTrue(img->dim()->height() == h);
			Assert::IsTrue(img->timestamp() == timestamp);
			const auto* data = img->pixels()->Data();
			for (int i = 0;i < w * h;++i)
				Assert::IsTrue(data[i] == const_pixels_value);
		}

	public:
		
		TEST_METHOD(CreateImage_works)
		{
			FlatBufferBuilder fbb;
			auto pixels = fillImageData(fbb);
			auto img = CreateImage(fbb, &Dimensions(w, h), pixels, timestamp);
			fbb.Finish(img);
			
			const Image* recevied_img = generated_code::GetImage(fbb.GetBufferPointer());
			validate(recevied_img);
			
		}

		TEST_METHOD(ImageBuilder_works)
		{
			FlatBufferBuilder fbb;
			auto pixels = fillImageData(fbb);
			
			ImageBuilder imbuild(fbb);
			imbuild.add_timestamp(timestamp);
			imbuild.add_dim(&Dimensions(w, h));
			imbuild.add_pixels(pixels);
			auto img = imbuild.Finish();
			fbb.Finish(img);

			const generated_code::Image* recevied_img = generated_code::GetImage(fbb.GetBufferPointer());
			validate(recevied_img);
		}

	};
}