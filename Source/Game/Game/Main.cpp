#include <iostream>
#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Renderer/Renderer.h"
#include "Core/Time.h"



int main()
{
	kiko::g_memoryTracker.DisplayInfo();
	int* p = new int;
	kiko::g_memoryTracker.DisplayInfo();
	delete p;
	kiko::g_memoryTracker.DisplayInfo();

	kiko::Time timer;
	for (int i = 0; i < 1000000; i++){}
	std::cout << timer.GetElapsedMilliseconds() << std::endl;

	/*auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000000; i++)
	{

	}
	auto end = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;*/

	//std::cout << kiko::getFilePath() << std::endl;
	//kiko::setFilePath("Assets");
	//std::cout << kiko::getFilePath() << std::endl;

	//size_t size;
	//kiko::getFileSize("game.txt", size);
	//std::cout << size << std::endl;

	////std::string s;
	////kiko::readFile("game.txt", s);
	////std::cout << s << std::endl;

	//kiko::seedRandom((unsigned int)time(nullptr));
	//for (int i = 0; i < 10; i++)
	//{
	//	std::cout << kiko::random(10, 20) << std::endl;
	//}
}
