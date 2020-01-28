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
	uint8_t currentWave = 1;

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