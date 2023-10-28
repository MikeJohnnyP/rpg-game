#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton()
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::Initialize()
{
	size = sf::Vector2i(64, 64);
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setOutlineThickness(1);

}

void Skeleton::Load()
{
	if (texture.loadFromFile("Assets/Skeleton/Texture/spritesheet.png"))
	{
		sprite.setTexture(texture);
		int yIndex = 3;
		int xIndex = 0;

		sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
		sprite.setScale(sf::Vector2f(3, 3));
		sprite.setPosition(sf::Vector2f(700, 800));
		
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));

		std::cout << "Skeleton Texture is loaded" << std::endl;
	}
	else
	{
		std::cout << "Skeleton Texture is not loaded" << std::endl;
	}

}

void Skeleton::Update(float deltaTime)
{
	boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);
}
