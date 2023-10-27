#include "Player.h"
#include <iostream>

void Player::Initialize()
{
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Texture/spritesheet.png"))
	{
		sprite.setTexture(texture);

		int yIndex = 0;
		int xIndex = 0;

		sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
		sprite.setScale(sf::Vector2f(3, 3));

		std::cout << "Player Texture is loaded" << std::endl;
	}
	else
	{
		std::cout << "Player Texture is not loaded" << std::endl;
	}

}

void Player::Update(Skeleton& skeleton)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.move(sf::Vector2f(1, 0.f));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		sprite.move(sf::Vector2f(0.f, 1));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		sprite.move(sf::Vector2f(0.f, -1));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.move(sf::Vector2f(-1, 0.f));

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
		bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed);
	}
}

void Player::Draw(sf::RenderWindow & window)
	{
		window.draw(sprite);
		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}

	}
