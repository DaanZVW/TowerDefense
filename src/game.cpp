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
        "Space Defense"
        ,sf::Style::Fullscreen
    };
	
    // Make fileReader for pathnodes
    fileReader fileHandlerMap{ "../res/configfiles/maps/easy.json" };
	
    // Make tiles
    sf::Color standardColor = sf::Color::Green;
    tilemap map{
        sf::Vector2i{0,0}, 
        sf::Vector2i{ 
            int( window.getSize().x * TILEMAPSIZE ),
            int( window.getSize().y )
        }, 
        fileHandlerMap.getGridSize(), 
        standardColor 
    };
    
    // levelEditor lvlEditor{ map };

    std::vector<sf::Vector2i> createdPath = fileHandlerMap.makeNodes();
	
    std::vector<sf::Vector2f> pathPosition;



    // Make the path
    map.makePath( createdPath , sf::Color::Yellow);

    // Make fileReader fot towers
	
    fileReader fileHandlerConfig{ "../res/configfiles/config.json" };
    sf::Font *font = fileHandlerConfig.getFont();
	
	
    // Make enemy character
	enemyCharGroup pietje(fileHandlerConfig.getEnemyConfig(),
		createdPath,
		map.getTileSize(),
		map.getPixelPosition(sf::Vector2i(0, 0)),
		fileHandlerConfig.getWaves()
	);

    menu sideMenu{
        sf::Vector2f{ float(window.getSize().x * TILEMAPSIZE), 0 },
        sf::Vector2f{ 
            float(window.getSize().x * (1-TILEMAPSIZE)),
            float(window.getSize().y )
        },
        fileHandlerConfig.makeTowers(),
        map.getTileSize(),
        font
    };

    towerGroup groupTower;

    mouseControl mouse{ map, sideMenu, groupTower };

    shotHandler shots{ window, groupTower, pietje };

    // Do this while the window is open
    while (window.isOpen()) {

        sf::Vector2i mousePos = sf::Mouse::getPosition( window );

        // Clear the window with all excisting objects
		window.clear( sf::Color::Black );

        map.draw( window );
        
        pietje.drawAll( window );

        pietje.move(); 
		
        sideMenu.draw( window );

        groupTower.draw( window );
	
        shots.update();
        
        mouse.updateMouse( mousePos );

        pietje.deleteKilled();


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
                    }else if ( event.key.code == sf::Keyboard::Space ) {
						pietje.nextWave();
                    }
                    break;
                
                // Close screen when closed
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if ( event.mouseButton.button == sf::Mouse::Left ) {
                        mouse.selectClick( sf::Mouse::getPosition( window ) );
                        // lvlEditor.addNode( sf::Mouse::getPosition( window ) );
                    } else if ( event.mouseButton.button == sf::Mouse::Right ) {
                        mouse.deselectClick();
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