//Created by Dale Sinnott
#include "Grid.h"
#include <iostream>
Grid::Grid()
{

}
void Grid::update()
{
	for (int i = 0; i < m_height * m_width; i++)
	{
		map.at(i)->update();
	}
}
void Grid::render(sf::RenderWindow &window)
{
	for (int i = 0; i < m_height * m_width; i++)
	{
		map.at(i)->render(window);
	}
}
void Grid::initialise(int level)
{
	//Tile textures
	std::string floorTexturePath = "ASSETS//IMAGES//floor2.png";
	std::string wallTexturePath = "ASSETS//IMAGES//wall3.png";
	std::string exitTexturePath = "ASSETS//IMAGES//exit.png";
	std::string tableTexturePath = "ASSETS//IMAGES//table.png";
	std::string chairTexturePath = "ASSETS//IMAGES//chair.png";
	std::string bedTexturePath = "ASSETS//IMAGES//bed.png";
	std::string entranceTexturePath = "ASSETS//IMAGES//entrance.png";
	//Load the level grid from a text file
	switch (level)
	{
	case 1:
		lLoader.load("ASSETS//LEVELS//Level1.txt");
		break;
	case 2:
		lLoader.load("ASSETS//LEVELS//Level2.txt");
		break;
	case 3:
		lLoader.load("ASSETS//LEVELS//Level3.txt");
		break;
	case 4:
		lLoader.load("ASSETS//LEVELS//Level4.txt");
		break;
	case 5:
		lLoader.load("ASSETS//LEVELS//Level5.txt");
		break;
	default:
		break;
	}
	
	sf::Texture floorTexture;
	if (!floorTexture.loadFromFile(floorTexturePath)){std::cout << floorTexturePath << std::endl;}
	sf::Texture wallTexture;
	if (!wallTexture.loadFromFile(wallTexturePath)){std::cout << wallTexturePath << std::endl;}
	sf::Texture exitTexture;
	if (!exitTexture.loadFromFile(exitTexturePath)) { std::cout << exitTexturePath << std::endl; }
	sf::Texture tableTexture;
	if (!tableTexture.loadFromFile(tableTexturePath)) { std::cout << tableTexturePath << std::endl; }
	sf::Texture chairTexture;
	if (!chairTexture.loadFromFile(chairTexturePath)) { std::cout << chairTexturePath << std::endl; }
	sf::Texture bedTexture;
	if (!bedTexture.loadFromFile(bedTexturePath)) { std::cout << bedTexturePath << std::endl; }
	sf::Texture entranceTexture;
	if (!entranceTexture.loadFromFile(entranceTexturePath)) { std::cout << entranceTexturePath << std::endl; }

	m_width = 14;
	m_height = 8;
	Tile tempTile(sf::Vector2f(0, 0),
		std::make_shared<sf::Texture>(floorTexture),
		std::make_shared<sf::Texture>(wallTexture),
		std::make_shared<sf::Texture>(exitTexture),
		std::make_shared<sf::Texture>(tableTexture),
		std::make_shared<sf::Texture>(chairTexture),
		std::make_shared<sf::Texture>(bedTexture),
		std::make_shared<sf::Texture>(entranceTexture),
		86);
	tCount = 0;
	map.clear();
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{//set tiles into grid
			tempTile.updatePosition(sf::Vector2f( + x * 86, + y * 86));
			switch (lLoader.level[y][x])
			{
			case 1:
				tempTile.setType(Tile::WALL);
				break;
			case 2:
				tempTile.setType(Tile::EXIT);
				break;
			case 3:
				tempTile.setType(Tile::TABLE);
				break;
			case 4:
				tempTile.setType(Tile::CHAIR);
				break;
			case 5:
				tempTile.setType(Tile::BED);
				break;
			case 6:
				tempTile.setType(Tile::ENTRANCE);
				break;
			default:
				tempTile.setType(Tile::DEFAULT);
				break;
			}
			map.push_back(std::make_shared<Tile>(tempTile));
		}
	}
}