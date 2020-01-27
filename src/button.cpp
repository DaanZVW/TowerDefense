// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include "button.hpp"

button::button( 
    const sf::Vector2f &position,
    const sf::Vector2f &size, 
    const std::string &text,
    const sf::Font *font, 
    sf::Color buttonColor,
    sf::Color textColor, 
    sf::Text::Style style
):
    position ( position ),
    size ( size ),
    textObject{ 
        position + sf::Vector2f{ 
            float( size.x * TIB_OFFSET_X + 
                ( (size.x - (size.x * TIB_OFFSET_X)*2) - (text.size() * size.x * TIB_CHAR_DEVIDER) ) / 2.35 ), 
            float( size.y * TIB_OFFSET_Y ) },
        text,
        font,
        int(size.x * TIB_CHAR_DEVIDER),
        textColor,
        style
    }
{
    setPosition( position );
    setSize( size );
    setFillColor( buttonColor );
}

void button::draw( sf::RenderWindow &window ) {
    window.draw( *this );
    window.draw( textObject );
}

bool button::pointInButton( const sf::Vector2i &tPosition ) {
    return getGlobalBounds().contains( sf::Vector2f{tPosition} );
}