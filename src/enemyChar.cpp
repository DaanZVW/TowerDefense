#include "enemyChar.hpp"

enemyChar::enemyChar(int HP, int DMG, float speed) :HP(HP), DMG(DMG), speed(speed) {
	setSize(sf::Vector2f(32, 32));
	setPosition(sf::Vector2f(128, 180));

	texture.loadFromFile("mario.png");
	setTexture(&texture);
}
const float enemyChar::getSpeed() {
	return speed;
}
const int enemyChar::getDamage() {
	return DMG;
}
const void enemyChar::followPath(float steps, float tileSize) {

}


