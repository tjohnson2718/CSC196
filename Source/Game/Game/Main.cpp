#include "Renderer/Renderer.h"
#include "Core/Core.h" 
#include "Renderer/Model.h"
#include"Input/InputSystem.h"
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
	kiko::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	kiko::InputSystem inputSystem;
	inputSystem.Initialize();

	kiko::Model model;
	model.Load("ship.txt");

	vector<Star> stars; 

	for (int i = 0; i < 1000; i++)
	{
		kiko::Vector2 pos(kiko::Vector2(kiko::random(renderer.GetWidth()), kiko::random(renderer.GetHeight())));
		kiko::Vector2 vel(kiko::randomf(0.7f, 4), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	kiko::Transform transform { { 400, 300 }, 0, 3 };

	kiko::vec2 position{ 400, 300 };
	float speed = 100; //pixels per second
	float turnRate = kiko::DegreesToRadians(180);

	// main game loop
	bool quit = false;
	while (!quit)
	{
		kiko::g_time.Tick();
		inputSystem.Update();
		if (inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		float rotate = 0;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_D)) rotate = 1;
		transform.rotation += rotate * turnRate * kiko::g_time.GetDeltaTime();

		float thrust = 0;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_W)) thrust = 1;

		kiko::vec2 forward = kiko::vec2{ 0, -1 }.Rotate(transform.rotation);
		transform.position += forward * speed * thrust * kiko::g_time.GetDeltaTime();
		transform.position.x = kiko::Wrap(transform.position.x, renderer.GetWidth());
		transform.position.y = kiko::Wrap(transform.position.y, renderer.GetHeight());

		/*kiko::vec2 direction;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_S)) direction.y = 1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_D)) direction.x = 1;

		position += direction * speed * kiko::g_time.GetDeltaTime();*/

		renderer.SetColor(0, 0, 0, 0); //sets color to black
		renderer.BeginFrame(); //clears the screen, allows for less static
		//draw

		for (auto& star : stars) //literally just made space screensaver
		{
			star.Update();

			if (star.m_pos.x >= renderer.GetWidth()) star.m_pos.x = 0;
			if (star.m_pos.y >= renderer.GetHeight()) star.m_pos.y = 0;
			renderer.SetColor(kiko::random(256), kiko::random(256), 150, 255);
			renderer.DrawPoint(star.m_pos.x, star.m_pos.y);
		}

		model.Draw(renderer, transform.position, transform.rotation, transform.scale);

		renderer.EndFrame();

		//this_thread::sleep_for(chrono::milliseconds(10));
	}

	return 0;
}
