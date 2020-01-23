#ifndef ENEMYCHAR__HPP
#define ENEMYCHAR__HPP

#include <SFML/Graphics.hpp>
#include <vector>
#ifdef INCLUDE
	#include <jsoncpp/json/json.h>
	#define __FUNCTIONNAME__ __func__
#else
	#include <json/json.h>
	#define __FUNCTIONNAME__ __FUNCTION__
#endif // INCLUDE



/* TODO 
-comments fixen


*/

//class healthBar: 


/// @brief Class for an enemy character
/// @author Wilco Matthijssen
class enemyChar : public sf::RectangleShape {
	Json::Value & baseStats;

	std::vector<sf::Vector2f> & route;
	std::vector<sf::Vector2f>::iterator currTargetLocation;

	sf::RectangleShape hp;
	sf::RectangleShape hpBar;
	sf::Clock textureClock;

	bool moving{true};
	float health;

	Json::Value::iterator currAnimation;
	float animationInterval = 20;
	float animationCounter = 0;
public:
	

	/// @brief Construct an enemyChar with json
	///
	/// @param stats	Used for getting stats
	/// @param route	route for enemy to walk
	/// @textures		textures of all enemyChar's
	/// 
	enemyChar(Json::Value & stats, std::vector<sf::Vector2f>& route, std::map<std::string, sf::Texture> & textures);

	/// @brief	Changes texture when interval is reached
	///
	/// @param	steps	increases the counter
	///
	void animate(const float& steps);

	/// @brief	Returns health of enemyChar
	///
	/// @return	const float
	///
	const float getHealth();

	/// @brief	Removes health from enemyChar
	///
	/// @param  
	/// @return	void
	///
	void decreaseHealth(const float & damage);

	/// @brief	Returns speed of enemyChar
	///
	/// @return	const float
	///
	const float getSpeed();

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
	void followPath(float steps);

	/// @brief	draws HP bar on window 
	///
	/// @param  window 
	/// @return	void
	///
	void drawHP(sf::RenderWindow& window);


	
	void enemyCharHit( const int & damage );

};

//class base : public sf::RectangleShape {
//private:
//	int health;
//};


/// @brief Class for an enemy character
/// @author Wilco Matthijssen
class enemyCharGroup {
private:

	//std::shared_ptr<base> target;
	Json::Value enemyTemplates;
	std::vector<sf::Vector2f> & route;
	sf::Texture texture;
	sf::Clock clock;
	float tileSize;
	sf::Clock clockSpawn;
	std::map<std::string, sf::Texture> textures;
	int counter = 0;
	Json::Value waves;
	std::vector< std::unique_ptr< enemyChar > > enemies;
	Json::Value::iterator currWave;
public:


	/// @brief	draws HP bar on window 
	///
	/// @param enemyTemplates Json::Value of enemies config
	/// @param route	route that enemies will walk
	/// @return	void
	///
	enemyCharGroup(Json::Value enemyTemplates, std::vector<sf::Vector2f> & route);

	/// @brief	sets route for enemyChar and converts it to pixels.
	///
	/// @param route route in tiles
	/// @param tilesize size of tiles
	/// @return	void
	///
	void setRoute(const std::vector<sf::Vector2i> & route, const float & tilesize, const sf::Vector2f& offset);

	/// @brief	spawns new enemies based on time passed
	///
	/// @return	void
	///
	void spawnWave();

	/// @brief	draws all enemies on window
	///
	/// @param  window 
	/// @return	void
	///
	void drawAll(sf::RenderWindow& window);
	
	/// @brief	deletes all enemies where health is 0 or lower.
	///
	/// @return	void
	///
	void deleteKilled();
	
	/// @brief	moves all enemies based on speed and time passed
	///
	/// @return	void
	///
	void move();
	
	/// @brief	draws HP bar on window for all enemies 
	///
	/// @param  window 
	/// @return	void
	///
	void drawHP(sf::RenderWindow& window);
	
	/// @brief	updates textures of enemies WIP
	///
	/// @return	void
	///
	void updateTextures();
	
	/// @brief	sets the waves of enemies the class will spawn
	///
	/// @param  enemyWaves waves of enemies 
	/// @return	void
	///
	void setWaves(const Json::Value enemyWaves);
	
	/// @brief	makes next wave availlable to spawn
	///
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
	
	/// @brief	returns amount of enemies
	///
	/// @param  window 
	/// @return	size_t
	///
	size_t size();

	/// @brief	applies damage on enemy and kills it if less hp than damage
	///
	/// @param  index	index of enemy to take damage
	/// @param	damage	damage for enemy to take
	/// @return	void
	///
	void damageEnemy(const size_t& index, const float & damage);


	/// @brief	returns all enemies by reference
	///
	/// @return	std::vector<std::unique_ptr<enemyChar>>
	///
	std::vector<std::unique_ptr<enemyChar>> & getEnemies();






// // random
// float stuff(sf::Vector2f one, sf::Vector2f two) {
// 	//range
// 	float result = pow(abs(one.x - two.x),2 )+ pow(abs(one.y - two.y),2);
// 	return sqrt(result);
// }

// float otherStuff(sf::Vector2f one, sf::Vector2f two) {
// 	//angle
// 	float dot =  one.y * two.y;   	
// 	float det =  one.x * two.x;
// 	return atan2(dot, det) * 180 / 3.14159265359;
// }

};
#endif // ENEMYCHAR__HPP