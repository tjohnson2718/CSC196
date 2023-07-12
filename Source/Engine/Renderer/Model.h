#pragma once
#include "Core/Core.h"
#include "Renderer.h"
#include <vector>


namespace kiko
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<vec2>& points) : m_points{ points } {};

		bool Load(const std::string& filename);
		void Draw(Renderer& renderer, const vec2& position, float rotation, float scale); 

	private:
		std::vector<Vector2> m_points;
	};
}