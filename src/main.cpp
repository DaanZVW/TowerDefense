// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

// Include std::libs
#include <fstream>
#include <iostream>
#include <vector>

// Include External libs
#include <jsoncpp/json/json.h>
#include <SFML/Graphics.hpp>

// Include External hpp's
// #include "path.hpp"
#include "tilemap.hpp"



int main() {
    // Starting message
    std::cout << "Factory starting ..." << std::endl;

    // std::vector<sf::Vector2i> v = { sf::Vector2i{3,3}, sf::Vector2i{10,3}, sf::Vector2i{10, 25}, sf::Vector2i{5, 25} };
    // path pathmaker { v };

    tilemap mafklapper{sf::Vector2f{0,0}, sf::Vector2f{1920, 1080}, sf::Vector2i{0,0}, sf::Color::Green };

    // Make SFML window
    sf::RenderWindow window{ sf::VideoMode{1920, 1080}, "SFML window", sf::Style::Fullscreen };

    // Do this while the window is open
    while (window.isOpen()) {

        // Clear the window with all excisting objects
		window.clear( sf::Color::Black );

        // sf::RectangleShape jon{sf::Vector2f{40,40}};
        // jon.setPosition( sf::Vector2f{40,40});

        // window.draw( jon );

        mafklapper.draw( window );

        // Draw all excisting objects on the screen
		window.display();

        // Sleep 5 miliseconds so the close event gets time
		sf::sleep( sf::milliseconds( 10 ));

        // Close SFML window when it gets closed
        sf::Event event;		
	    while( window.pollEvent(event) ){
            if( event.type == sf::Event::KeyPressed ){
                // Close window
                if( event.key.code == sf::Keyboard::Escape ){
                    window.close();
                }
            }
            // Close window when cross right top of the window is pressed
            if( event.type == sf::Event::Closed ) {
                window.close();
            }
		}	
	}

    // Give end message
	std::cout << "Terminating application" << std::endl;

    // Close main
	return 0;
}