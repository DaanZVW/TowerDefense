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
	unsigned int value;

	unsigned int upgrade = 1;
	unsigned int totalValue;
	
	bool selected = false;
	
	sf::Clock fireclock;

	tower( 
		const std::string & name, 
		const unsigned int & damage, 
		const unsigned int & range, 
		const unsigned int & firerate, 
		const std::string & texture,
		const unsigned int &value
	);

	tower( 
		const std::string & name, 
		const unsigned int & damage, 
		const unsigned int & range, 
		const unsigned int & firerate, 
		const sf::Color & color,
		const unsigned int &value
	);

	void draw( sf::RenderWindow &window);
	int getDamage();
	int getFireRate();
	bool inRange( const sf::Vector2f & pos );
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

	void draw( sf::RenderWindow &window );
};





#endif /*TOWER_HPP*/