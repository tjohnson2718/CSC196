#include "Enemy.h"
#include "Player.h"
#include "SpaceGame.h"
#include "Framework/Scene.h"
#include "Renderer/Renderer.h"

void Enemy::Update(float dt)
{
	Actor::Update(dt);

	Player* player = m_scene->GetActor<Player>();
	if (player)
	{
		kiko::Vector2 direction = player->m_transform.position - m_transform.position;
		m_transform.rotation = direction.Angle() + kiko::HalfPi;
	}

	kiko::vec2 forward = kiko::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * m_speed * kiko::g_time.GetDeltaTime();
	m_transform.position.x = kiko::Wrap(m_transform.position.x, (float)kiko::g_renderer.GetWidth());
	m_transform.position.y = kiko::Wrap(m_transform.position.y, (float)kiko::g_renderer.GetHeight());

	if (m_fireTimer != 0)
	{

	}
	else
	{

	}
}

void Enemy::OnCollision(Actor* other)
{
	//Player* p = dynamic_cast<Player*>(other)
	if (other->m_tag == "Player")
	{
		m_game->AddPoints(100);
		m_destroyed = true;
	}
}
