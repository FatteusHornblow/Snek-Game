#pragma once
#include <chrono>
class FrameTimer
{
public:
	FrameTimer();
	float MarkTime();
	~FrameTimer();
private:
	std::chrono::steady_clock::time_point last;
};

