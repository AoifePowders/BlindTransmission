#include "levelLoader.h"

LevelLoader::LevelLoader() {}
LevelLoader::~LevelLoader() {}


void LevelLoader::load(std::string textFile)
{
	//Resets the array
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			level[i][j] = 0;
		}
	}
	//Open file and input into the array 
	std::ifstream file;
	file.open(textFile);
	if (file.is_open())
	{
		std::cout << "File Opened" << std::endl;
		while (!file.eof())
		{
			for (int i = 0; i < HEIGHT; i++)
			{
				for (int j = 0; j < WIDTH; j++)
				{
					file >> level[i][j];
					std::cout << level[i][j];
				}
				std::cout << std::endl;
			}
		}
	}
	file.close();
}