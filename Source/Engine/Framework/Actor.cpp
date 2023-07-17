#include "Actor.h"

namespace kiko
{
	void Actor::Draw(kiko::Renderer& renderer)
	{
		m_model.Draw(renderer, m_transform);
	}
}

