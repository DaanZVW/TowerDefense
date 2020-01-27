#ifndef MENUTEXTOBJECT_HPP
#define MENUTEXTOBJECT_HPP

// Include external libs
#include <SFML/Graphics.hpp>

/// @brief Class for text objects in menu
/// @author Daan Zimmerman van Woesik
class menuTextObject : public sf::Text{
public:

	/// @brief Construct a menuTextObject by nessesary information
	/// 
	/// @param position 	Position where the text object is gonna be put
	/// @param text			Text whats gonna be on the text object
	/// @param font			Font whats gonna be used, Note that its a pointer
	/// @param charSize		Charsize which is gonna be used
	/// @param color		Color that is gonna be used, default value sf::Color::White
	/// @param style		Style which is gonna be used, default value sf::Style::Bold
	///
	menuTextObject(
		const sf::Vector2f &position, 
		const std::string &text,
		const sf::Font *font, 
		int charSize, 
		sf::Color color = sf::Color::White, 
		sf::Text::Style style = sf::Text::Bold
	);
	
};

#endif /*MENUTEXTOBJECT_HPP*/