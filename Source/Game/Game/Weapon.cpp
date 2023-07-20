#include "Weapon.h"

void Weapon::Update(float dt)
{
	Actor::Update(dt);

	kiko::vec2 forward = kiko::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * m_speed * kiko::g_time.GetDeltaTime();
	m_transform.position.x = kiko::Wrap(m_transform.position.x, (float)kiko::g_renderer.GetWidth());
	m_transform.position.y = kiko::Wrap(m_transform.position.y, (float)kiko::g_renderer.GetHeight());
}

void Weapon::OnCollision(Actor* other)
{
	m_destroyed = true;
}
