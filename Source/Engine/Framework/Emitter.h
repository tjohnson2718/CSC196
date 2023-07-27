#pragma once
#include "Actor.h"
#include "EmitterData.h"

namespace kiko
{
	class Emitter : public Actor
	{
	public:
		Emitter() = default;
		Emitter(const Transform& transform, const EmitterData& data) :
			Actor{ transform },
			m_data{ data }
		{}
		void Update(float dt);
		void Draw(kiko::Renderer& renderer);
	private:
		void Emit();
	private:
		EmitterData m_data;
	};
}
