#pragma once

#include <chrono>

class FpsCounter
{
public:
	FpsCounter();

	void Count();
	unsigned GetFramesPerSecond() const;

private:
	bool ASecondHasPassed() const;

	std::chrono::time_point<std::chrono::high_resolution_clock> frameStart;
	unsigned frameCount;
	unsigned lastFramesPerSecond;
};
