// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include "filehandler.hpp"

// =================================================================================
// =================================================================================
// ===============================Constructor=======================================

fileReader::fileReader( const std::string &filename ):
    filename( filename )
{   
    std::ifstream fileReader(filename);
    fileReader >> fileInfo;
}

// =================================================================================

std::vector<sf::Vector2i> fileReader::makeNodes(){
    std::vector<sf::Vector2i> nodes;
    for ( auto node : fileInfo["PathNodes"] ) {
        nodes.push_back( sf::Vector2i{ node["x"].asInt(), node["y"].asInt() } );
    }
    return nodes;
}

// =================================================================================

std::vector< tower* > fileReader::makeTowers(){
    std::vector< tower* > towers;
    for ( auto towerObject : fileInfo["Towers"] ) {
        towers.push_back( 
            new tower{ 
                towerObject["Name"].asString(),
                towerObject["Damage"].asUInt(),
                towerObject["Range"].asUInt(),
                towerObject["Firerate"].asUInt(),
                towerObject["Texture"].asString(),
                towerObject["Cost"].asUInt()
            } 
        );
    }
    return towers;
}
const Json::Value & fileReader::getEnemyConfig() {
	for (auto& enemy : fileInfo["enemyChar"]) {
		textures[enemy["textureFile"].asString()].loadFromFile(enemy["textureFile"].asString());
	}
	return fileInfo["enemyChar"];
}

const Json::Value& fileReader::getWaves(){
	return fileInfo["waves"];
}

const Json::Value& fileReader::getBaseConfig(){
	textures[fileInfo["base"]["textureFile"].asString()].loadFromFile(fileInfo["base"]["textureFile"].asString());
	return fileInfo["base"];
}

std::map<std::string, sf::Texture>& fileReader::getTextures(){
	return textures;
}

// =================================================================================



// =================================================================================


sf::Vector2i fileReader::getGridSize(){
    sf::Vector2i gridSize{fileInfo["Info"]["GridSize"][0].asInt(), fileInfo["Info"]["GridSize"][1].asInt()};
    if (gridSize == sf::Vector2i{0, 0}) {
        std::cerr << "[Error] GridSize from Path " << filename << " does not excist! Will use default size..." << std::endl;
        return sf::Vector2i{50, 50};
    }
    return gridSize;
}

// =================================================================================

sf::Font* fileReader::getFont() {
    sf::Font *font = new sf::Font;
    if ( !font->loadFromFile( fileInfo["Info"]["TextFont"].asString() ) ) {
        std::cerr << "[Error] Font from Path " << filename << " does not exist! Will use default font..." << std::endl;
        font->loadFromFile( "../res/fonts/Arial.ttf" );
    }
    return font;
}

// =================================================================================

std::vector< sf::RectangleShape* > fileReader::getMenuTextures( std::pair<int, int> switchIndex ) {
    std::vector< sf::RectangleShape* > pictures;

    for ( auto picturePath : fileInfo["Menu"] ) {
        sf::Texture *texture = new sf::Texture;
        texture->loadFromFile( picturePath["Path"].asString() );

        sf::RectangleShape *rect = new sf::RectangleShape;
        rect->setTexture( texture );
        
        pictures.push_back( rect );
    }

    if (switchIndex.first != switchIndex.second) {
        sf::RectangleShape *tmp = pictures[switchIndex.first];
        pictures[switchIndex.first] = pictures[switchIndex.second];
        pictures[switchIndex.second] = tmp;
    }

    return pictures;
}

// =================================================================================

uint32_t fileReader::getMoney() {
    return fileInfo["Info"]["BeginMoney"].asUInt();
}

// =================================================================================
// ===============================Writehandler======================================
// =================================================================================

fileWriter::fileWriter( const std::string &filename ):
    filename( filename )
{}

// =================================================================================

void fileWriter::makeLevelJson( const std::string &name, const std::string &difficulty, const std::vector<sf::Vector2i> &nodes ) {
    Json::Value fileInfo;

    fileInfo["Info"]["Difficulty"] = difficulty;
    fileInfo["Info"]["Name"] = name;

    for ( auto node : nodes ) {
        Json::Value tmpNode;
        tmpNode["x"] = node.x;
        tmpNode["y"] = node.y;
        fileInfo["PathNodes"].append(tmpNode);
    }

    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "    ";

    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outputFileStream(filename);
    writer -> write(fileInfo, &outputFileStream);
}