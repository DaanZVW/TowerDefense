#include "healthBar.hpp"
#include "macro.hpp"
#include <iostream>
healthBar::healthBar(const float& maxHealth) :
	maxHealth(maxHealth)
{
	LOGFUNCNAME();
	back.setOutlineColor(sf::Color::Black);
	back.setOutlineThickness(1);
	back.setFillColor(sf::Color::Red);
	front.setFillColor(sf::Color::Green);
}

void healthBar::setSize(const sf::Vector2f& size) {
	LOGFUNCNAME(<<size.x<<'\t'<<size.y);
	back.setSize(sf::Vector2f(size.x - 2, size.y - 2));
	front.setSize(sf::Vector2f((size.x - 2), size.y - 2));
}

void healthBar::setPosition(const sf::Vector2f& position) {
	LOGFUNCNAME(<< position.x << '\t' << position.y);
	back.setPosition(position.x + 1, position.y + 1);
	front.setPosition(position.x + 1, position.y + 1);
}
void healthBar::setPercentage(const float& currentHealth) {
	LOGFUNCNAME(<<currentHealth);
	const float percentage = currentHealth / maxHealth;
	front.setSize(sf::Vector2f((back.getSize().x) * percentage, back.getSize().y));
}
void healthBar::draw(sf::RenderWindow& window) {
	LOGFUNCNAME();
	window.draw(back);
	window.draw(front);
}

