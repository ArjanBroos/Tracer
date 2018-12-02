#include "FpsCounter.h"

std::chrono::time_point<std::chrono::high_resolution_clock> Now()
{
	return std::chrono::high_resolution_clock::now();
}

FpsCounter::FpsCounter() :
	frameCount(0),
	frameStart(Now()),
	lastFramesPerSecond(0)
{
}

void FpsCounter::Count()
{
	if (ASecondHasPassed())
	{
		lastFramesPerSecond = frameCount;
		frameCount = 0;
		frameStart = Now();
	}
	frameCount++;
}

unsigned FpsCounter::GetFramesPerSecond() const
{
	return lastFramesPerSecond;
}

bool FpsCounter::ASecondHasPassed() const
{
	return Now() - frameStart > std::chrono::seconds(1);
}
