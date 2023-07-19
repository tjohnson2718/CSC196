#pragma once
#include <list>
#include "Actor.h"

namespace kiko
{
	class Renderer;

	class Scene
	{
	public:
		Scene() = default;

		void Update(float dt);
		void Draw(Renderer& renderer);

		void Add(std::unique_ptr<Actor> actor);
		void Remove(Actor* actor);
		void RemoveAll();

	private:
		std::list<std::unique_ptr<Actor>> m_actors;

	};
}