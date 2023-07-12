#pragma once
#include <cmath>

namespace kiko
{
	constexpr float Pi = 3.14159265359f;
	constexpr float TwoPi = 6.28318530718f;
	constexpr float HalfPi = 1.57079632679f;

	constexpr float RadiansToDegrees(float radians) { return radians * (180.0f / Pi); }
	constexpr float DegreesToRadians(float degrees) { return degrees * (Pi / 180.0f); }

	constexpr int Wrap(int value, int max)
	{
		return (value % max) + ((value < 0) ? max : 0);
	}
}
