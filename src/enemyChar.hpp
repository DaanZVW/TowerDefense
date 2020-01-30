#ifndef ENEMYCHAR__HPP
#define ENEMYCHAR__HPP

// Include std::libs
#include <math.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <memory>

// Include external libs
#ifdef INCLUDE
	#include <json/json.h>
#else
	#include <json/json.h>
#endif // INCLUDE
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Include external files
#include "healthBar.hpp"
#include "macro.hpp"
#include "base.hpp"


/// @brief Class for an enemy character
/// @author Wilco Matthijssen
class enemyChar : public sf::RectangleShape {

	Json::Value& baseStats;
	healthBar hpBar;
	float health;

	Json::Value::iterator currAnimation;
	float animationInterval;
	float animationCounter;


	/// @brief	Follows path for n steps to the left and returns remainder if target is reached
	///
	/// @param  steps	steps enemyChar can move
	/// @param	target	target to move towards
	/// @return	const float 
	///
	const float moveLeftToTarget(float steps, const float target);

	/// @brief	Follows path for n steps to the right and returns remainder if target is reached
	///
	/// @param  steps	steps enemyChar can move
	/// @param	target	target to move towards
	/// @return	const float 
	///
	const float moveRightToTarget(float steps, const float target);

	/// @brief	Follows path for n steps up and returns remainder if target is reached
	///
	/// @param  steps	steps enemyChar can move
	/// @param	target	target to move towards
	/// @return	const float 
	///
	const float moveUpToTarget(float steps, const float target);

	/// @brief	Follows path for n steps down and returns remainder if target is reached
	///
	/// @param  steps	steps enemyChar can move
	/// @param	target	target to move towards
	/// @return	const float 
	///
	const float moveDownToTarget(float steps, const float target);
public:
	std::vector<sf::Vector2f>::iterator currTargetLocation;


	float tileSteps = 0;
	/// @brief Construct an enemyChar with json
	///
	/// @param stats	Used for getting stats
	/// @param route	route for enemy to walk
	/// @param textures	textures of all enemyChar's
	/// @param size		size of enemyChar in pixels
	/// 
	enemyChar(Json::Value& stats, std::vector<sf::Vector2f>& route, std::map<std::string, sf::Texture>& textures, const sf::Vector2f& size);

	/// @brief	Changes texture when interval is reached
	///
	/// @param	steps	increases the counter
	/// @return void
	///
	void animate(const float steps);

	/// @brief	Returns health of enemyChar
	///
	/// @return	const float
	///
	const float getHealth();

	/// @brief	Returns speed of enemyChar
	///
	/// @return	const float
	///
	const float getSpeed();

	/// @brief	Removes health from enemyChar
	///
	/// @param  damage	damage that will be dealt to enemyChar
	/// @return	void
	///
	void decreaseHealth(const float& damage);


	/// @brief	Returns damage of enemyChar
	///
	/// @return	const float
	///
	const float getDamage();




	/// @brief	Follows path for n steps 
	///
	/// @param  steps
	/// @return	void
	///
	void followPath(float& steps);

	/// @brief	draws HP bar on window 
	///
	/// @param  window 
	/// @return	void
	///
	void drawHP(sf::RenderWindow& window);

	/// @brief	Returns reward for killing enemyChar
	///
	/// @return	unsigned int
	///
	unsigned int getReward();
};


/// @brief Class for an enemy character
/// @author Wilco Matthijssen
class enemyCharGroup {
private:

	//std::shared_ptr<base> target;
	Json::Value enemyTemplates;
	std::vector<sf::Vector2f>  route;
	sf::Texture texture;
	sf::Clock clock;
	float tileSize;
	sf::Clock clockSpawn;
	std::map<std::string, sf::Texture> &textures;
	//unsigned int counter = 0;
	Json::Value waves;
	std::vector< std::shared_ptr< enemyChar > > enemies;
	Json::Value::iterator currWave;
	unsigned int &money;
	base& target;
	sf::Music deathmusic;
	sf::Music damagemusic;
	
	/// @brief	spawns new enemies based on time passed
	///
	/// @return	void
	///
	void spawnWave();

	/// @brief	sets route for enemyChar and converts it to pixels.
	///
	/// @param route route in tiles
	/// @param tilesize size of tiles
	/// @return	void
	///
	void setRoute(const std::vector<sf::Vector2i>& route, const float& tilesize, const sf::Vector2f& offset);

	/// @brief	sets the waves of enemies the class will spawn
	/// @details sets current wave as first wave in enemyWaves
	/// @param  enemyWaves waves of enemies 
	/// @return	void
	///
	void setWaves(const Json::Value enemyWaves);
	
	/// @brief	makes next wave availlable to spawn
	/// @details set next wave as current wave if it's not the last wave
	/// @return	void
	///
	void nextWave();

	/// @brief	sets the tile size to scale enemy size from
	///
	/// @param  size	size of tile 
	/// @return	void
	///
	void setTileSize(const float& givenTilesize, const sf::Vector2f& offset);
	
	/// @brief	Returns true is all enemies are dead
	///
	/// @param  window 
	/// @return	void
	///
	const bool isEnemyDefeated();

	/// @brief	Moves enemy for n steps and return false if enemy reached end 
	///
	/// @param  enemy shared_ptr to enemy
	/// @param	steps how many steps does the enemy need to move
	/// @return	bool
	///
	const bool move(std::shared_ptr<enemyChar>& enemy, float steps);
public:

	/// @brief	construct an enemyCharGroup
	/// @details constructs an enemyCharGroup containing enemyChars for how many are defined in param waves.
	///
	/// @param enemyTemplates Json::Value of enemies config
	/// @param route	route that enemies will walk
	///	@param tilesize	size of tile in route
	/// @param offset	top left pixel position of route
	///	@param waves	waves of enemies the class needs to spawn
	///	@param money	increases when an enemyChar dies
	/// @param target	target for enemyChar's
	/// @param textures	map containing all textures
	///
	enemyCharGroup(Json::Value enemyTemplates, 
		const std::vector<sf::Vector2i>& route, 
		const float& tilesize, 
		const sf::Vector2f& offset, 
		Json::Value waves, 
		unsigned int & money,
		base & target,
		std::map<std::string, sf::Texture>& textures);

	/// @brief	draws all enemies on window
	///
	/// @param  window 
	/// @return	void
	///
	void draw(sf::RenderWindow& window);

	/// @brief	moves all enemies based on speed and time passed
	///
	/// @return	void
	///
	void update();


	/// @brief	applies damage on enemy and kills it if less hp than damage
	///
	/// @param  index	index of enemy to take damage
	/// @param	damage	damage for enemy to take
	/// @return	void
	///
	void damageEnemy(std::weak_ptr<enemyChar> & target, const float & damage);

	/// @brief	returns all enemies by reference
	///
	/// @return	std::vector<std::unique_ptr<enemyChar>>
	///
	std::vector<std::shared_ptr<enemyChar>> & getEnemies();


	/// @brief	returns the current wave number
	///
	/// @return	unsigned int
	///
	unsigned int getWaveNumber();
};
#endif // ENEMYCHAR__HPP