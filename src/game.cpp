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

    // Make fileReader for pathnodes
    fileReader fileHandler{ "../res/configfiles/maps/easy.json" };

    // Make tiles
    sf::Color standardColor = sf::Color::Green;
    tilemap map{
        sf::Vector2i{0,0}, 
        sf::Vector2i{ 
            int( window.getSize().x * TILEMAPSIZE ),
            int( window.getSize().y )
        }, 
        fileHandler.getGridSize(), 
        standardColor 
    };
    
    // levelEditor lvlEditor{ map };

    // Make the path
    map.makePath( fileHandler.makeNodes() , sf::Color::Yellow);

    // Make fileReader fot towers
    fileReader fileHandlerTowers{ "../res/configfiles/config.json" };


    // Make enemy character
    enemyChar pietje{ 100, 10, 0.5 };

    menu sideMenu{
        sf::Vector2f{ window.getSize().x * TILEMAPSIZE, 0 },
        sf::Vector2f{ 
            window.getSize().x * (1-TILEMAPSIZE) ,
            window.getSize().y 
        },
        fileHandlerTowers.makeTowers()
    };

    // Do this while the window is open
    while (window.isOpen()) {

        // Clear the window with all excisting objects
		window.clear( sf::Color::Black );

        map.draw( window );

        pietje.followPath( 1 );
        window.draw( pietje );

        window.draw( sideMenu );

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
                        // return;
                    }
                    break;
                
                // Close screen when closed
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if ( event.mouseButton.button == sf::Mouse::Left ) {
                        // lvlEditor.addNode( sf::Mouse::getPosition( window ) );
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