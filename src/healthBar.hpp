#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP
#include <SFML/Graphics.hpp>

/// @brief Class for displaying a healthbar
/// @author Wilco Matthijssen
class healthBar {
private:
	float maxHealth;
	sf::RectangleShape back;
	sf::RectangleShape front;
public:

	/// @brief	Constructor for healthBar
	///
	/// @param	maxHealth	sets maxHealth to calculate percentage of healthbar from
	///
	healthBar(const float& maxHealth);

	/// @brief	sets size of healthbar
	///
	/// @param	size	size to set healthBar
	/// @return void
	///
	void setSize(const sf::Vector2f& size);

	/// @brief	sets position of healthBar
	///
	/// @param	position	position to place healthBar
	/// @return void
	///
	void setPosition(const sf::Vector2f& position);

	/// @brief	sets percentage of healthBar
	///
	/// @param	currentHealth	health to change the healthBar percentage with
	/// @return void
	///
	void setPercentage(const float& currentHealth);

	/// @brief	draws healthBar to sf::Renderwindow
	///
	/// @param	window	sf::RenderWindow to draw healthBar on
	/// @return void
	///
	void draw(sf::RenderWindow& window);
};

#endif // !HEALTHBAR_HPP