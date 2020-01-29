#ifndef BASE_HPP
#define BASE_HPP
#include <SFML/Graphics.hpp>
#include "healthBar.hpp"
#include <SFML/Audio.hpp>
/// @brief gameStates
/// @author Wilco Matthijssen
enum class  gameState { GAMEOVER, PLAYING };


/// @brief Class for base that enemyChar is meant to destroy and towers are meant to defend
/// @author Wilco Matthijssen
class base : public sf::RectangleShape {
private:
	unsigned int health;
	gameState& state;
	healthBar hpBar;
	sf::Music damagemusic;
public:
	/// @brief	constructs a base
	///
	/// @param	size		size to set base
	/// @param	position	position to set base
	/// @param	texture		texture to set base
	/// @param	health		health to set base
	/// @param	state		state variable to change when damage dealt to base is greater than health
	///
	base(const sf::Vector2f& size, const sf::Vector2f& position, sf::Texture& texture, const unsigned int& health, gameState& state);
	
	/// @brief	decreases health or changes state if damage >= health
	///
	/// @param	damage damage to decrease health with
	/// @return void
	///
	void decreaseHealth(const unsigned int& damage);
	
	/// @brief	draws base to window
	///
	/// @param	window sf::RenderWindow to draw base onto
	/// @return void
	///
	void draw(sf::RenderWindow& window);
};

#endif // !BASE_HPP
