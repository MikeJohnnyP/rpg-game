#pragma once
#include <SFML/Graphics.hpp>

class FrameRate
{
private:
	sf::Text frameText;
	sf::Font fonts;
	float timer;

public:

	FrameRate();
	~FrameRate();
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

