#pragma once
#include "Skeleton.h"
#include "Math.h"
#include "Bullet.h"

class Player
{
private:
	sf::Vector2i size;
	sf::Texture texture;
	float playerSpeed;
	float fireRateTimer;
	float maxFireRate;
	std::vector<Bullet> bullets;
	sf::RectangleShape boundingRectangle;
	
public:
	sf::Sprite sprite;

public:
	Player();
	~Player();
	void Initialize();
	void Load();
	void Update(float deltaTime,Skeleton& skeleton, sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow& window);
};

