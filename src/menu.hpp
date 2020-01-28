#ifndef MENU_HPP
#define MENU_HPP

// Include std::Libs
#include <vector>
#include <string>

// Include external libs
#include <SFML/Graphics.hpp>

// Include external files
#include "menuTextObject.hpp"
#include "towerInfoMenu.hpp"
#include "tower.hpp"
#include "button.hpp"
#include "filehandler.hpp"

// Menu top info offsets (MTI)
#define MTI_OFFSET_X			0.05
#define MTI_OFFSET_Y			0.01
#define MTI_CHAR_DEVIDER		0.05
#define MTI_TEXT_SPACING		0.08
#define MTI_SPLIT_LINE_Y		0.17

// Tower buy menu offsets (TBM)
#define TBM_OFFSET_X			0.05
#define TBM_TEXT_SPACING		0.1

// Tower info menu offsets (TIM)
#define TIM_OFFSET_X			0.3
#define TIM_TEXT_SPACING		0.2
#define PICTURE_SIZE_DEVIDER	6
#define TIM_CHARSIZE_DEVIDER	0.1

// Tower Info Offsets (TIO)
#define TIO_OFFSET_X			0.15
#define TIO_OFFSET_Y 			0.2
#define TIO_TEXT_SPACING		0.05
#define TIO_CHARSIZE_DEVIDER 	0.035

// Defines for money multipliers
#define GIVE_BACK_MULTIPLIER	0.80
#define PAY_MULTIPLIER			1.1

// Defines for upgrade stats
#define DAMAGE_MULTIPLIER		1.1
#define RANGE_MULTIPLIER		1.05

// ===============================================================

/// @brief Class between the menu and an collection of text objects
/// @author Daan Zimmerman van Woesik & Nic Jenneboer
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

	std::vector< button* > buttons;
	
	tower* selectedTower = NULL;

	std::vector< menuTextObject* > topInfoText;
	std::vector< sf::RectangleShape* > topInfoIcons;
	sf::RectangleShape splitLine;

	sf::Clock clock;
	uint16_t timePlayed = 0;

public:

	bool showInfoTowerMenu = false;
	bool insufficientMoney = true;
	bool showUpgrades = false;

	/// @brief 					Construct the collection of textObjects with tower objects
	/// 
	/// @param position 		Position where the menu is gonna be made
	/// @param size				Size which the menu is gonna be
	/// @param towers			Vector with tower class pointers with all the different towers in the game
	/// @param tilesize			How big a tile is
	/// @param font				Font whats gonna be used, Note that its a pointer
	/// @param iconsTowerMenu	Icons for the TowerMenu	menu
	/// @param iconsInfoTower	Icons for the InfoTower menu
	///	@param money			Money variable which is used for all the objects
	///
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

	/// @brief 			Draw all the active menu objects
	///
	/// @param window 	The window where the menu has to be drawn on
	/// @return Void
	///	
	void draw( sf::RenderWindow &window );

	/// @brief 	Return the towers			
	///
	/// @return Vector with all the different towers
	///	
	std::vector<tower*> getTowers();

	/// @brief 				Set the selectedTower variable to the pointer which is given			
	///	
	/// @param towerPointer	Tower pointer which selectedTower will be set to
	/// @return Void
	///	
	void setSelectedTower( tower* towerPointer );

	/// @brief 				Set the selectedTower variable to the pointer which is given			
	///	
	/// @param towerPointer	Tower pointer which selectedTower will be set to
	/// @return Void
	///
	tower* getSeletedTower();

	/// @brief 	Get infoTower menu			
	///	
	/// @return Return infoTower menu
	///
	towerInfoMenu getMoveableMenu();

	/// @brief 	Return the current money				
	///
	/// @return Return money
	///
	uint32_t getMoney();

	/// @brief 			Set the selectedTower variable to the pointer which is given			
	///	
	/// @param newValue New value where the money is set to
	/// @return 		Void
	///
	void setMoney( const uint32_t &newValue );

	/// @brief	Get all the buttons on the menu
	///
	/// @return A vector with all the buttons
	///
	std::vector<button*> getButtons();
};

#endif /*MENU_HPP*/