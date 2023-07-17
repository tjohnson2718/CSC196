#include "Scene.h"
#include "Actor.h"

namespace kiko
{
	void Scene::Update(float dt)
	{
		for (auto actor : m_actors)
		{
			actor->Update(dt);
		}
	}

	void Scene::Draw(Renderer& renderer)
	{
		for (auto actor : m_actors)
		{
			actor->Draw(renderer);
		}
	}

	void Scene::Add(Actor* actor)
	{
		actor->m_scene = this;
		m_actors.push_back(actor);
	}

	void Scene::Remove(Actor* actor)
	{
		m_actors.remove(actor);
	}

	void Scene::RemoveAll()
	{
		m_actors.clear();
	}
}