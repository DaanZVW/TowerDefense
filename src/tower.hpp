#ifndef TOWER_HPP
#define TOWER_HPP

#include "tilemap.hpp"



class tower : public sf::RectangleShape{
public:
	const std::string & name;
	int damage;
	int range;
	int firerate;
	sf::Color mycolor;

	tower( const std::string & name, const int & damage, const int & range, const int & firerate, const std::string & texture );

	tower( const std::string & name, const int & damage, const int & range, const int & firerate, const sf::Color & color);

};

class towerGroup{
private:
	std::vector< tower* > towers;

public:
	towerGroup();

	void add(tower* & newTower );

	void draw( sf::RenderWindow &window );


};





#endif /*TOWER_HPP*/