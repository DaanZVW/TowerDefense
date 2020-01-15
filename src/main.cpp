// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

// Include std::libs
#include <iostream>
#include <vector>

// Include External libs
#include <json/json.h>
#include <SFML/Graphics.hpp>

// Include External hpp's
#include "filehandler.hpp"
#include "tilemap.hpp"
#include "enemyChar.hpp"
#include "levelEditor.hpp"
#include "tower.hpp"

int main() {
    // Starting message
    std::cout << "Application starting ..." << std::endl;

    // Make SFML window
    sf::RenderWindow window{ sf::VideoMode{1680, 1050}, "SFML window", sf::Style::Fullscreen };

    // Make tiles
    sf::Color standardColor = sf::Color::Green;
    tilemap map{sf::Vector2f{0,0}, sf::Vector2f{1200, 1050}, 30, standardColor };
    
    // levelEditor lvlEditor{ map };

    // Make fileReader for pathnodes
    fileReader maffeHandler{ "../res/configfiles/maps/test.json" };

    // Make the path
    map.makePath( maffeHandler.makeNodes() , sf::Color::Yellow);

    // Make enemy character
    enemyChar pietje{ 100, 10, 0.5 };

    tower henk( map );

    // Do this while the window is open
    while (window.isOpen()) {

        // Clear the window with all excisting objects
		window.clear( sf::Color::Black );

        // sf::Vector2i test = map.getTilePosition( sf::Mouse::getPosition( window ) );
        // std::cout << test.x << " " << test.y << std::endl;

        map.draw( window );

        pietje.followPath( 1 );
        window.draw( pietje );

        henk.placeTower( sf::Mouse::getPosition( window ) );
        window.draw(henk);

        // Draw all excisting objects on the screen
		window.display();

        // Sleep 5 miliseconds so the close event gets time
		sf::sleep( sf::milliseconds( 10 ));

        // SFML events
        sf::Event event;		
	    while( window.pollEvent(event) ){
            switch( event.type ) {

                // Keyboard inputs case
                case sf::Event::KeyPressed:
                    // Close screen when escape is pressed
                    if( event.key.code == sf::Keyboard::Escape ){
                        window.close();
                    } else if ( event.key.code == sf::Keyboard::Enter ) {
                        //lvlEditor.makeLevel( "../res/configfiles/maps/", "test", "Grote gekte" );
                        return 0;
                    }
                    break;
                
                // Close screen when closed
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if ( event.mouseButton.button == sf::Mouse::Left ) {
                        //lvlEditor.addNode( sf::Mouse::getPosition() );
                    } else if ( event.mouseButton.button == sf::Mouse::Right ) {
                        //lvlEditor.popNode();
                    }
                    break;

                 default:
                    break;
            }
		}	
	}

    // Give end message
	std::cout << "Terminating application" << std::endl;

    // Close main
	return 0;
}
