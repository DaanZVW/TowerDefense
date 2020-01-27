#ifndef TOWER_HPP
#define TOWER_HPP

#include "tilemap.hpp"

class tower : public sf::RectangleShape{
public:
	const std::string name;
	unsigned int damage;
	unsigned int range;
	unsigned int firerate;
	sf::Color mycolor;
	unsigned int cost;
	bool selected = false;
	sf::Clock fireclock;

	void draw( sf::RenderWindow &window);

	int getDamage();

	int getFireRate();

	bool inRange( const sf::Vector2f & pos );

	tower( 
		const std::string & name, 
		const unsigned int & damage, 
		const unsigned int & range, 
		const unsigned int & firerate, 
		const std::string & texture,
		const unsigned int cost
	);

	tower( 
		const std::string & name, 
		const unsigned int & damage, 
		const unsigned int & range, 
		const unsigned int & firerate, 
		const sf::Color & color,
		const unsigned int cost
	);
};

class towerGroup{
private:

	tower* tmpTower;

public:

	std::vector< tower* > towers;
	bool showTmpTower = false;

	towerGroup();

	void add( tower* &newTower );
	void addTmpTower();
	void clearTmpTower();

	bool towersInRange( const sf::Vector2f & pos );

	bool isTower( tile* &checkTile );

	tower* getTower( tile* &checkTower );

	std::vector< tower* > getTowers();

	void draw( sf::RenderWindow &window );
};





#endif /*TOWER_HPP*/