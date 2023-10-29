#include "Map.h"
#include <iostream>

Map::Map() : tileWidth(16), tileHeight(16), totalTileSheetX(0), totalTileSheetY(0)
{
}

Map::~Map()
{
}

void Map::Initialize()
{
}

void Map::Load()
{
	if (tileSheetTexture.loadFromFile("Assets/Worlds/Prison/tilesheet.png")) {
		totalTileSheetX = tileSheetTexture.getSize().x / tileWidth;
		totalTileSheetY = tileSheetTexture.getSize().y / tileHeight; 

		std::cout << "Load world prison sucessfully" << std::endl;
		for (size_t i = 0; i < 10; i++) 
		{
			sprites[i].setTexture(tileSheetTexture);
			sprites[i].setScale(sf::Vector2f(5, 5));
			sprites[i].setTextureRect(sf::IntRect(i * tileWidth, i * tileHeight, tileWidth, tileHeight));
			sprites[i].setPosition(sf::Vector2f(500 + i * tileWidth * 5 , 500));
		}
		
	}
	else {
		std::cout << "Failed to load world prison" << std::endl;
	}
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for(size_t i =0; i<10;i++)
	window.draw(sprites[i]);
}
