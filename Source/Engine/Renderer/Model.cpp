#include "Model.h"

namespace kiko
{
	void Model::Draw(Renderer& renderer)
	{
		for (int i = 0; i < m_points.size() - 1; i++)
		{
			vec2 p1 = m_points[i];
			vec2 p2 = m_points[i + 1];

			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
}