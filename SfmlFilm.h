#pragma once

#include "Film.h"
#include <SFML/Graphics.hpp>

class SfmlFilm
{
public:
	SfmlFilm(unsigned width, unsigned height);
	SfmlFilm(const SfmlFilm& other);
	SfmlFilm(SfmlFilm&& other);
	SfmlFilm& operator=(const SfmlFilm& other);
	SfmlFilm& operator=(SfmlFilm&& other);

	unsigned GetWidth() const;
	unsigned GetHeight() const;

	void Clear();
	void AddSample(unsigned x, unsigned y, RgbaColor sample, float weight);
	const sf::Sprite& GetSprite();

private:
	Film film;
	sf::Texture texture;
	sf::Sprite sprite;
};