#ifndef ENEMYCHAR__HPP
#define ENEMYCHAR__HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <json/json.h>
#include <vector>

/* TODO 
-comments fixen
- json
- animaties

*/


/// @brief Class for an enemy character
/// @author Wilco Matthijssen
class enemyChar : public sf::RectangleShape {

	unsigned int baseDamage;
	float speed;
	float health;
	float maxHealth;
	std::vector<sf::Vector2f> & route;
	std::vector<sf::Vector2f>::iterator currTargetLocation;
	bool dead{ false };
	sf::RectangleShape hp;
	sf::RectangleShape hpBar;
	sf::IntRect texturepos;


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
	enemyChar(int health, int baseDamage, float speed, std::vector<sf::Vector2f>& route, sf::Texture &texture);
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
	const int getDamage();

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

	std::shared_ptr<base> target;
	std::vector<sf::Vector2f> & route;// = std::make_shared<std::vector<sf::Vector2f>>((10, 10));
	sf::Texture texture;
	Json::Value enemyTemplates;
public:
	enemyCharGroup(Json::Value enemyTemplates, std::vector<sf::Vector2f> & route);
	void spawnWave();

	void drawAll(sf::RenderWindow& window);

	void deleteKilled();
	const bool isEnemyDefeated();

	void move();
	
	void drawHP(sf::RenderWindow& window);
	void updateTextures();
	size_t size();
};

#endif // ENEMYCHAR__HPP