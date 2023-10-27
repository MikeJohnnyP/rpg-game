#include "Player.h"
#include <iostream>

void Player::Initialize()
{
	size = sf::Vector2i(64, 64);
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Texture/spritesheet.png"))
	{
		sprite.setTexture(texture);

		int yIndex = 0;
		int xIndex = 0;
		
		
		sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
		sprite.setScale(sf::Vector2f(3, 3));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));

		std::cout << "Player Texture is loaded" << std::endl;
	}
	else
	{
		std::cout << "Player Texture is not loaded" << std::endl;
	}

}

void Player::Update(float deltaTime, Skeleton& skeleton)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.move(sf::Vector2f(1, 0.f) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		sprite.move(sf::Vector2f(0.f, 1) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		sprite.move(sf::Vector2f(0.f, -1) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.move(sf::Vector2f(-1, 0.f) * playerSpeed * deltaTime);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
		int i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		sf::Vector2f direction = skeleton.sprite.getPosition() - bullets[i].getPosition();
		direction = Math::nomalizedVector(direction);
		bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed * deltaTime);
	}
	
	boundingRectangle.setPosition(sprite.getPosition());
	
	if (Math::didCollision(sprite.getGlobalBounds(),skeleton.sprite.getGlobalBounds())){
		std::cout << "COLLISION" << std::endl;
	}
}

void Player::Draw(sf::RenderWindow & window)
	{
		window.draw(sprite);
		window.draw(boundingRectangle);
		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}

	}
