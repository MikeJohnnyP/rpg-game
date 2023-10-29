#include "Player.h"
#include <iostream>

Player::Player() :
	playerSpeed(2.0f),
	fireRateTimer(0),
	maxFireRate(150)
{
}

Player::~Player()
{
}

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

		int yIndex = 3;
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

void Player::Update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePosition)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.move(sf::Vector2f(1, 0.f) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		sprite.move(sf::Vector2f(0.f, 1) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		sprite.move(sf::Vector2f(0.f, -1) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.move(sf::Vector2f(-1, 0.f) * playerSpeed * deltaTime);
//--------------------------- Bullets ---------------------------------------	
	fireRateTimer += deltaTime;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& fireRateTimer>= maxFireRate)
	{
		
		bullets.push_back(Bullet());
		int i = bullets.size() - 1;
		bullets[i].Initialize(sprite.getPosition(), mousePosition, 10.0f);
		fireRateTimer = 0;
	}
	
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Update(deltaTime);
		//sf::Vector2f direction = mousePosition - bullets[i].getPosition();
		//direction = Math::nomalizedVector(direction);
		//bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed * deltaTime);
		//std::cout << i << std::endl;
		
		if (skeleton.health >= 0) {
			if (Math::didCollision(bullets[i].getFloatRect(), skeleton.sprite.getGlobalBounds())) {
				bullets.erase(bullets.begin() + i);
				skeleton.changeHp(-10);
				std::cout << "COLLISION" << std::endl;

			}
		}
	}
	//--------------------------- Bullets ---------------------------------------	

	boundingRectangle.setPosition(sprite.getPosition());
	
	
}

void Player::Draw(sf::RenderWindow & window)
	{
		window.draw(sprite);
		window.draw(boundingRectangle);
		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].Draw(window);
		}

	}
