#pragma once
#include "Core/Core.h"
#include "Renderer/Model.h"

namespace kiko
{
	class Actor
	{
	public:
		Actor() = default;

		Actor(const kiko::Transform& transform, const kiko::Model& model) :
			m_transform{ transform },
			m_model{ model }
		{}

		virtual void Update(float dt);
		virtual void Draw(kiko::Renderer& renderer);

		class Scene* m_scene = nullptr;
		friend class Scene;

		kiko::Transform m_transform;

	protected:
		bool m_destroyed = false;
		float m_lifespan = -1.0f;

		kiko::Model m_model;
	};
}
