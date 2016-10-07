#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "aliases.hpp"
#include "events.hpp"
#include "debugging.hpp"

// canadian spelling because i can.
#define Colour Color
#define setFillColour setFillColor
#define Rectangle sf::RectangleShape

int main()
{
	string compile_date = __DATE__;
	string compile_time = __TIME__;

	Window window;
		#if defined LINUX || defined WINDOWS
		window.create(sf::VideoMode(800,500), "text game", sf::Style::Default);
		#elif defined ANDROID
		#warning need to figure out video mode that is acceptable for android
		window.create(sf::VideoMode(800,500), "text game", sf::Style::Default);
		#endif

		#ifdef WINDOWS
		window.setVerticalSyncEnabled(false);
		#endif

		window.setFramerateLimit(31); // i like 31, it's not 30.
		window.clear(sf::Colour::Black); // make the hole window black
	log("initialized the window");

	Rectangle rectangle;
		rectangle.setFillColour(sf::Colour::Red);

		// set rectangle size to 1/2 of the screen size
		rectangle.setSize(Vector2f(window.getSize().x / 4,window.getSize().y / 4));

		// when we set position, set the centre of the rectangle to that position; by default it sets the top left corner.
		rectangle.setOrigin(Vector2f(rectangle.getSize().x / 2,rectangle.getSize().y / 2));

		// set position to middle of screen
		rectangle.setPosition(Vector2f(window.getSize().x / 2,window.getSize().y / 2));
	log("initialized the shape");

	Font font;
		font.loadFromFile("../font.ttf");

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				default:
					// platform specific events
					#if defined LINUX || defined WINDOWS
					computerEvents(event);
					#elif defined ANDROID
					androidEvents(event);
					#endif
			}
		}

		window.clear(sf::Colour::Black);
		window.draw(rectangle);
		window.display();
	}

	log("shutting down");
	return 0;
}