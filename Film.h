#pragma once

#include <vector>
#include "Spectrum.h"

class Film
{
public:
	Film(unsigned width, unsigned height);

	unsigned GetWidth() const;
	unsigned GetHeight() const;

	void Clear();
	void AddSample(unsigned x, unsigned y, Spectrum sample, float weight);
	const std::vector<Spectrum>& GetImage() const;

private:
	unsigned width;
	unsigned height;
	std::vector<Spectrum> image;
};