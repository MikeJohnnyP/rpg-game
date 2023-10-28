#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() : timer(0)
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
	if (fonts.loadFromFile("Assets/Fonts/arial.ttf")) {
		std::cout << "Load Font sucessfully" << std::endl;
		frameText.setFont(fonts);
	}
	else {
		std::cout << "Failed to load font" << std::endl;
	}
}

void FrameRate::Update(float deltaTime)
{
	timer += deltaTime;
	if (timer >= 100.f) {
		std::string frameString = "FPS: " + std::to_string((int)(1000 / deltaTime)) + "    Frame Time: " + std::to_string((int)deltaTime);
		frameText.setString(frameString);
		timer = 0;
	}
}

void FrameRate::Draw(sf::RenderWindow& window)
{
	window.draw(frameText);
}
