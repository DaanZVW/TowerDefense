#ifndef MENU_HPP
#define MENU_HPP

#include "tower.hpp"
#include <vector>
#include <string>
#include "filehandler.hpp"

// Menu top info offsets (MTI)
#define MTI_OFFSET_X			0.05
#define MTI_OFFSET_Y			0.01
#define MTI_CHAR_DEVIDER		0.05
#define MTI_TEXT_SPACING		0.08
#define MTI_SPLIT_LINE_Y		0.17

// Tower info menu offsets (TIM)
#define TIM_OFFSET_X			0.3
#define TIM_TEXT_SPACING		0.2
#define PICTURE_SIZE_DEVIDER	6
#define TIM_CHARSIZE_DEVIDER	0.1

// Tower buy menu offsets (TBM)
#define TBM_OFFSET_X			0.05
#define TBM_TEXT_SPACING		0.1

// Tower Info Offsets (TIO)
#define TIO_OFFSET_X			0.15
#define TIO_OFFSET_Y 			0.2
#define TIO_TEXT_SPACING		0.05
#define TIO_CHARSIZE_DEVIDER 	0.035


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

class towerInfoMenu : public sf::RectangleShape {
private:

	sf::Vector2f position;
	sf::Vector2f menuSize;
	const sf::Font *font;
	unsigned int amount;
	const float &tileSize;
	sf::Color color;
	sf::Text::Style style;

	std::vector<menuTextObject*> textObjects;

public:

	towerInfoMenu(
		sf::Vector2f position,
		sf::Vector2f menuSize, 
		const sf::Font *font,
		unsigned int amount,
		std::vector< tower* > &alltowers,
		const float &tileSize,
		sf::Color color, 
		sf::Text::Style style
	);

	towerInfoMenu(
		sf::Vector2f position,
		sf::Vector2f menuSize, 
		const sf::Font *font,
		unsigned int amount,
		std::vector< sf::RectangleShape* > &allpictures,
		const float &tileSize,
		sf::Color color, 
		sf::Text::Style style
	);
	
	void draw( sf::RenderWindow &window );
	void updateStrings( const std::vector<std::string> &textInTextObjects );
	void updateObjectPositions( std::vector< sf::RectangleShape* > &allpictures, const sf::Vector2i &position );
};

// ===============================================================

class menu : public sf::RectangleShape{
private:
	sf::Vector2f position;
	sf::Vector2f size;
	std::vector<tower*> allTowers;
	int tilesize;
	const sf::Font *font;
	std::vector< sf::RectangleShape* > iconsTowerMenu;
	std::vector< sf::RectangleShape* > iconsInfoTower;
	uint32_t &money;
	
	towerInfoMenu towerMenu;
	towerInfoMenu infoMenu;
	towerInfoMenu infoTower;

	tower* selectedTower = NULL;

	std::vector< menuTextObject* > topInfoText;
	std::vector< sf::RectangleShape* > topInfoIcons;
	sf::RectangleShape splitLine;

	sf::Clock clock;
	uint16_t timePlayed = 0;

public:

	bool showInfoTowerMenu = false;

	menu( 
		const sf::Vector2f & position, 
		const sf::Vector2f & size, 
		std::vector<tower*> towers, 
		const float & tilesize, 
		const sf::Font *font,
		std::vector< sf::RectangleShape* > iconsTowerMenu,
		std::vector< sf::RectangleShape* > iconsInfoTower,
		uint32_t &money
	);

	void draw( sf::RenderWindow &window );
	void showInfoTower( sf::RenderWindow &window );

	std::vector<tower*> getTowers();

	void setSelectedTower( tower* towerPointer );
	tower* getSeletedTower();
	towerInfoMenu getMoveableMenu();

	uint32_t getMoney();
	void setMoney( const uint32_t &newValue );

};

#endif /*MENU_HPP*/