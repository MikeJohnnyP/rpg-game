#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

sf::Vector2f nomalizedVector(sf::Vector2f vector)
{
	float m = sqrt(vector.x * vector.x + vector.y * vector.y);
	sf::Vector2f thenNomallized;
	thenNomallized.x = vector.x / m;
	thenNomallized.y = vector.y / m;
	return thenNomallized;
}
int main()
{
	//----------------------INITIALIZE----------------------------
	
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game",sf::Style::Close);
	//sf::RectangleShape bullets(sf::Vector2f(50, 25));
	float bulletSpeed = 0.5f;
	//----------------------INITIALIZE----------------------------
	//-------------------------------LOAD----------------------------
	//----------------------Skeleton----------------------------
	
	sf::Texture skeletonTexture;
	sf::Sprite skeletonSprite;
	if (skeletonTexture.loadFromFile("Assets/Player/Texture/spritesheet.png"))
	{
		skeletonSprite.setTexture(skeletonTexture);
		int yIndex = 3;
		int xIndex = 0;

		skeletonSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
		skeletonSprite.setScale(sf::Vector2f(3, 3));
		skeletonSprite.setPosition(sf::Vector2f(1650, 800));

		std::cout << "Skeleton Texture is loaded" << std::endl;
	}
	else
	{
		std::cout << "Skeleton Texture is not loaded" << std::endl;
	}

	//----------------------Skeleton----------------------------
	
	//----------------------Player----------------------------
	
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Texture/spritesheet.png"))
	{
		playerSprite.setTexture(playerTexture);

		int yIndex = 0;
		int xIndex = 0;

		playerSprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64,64,64));
		playerSprite.setScale(sf::Vector2f(3, 3));
		
		std::cout << "Player Texture is loaded" << std::endl;
	}
	else
	{
		std::cout << "Player Texture is not loaded" << std::endl;
	}

	//----------------------Player----------------------------
	
	//----------------------Bullet----------------------------
	//bullets.setPosition(playerSprite.getPosition());
	//sf::Vector2f directions = skeletonSprite.getPosition() - bullets.getPosition();
	//directions = nomalizedVector(directions);
	//----------------------Bullet----------------------------
	//-------------------------------LOAD----------------------------
	
	//----------------------UPDATE----------------------------
	std::vector<sf::RectangleShape> bullets;
	sf::Vector2f direction;
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}

	//----------------------UPDATE----------------------------
	
		//bullets.setPosition(bullets.getPosition() + directions * bulletSpeed);
	//----------------------PlayerMovement----------------------------

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerSprite.move(sf::Vector2f(1, 0.f));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.move(sf::Vector2f(0.f, 1));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.move(sf::Vector2f(0.f, -1));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerSprite.move(sf::Vector2f(-1, 0.f));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
			int i = bullets.size() - 1;
			bullets[i].setPosition(playerSprite.getPosition());
		}
	
	//----------------------PlayerMovement----------------------------
		for (size_t i = 0; i < bullets.size(); i++)
		{
			sf::Vector2f direction = skeletonSprite.getPosition() - bullets[i].getPosition();
			direction = nomalizedVector(direction);
			bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed);

	//--------------------DRAW----------------------------
		}
		window.clear(sf::Color::Black);
		window.draw(skeletonSprite);
		window.draw(playerSprite);
		
		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}
		
		window.display();

	//----------------------DRAW----------------------------
	}
	return 0;
	
}
