#pragma once

struct Spectrum
{
	Spectrum();
	Spectrum(float r, float g, float b);

	Spectrum operator*(float c);
	Spectrum& operator+=(const Spectrum& other);

	float r;
	float g;
	float b;
};