#include "SfmlFilm.h"
#include <algorithm>

SfmlFilm::SfmlFilm(unsigned width, unsigned height) :
	film(width, height)
{
	texture.create(width, height);
	texture.setSmooth(false);
	sprite.setTexture(texture);
}

SfmlFilm::SfmlFilm(const SfmlFilm& other) :
	film(other.film),
	texture(other.texture),
	sprite(other.sprite)
{
	texture.update(other.texture);
	sprite.setTexture(texture);
}

SfmlFilm::SfmlFilm(SfmlFilm&& other) :
	film(other.film),
	texture(other.texture),
	sprite(other.sprite)
{
	// SFML texture does not support move semantics, so copy texture contents
	texture.update(other.texture);
	sprite.setTexture(texture);
}

SfmlFilm& SfmlFilm::operator=(const SfmlFilm& other)
{
	return *this = SfmlFilm(other);
}

SfmlFilm& SfmlFilm::operator=(SfmlFilm&& other)
{
	film = other.film;
	texture = other.texture;
	sprite = other.sprite;
	return *this;
}

unsigned SfmlFilm::GetWidth() const
{
	return film.GetWidth();
}

unsigned SfmlFilm::GetHeight() const
{
	return film.GetHeight();
}

void SfmlFilm::Clear()
{
	film.Clear();
}

void SfmlFilm::AddSample(unsigned x, unsigned y, Spectrum sample, float weight)
{
	film.AddSample(x, y, sample, weight);
}

const sf::Sprite& SfmlFilm::GetSprite()
{
	auto rgba = ToRgba(film.GetImage());
	texture.update(rgba.data());
	return sprite;
}

std::vector<sf::Uint8> SfmlFilm::ToRgba(const std::vector<Spectrum>& image)
{
	std::vector<sf::Uint8> rgba;
	rgba.reserve(GetWidth() * GetHeight() * 4);
	for (auto spectrum : image)
	{
		const auto max = 255;
		rgba.push_back(static_cast<sf::Uint8>(spectrum.r * max));
		rgba.push_back(static_cast<sf::Uint8>(spectrum.g * max));
		rgba.push_back(static_cast<sf::Uint8>(spectrum.b * max));
		rgba.push_back(max);
	}
	return rgba;
}
