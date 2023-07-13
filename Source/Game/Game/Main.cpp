#include "Renderer/Renderer.h"
#include "Core/Core.h" 
#include "Renderer/Model.h"
#include"Input/InputSystem.h"
#include "Player.h"
#include "Enemy.h"

#include <iostream> 
#include <vector>
#include <thread>

using namespace std;

class Star
{
public:
	Star(const kiko::Vector2& pos, const kiko::Vector2& vel) :
		m_pos{ pos },
		m_vel{ vel }
	{}

	void Update()
	{
		m_pos += m_vel * kiko::g_time.GetDeltaTime();
	}

	void Draw(kiko::Renderer& renderer)
	{
		renderer.DrawPoint(m_pos.x, m_pos.y);
	}

public:
	kiko::vec2 m_pos;
	kiko::vec2 m_vel;
};


int main(int argc, char* argv[])
{
	kiko::seedRandom((unsigned int)time(nullptr));
	kiko::setFilePath("assets");

	//our window setup
	kiko::g_renderer.Initialize();
	kiko::g_renderer.CreateWindow("CSC196", 800, 600);

	
	kiko::g_inputSystem.Initialize();

	kiko::Model model;
	model.Load("ship.txt");

	vector<Star> stars; 

	for (int i = 0; i < 1000; i++)
	{
		kiko::Vector2 pos(kiko::Vector2(kiko::random(kiko::g_renderer.GetWidth()), kiko::random(kiko::g_renderer.GetHeight())));
		kiko::Vector2 vel(kiko::randomf(0.7f, 4), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	kiko::Transform transform { { 400, 300 }, 0, 3 };

	kiko::vec2 position{ 400, 300 };
	float speed = 100; //pixels per second
	constexpr float turnRate = kiko::DegreesToRadians(180);

	Player player{ 200, kiko::Pi, { { 400, 300 }, 0, 6  }, model };

	std::vector<Enemy> enemies;
	for (int i = 0; i < 100; i++)
	{
		Enemy enemy{ 300.0f, kiko::Pi, { { kiko::random(800), kiko::random(600) }, kiko::randomf(kiko::TwoPi), 3.0f}, model};
		enemies.push_back(enemy);
	}
	

	// main game loop
	bool quit = false;
	while (!quit)
	{
		kiko::g_time.Tick();
		kiko::g_inputSystem.Update();
		if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		player.Update(kiko::g_time.GetDeltaTime());

		for (auto& enemy : enemies) enemy.Update(kiko::g_time.GetDeltaTime());
		
		kiko::g_renderer.SetColor(0, 0, 0, 0); //sets color to black
		kiko::g_renderer.BeginFrame(); //clears the screen, allows for less static
		//draw

		for (auto& star : stars) //literally just made space screensaver
		{
			star.Update();

			if (star.m_pos.x >= kiko::g_renderer.GetWidth()) star.m_pos.x = 0;
			if (star.m_pos.y >= kiko::g_renderer.GetHeight()) star.m_pos.y = 0;
			kiko::g_renderer.SetColor(kiko::random(256), kiko::random(256), 150, 255);
			kiko::g_renderer.DrawPoint(star.m_pos.x, star.m_pos.y);
		}

		player.Draw(kiko::g_renderer);
		for (auto& enemy : enemies) enemy.Draw(kiko::g_renderer);

		kiko::g_renderer.EndFrame();

		//this_thread::sleep_for(chrono::milliseconds(10));
	}

	return 0;
}
