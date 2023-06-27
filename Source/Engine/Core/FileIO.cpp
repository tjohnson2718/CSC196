#include "FileIO.h"

namespace kiko
{
	std::string kiko::getFilePath()
	{
		return std::filesystem::current_path().string();
	}
}
