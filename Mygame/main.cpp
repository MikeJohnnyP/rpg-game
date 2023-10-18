#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	//----------------------INITIALIZE----------------------------
	sf::RenderWindow window(sf::VideoMode(800, 800), "RPG Game",sf::Style::Default);
	//----------------------INITIALIZE----------------------------
	
	//----------------------LOAD----------------------------
	sf::Texture playTexture;
	sf::Sprite playSprite;

	if (playTexture.loadFromFile("Assets/Texture/spritesheet.png"))
	{
		playSprite.setTexture(playTexture);

		int yIndex = 0;
		int xIndex = 0;

		playSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64,64,64));
		playSprite.setScale(sf::Vector2f(3, 3));
		
		std::cout << "Texture is loaded" << std::endl;
	}
	else
	{
		std::cout << "Texture is not loaded" << std::endl;
	}
	//----------------------LOAD----------------------------
	//----------------------UPDATE----------------------------
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}
	//----------------------UPDATE----------------------------

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playSprite.move(sf::Vector2f(0.1, 0.f));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playSprite.move(sf::Vector2f(0.f, 0.1));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playSprite.move(sf::Vector2f(0.f, -0.1));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playSprite.move(sf::Vector2f(-0.1, 0.f));
		
	//----------------------DRAW----------------------------
		window.clear(sf::Color::Black);
		window.draw(playSprite);
		window.display();
	//----------------------DRAW----------------------------
	}
	return 0;
}