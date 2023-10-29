#include "Bullet.h"
#include "Math.h"

Bullet::Bullet() : speed(0)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize(const sf::Vector2f position, const sf::Vector2f target, float speed)
{
	this->speed = speed;
	rectangleShape.setSize(sf::Vector2f(10, 10));
	rectangleShape.setPosition(position);
	direction = Math::nomalizedVector(target - position);
}

void Bullet::Update(float deltaTime)
{
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * deltaTime * speed);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectangleShape);
}
