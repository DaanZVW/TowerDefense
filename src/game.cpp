// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include "game.hpp"

game::game( const std::string &configFilePath ):
    configFilePath ( configFilePath )
{}

// =========================================================

void game::run() {

    // Starting message
    std::cout << "Application starting ..." << std::endl;

    // Make SFML window
    sf::RenderWindow window{ 
        sf::VideoMode { 
            sf::VideoMode::getDesktopMode().width, 
            sf::VideoMode::getDesktopMode().height
        },
        "SFML window",
        sf::Style::Fullscreen
    };

    // Make tiles
    sf::Color standardColor = sf::Color::Green;
    tilemap map{
        sf::Vector2f{0,0}, 
        sf::Vector2f{ 
            float( window.getSize().x * MENUSIZE ),
            float( window.getSize().y )
        }, 
        30, 
        standardColor 
    };
    
    // levelEditor lvlEditor{ map };

    // Make fileReader for pathnodes
    fileReader maffeHandler{ "../res/configfiles/maps/test.json" };

    // Make the path
    map.makePath( maffeHandler.makeNodes() , sf::Color::Yellow);

    // Make enemy character
    enemyChar pietje{ 100, 10, 0.5 };

    // Do this while the window is open
    while (window.isOpen()) {

        // Clear the window with all excisting objects
		window.clear( sf::Color::Black );

        // sf::Vector2i test = map.getTilePosition( sf::Mouse::getPosition( window ) );
        // std::cout << test.x << " " << test.y << std::endl;

        map.draw( window );

        pietje.followPath( 1 );
        window.draw( pietje );

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
                    } else if ( event.key.code == sf::Keyboard::Return ) {
                        // lvlEditor.makeLevel( "../res/configfiles/maps/", "test", "Grote gekte" );
                    }
                    break;
                
                // Close screen when closed
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if ( event.mouseButton.button == sf::Mouse::Left ) {
                        // lvlEditor.addNode( sf::Mouse::getPosition() );
                    } else if ( event.mouseButton.button == sf::Mouse::Right ) {
                        // lvlEditor.popNode();
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

}