// app1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fb_helpers.h"
#include "image_generated.h"

using namespace generated_code;
using namespace fb_helpers;

struct Config {
	static const size_t image_width = 3;
	static const size_t image_height = 5;
};

void fillBufferWithImageData(flatbuffers::FlatBufferBuilder& fbb) {
	unsigned char* pixels_buf;
	auto pixels = fbb.CreateUninitializedVector(Config::image_width * Config::image_height, &pixels_buf);
	for (int i = 0;i < Config::image_width * Config::image_height;++i)
		pixels_buf[i] = 15;
	uint64_t timestamp = 100;
	auto img = CreateImage(fbb, &Dimensions(Config::image_width, Config::image_height), pixels, timestamp);
	fbb.Finish(img);
}

void exampleImage() {
	int bufsize = Config::image_width * Config::image_height + 64;
	char* my_buffer = new char[bufsize];
	BorrowedBuffer prealloc(my_buffer, bufsize);
	fillBufferWithImageData(prealloc.get_fbb());
	delete[] my_buffer;
}

int main()
{
	exampleImage();
	return 0;
}
