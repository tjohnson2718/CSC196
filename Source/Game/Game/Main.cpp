#include "Renderer/Renderer.h"
#include "Core/Core.h" 
#include "Renderer/Model.h"
#include"Input/InputSystem.h"
#include "Player.h"
#include "Enemy.h"
#include "Audio/AudioSystem.h"
#include "Framework/Scene.h"

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

	kiko::g_audioSystem.Initialize();
	kiko::g_audioSystem.AddAudio("shoot", "Laser2.wav");

	kiko::Model model;
	model.Load("ship.txt");

	vector<Star> stars; 

	for (int i = 0; i < 1000; i++)
	{
		kiko::Vector2 pos(kiko::Vector2(kiko::random(kiko::g_renderer.GetWidth()), kiko::random(kiko::g_renderer.GetHeight())));
		kiko::Vector2 vel(kiko::randomf(0.7f, 4), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	kiko::Scene scene;
	scene.Add(new Player{ 200, kiko::Pi, { { 400, 300 }, 0, 6  }, model });

	for (int i = 0; i < 5; i++)
	{
		Enemy* enemy = new Enemy{ 10.0f, kiko::Pi, { { kiko::random(800), kiko::random(600) }, kiko::randomf(kiko::TwoPi), 3.0f}, model};
		scene.Add(enemy);
	}
	

	// main game loop
	bool quit = false;
	while (!quit)
	{
		kiko::g_time.Tick();

		kiko::g_audioSystem.Update();

		if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE) &&
			!kiko::g_inputSystem.GetPreviousKeyDown(SDL_SCANCODE_SPACE))
		{
			kiko::g_audioSystem.PlayOneShot("shoot");
		}

		kiko::g_inputSystem.Update();
		if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		scene.Update(kiko::g_time.GetDeltaTime());
		
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

		scene.Draw(kiko::g_renderer);

		kiko::g_renderer.EndFrame();

		//this_thread::sleep_for(chrono::milliseconds(10));
	}

	return 0;
}
