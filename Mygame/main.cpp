#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Skeleton.h"


int main()
{
	//----------------------INITIALIZE----------------------------

	sf::RenderWindow window(sf::VideoMode(800, 900), "RPG Game", sf::Style::Close);
	window.setFramerateLimit(60);
	//----------------------INITIALIZE----------------------------
	
	
	Player player;
	player.Initialize();
	player.Load();
	
	//----------------------Player----------------------------

	//----------------------Skeleton----------------------------
	Skeleton skeleton;
	skeleton.Initialize();
	skeleton.Load();
	
	//----------------------Player----------------------------



	//----------------------UPDATE----------------------------
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time deltaTimeTimer = clock.restart();
		float deltaTime = deltaTimeTimer.asMilliseconds();
		std::cout << deltaTime << std::endl;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}
		
	//----------------------UPDATE----------------------------
		player.Update(deltaTime, skeleton);
		skeleton.Update(deltaTime);
	


	//--------------------DRAW----------------------------

		window.clear(sf::Color::Black);
		player.Draw(window);
		skeleton.Draw(window);
		window.display();
}

	//----------------------DRAW----------------------------
	
	return 0;
	
}
