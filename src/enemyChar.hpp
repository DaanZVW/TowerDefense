#ifndef ENEMYCHAR__HPP
#define ENEMYCHAR__HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <vector>


/// @brief Class for an enemy character
/// @author Wilco Matthijssen
class enemyChar : public sf::RectangleShape {

	unsigned int health;
	unsigned int baseDamage;
	float speed;
	sf::Texture texture;
	std::vector<sf::Vector2f> moves{ {128,128},{192,128} ,{192,96}, {256,96},{256,64},{478,64} };
	unsigned int moveindex = 0;
	
public:
	

	/// @brief Construct a tic-tac-toe game
	///
	/// @param window	Used for getting size of pieces
	/// 
	enemyChar(Json::Value stats);

	/// @brief Construct a tic-tac-toe game
	///
	/// @param window	Used for getting size of pieces
	/// 
	enemyChar(int health, int baseDamage, float speed);

	/// @brief Construct a tic-tac-toe game
	///
	/// @param window	Used for getting size of pieces
	/// 
	enemyChar(sf::Vector2f size, sf::Vector2f position, std::string textureFile, int health, int baseDamage, float speed);

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

};

class enemyCharGroup {
	void spawnWave();
	bool isEnemyDefeated();
	

};

#endif // ENEMYCHAR__HPP