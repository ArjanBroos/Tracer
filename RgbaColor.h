#pragma once

struct RgbaColor
{
	RgbaColor() : r(0), g(0), b(0), a(0) {}
	RgbaColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a) {}

	RgbaColor operator*(float c)
	{
		return RgbaColor(
			static_cast<unsigned char>(r*c),
			static_cast<unsigned char>(g*c),
			static_cast<unsigned char>(b*c),
			static_cast<unsigned char>(a*c));
	}

	RgbaColor& operator+=(const RgbaColor& rhs)
	{
		r += rhs.r;
		g += rhs.g;
		b += rhs.b;
		a += rhs.a;
		return *this;
	}

	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};