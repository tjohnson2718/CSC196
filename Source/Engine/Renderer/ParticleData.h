#pragma once
#include "Core/Vector2.h"
#include "Core/Color.h"

namespace kiko
{
	struct ParticleData
	{
		vec2 position;
		vec2 prevPosition;
		vec2 velocity;
		float damping = 0;
		Color color;
		float lifetimer = 0;
		float lifetime = 0;
	};
}