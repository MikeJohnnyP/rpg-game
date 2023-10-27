#pragma once
#include <SFML/Graphics.hpp>

class Math
{
public:
	static sf::Vector2f nomalizedVector(sf::Vector2f vector);
	static bool didCollision(sf::FloatRect rect1, sf::FloatRect rect2);
};

