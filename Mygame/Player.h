#pragma once
#include "Skeleton.h"
#include "Math.h"

class Player
{
private:
	sf::Texture texture;
	float bulletSpeed = 0.5f;
	std::vector<sf::RectangleShape> bullets;
	sf::Vector2f direction;

public:
	sf::Sprite sprite;

public:
	void Initialize();
	void Load();
	void Update(Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);
};

