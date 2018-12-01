#include "SfmlFilm.h"

SfmlFilm::SfmlFilm(unsigned width, unsigned height) :
	film(width, height)
{
	texture.create(width, height);
	texture.setSmooth(false);
	sprite.setTexture(texture);
}

void SfmlFilm::Clear()
{
	film.Clear();
}

void SfmlFilm::AddSample(unsigned x, unsigned y, RgbaColor sample, float weight)
{
	film.AddSample(x, y, sample, weight);
}

const sf::Sprite & SfmlFilm::GetSprite()
{
	texture.update(film.GetRgba());
	return sprite;
}
