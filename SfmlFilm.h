#pragma once

#include "Film.h"
#include <SFML/Graphics.hpp>

class SfmlFilm
{
public:
	SfmlFilm(unsigned width, unsigned height);

	void Clear();
	void AddSample(unsigned x, unsigned y, RgbaColor sample, float weight);
	const sf::Sprite& GetSprite();

private:
	Film film;
	sf::Texture texture;
	sf::Sprite sprite;
};