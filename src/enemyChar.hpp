#ifndef ENEMYCHAR__HPP
#define ENEMYCHAR__HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#ifdef INCLUDE
	#include <jsoncpp/json/json.h>
#else
	#include <json/json.h>
#endif // INCLUDE

#include <vector>

/* TODO 
-comments fixen
- json
- animaties

*/

//class healthBar: 


/// @brief Class for an enemy character
/// @author Wilco Matthijssen
class enemyChar : public sf::RectangleShape {

	float health;
	float maxHealth;
	float baseDamage;
	float speed;
	std::vector<sf::Vector2f> & route;
	std::vector<sf::Vector2f>::iterator currTargetLocation;
	sf::RectangleShape hp;
	sf::RectangleShape hpBar;
	sf::Clock textureClock;
	bool moving{true};

public:
	

	///// @brief Construct an enemyChar with json
	/////
	///// @param Json::Value	Used for getting stats
	///// 
	enemyChar(Json::Value stats, std::vector<sf::Vector2f>& route, sf::Texture& texture);

	/// @brief Construct an enemyChar
	///
	/// @param health	Used for getting size of pieces
	/// 
	enemyChar(float health, float baseDamage, float speed, std::vector<sf::Vector2f>& route, sf::Texture &texture);
	///// @brief Construct an enemyChar
	/////
	///// @param window	Used for getting size of pieces
	///// 
	//enemyChar(sf::Vector2f size, sf::Vector2f position,  std::vector<sf::Vector2f>& route, std::string textureFile, int health, int baseDamage, float speed);

	/// @brief	Returns speed of enemyChar
	///
	/// @return	float 
	///
	const float getSpeed();

	/// @brief	Returns damage of enemyChar
	///
	/// @return	int
	///
	const float getDamage();

	/// @brief	Follows path for n steps 
	///
	/// @param	tileSize  
	/// @param  steps
	/// @return	void
	///
	const void followPath(float steps);

	const bool isDead() {
		return health <= 0;
	}
	void drawHP(sf::RenderWindow& window);
};
class base : public sf::RectangleShape {
private:
	int health;
};

class enemyCharGroup {
private:
	std::vector<std::unique_ptr<enemyChar>> enemies;

	//std::shared_ptr<base> target;
	Json::Value enemyTemplates;
	std::vector<sf::Vector2f> & route;
	sf::Texture texture;
	sf::Clock clock;
	float tileSize;
	sf::Clock clockSpawn;
	
public:
	enemyCharGroup(Json::Value enemyTemplates, std::vector<sf::Vector2f> & route);
	void spawnWave();
	void drawAll(sf::RenderWindow& window);
	void deleteKilled();
	void move();
	void drawHP(sf::RenderWindow& window);
	void updateTextures();
	void setTileSize(float size);
	const bool isEnemyDefeated();
	size_t size();
};

#endif // ENEMYCHAR__HPP