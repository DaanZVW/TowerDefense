// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>

// Include external libs
#include <SFML/Graphics.hpp>

// Include external files
#include "menuTextObject.hpp"

// Text In Button Offsets (TIB)
#define TIB_OFFSET_X        2.02 
#define TIB_OFFSET_Y        0.15
#define TIB_CHAR_DEVIDER    0.23

/// @brief Class to make a button that can interact with a mouse position
/// @author Daan Zimmerman van Woesik
class button : public sf::RectangleShape {
private:

    sf::Vector2f position;
    sf::Vector2f size;
    menuTextObject textObject;

public:

    /// @brief Constructor for the button class
    /// 
    /// @param position Pixel position which is used for the button
    /// @param size Pixel size which is used for the button
    /// @param text Text which is used on top of the button
    /// @param font Pointer font which is used for the text on top of the button
    /// @param buttonColor Color which is used for the background of the button
    /// @param textColor Color which is used for the text
    /// @param style Style which is used for the text
    ///
    button( 
        const sf::Vector2f &position,
        const sf::Vector2f &size, 
        const std::string &text,
        const sf::Font *font,
        sf::Color buttonColor = sf::Color::Red,
        sf::Color textColor = sf::Color::Black, 
        sf::Text::Style style = sf::Text::Bold  
    );

    /// @brief Function that draws the button
    ///
    /// @param window RenderWindow where the button is gonna be drawn on
    /// @return void
    ///
    void draw( sf::RenderWindow &window );

    /// @brief Function that looks at a vector2i and looks if it contains that point
    ///
    /// @param tPosition Vector Position of the point
    /// @return returns a boolean for if point is in the point
    ///
    bool pointInButton( const sf::Vector2i &tPosition );

    /// @brief Returns the string which is set at the text object
    ///
    /// @return returns the string used in the textObject
    ///
    std::string getString();
};

#endif /*BUTTON_HPP*/