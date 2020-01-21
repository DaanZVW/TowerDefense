#include "enemyChar.hpp"
#include <stdlib.h>     /* srand, rand */

#ifdef  WILCO
#define LOG(msg) std::cout<<msg<<std::endl;
#else
#define LOG(msg)
#endif //  WILCO


enemyChar::enemyChar(Json::Value & stats, std::vector<sf::Vector2f>& route, std::map<std::string, sf::Texture> & textures):
	baseStats(stats),
	health(stats["health"].asFloat()),
	route(route),
	textures(textures)
{
	
	setSize(sf::Vector2f(32, 32));
	setPosition(*route.begin());

	setTextureRect(sf::IntRect(20, 320, 170, 320));
	setTexture(&textures[stats["textureFile"].asString()]);
	currTargetLocation = route.begin();
}


const float enemyChar::getSpeed() {
	LOG(__FUNCTIONNAME__ << "\t" << baseStats["speed"].asFloat());
	return baseStats["speed"].asFloat();
}
const float enemyChar::getDamage() {
	LOG(__FUNCTIONNAME__ << "\t" << baseStats["damage"].asFloat());
	return baseStats["damage"].asFloat();
}
void enemyChar::followPath(float  steps) {
	LOG(__FUNCTIONNAME__ << "\t" <<steps);
	if (textureClock.getElapsedTime().asSeconds() > 0.11) {
		textureClock.restart();
		if (moving) {
			setTextureRect(sf::IntRect(170, 320, 300, 320));
			moving = false;
		}
		else {
			setTextureRect(sf::IntRect(20, 320, 170, 320));
			moving = true;
		}
		
	}
	if (route.end() == currTargetLocation) {
		health = 0;
		return; 
	}
	sf::Vector2f currNode =*currTargetLocation;
	steps *= baseStats["speed"].asFloat();
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
		//health -= rand() % 5;
		followPath(steps/ baseStats["speed"].asFloat());

	}
}

void enemyChar::drawHP(sf::RenderWindow& window){
	LOG(__FUNCTIONNAME__);
	if (health >= 0) {
		 
		hpBar.setSize(sf::Vector2f(getSize().x, getSize().y * 0.05));
		hpBar.setPosition(getGlobalBounds().left, getGlobalBounds().top);
		hpBar.setFillColor(sf::Color::Red);
		hpBar.setOutlineThickness(1);
		hpBar.setOutlineColor(sf::Color::Black);
		hp.setSize(sf::Vector2f(getSize().x * (health / baseStats["health"].asFloat()), getSize().y * 0.05));
		hp.setPosition(getGlobalBounds().left, getGlobalBounds().top);
		hp.setFillColor(sf::Color::Green);
		window.draw(hpBar);
		window.draw(hp);
	}
}


void enemyChar::enemyCharHit( const int & damage ){
	health -= damage;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void enemyCharGroup::spawnWave() {
	LOG(__FUNCTIONNAME__);
	if (clockSpawn.getElapsedTime().asSeconds() > 1) {
		clockSpawn.restart();
		for (auto& wave : waves) {
			for (auto& enemy : wave) {
				if (enemy["amount"].asInt() > 0) {
					enemy["amount"] = enemy["amount"].asInt() -1;
					enemies.push_back(std::make_unique<enemyChar>(enemyTemplates[enemy["name"].asString()] ,route, textures));
					(*(enemies.end() - 1)).get()->setSize(sf::Vector2f(tileSize * 0.5, tileSize * 0.5));
					(*(enemies.end() - 1)).get()->setOrigin(sf::Vector2f(tileSize/4, tileSize/4));
					return;
				}
				
			}
		}

	}

};

void enemyCharGroup::drawAll(sf::RenderWindow& window) {
	LOG(__FUNCTIONNAME__);
	for (auto& enemy : enemies) {
		window.draw(*enemy);
		enemy->drawHP(window);
	}
	//drawHP(window);
}

void enemyCharGroup::deleteKilled() {
	LOG(__FUNCTIONNAME__);
	enemies.erase(remove_if(enemies.begin(), enemies.end(), [](auto& obj)
		{
			return obj->health <= 0;
		}), enemies.end());
}
const bool enemyCharGroup::isEnemyDefeated() {
	LOG(__FUNCTIONNAME__);
	return !enemies.size();
}

void enemyCharGroup::move() {
	LOG(__FUNCTIONNAME__);
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
	LOG(__FUNCTIONNAME__);
	std::cout << enemyTemplates["spoderman"]["textureFile"].asString() << std::endl;
	for (auto& enemy : enemyTemplates) {
		textures[enemy["textureFile"].asString()].loadFromFile(enemy["textureFile"].asString());
	}
	spawnWave();

}


void enemyCharGroup::drawHP(sf::RenderWindow& window){
	LOG(__FUNCTIONNAME__);
	for (auto& enemy : enemies) {
		enemy->drawHP(window);
	}
}

void enemyCharGroup::updateTextures(){
	LOG(__FUNCTIONNAME__);
}

void enemyCharGroup::setWaves(const Json::Value enemyWaves){
	LOG(__FUNCTIONNAME__);
	waves = enemyWaves;
}

void enemyCharGroup::setTileSize(float size) {
	LOG(__FUNCTIONNAME__);
	tileSize = size;
}



size_t enemyCharGroup::size() {
	LOG(__FUNCTIONNAME__);
	return enemies.size();
}

void enemyCharGroup::damageEnemy(const size_t& index, const float & damage){
	LOG(__FUNCTIONNAME__);
	if (enemies[index].get()->health > damage) {
		enemies[index].get()->health -= damage;
	}
	else {
		enemies.erase(enemies.begin() + index);
	}
}

std::vector<std::unique_ptr<enemyChar>>& enemyCharGroup::getEnemies(){
	LOG(__FUNCTIONNAME__);
	return enemies;
}


