#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	//----------------------INITIALIZE----------------------------
	sf::ContextSettings setting;
	setting.antialiasingLevel = 10; //set anti-aliasing
	sf::RenderWindow window(sf::VideoMode(800, 800), "RPG Game",sf::Style::Default,setting);
	sf::CircleShape shape(50.f);
	sf::RectangleShape rec1(sf::Vector2f(100, 100));
	sf::CircleShape polygon(50, 5);

	// shape properties
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(sf::Vector2f(200, 400));
	shape.setOutlineThickness(5.0f);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOrigin(shape.getRadius(), shape.getRadius());

	//rec1 properties
	rec1.setPosition(sf::Vector2f(400, 400));
	rec1.setFillColor(sf::Color::Blue);
	rec1.setOutlineColor(sf::Color::Yellow);
	rec1.setOutlineThickness(5.0f);
//	rec1.setRotation(45);
	rec1.setOrigin(rec1.getSize() / 2.0f);

	//Polygon properties
	polygon.setPosition(600, 400);
	polygon.setFillColor(sf::Color::White);
	polygon.setOrigin(polygon.getRadius(), polygon.getRadius());
	polygon.setOutlineThickness(5.0f);
	polygon.setOutlineColor(sf::Color::Green);

	//----------------------INITIALIZE----------------------------
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

	//----------------------DRAW----------------------------
		window.clear(sf::Color::Black);
		window.draw(shape);
		window.draw(rec1);
		window.draw(polygon);
		window.display();
	//----------------------DRAW----------------------------
	}
	return 0;
}