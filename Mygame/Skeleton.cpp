#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : health(100)
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::changeHp(int hp)
{
	health += hp;
	healthText.setString(std::to_string(health));


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
	if (fonts.loadFromFile("Assets/Fonts/arial.ttf")) {
		std::cout << "Load Font sucessfully" << std::endl;
		healthText.setFont(fonts);
		healthText.setPosition(sprite.getPosition());
		healthText.setString(std::to_string(health));
	}
	else {
		std::cout << "Failed to load font" << std::endl;
	}

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
	healthText.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	if (health >= 0) {
		window.draw(sprite);
		window.draw(boundingRectangle);
		window.draw(healthText);
	}
}
