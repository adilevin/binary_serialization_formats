// app1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fb_helpers.h"
#include "bin_buffer.h"
#include "image_generated.h"
#include <fstream>
#include <iostream>

using namespace generated_code;
using namespace fb_helpers;

struct Config {
	static const size_t image_width = 3;
	static const size_t image_height = 5;
};

void fillBufferWithImageData(BorrowedBinBuffer& prealloc) {
	unsigned char* pixels_buf;
	auto pixels = prealloc.fbb().CreateUninitializedVector(Config::image_width * Config::image_height, &pixels_buf);
	for (int i = 0;i < Config::image_width * Config::image_height;++i)
		pixels_buf[i] = 15;
	uint64_t timestamp = 100;
	auto img = CreateImage(prealloc.fbb(), &Dimensions(Config::image_width, Config::image_height), pixels, timestamp);
	prealloc.finish(img);
}

void write_to_file(const gc_ns::Ibin_buffer& binbuf, const char* filename) {
	std::ofstream f(filename, std::ios::binary);
	f.write((const char*)binbuf.get_data(), binbuf.get_size());
	f.close();
}

void createAndWriteToFile() {
	gc_ns::bin_buffer binbuf(Config::image_width * Config::image_height + 128);
	BorrowedBinBuffer prealloc(binbuf);
	fillBufferWithImageData(prealloc);
	std::cout << "Writing img.dat\n";
	write_to_file(binbuf, "img.dat");
}

int main()
{
	createAndWriteToFile();
	return 0;
}
