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

// Standard C++
typedef std::string string;

template <typename T>
using Vector = std::vector<T>;

// note 1
#define CENTRE_ORIGIN setOrigin(Vector2f(this->getGlobalBounds().width/2,this->getGlobalBounds().height/2))