#ifndef TOWER_HPP
#define TOWER_HPP

#include "tilemap.hpp"

class tower : public sf::RectangleShape{
public:
	const std::string name;
	int damage;
	int range;
	int firerate;
	sf::Color mycolor;
	bool showRange = false;
	sf::Clock fireclock;

	void draw( sf::RenderWindow &window);

	int getDamage();

	int getFireRate();

	bool inRange( const sf::Vector2f & pos );

	tower( const std::string & name, const int & damage, const int & range, const int & firerate, const std::string & texture );
	tower( const std::string & name, const int & damage, const int & range, const int & firerate, const sf::Color & color);
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