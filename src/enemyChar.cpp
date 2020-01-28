#include "enemyChar.hpp"

//==========================================================================

enemyChar::enemyChar(Json::Value & stats, std::vector<sf::Vector2f>& route, std::map<std::string, sf::Texture> & textures, const sf::Vector2f & size):
	baseStats(stats),
	hpBar(stats["health"].asFloat()),
	health(stats["health"].asFloat()),
	currAnimation(stats["texturepos"].begin()),
	animationInterval(size.x/4),
	animationCounter(size.x/4)
{
	LOGFUNCNAME();
	setPosition(*route.begin());
	setSize(size);
	hpBar.setSize(sf::Vector2f(getLocalBounds().height , getLocalBounds().width* 0.1));
	setTexture(&textures[stats["textureFile"].asString()]);
	currTargetLocation = route.begin();
}

void enemyChar::animate(const float steps){
	LOGFUNCNAME(<< steps);
	animationCounter += steps;
	if (animationCounter > animationInterval) {
		if (currAnimation == baseStats["texturepos"].end()) {
			if (baseStats["texturepos"].end() == baseStats["texturepos"].begin()) {
				return;
			}
			currAnimation = baseStats["texturepos"].begin();
		}
		setTextureRect(sf::IntRect((*currAnimation)["positionX"].asInt(),
				(*currAnimation)["positionY"].asInt(),
				(*currAnimation)["sizeX"].asInt(),
				(*currAnimation)["sizeY"].asInt()));
				++currAnimation;
				animationCounter = 0;
				
	}
}

//==========================================================================

const float enemyChar::getHealth(){
	LOGFUNCNAME();
	return health;
}

//==========================================================================

const float enemyChar::getSpeed()
{
	return baseStats["speed"].asFloat();
}

//==========================================================================

void enemyChar::decreaseHealth(const float& damage){
	LOGFUNCNAME(<<damage);
	health -= abs(damage);
}

//==========================================================================

const float enemyChar::getDamage() {	
	LOGFUNCNAME(<< baseStats["damage"].asFloat());
	return baseStats["damage"].asFloat();
}

//==========================================================================

const float enemyChar::moveLeftToTarget(float steps, const float target) {
	setRotation(270);
	move(-steps, 0);
	if (getPosition().x < target) {
		setPosition(target, getPosition().y);
		return target - getPosition().x;
	}
	return 0;
}

//==========================================================================

const float enemyChar::moveRightToTarget(float steps, const float target) {
	setRotation(90);
	move(steps, 0);
	if (getPosition().x > target) {
		setPosition(target, getPosition().y);
		return target - getPosition().x;
	}
	return 0;
}

//==========================================================================

const float enemyChar::moveUpToTarget(float steps, const float target) {
	setRotation(0);
	move(0, -steps);
	if (getPosition().y < target) {
		setPosition(getPosition().x, target);
		return target - getPosition().y;
	}
	return 0;
}

//==========================================================================

const float enemyChar::moveDownToTarget(float steps, const float target) {
	setRotation(180);
	move(0, steps);
	if (getPosition().y > target) {
		setPosition(getPosition().x, target);
		return target - getPosition().y;
	}
	return 0;
}

//==========================================================================

void enemyChar::followPath(float& steps) {
	sf::Vector2f currNode = *currTargetLocation;
	if (getPosition().x > currNode.x) {
		steps = moveLeftToTarget(steps, currNode.x);
	}
	if (getPosition().x < currNode.x) {
		steps = moveRightToTarget(steps, currNode.x);
	}
	if (getPosition().y > currNode.y) {
		steps = moveUpToTarget(steps, currNode.y);
	}
	if (getPosition().y < currNode.y) {
		steps = moveDownToTarget(steps, currNode.y);
	}
}

//==========================================================================

void enemyChar::drawHP(sf::RenderWindow& window){
	LOGFUNCNAME();
	if (health >= 0) {
		hpBar.setPosition(sf::Vector2f(getGlobalBounds().left, getGlobalBounds().top));
		hpBar.setPercentage(health);
		hpBar.draw(window);
	}

}

//==========================================================================

unsigned int enemyChar::getReward() {
	return baseStats["reward"].asUInt();
}

//==========================================================================
//==========================================================================
//==========================================================================

void enemyCharGroup::spawnWave() {
	LOGFUNCNAME();
	if (clockSpawn.getElapsedTime().asSeconds() > 1) {
		clockSpawn.restart();
		if (currWave != waves.end()){
			for (auto& enemy : *currWave) {
				if (enemy["amount"].asInt() > 0) {
					enemy["amount"] = enemy["amount"].asInt() -1;
					enemies.push_back(std::make_shared<enemyChar>(enemyTemplates[enemy["name"].asString()] ,route, textures, sf::Vector2f(tileSize / 2, tileSize / 2)));
					(*(enemies.end() - 1)).get()->setOrigin(sf::Vector2f(tileSize/4, tileSize/4));
					return;
				}
			}
			if (isEnemyDefeated()) {
				nextWave();
			}
		}
	}
};

