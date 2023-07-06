#include <iostream>
#include "Core/Core.h"
#include <vector>
#include "Renderer/Renderer.h"

using namespace std;
int main(int argc, char* argv[])
{
	kiko::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);
	cin.get();
	

	while (1)
	{
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();
		//draw
		/*for (auto point : points)
		{
			point.x += 1;
			renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), 255);
			renderer.DrawPoint(point.x, point.y);

		}*/

		for (int i = 0; i < 1000; i++)
		{
			renderer.SetColor(kiko::random(0, 256), kiko::random(0, 256), kiko::random(0, 256), 255);
			renderer.DrawPoint(kiko::random(renderer.GetWidth()), kiko::random(renderer.GetHeight()));
		}
		//draw random lines


		renderer.EndFrame();
	}

	return 0;
}
