#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef ENEMYCHAR__HPP
#define ENEMYCHAR__HPP

class enemyChar : public sf::RectangleShape {

	int DMG;
	float speed;
	sf::Texture texture;

public:
	int HP;
	enemyChar(int HP, int DMG, float speed);
	const float getSpeed();
	const int getDamage();
	const void followPath(float steps, float tileSize);

};

#endif // ENEMYCHAR__HPP