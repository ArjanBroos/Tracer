#include "Film.h"

Film::Film(unsigned width, unsigned height) :
	width(width),
	height(height)
{
	rgba.resize(width*height);
}

unsigned Film::GetWidth() const
{
	return width;
}

unsigned Film::GetHeight() const
{
	return height;
}

void Film::Clear()
{
	std::fill(rgba.begin(), rgba.end(), RgbaColor());
}

void Film::AddSample(unsigned x, unsigned y, RgbaColor radiance, float weight)
{
	rgba[y*width + x] += radiance * weight;
}

const unsigned char* Film::GetRgba() const
{
	return reinterpret_cast<const unsigned char*>(rgba.data());
}
