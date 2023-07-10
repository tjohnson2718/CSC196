#include "Renderer/Renderer.h"
#include "Core/Core.h" //linked to a bunch of directories
#include "Renderer/Model.h"
#include <iostream> //searches the system instead
#include <vector>
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
		m_pos += m_vel;
	}

	void Draw(kiko::Renderer& renderer)
	{
		renderer.DrawPoint(m_pos.x, m_pos.y);
	}

public:
	kiko::vec2 m_pos;
	kiko::vec2 m_vel;
};

//adds literally too many things at once
/*
void func()
{
	int* p = new int[1000000000];
}

void funcs() //will crash your shit with a stack overflow
{
	int i[100000];
	funcs();
}
*/

int main(int argc, char* argv[])
{

	kiko::seedRandom((unsigned int)time(nullptr));

	//our window setup
	kiko::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	std::vector<kiko::vec2> points{ {-10, 5}, { 10, 5 }, { -10, -5 }, { -10, 5 } }; //initializer list, dont need to specify vec2 cause it already knows
	kiko::Model model(points);
	kiko::vec2 v{5, 5};
	v.Normalize();


	//vector<umbra::Vector2> points; //an array of values
	vector<Star> stars; //not in a namespace so its fine

	for (int i = 0; i < 1000; i++)
	{
		kiko::Vector2 pos(kiko::Vector2(kiko::random(renderer.GetWidth()), kiko::random(renderer.GetHeight())));
		kiko::Vector2 vel(kiko::randomf(0.7f, 4), 0.0f);

		stars.push_back(Star(pos, vel));
	}

	while (true)
	{
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

		model.Draw(renderer, { 400, 300 }, 25.6);

		/*
		for (int i = 0; i < 1000; i++)
		{
			umbra::Vector2 pos(umbra::random(renderer.GetWidth()), umbra::random(renderer.GetHeight()));

			renderer.SetColor(umbra::random(256), umbra::random(256), 150, 255); //sets a random color BEFORE its drawn
			renderer.DrawPoint(umbra::random(renderer.GetWidth()), umbra::random(renderer.GetHeight()));
			//renderer.DrawLine(umbra::random(renderer.GetWidth()), umbra::random(renderer.GetHeight()), renderer.GetWidth(), umbra::random(renderer.GetHeight()));
		}

		for (int i = 0; i < 10; i++)
		{

		}
		*/

		renderer.EndFrame();
	}

	return 0;
}

//umbra::CreateWindow("CSC196", 800, 600);
//cin.get(); // is a pause, prevents window from opening/closing too fast

/*
//memory time fellas
umbra::g_memoryTracker.DisplayInfo();
int* p = new int; //holds the ADDRESS of an int
umbra::g_memoryTracker.DisplayInfo();
delete p;
umbra::g_memoryTracker.DisplayInfo();

umbra::Time timer;
for (int i = 0; i < 10000000000000000000; i++) {}
cout << timer.GetElapsedSeconds() << endl;
*/

//chrono time, literally	
//auto start = std::chrono::high_resolution_clock::now(); //auto - figures out the datatype by the code assignment
//for (int i = 0; i < 10000000000000000000; i++) {}
//auto end = std::chrono::high_resolution_clock::now();
//cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl; //<casts> it into microsecodns

/*
cout << umbra::getFilePath() << endl;
umbra::setFilePath("Assets"); //not case sensitive
cout << umbra::getFilePath() << endl;

size_t size;
umbra::getFileSize("game.txt", size);
cout << size << endl;

std::string s;
umbra::readFile("game.txt", s);
cout << s << endl;
*/

// ../ goes back a SINGLE directory, can nagivate the entire directory

/*
umbra::seedRandom((unsigned int)time(nullptr)); //returns system time in seconds starting // () is a cast
for (int i = 0; i < 10; i++)
{
	cout << umbra::random(10, 20) << endl;
}
*/
