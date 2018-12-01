#pragma once

#include <vector>
#include "RgbaColor.h"

class Film
{
public:
	Film(unsigned width, unsigned height);

	void Clear();
	void AddSample(unsigned x, unsigned y, RgbaColor sample, float weight);
	unsigned char* GetRgba();

private:
	unsigned width;
	unsigned height;
	std::vector<RgbaColor> rgba;
};