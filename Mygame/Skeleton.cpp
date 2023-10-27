#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
	if (texture.loadFromFile("Assets/Skeleton/Texture/spritesheet.png"))
	{
		sprite.setTexture(texture);
		int yIndex = 3;
		int xIndex = 0;

		sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
		sprite.setScale(sf::Vector2f(3, 3));
		sprite.setPosition(sf::Vector2f(1650, 800));

		std::cout << "Skeleton Texture is loaded" << std::endl;
	}
	else
	{
		std::cout << "Skeleton Texture is not loaded" << std::endl;
	}

}

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
