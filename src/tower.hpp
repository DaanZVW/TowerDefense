#ifndef TOWER_HPP
#define TOWER_HPP

// Include external files
#include "tilemap.hpp"

/// @brief Class for a tower
class tower : public sf::RectangleShape{
public:
	const std::string name;
	double damage;
	double range;
	double firerate;
	sf::Color mycolor;
	unsigned int value;

	unsigned int upgrade = 1;
	unsigned int totalValue;
	
	bool selected = false;
	
	sf::Clock fireclock;

	/// @brief Construct an tower with texture.
	///
	/// @param name		The name of the tower
	/// @param damage   The damage that an tower can give to an enemy.
	/// @param range    The range in tiles from the tower midpoint position.
	/// @param firerate	The number of shots in one minut. 
	/// @param texture  The texture of the tower.
	/// @param value    The price for this tower.
    /// 
	tower( 
		const std::string & name, 
		const unsigned int & damage, 
		const unsigned int & range, 
		const unsigned int & firerate, 
		const std::string & texture,
		const unsigned int &value
	);

	/// @brief Construct an tower with color.
	///
	/// @param name		The name of the tower
	/// @param damage   The damage that an tower can give to an enemy.
	/// @param range    The range in tiles from the tower midpoint position.
	/// @param firerate	The number of shots in one minut. 
	/// @param texture  The color of the tower.
	/// @param value    The price for this tower.
	tower( 
		const std::string & name, 
		const unsigned int & damage, 
		const unsigned int & range, 
		const unsigned int & firerate, 
		const sf::Color & color,
		const unsigned int &value
	);

	/// @brief draw this tower to window.
	///
	/// @param	window 	The renderwindow.
	///
	/// @return void
	///
	void draw( sf::RenderWindow &window);

	/// @brief Get the tower damage variable.
	///
	/// @return int
	///
	int getDamage();

	/// @brief Get the firerate variable.
	///
	/// @return int
	///
	int getFireRate();

	/// @brief returns if an position is inside the range of the tower.
	///
	/// @param	pos 	An given screen position.
	///
	/// @return bool
	///
	bool inRange( const sf::Vector2f & pos );
};

/// @brief Class for a towerGroup
class towerGroup{
private:

	tower* tmpTower;

public:

	std::vector< tower* > towers;
	bool showTmpTower = false;

	/// @brief Construct an towerGroup.
	towerGroup();

	/// @brief makes an temporary tower.
	///
	/// @param newTower 	newTower to save in tmpTower variable.
	///
	/// @return void
	///
	void add( tower* &newTower );

	/// @brief add pointer to an new copy of tmptower to the vector towers.
	///
	///
	/// @return void
	///
	void addTmpTower();

	/// @brief removes the saved tmpTower.
	///
	///
	/// @return void
	///
	void clearTmpTower();

	/// @brief Checks if an tower is placed on an given tile.
	///
	/// @param checkTile	An grid tile.
	///
	/// @return bool
	///
	bool isTower( tile* &checkTile );

	/// @brief get an tower pointer from towers with an given tile.
	///
	/// @param checkTower	An grid tile.
	///
	/// @return tower*
	///
	tower* getTower( tile* &checkTower );

	/// @brief draws all the towers on the given renderwindow.
	///
	/// @param window	.The renderwindow
	///
	/// @return void
	///
	void draw( sf::RenderWindow &window );
};





#endif /*TOWER_HPP*/