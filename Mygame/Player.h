#pragma once
#include "Skeleton.h"
#include "Math.h"

class Player
{
private:
	sf::Vector2i size;
	sf::Texture texture;
	float bulletSpeed;
	float playerSpeed;
	std::vector<sf::RectangleShape> bullets;
	sf::RectangleShape boundingRectangle;
	
public:
	sf::Sprite sprite;

public:
	Player();
	~Player();
	void Initialize();
	void Load();
	void Update(float deltaTime,Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);
};

