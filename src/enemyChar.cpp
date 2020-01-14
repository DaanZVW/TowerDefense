#include "enemyChar.hpp"

enemyChar::enemyChar(Json::Value stats): 
	health(stats["health"].asInt()),
	baseDamage(stats["baseDamage"].asInt()),
	speed(stats["speed"].asFloat())
{
	setSize(sf::Vector2f(stats["size"][0].asFloat(), stats["size"][1].asFloat()));
	setPosition(sf::Vector2f(stats["position"][0].asFloat(), stats["position"][1].asFloat()));
	texture.loadFromFile(stats["texture"].asString());
	setTexture(&texture);
}

enemyChar::enemyChar(int health, int baseDamage, float speed) 
	:health(health), baseDamage(baseDamage), speed(speed) 
{
	setSize(sf::Vector2f(32, 32));
	setPosition(sf::Vector2f{ 128,224 });
	texture.loadFromFile("mario.png");
	setTexture(&texture);
}

enemyChar::enemyChar(sf::Vector2f size, sf::Vector2f position, std::string textureFile="mario.png",int health =10, int baseDamage=10, float speed=10) 
	:health(health), baseDamage(baseDamage), speed(speed) 
{
	setSize(size);
	setPosition(position);
	texture.loadFromFile(textureFile);
	setTexture(&texture);
}

const float enemyChar::getSpeed() {
	return speed;
}
const int enemyChar::getDamage() {
	return baseDamage;
}
const void enemyChar::followPath(float steps) {
	if (moves.size() <= moveindex) { return; }
	sf::Vector2f currNode=moves[moveindex];
	steps *= speed;
	if (getPosition().x > currNode.x) {
		setPosition(sf::Vector2f{ getPosition().x-steps, getPosition().y });
		steps = 0;
		if (getPosition().x < currNode.x) {
			steps = getPosition().x - currNode.x;
			setPosition(sf::Vector2f{ currNode.x, getPosition().y});
		}
	}
	if (getPosition().x < currNode.x) {
		setPosition(sf::Vector2f{ getPosition().x + steps, getPosition().y });
		steps = 0;
		if (getPosition().x > currNode.x) {
			steps = getPosition().x - currNode.x;
			setPosition(sf::Vector2f{ currNode.x, getPosition().y });
		}
	}

	if (getPosition().y > currNode.y) {
		setPosition(sf::Vector2f{ getPosition().x , getPosition().y- steps });
		steps = 0;
		if (getPosition().y < currNode.y) {
			steps = getPosition().y - currNode.y;
			setPosition(sf::Vector2f{ getPosition().x, currNode.y });
		}
	}
	if (getPosition().y < currNode.y) {
		setPosition(sf::Vector2f{ getPosition().x , getPosition().y+ steps });
		steps = 0;
		if (getPosition().y > currNode.y) {
			steps = getPosition().y - currNode.y;
			setPosition(sf::Vector2f{ getPosition().x, currNode.y });
		}
	}
	if (getPosition() == currNode && steps) {
		++moveindex;
		followPath(steps/speed);
	}

}


