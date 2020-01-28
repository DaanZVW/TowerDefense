#ifndef TOWERINFOMENU_HPP
#define TOWERINFOMENU_HPP

// Include external libs
#include <SFML/Graphics.hpp>

// Include external files
#include "menuTextObject.hpp"
#include "tower.hpp"

// Menu top info offsets (MTI)
#define MTI_OFFSET_X			0.05
#define MTI_OFFSET_Y			0.01
#define MTI_CHAR_DEVIDER		0.05
#define MTI_TEXT_SPACING		0.08
#define MTI_SPLIT_LINE_Y		0.26

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
#define TIO_OFFSET_Y 			0.3
#define TIO_TEXT_SPACING		0.05
#define TIO_CHARSIZE_DEVIDER 	0.035

// Defines for money multipliers
#define GIVE_BACK_MULTIPLIER	0.80
#define PAY_MULTIPLIER			1.1

// Defines for upgrade stats
#define DAMAGE_MULTIPLIER		1.5
#define RANGE_MULTIPLIER		1.05

// ===============================================================

/// @brief Class between the menu and an collection of text objects
/// @author Daan Zimmerman van Woesik
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
	
	/// @brief Construct the collection of textObjects with tower objects
	/// 
	/// @param position 	Position where the objects can be made
	/// @param menuSize		Size where the objects can be made
	/// @param font			Font whats gonna be used, Note that its a pointer
	/// @param amount		How many text objects are gonna be in the collection
	/// @param alltowers	Vector with tower class pointers with all the different towers in the game
	/// @param tileSize		How big a tile is
	/// @param color		Color that is gonna be used, default value sf::Color::White
	/// @param style		Style which is gonna be used, default value sf::Style::Bold	
	///
	towerInfoMenu(
		sf::Vector2f position,
		sf::Vector2f menuSize, 
		const sf::Font *font,
		unsigned int amount,
		std::vector< tower* > &alltowers,
		const float &tileSize,
		sf::Color color = sf::Color::White, 
	    sf::Text::Style style = sf::Text::Bold
	);

	/// @brief Construct the collection of textObjects with pictureObjects
	/// 
	/// @param position 	Position where the objects can be made
	/// @param menuSize		Size where the objects can be made
	/// @param font			Font whats gonna be used, Note that its a pointer
	/// @param amount		How many text objects are gonna be in the collection
	/// @param allpictures	Vector with tower RectangleShape pointers with different textures already set
	/// @param tileSize		How big a tile is
	/// @param color		Color that is gonna be used, default value sf::Color::White
	/// @param style		Style which is gonna be used, default value sf::Style::Bold	
	///
	towerInfoMenu(
		sf::Vector2f position,
		sf::Vector2f menuSize, 
		const sf::Font *font,
		unsigned int amount,
		std::vector< sf::RectangleShape* > &allpictures,
		const float &tileSize,
		sf::Color color = sf::Color::White, 
	    sf::Text::Style style = sf::Text::Bold
	);
	
	/// @brief 		Draws all the different text objects in the collection
	/// @details	The object itself is not drawns
	///
	/// @param window	Window where all the text objects are gonna be drawn on
	/// @return Void
	///
	void draw( sf::RenderWindow &window );

	/// @brief 		Give all the text objects a new string
	///
	/// @param textInTextObjects	Vector with strings which is gonna be put on every text object according to the index
	/// @return Void
	///
	void updateStrings( const std::vector<std::string> &textInTextObjects );

	/// @brief 		Give the index text objects in the collection the given color
	///
	/// @param index	Index in collection
	/// @param color	Color where the index is gonna be changed to
	/// @return Void
	///
	void updateColor( const int &index, const sf::Color &color );

	/// @brief 		Change all the pictures and text objects according to the position
	///
	/// @param textInTextObjects	The rectangles used for the pictures
	/// @param position				Position where all objects are gonna be changed to
	/// @return Void
	///
	void updateObjectPositions( std::vector< sf::RectangleShape* > &allpictures, const sf::Vector2i &position );

	/// @brief 	Get the original color which is given in the constructor
	///
	/// @return	Return the original color 
	///
	sf::Color getOriginalColor();
};

#endif /*TOWERINFOMENU_HPP*/