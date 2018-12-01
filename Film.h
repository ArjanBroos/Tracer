#pragma once

#include <vector>
#include "RgbaColor.h"

class Film
{
public:
	Film(unsigned width, unsigned height);

	unsigned GetWidth() const;
	unsigned GetHeight() const;

	void Clear();
	void AddSample(unsigned x, unsigned y, RgbaColor sample, float weight);
	const unsigned char* GetRgba() const;

private:
	unsigned width;
	unsigned height;
	std::vector<RgbaColor> rgba;
};