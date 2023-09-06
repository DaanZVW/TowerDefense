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
        nodes.push_back( sf::Vector2i{ node["x"].get<int32_t>(), node["y"].get<int32_t>() } );
    }
    return nodes;
}

// =================================================================================

std::vector< tower* > fileReader::makeTowers(){
    std::vector< tower* > towers;
    for ( auto towerObject : fileInfo["Towers"] ) {
		textures[towerObject["textureFile"].get<std::string>()].loadFromFile(towerObject["textureFile"].get<std::string>());
       // sf::Texture *texture = new sf::Texture;
        //texture->loadFromFile(towerObject["textureFile"].asString());
		textures[towerObject["bulletTexture"].get<std::string>()].loadFromFile(towerObject["bulletTexture"].get<std::string>());
        //sf::Texture *bulletTexture = new sf::Texture;
       // bulletTexture->loadFromFile(towerObject["bulletTexture"].asString());
        towers.push_back( 
            new tower{ 
                towerObject["Name"].get<std::string>(),
                towerObject["Damage"].get<uint32_t>(),
                towerObject["Range"].get<uint32_t>(),
                towerObject["Firerate"].get<uint32_t>(),
                &textures[towerObject["textureFile"].get<std::string>()],
                &textures[towerObject["bulletTexture"].get<std::string>()],
                towerObject["Cost"].get<uint32_t>()
            } 
        );
    }
    return towers;
}
const Json & fileReader::getEnemyConfig() {
	for (auto& enemy : fileInfo["enemyChar"]) {
		textures[enemy["textureFile"].get<std::string>()].loadFromFile(enemy["textureFile"].get<std::string>());
	}
	return fileInfo["enemyChar"];
}

const Json& fileReader::getWaves(){
	return fileInfo["waves"];
}

const Json& fileReader::getBaseConfig(){
	textures[fileInfo["base"]["textureFile"].get<std::string>()].loadFromFile(fileInfo["base"]["textureFile"].get<std::string>());
	return fileInfo["base"];
}

std::map<std::string, sf::Texture>& fileReader::getTextures(){
	return textures;
}

// =================================================================================



// =================================================================================


sf::Vector2i fileReader::getGridSize(){
    sf::Vector2i gridSize{fileInfo["Info"]["GridSize"][0].get<int32_t>(), fileInfo["Info"]["GridSize"][1].get<int32_t>()};
    if (gridSize == sf::Vector2i{0, 0}) {
        std::cerr << "[Error] GridSize from Path " << filename << " does not excist! Will use default size..." << std::endl;
        return sf::Vector2i{50, 50};
    }
    return gridSize;
}

// =================================================================================

sf::Font* fileReader::getFont() {
    sf::Font *font = new sf::Font;
    if ( !font->loadFromFile( fileInfo["Info"]["TextFont"].get<std::string>() ) ) {
        std::cerr << "[Error] Font from Path " << filename << " does not exist! Will use default font..." << std::endl;
        font->loadFromFile( "../res/fonts/Arial.ttf" );
    }
    return font;
}

// =================================================================================

std::vector< sf::RectangleShape* > fileReader::getMenuTextures( std::pair<int, int> switchIndex ) {
    std::vector< sf::RectangleShape* > pictures;

    for ( auto picturePath : fileInfo["Menu"] ) {
       // sf::Texture *texture = new sf::Texture;
		textures[picturePath["Path"].get<std::string>()].loadFromFile(picturePath["Path"].get<std::string>());
        //texture->loadFromFile( picturePath["Path"].asString() );

        sf::RectangleShape *rect = new sf::RectangleShape;
        rect->setTexture( &textures[picturePath["Path"].get<std::string>()] );
        
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
    return fileInfo["Info"]["BeginMoney"].get<uint32_t>();
}

// =================================================================================

int fileReader::getAmountRandomObjects() {
    return fileInfo["Info"]["RandomObjects"].get<int32_t>();
}


// =================================================================================
// ===============================Writehandler======================================
// =================================================================================

fileWriter::fileWriter( const std::string &filename ):
    filename( filename )
{}

// =================================================================================

void fileWriter::makeLevelJson( const std::string &name, const std::string &difficulty, const std::vector<sf::Vector2i> &nodes ) {
    // Json fileInfo;

    // fileInfo["Info"]["Difficulty"] = difficulty;
    // fileInfo["Info"]["Name"] = name;

    // for ( auto node : nodes ) {
    //     Json tmpNode;
    //     tmpNode["x"] = node.x;
    //     tmpNode["y"] = node.y;
    //     fileInfo["PathNodes"].append(tmpNode);
    // }

    // Json::StreamWriterBuilder builder;
    // builder["commentStyle"] = "None";
    // builder["indentation"] = "    ";

    // std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    // std::ofstream outputFileStream(filename);
    // writer -> write(fileInfo, &outputFileStream);
}