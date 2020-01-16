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
tilemap::tilemap( const sf::Vector2i &position, const sf::Vector2i &size, const sf::Vector2i &gridSize, const sf::Color &color ):
    position ( position ),
    size ( size ),
    gridSize ( gridSize ),
    color ( color )
{   
    makeTilemap( gridSize );
}

void tilemap::makeTilemap( const sf::Vector2i &gridSize ) {
    grid.clear();

    sf::Vector2i totalSize{ size - position };

    int XValue = totalSize.x / gridSize.x;
    int YValue = totalSize.y / gridSize.y;
    tileSize = (XValue > YValue) ? YValue : XValue;

    XOffset = (totalSize.x - ( tileSize * gridSize.x )) / 2;
    YOffset = (totalSize.y - ( tileSize * gridSize.y )) / 2;
    
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


void tilemap::draw( sf::RenderWindow &window ) {
    sf::RectangleShape background{position};
    background.setSize(size);
    background.setFillColor(sf::Color::Blue);
    window.draw(background);

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
    if ( nodes.size() <= 0 ) {
        return;
    }

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
    sf::Vector2i index{
        int(tmpPosition.x / ((size.x-(2*XOffset)) / gridSize.x) - ( XOffset / tileSize )),
        int(tmpPosition.y / ((size.y-(2*YOffset)) / gridSize.y) - ( YOffset / tileSize ))
    };

    if ( index.x >= gridSize.x || index.x < 0 || index.y >= gridSize.y || index.y < 0 ) {
        return sf::Vector2i{ -1,-1 };
    }
    return index;
}

void tilemap::clearTilemap() {
    makeTilemap( gridSize );
} 

tile* tilemap::getTileFromIndex( sf::Vector2i &tileindex ) {
    return grid[tileindex.x][tileindex.y];
}

float tilemap::getTileSize(){
    return tileSize;
}

sf::Vector2f tilemap::getMapPosition(){
    return position;
}

sf::Vector2f tilemap::getMapSize(){
    return size;
}