// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include "tilemap.hpp"

tile::tile( const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color ):
    position ( position ),
    size ( size ),
    color ( color )
{
    setPosition( position );
    setSize( size );
    setFillColor( color );
    setOutlineColor( sf::Color::Black );
    setOutlineThickness( 1 );
}

tilemap::tilemap( const sf::Vector2f &position, const sf::Vector2f &size, const sf::Vector2i &gridSize, const sf::Color &color ):
    position ( position ),
    size ( size ),
    gridSize ( gridSize ),
    color ( color )
{   
    int amountGrid = 20;
    sf::Vector2f totalSize = size - position;
    int maxBlockYSize = totalSize.y / ( totalSize.x / amountGrid );
    sf::Vector2f tilesize{ totalSize.x / amountGrid, totalSize.x / amountGrid };
    
    for (int x = 0; x < amountGrid; x++) {
        std::vector<tile*> row;
        for (int y = 0; y < maxBlockYSize; y++) {
            row.push_back( new tile{ 
                sf::Vector2f{ x*(totalSize.x / amountGrid), y*(totalSize.x / amountGrid) },
                tilesize,
                color
            });
            std::cout << "janka" << std::endl;
        }
        grid.push_back( row );    
    }
}


void tilemap::draw( sf::RenderWindow &window ) {
    std::cout << grid.size() << std::endl;
    // std::cout << "jonkoline" << std::endl;
    for (auto row : grid){
        for (auto tile : row) {
            window.draw( *tile );
            // std::cout << "jonko" << std::endl;
        }
    }
}