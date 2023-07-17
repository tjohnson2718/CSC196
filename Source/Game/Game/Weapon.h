#pragma once
#include "Framework/Actor.h"

class Weapon : public kiko::Actor
{
public:
	Weapon(float speed, const kiko::Transform& transform, const kiko::Model& model) :
		Actor{ transform, model },
		m_speed{ speed }
	{}

	void Update(float dt) override;

private:
	float m_speed = 0;

};