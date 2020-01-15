// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include "tilemap.hpp"

tile::tile( const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color ){
    setPosition( position );
    setSize( size );
    setFillColor( color );
    setOutlineColor( sf::Color::Black );
    setOutlineThickness( 1 );

    allowplacement = true;
}

void tile::setAllowPlacement( const bool &value ){
    allowplacement = value;
}

bool tile::getAllowPlacement(){
    return allowplacement;
}


// ======================================================
// ======================================================
// ======================================================


tilemap::tilemap( 
    const sf::Vector2i &position, 
    const sf::Vector2i &size, 
    const sf::Vector2i &gridSize, 
    const sf::Color &color 
):
    position ( position ),
    size ( size ),
    color ( color )
{   
    makeTilemap( gridSize );
}

void tilemap::makeTilemap( const sf::Vector2i &gridSize ) {
    grid.clear();

    sf::Vector2i totalSize{ size - position };

    int XValue = totalSize.x / gridSize.x;
    int YValue = totalSize.y / gridSize.y;
    float tileSize = (XValue > YValue) ? YValue : XValue;

    float XOffset = (totalSize.x - ( tileSize * gridSize.x )) / 2;
    float YOffset = (totalSize.y - ( tileSize * gridSize.y )) / 2;
    
    for ( int x = 0; x < gridSize.x; x++) {
        std::vector<tile*> row;
        for ( int y = 0; y < gridSize.y; y++ ){
            row.push_back( new tile{ 
                sf::Vector2f{(x * tileSize) + XOffset, (y * tileSize) + YOffset },
                sf::Vector2f{tileSize, tileSize},
                color
            });
        }
        grid.push_back( row );
    }
}

// void tilemap::makeTilemap( const int &tmpGridSize ) {
//     grid.clear();

//     sf::Vector2f totalSize = size - position;
//     int maxBlockYSize = totalSize.y / ( totalSize.x / tmpGridSize );
//     sf::Vector2f tilesize{ totalSize.x / tmpGridSize, totalSize.x / tmpGridSize };
//     gridSize = sf::Vector2i{ tmpGridSize, maxBlockYSize };
    
//     for (int x = 0; x < tmpGridSize; x++) {
//         std::vector<tile*> row;
//         for (int y = 0; y < maxBlockYSize; y++) {
//             row.push_back( new tile{ 
//                 sf::Vector2f{ x * (totalSize.x / tmpGridSize), y * (totalSize.x / tmpGridSize) },
//                 tilesize,
//                 color
//             });
//         }
//         grid.push_back( row );    
//     }
// }

void tilemap::draw( sf::RenderWindow &window ) {
    for (auto row : grid){
        for (auto tile : row) {
            window.draw( *tile );
        }
    }
}

bool tilemap::changeTile( const sf::Vector2i &tmpPosition, const sf::Color &color, const bool &allowPlacement ) {
    if ((unsigned int)tmpPosition.x >= grid.size()) {
        return false;
    } else if ((unsigned int)tmpPosition.y >= grid[0].size()) {
        return false;
    }

    grid[tmpPosition.x][tmpPosition.y]->setFillColor( color );
    grid[tmpPosition.x][tmpPosition.y]->setAllowPlacement( allowPlacement );

    return true;
}

void tilemap::makePath( const std::vector<sf::Vector2i> &nodes, const sf::Color &color ) {
    sf::Vector2i currentnode = nodes[0];
    changeTile( currentnode, color, false);

    for ( unsigned int i = 1; i < nodes.size(); i++ ) {
        if ( currentnode.x != nodes[i].x ) {
            int tmp = (currentnode.x > nodes[i].x) ? -1 : 1;

            while (currentnode.x != nodes[i].x) {
                changeTile( currentnode, color, false );
                currentnode.x += tmp;
            }
        }
        if ( currentnode.y != nodes[i].y ) {
            int tmp = (currentnode.y > nodes[i].y) ? -1 : 1;

            while (currentnode.y != nodes[i].y) {
                changeTile( currentnode, color, false );
                currentnode.y += tmp;
            }
            
        }
        changeTile( currentnode, color, false );
    }
}

sf::Vector2i tilemap::getTilePosition( sf::Vector2i tmpPosition ){
    return sf::Vector2i{
        int(tmpPosition.x / (size.x / gridSize.x)),
        int(tmpPosition.y / (gridSize.y * ((size.x - position.x) / gridSize.x) / gridSize.y))
    };
}

void tilemap::clearTilemap() {
    makeTilemap( gridSize );
}