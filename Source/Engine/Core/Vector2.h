#pragma once

namespace kiko
{
	class Vector2
	{
	public:
		float x, y;
	public:
		Vector2() : x{ 0 }, y{ 0 } {}
		Vector2(float v) { x = 0; y = 0; }
		Vector2(float x, float y) { this->x = x; this->y = y; }
		
	};
}