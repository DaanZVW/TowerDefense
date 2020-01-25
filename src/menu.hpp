#ifndef MENU_HPP
#define MENU_HPP

#include "tower.hpp"
#include <vector>
#include <string>
#include "filehandler.hpp"

// Tower Info Offsets (TIO)
#define TIO_OFFSET_X			0.02
#define TIO_OFFSET_Y 			0.2
#define TIO_TEXT_DEVIDER		0.05
#define TIO_CHARSIZE_DEVIDER 	0.02

class menuTextObject : public sf::Text{
public:

	menuTextObject(
		const sf::Vector2f &position, 
		const std::string &text,
		const sf::Font *font, 
		int charSize, 
		sf::Color color, 
		sf::Text::Style style 
	);
	
};

// ===============================================================

class towerInfoMenu {
private:

	sf::Vector2f position;
	const sf::Font *font;
	int amount;
	sf::Color color;
	sf::Text::Style style;

	std::vector<menuTextObject*> textObjects;

public:

	towerInfoMenu(
		sf::Vector2f position,  
		const sf::Font *font,
		int amount,
		sf::Color color, 
		sf::Text::Style style
	);

	void draw( sf::RenderWindow &window );
	void updateStrings( const std::vector<std::string> &textInTextObjects );
};

// ===============================================================

class menu : public sf::RectangleShape{
private:
	sf::Vector2f position;
	sf::Vector2f size;
	std::vector<tower*> allTowers;
	int tilesize;
	const sf::Font *font;

	tower* selectedTower = NULL;
	towerInfoMenu infoMenu;

public:

	menu( const sf::Vector2f & position, const sf::Vector2f & size, std::vector<tower*> towers, const float & tilesize, const sf::Font *font );

	void draw( sf::RenderWindow &window );

	std::vector<tower*> getTowers();

	void setSelectedTower( tower* towerPointer );
	tower* getSeletedTower();

};

#endif /*MENU_HPP*/