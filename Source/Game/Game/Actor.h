#pragma once
#include "Core/Core.h"
#include "Renderer/Model.h"

class Actor
{
public:
	Actor() = default;

	Actor(const kiko::Transform& transform, const kiko::Model& model) :
		m_transform { transform },
		m_model { model }
	{}

	virtual void Update(float dt) = 0;
	virtual void Draw(kiko::Renderer& renderer);

protected:
	kiko::Transform m_transform;
	kiko::Model m_model;
};