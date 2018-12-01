#include "Spectrum.h"

Spectrum::Spectrum() :
	r(0),
	g(0),
	b(0)
{
}

Spectrum::Spectrum(float r, float g, float b) :
	r(r),
	g(g),
	b(b)
{
}

Spectrum Spectrum::operator*(float c)
{
	return Spectrum(r*c, g*c, b*c);
}

Spectrum& Spectrum::operator+=(const Spectrum& other)
{
	r += other.r;
	g += other.g;
	b += other.b;
	return *this;
}