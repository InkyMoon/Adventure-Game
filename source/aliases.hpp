#ifndef ALIASES_HPP
#define ALIASES_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <string>

// just because i want to and i think it looks nicer; also avoids using the 'using namespace sf' statement.

// SFML
	typedef sf::RectangleShape RectangleShape;
	typedef sf::RenderWindow Window;
	typedef sf::Color Color;
	typedef sf::Vector2f Vector2f;
	typedef sf::Event Event;
	typedef sf::Font Font;
	typedef sf::Text Text;
	typedef sf::Image Image;

// Standard C++
typedef std::string string;

template <typename T>
using Vector = std::vector<T>;

// note 1
void centre_origin(RectangleShape& o) {	o.setOrigin(o.getGlobalBounds().width/2,o.getGlobalBounds().height/2); }
void centre_origin(Text& o) {	o.setOrigin(o.getGlobalBounds().width/2,o.getGlobalBounds().height/2); }

#endif // ALIASES_HPP