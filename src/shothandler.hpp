#ifndef SHOTHANDLER_HPP
#define SHOTHANDLER_HPP

// Include external files
#include "tower.hpp"
#include "enemyChar.hpp"

static const float pi = 3.1415926;

/// @brief Class for an bullet
class bullet : public sf::RectangleShape{
private:
	tower * myTower;
	std::weak_ptr<enemyChar>  enemy;
	sf::Clock clock;


public:
	/// @brief Construct an bullet
	///
	/// @param myTower	a pointer to an associated tower.
	/// @param enemy	a weak pointer to an enemyChar as target.
	/// 
	bullet( tower * myTower, std::weak_ptr<enemyChar>  enemy );

	/// @brief For updating the bullet position in the direction to the target enemy.
	///
	/// @return void
	///
	void updatePos();

	/// @brief Get the bullet damage from the associated tower. 
	///
	/// @return void
	///
	int getDamage();

	/// @brief  this function checks if the bullet intersects with the target enemy.
	///
	/// @return bool
	///
	bool intersectsEnemy();

	/// @brief  this function returns the target enemy.
	///
	/// @return std::weak_ptr<enemyChar>&
	///
	std::weak_ptr<enemyChar>& getTarget() { return enemy; }
};

/// @brief Class for handling the shots from towers to enemies.
class shotHandler{
private:
	sf::RenderWindow & window;
	towerGroup & towers;
	enemyCharGroup & enemyGroupObj;
	std::vector < std::unique_ptr<bullet> > bullets;

public:
	/// @brief Construct an shotHandler
	///
	/// @param window			a window for drawing objects.
	/// @param towers			a group of towers.
	/// @param enemyGroupObj	a group of enemies.
	/// 
	shotHandler( sf::RenderWindow & window, towerGroup & towers, enemyCharGroup & enemyGroupObj );

	/// @brief  this function creates bullets from towers to in range enemies and updates the enemies health.
	///
	/// @return void
	///
	void update();


};


#endif /*SHOTHANDLER_HPP*/