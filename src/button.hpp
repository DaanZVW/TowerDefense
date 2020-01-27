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

class button : public sf::RectangleShape {
private:

    sf::Vector2f position;
    sf::Vector2f size;
    menuTextObject textObject;

public:

    button( 
        const sf::Vector2f &position,
        const sf::Vector2f &size, 
        const std::string &text,
        const sf::Font *font,
        sf::Color buttonColor = sf::Color::Red,
        sf::Color textColor = sf::Color::Black, 
        sf::Text::Style style = sf::Text::Bold  
    );

    void draw( sf::RenderWindow &window );
    bool pointInButton( const sf::Vector2i &tPosition );
};

#endif /*BUTTON_HPP*/