#pragma once
#include <SFML/Graphics.hpp>
class Skeleton
{
private:
	sf::Texture texture;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;
	sf::Font fonts;
	sf::Text healthText;
public:
	sf::Sprite sprite;
	int health;

public:
	Skeleton();
	~Skeleton();
	void changeHp(int hp);
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

