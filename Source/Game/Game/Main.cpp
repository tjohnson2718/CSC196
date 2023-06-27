#include <iostream>
#include "Core/Random.h"
#include "Core/FileIO.h"

int main()
{
	std::cout << kiko::getFilePath() << std::endl;

	kiko::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 10; i++)
	{
		std::cout << kiko::random(10, 20) << std::endl;
	}
}
