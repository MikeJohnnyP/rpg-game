#include "Math.h"

sf::Vector2f Math::nomalizedVector(sf::Vector2f vector)
{
		float m = sqrt(vector.x * vector.x + vector.y * vector.y);
		sf::Vector2f thenNomallized;
		thenNomallized.x = vector.x / m;
		thenNomallized.y = vector.y / m;
		return thenNomallized;
	
}
