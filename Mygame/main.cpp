#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Skeleton.h"


int main()
{
	//----------------------INITIALIZE----------------------------

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Close);
	//sf::RectangleShape bullets(sf::Vector2f(50, 25));

	//----------------------INITIALIZE----------------------------

	//----------------------Skeleton----------------------------
	Skeleton skeleton;
	skeleton.Load();
	//----------------------Player----------------------------
	Player player;
	player.Load();
	//----------------------Player----------------------------





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
		player.Update(skeleton);
	


	//--------------------DRAW----------------------------

		window.clear(sf::Color::Black);
		player.Draw(window);
		skeleton.Draw(window);
		window.display();
}

	//----------------------DRAW----------------------------
	
	return 0;
	
}