//==========================================================================

void enemyCharGroup::setWaves(const Json::Value enemyWaves){
	LOGFUNCNAME();
	waves = enemyWaves;
	currWave = waves.begin();
}

//==========================================================================

void enemyCharGroup::nextWave() {
	LOGFUNCNAME();
	if (currWave != waves.end()) {
		++currWave;
	}
	
}

//==========================================================================

void enemyCharGroup::setTileSize(const float & givenTilesize, const sf::Vector2f& offset){
	LOGFUNCNAME(<< givenTilesize);
	for (auto& pos : route) {
		pos=(sf::Vector2f((pos.x / tileSize) * givenTilesize +offset.x, (pos.y / tileSize)*givenTilesize+offset.y));
	}
	tileSize = givenTilesize;
}

//==========================================================================

void enemyCharGroup::setRoute(const std::vector<sf::Vector2i>& givenRoute, const float& givenTilesize, const sf::Vector2f & offset) {
	LOGFUNCNAME(<< givenTilesize);
	route.clear();
	tileSize = givenTilesize;
	for (auto& pos : givenRoute) {
		route.push_back(sf::Vector2f((pos.x * tileSize)+offset.x + (tileSize/2),( pos.y * tileSize)+offset.y + (tileSize / 2)));
	}
}

//==========================================================================

void enemyCharGroup::draw(sf::RenderWindow& window) {
	LOGFUNCNAME();
	for (auto& enemy : enemies) {
		window.draw(*enemy);
		enemy->drawHP(window);
	}
}

//==========================================================================

const bool enemyCharGroup::isEnemyDefeated() {
	LOGFUNCNAME();
	return enemies.begin() == enemies.end();
}

//==========================================================================

void enemyCharGroup::update() {
	LOGFUNCNAME();
	float steps= clock.restart().asSeconds() * tileSize;
	spawnWave();
	
	enemies.erase(remove_if(enemies.begin(), enemies.end(), [&](auto & obj)
		{
			if (!enemyCharGroup::move(obj, steps)) {
				target.decreaseHealth(obj->getDamage());
				return true;
			}
			return false;
		}
	), enemies.end());
}

//==========================================================================

enemyCharGroup::enemyCharGroup (
	Json::Value enemyTemplates, 
	const std::vector<sf::Vector2i>& route, 
	const float& tilesize, 
	const sf::Vector2f& offset, 
	Json::Value waves, 
	unsigned int & money,
	base &target,
	std::map<std::string, sf::Texture>& textures
):
	enemyTemplates(enemyTemplates),
	textures(textures),
	money(money),
	target(target)
{
	LOGFUNCNAME();
	setRoute(route, tilesize, offset);
	setWaves(waves);

	damagemusic.openFromFile("../res/sound/headshot2.wav");
	damagemusic.setVolume( 20 );
	damagemusic.setPitch( 40 );
	deathmusic.openFromFile("../res/sound/Spider_death.ogg");
}

//==========================================================================

void enemyCharGroup::damageEnemy(std::weak_ptr<enemyChar>& target, const float & damage){
	LOGFUNCNAME();
	if (auto t = target.lock()) {
		if (damage >= t->getHealth()) {
			money += t->getReward();

			damagemusic.stop();
			damagemusic.play();
			deathmusic.stop();
			deathmusic.play();
			
			for (size_t i = 0; i < enemies.size(); ++i) {
				if (enemies[i] == t) {
					enemies.erase(enemies.begin() +i);
					break;
				}
			}
		}
		else {
			damagemusic.stop();
			damagemusic.play();
			t->decreaseHealth(damage);
		}
	}
}

//==========================================================================

std::vector<std::shared_ptr<enemyChar>>& enemyCharGroup::getEnemies(){
	LOGFUNCNAME();
	return enemies;
}

//==========================================================================

const bool enemyCharGroup::move(std::shared_ptr<enemyChar> & enemy, float steps) {
	LOGFUNCNAME(<<steps);
	
	steps *= enemy->getSpeed();
	enemy->animate(steps);
	while (steps) {
		if (enemy->currTargetLocation == route.end()) {
			return false;
		}
		enemy->followPath( steps );

		if (enemy->getPosition() == *(enemy->currTargetLocation)) {
			++enemy->currTargetLocation;
		}
		
	}
	return true;	
}

