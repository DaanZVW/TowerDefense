// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include "game.hpp"

game::game( const std::string &configFilePath ):
    configFilePath ( configFilePath ),
	window(
	   sf::VideoMode {
		   sf::VideoMode::getDesktopMode().width,
		   sf::VideoMode::getDesktopMode().height
	   },
	   "Space Defense"
	   ,sf::Style::Fullscreen
	)
{}

// =========================================================

void game::run() {

    // Starting message
    std::cout << "game starting ..." << std::endl;

    // Make SFML window
   

	gameState state = gameState::PLAYING;

	window.setFramerateLimit(100);
    // Make fileReader for pathnodes
    fileReader fileHandlerMap{ "../res/configfiles/maps/easy.json" };

	uint32_t money = fileHandlerMap.getMoney();
	
    sf::Texture * background_image = new sf::Texture;
    background_image->setRepeated(true);
    background_image->loadFromFile("../res/images/background.jpg");

    // Make tiles
    sf::Color standardColor = sf::Color::Transparent;
    tilemap map{
        sf::Vector2i{0,0}, 
        sf::Vector2i{ 
            int( window.getSize().x * TILEMAPSIZE ),
            int( window.getSize().y )
        }, 
        fileHandlerMap.getGridSize(), 
        standardColor,
        background_image
    };
    
    // levelEditor lvlEditor{ map };

    std::vector<sf::Vector2i> createdPath = fileHandlerMap.makeNodes();
	
    std::vector<sf::Vector2f> pathPosition;



    // Make the path
    map.makePath( createdPath , sf::Color{255, 255, 255, 100});

	sf::Texture meteor_image;
    meteor_image.loadFromFile("../res/images/meteorGrey.png");


    map.makeRandomTiles(fileHandlerMap.getAmountRandomObjects(), &meteor_image);

    // Make fileReader fot towers
	
    fileReader fileHandlerConfig{ "../res/configfiles/config.json" };
    sf::Font *font = fileHandlerConfig.getFont();
    
	sf::Texture baseText;
	baseText.loadFromFile("../res/images/wovo_idle.png");
	base baseObj(sf::Vector2f(map.getTileSize(), map.getTileSize()),
			map.getPixelPosition(*(createdPath.end() - 1)),
			fileHandlerConfig.getTextures()[fileHandlerConfig.getBaseConfig()["textureFile"].asString()],
			fileHandlerConfig.getBaseConfig()["health"].asFloat(),
			state
			);
	
	
    // Make enemy character
	enemyCharGroup enemyGroupObj(fileHandlerConfig.getEnemyConfig(),
		createdPath,
		map.getTileSize(),
		map.getPixelPosition(sf::Vector2i(0, 0)),
		fileHandlerConfig.getWaves(),
		money,
		baseObj,
		fileHandlerConfig.getTextures()
	);

    menu sideMenu{
        sf::Vector2f{ float(window.getSize().x * TILEMAPSIZE), 0 },
        sf::Vector2f{ 
            float(window.getSize().x * (1-TILEMAPSIZE)),
            float(window.getSize().y )
        },
        fileHandlerConfig.makeTowers(),
        map.getTileSize(),
        font,
        fileHandlerConfig.getMenuTextures( std::pair<int, int>{4,5} ),
        fileHandlerConfig.getMenuTextures(),
        fileHandlerConfig.getMenuTextures( std::pair<int, int>{4,5} )[5],
        money
    };

    towerGroup groupTower;

    mouseControl mouse{ map, sideMenu, groupTower };

    shotHandler shots{ window, groupTower, enemyGroupObj };

    // Do this while the window is open
    while (window.isOpen()) {

        sf::Vector2i mousePos = sf::Mouse::getPosition( window );

        // Clear the window with all excisting objects
		window.clear( sf::Color::Black );
		sideMenu.currentWave = enemyGroupObj.getWaveNumber();
        // draw tilemap
        map.draw( window );

        // update all enemys position
		enemyGroupObj.update();
        
        // draw all enemys
		enemyGroupObj.draw( window );

        // update mouse
		mouse.updateMouse( mousePos );
		
        // draw the base
		baseObj.draw( window );

        // draw the towers
        groupTower.draw( window );

        // draw the bullets
		shots.update();

        // draw the Menu
        sideMenu.draw( window );

        // Draw all excisting objects on the screen
		window.display();

        // Sleep 5 miliseconds so the close event gets time
		// sf::sleep( sf::milliseconds( 10 ));
        
		if (state == gameState::GAMEOVER) {
			return;
		}

		// SFML events
        sf::Event event;		
	    while( window.pollEvent(event) ){
            switch( event.type ) {

                // Keyboard inputs case
                case sf::Event::KeyPressed:
                    // Close screen when escape is pressed
                    if( event.key.code == sf::Keyboard::Escape ){
                        //window.close();
						return;
                    } else if ( event.key.code == sf::Keyboard::Return ) {
                        // lvlEditor.makeLevel( "../res/configfiles/maps/", "test", "Grote gekte" );
                        // return;
                    }else if ( event.key.code == sf::Keyboard::Space ) {
						
                    }
					else if(event.key.code == sf::Keyboard::X)
					{
						money += 100;
					}
                    break;
                
                // Close screen when closed
                case sf::Event::Closed:
                    window.close();
					return ;
                    

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

void game::intro(){
	sf::Sprite background;
	sf::Texture texture;
	sf::Text introText;
	sf::Font font;
	sf::Clock clock;
	texture.loadFromFile("../res/images/intro.jpg");
	background.setScale(float(sf::VideoMode::getDesktopMode().width) / float(texture.getSize().x), float(sf::VideoMode::getDesktopMode().height) / float(texture.getSize().y));
	background.setTexture(texture);
	if (!font.loadFromFile("../res/fonts/joystick.ttf")) {
		std::cerr << "cant load font\n";
	}
	else {
		introText.setFont(font);
		introText.setString("Press space to continue...");
		introText.setFillColor(sf::Color(255, 255, 255, 200));
		introText.setCharacterSize(20);
		introText.setCharacterSize(20 * ((sf::VideoMode::getDesktopMode().width * 0.60) / introText.getLocalBounds().width));
		introText.setStyle(sf::Text::Regular);
		introText.setOrigin(introText.getLocalBounds().width / 2, introText.getLocalBounds().height / 2);
		introText.setPosition((float(sf::VideoMode::getDesktopMode().width / 2.0)), float(sf::VideoMode::getDesktopMode().height * (4.0 / 5.0)));
	}
	sf::Event event;

	while (true) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				return;
			}
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::Space:
					return;
				case sf::Keyboard::Escape:
					window.close();
					return;
				default:
					break;
				}
			}
		}
		if (clock.getElapsedTime().asSeconds() > 1) {
			clock.restart();
			if (introText.getFillColor() == sf::Color(255, 255, 255, 200)) {
				introText.setFillColor(sf::Color(160, 160, 160, 200));
			}
			else {
				introText.setFillColor(sf::Color(255, 255, 255, 200));
			}
		}
		window.clear();
		window.draw(background);
		window.draw(introText);
		window.display();
	}
}
