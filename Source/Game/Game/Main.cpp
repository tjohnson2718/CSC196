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

	//std::vector<kiko::vec2> points{ {-10, 5}, { 10, 5 }, { -10, -5 }, { -10, 5 } }; //initializer list, dont need to specify vec2 cause it already knows
	kiko::Model model;
	model.Load("ship.txt");

	//kiko::Model model(points);
	//kiko::vec2 v{5, 5};
	//v.Normalize();


	//vector<umbra::Vector2> points; //an array of values
	vector<Star> stars; //not in a namespace so its fine

	for (int i = 0; i < 1000; i++)
	{
		kiko::Vector2 pos(kiko::Vector2(kiko::random(renderer.GetWidth()), kiko::random(renderer.GetHeight())));
		kiko::Vector2 vel(kiko::randomf(0.7f, 4), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	kiko::vec2 position{ 400, 300 };
	float speed = 100; //pixels per second

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

		kiko::vec2 direction;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_S)) direction.y = 1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_D)) direction.x = 1;

		position += direction * speed * kiko::g_time.GetDeltaTime();

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

		model.Draw(renderer, position, 4.0f);

		renderer.EndFrame();

		//this_thread::sleep_for(chrono::milliseconds(10));
	}

	return 0;
}
