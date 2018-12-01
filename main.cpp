#include <SFML/Graphics.hpp>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "SfmlFilm.h"

SfmlFilm CreateTestFilm(unsigned width, unsigned height)
{
	SfmlFilm film(width, height);
	for (unsigned y = 0; y < height; y++)
	{
		for (unsigned x = 0; x < width; x++)
		{
			Spectrum spectrum(
				static_cast<float>(x) / width,
				static_cast<float>(y) / height,
				static_cast<float>(x + y) / (width + height));
			film.AddSample(x, y, spectrum, 1.f);
		}
	}
	return film;
}

int __stdcall WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	const unsigned width = 800;
	const unsigned height = 600;
	sf::RenderWindow window(sf::VideoMode(width, height), "Tracer");

	SfmlFilm film = CreateTestFilm(width, height);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(film.GetSprite());
		window.display();
	}

	return 0;
}