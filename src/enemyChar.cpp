#include "enemyChar.hpp"
#include <stdlib.h>     /* srand, rand */

enemyChar::enemyChar(Json::Value stats, std::vector<sf::Vector2f>& route, sf::Texture& texture):
	health(stats["health"].asFloat()),
	maxHealth(stats["health"].asFloat()),
	baseDamage(stats["baseDamage"].asFloat()),
	speed(stats["speed"].asFloat()),
	route(route)
{
	setSize(sf::Vector2f(32, 32));// stats["size"][0].asFloat(), stats["size"][1].asFloat()));
	setPosition(*route.begin());
	texturepos = sf::IntRect(20, 320, 170, 320);

	setOrigin(getSize().x/ 2, getSize().y/2);

	setTextureRect(texturepos);
	setTexture(&texture);
	currTargetLocation = route.begin();
}


enemyChar::enemyChar(float health, float baseDamage, float speed, std::vector<sf::Vector2f> & route, sf::Texture &texture)
	:health(health), maxHealth(health), baseDamage(baseDamage), speed(speed), route(route)
{
	setSize(sf::Vector2f(32, 32));
	setPosition(sf::Vector2f{ 10,224 });
	
	setTexture(&texture);
	currTargetLocation = route.begin()+1;
}

//enemyChar::enemyChar(sf::Vector2f size, sf::Vector2f position, std::vector<sf::Vector2f>& route, std::string textureFile="mario.png",int health =10, int baseDamage=10, float speed=10)
//	:health(health), baseDamage(baseDamage), speed(speed), route(route)
//{
//	setSize(size);
//	setPosition(position);
//	texture.loadFromFile(textureFile);
//	setTexture(&texture);
//}

const float enemyChar::getSpeed() {
	return speed;
}
const float enemyChar::getDamage() {
	return baseDamage;
}
const void enemyChar::followPath(float steps) {
	if (textureClock.getElapsedTime().asSeconds() > 0.025) {
		textureClock.restart();
		if (moving) {
			texturepos = sf::IntRect(170, 320, 300, 320);
			setTextureRect(texturepos);
			moving = false;
		}
		else {
			texturepos = sf::IntRect(20, 320, 170, 320);
			setTextureRect(texturepos);
			moving = true;
		}
		
	}
	if (route.end() == currTargetLocation) {
		health = 0;
		return; 
	}
	sf::Vector2f currNode =*currTargetLocation;
	steps *= speed;
	if (getPosition().x > currNode.x) {
		setRotation(180);
		move(-steps , 0);
		if (getPosition().x < currNode.x) {
			steps =currNode.x -getPosition().x;
			setPosition(currNode.x, getPosition().y);
		}
		else {
			steps = 0;
		}
	}
	if (getPosition().x < currNode.x) {
		setRotation(0);
		move(steps, 0);
		if (getPosition().x > currNode.x) {
			steps = getPosition().x - currNode.x;
			setPosition(currNode.x, getPosition().y);
		}
		else {
			steps = 0;
		}
	}
	if (getPosition().y > currNode.y) {
		setRotation(270);
		move(0, -steps);
		if (getPosition().y < currNode.y) {
			steps = currNode.y - getPosition().y;
			setPosition(getPosition().x, currNode.y);
		}
		else {
			steps = 0;
		}
	}
	if (getPosition().y < currNode.y) {
		setRotation(90);
		move(0, steps);
		if (getPosition().y > currNode.y) {
			steps = getPosition().y - currNode.y;
			setPosition(getPosition().x, currNode.y);
		}
		else {
			steps = 0;
		}
	}
	if (steps) {
		++currTargetLocation;
		//rotate(90);
		//health -= rand() % 5;
		followPath(steps/speed);
	}
}

void enemyChar::drawHP(sf::RenderWindow& window)
{
	if (health >= 0) {
		 
		hpBar.setSize(sf::Vector2f(getSize().x, getSize().y * 0.05));
		hpBar.setPosition(getGlobalBounds().left, getGlobalBounds().top);
		hpBar.setFillColor(sf::Color::Red);
		hpBar.setOutlineThickness(1);
		hpBar.setOutlineColor(sf::Color::Black);
		hp.setSize(sf::Vector2f(getSize().x * (health / maxHealth), getSize().y * 0.05));
		hp.setPosition(getGlobalBounds().left, getGlobalBounds().top);
		hp.setFillColor(sf::Color::Green);
		window.draw(hpBar);
		window.draw(hp);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void enemyCharGroup::spawnWave() {
	if (clockSpawn.getElapsedTime().asSeconds() > 1) {
		enemies.push_back(std::make_unique<enemyChar>(enemyTemplates["spoderman"] ,route, texture));
		clockSpawn.restart();
	}
	
	
		

};

void enemyCharGroup::drawAll(sf::RenderWindow& window) {
	for (auto& enemy : enemies) {
		window.draw(*enemy);
		enemy->drawHP(window);
	}
	//drawHP(window);
}

void enemyCharGroup::deleteKilled() {
	enemies.erase(remove_if(enemies.begin(), enemies.end(), [](auto& obj)
		{
			return obj->isDead();
		}), enemies.end());
}
const bool enemyCharGroup::isEnemyDefeated() {
	return !enemies.size();
}

void enemyCharGroup::move() {
	spawnWave();
	sf::Time elapsed= clock.restart();
	for (auto& enemy : enemies) {
		enemy->followPath(elapsed.asSeconds()*tileSize);
	}
}
enemyCharGroup::enemyCharGroup(Json::Value enemyTemplates, std::vector<sf::Vector2f> & route): 
	enemyTemplates(enemyTemplates),
	route( route ) 
{
	texture.loadFromFile("../res/images/PixelArt.png");
	spawnWave();

}


void enemyCharGroup::drawHP(sf::RenderWindow& window)
{
	for (auto& enemy : enemies) {
		enemy->drawHP(window);
	}
}

void enemyCharGroup::updateTextures()
{
}

void enemyCharGroup::setTileSize(float size) {
	tileSize = size;
}


size_t enemyCharGroup::size() {
	return enemies.size();
}