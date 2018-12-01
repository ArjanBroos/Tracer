#include "Film.h"

Film::Film(unsigned width, unsigned height) :
	width(width),
	height(height)
{
	image.resize(width*height);
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
	std::fill(image.begin(), image.end(), Spectrum());
}

void Film::AddSample(unsigned x, unsigned y, Spectrum radiance, float weight)
{
	image[y * width + x] += radiance * weight;
}

const std::vector<Spectrum>& Film::GetImage() const
{
	return image;
}
