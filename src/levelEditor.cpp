// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include "levelEditor.hpp"

levelEditor::levelEditor( tilemap &map ):
    map( map )
{}

void levelEditor::writeTileMap() {
    map.clearTilemap();
    map.makePath( nodes, sf::Color::Yellow );
}

void levelEditor::addNode( const sf::Vector2i &position ) {
    nodes.push_back( map.getTilePosition( position ) );
    writeTileMap();
}

void levelEditor::popNode() {
    if (nodes.size() != 0) {
        nodes.pop_back();
    }
    writeTileMap();
}

void levelEditor::makeLevel( const std::string &path, const std::string &name, const std::string &difficulty ) {
    fileWriter writer{ path + name + ".json" };
    writer.makeLevelJson( name, difficulty, nodes );
}   