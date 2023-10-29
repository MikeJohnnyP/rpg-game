#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "FrameRate.h"
#include "Player.h"
#include "Skeleton.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 1000), "RPG Game", sf::Style::Default);
	//window.setFramerateLimit(60);

	Player player;
	Skeleton skeleton;
	FrameRate frameRate;
	Map map;
	
	//----------------------INITIALIZE----------------------------
	
	player.Initialize();
	skeleton.Initialize();
	frameRate.Initialize();
	map.Initialize();
	
	//----------------------INITIALIZE----------------------------

	//----------------------LOAD----------------------------
	
	player.Load();
	skeleton.Load();
	frameRate.Load();
	map.Load();

	//----------------------LOAD----------------------------
	
	


	//----------------------UPDATE----------------------------
	sf::Clock clock;
	sf::Time deltaTimeTimer;
	double deltaTime = 0;
	while (window.isOpen())
	{
		clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds()/1000.0;
		

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}
		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
	//----------------------UPDATE----------------------------
		map.Update(deltaTime);
		player.Update(deltaTime, skeleton, mousePosition);
		skeleton.Update(deltaTime);
		frameRate.Update(deltaTime);


	//--------------------DRAW----------------------------

		window.clear(sf::Color::Black);
		map.Draw(window);
		player.Draw(window);
		skeleton.Draw(window);
		frameRate.Draw(window);
		window.display();
		deltaTimeTimer = clock.getElapsedTime();
}

	//----------------------DRAW----------------------------
	
	return 0;
	
}
