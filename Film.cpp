#include "Film.h"

Film::Film(unsigned width, unsigned height) :
	width(width),
	height(height)
{
	rgba.resize(width*height);
}

void Film::Clear()
{
	std::fill(rgba.begin(), rgba.end(), RgbaColor());
}

void Film::AddSample(unsigned x, unsigned y, RgbaColor radiance, float weight)
{
	rgba[y*width + x] += radiance * weight;
}

unsigned char* Film::GetRgba()
{
	return reinterpret_cast<unsigned char*>(&rgba[0]);
}
