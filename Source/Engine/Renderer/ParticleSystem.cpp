#include "ParticleSystem.h"
#include "Renderer/Renderer.h"

namespace kiko
{
	ParticleSystem g_particleSystem(1000);

	void ParticleSystem::Update(float dt)
	{
		for (auto& particle : m_particles)
		{
			if (particle.m_isActive) particle.Update(dt);
			particle.Draw(g_renderer);
		}
	}

	void ParticleSystem::Draw(Renderer& renderer)
	{
		for (auto& particle : m_particles)
		{
			if (particle.m_isActive) particle.Draw(renderer);
		}
	}

	Particle* ParticleSystem::GetFreeParticle()
	{
		for (auto& particle : m_particles)
		{
			if (!particle.m_isActive) return &particle;
		}
		return nullptr;
	}

}