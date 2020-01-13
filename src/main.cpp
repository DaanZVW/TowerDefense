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

int main() {
    // Starting message
    std::cout << "Factory starting ..." << std::endl;



    // Make SFML window
    sf::RenderWindow window{ sf::VideoMode{ 3000, 2000 }, "SFML window", sf::Style::Fullscreen };
    window.Style
    // Do this while the window is open
    while (window.isOpen()) {

        // Clear the window with all excisting objects
		window.clear( sf::Color::Green );

               

        // Draw all excisting objects on the screen
		window.display();

        // Sleep 5 miliseconds so the close event gets time
		sf::sleep( sf::milliseconds( 5 ));

        // Close SFML window when it gets closed
        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}

    // Give end message
	std::cout << "Terminating application" << std::endl;

    // Close main
	return 0;
}