#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "debugging.hpp"

typedef sf::Event Event;

#if defined LINUX || defined WINDOWS
void computerEvents(Event event)
{
	switch (event.type)
	{
		case sf::Event::MouseButtonPressed:
			switch (event.mouseButton.button)
			{
				case sf::Mouse::Left:
					log("left mouse pressed");
					break;
				case sf::Mouse::Right:
					log("right mouse pressed");
					break;
				default:
					log("some other mouse button pressed");
			}
			break;
		case sf::Event::MouseMoved:
			//log("mouse button moved");
			break;
		case sf::Event::MouseButtonReleased:
			switch (event.mouseButton.button)
			{
				case sf::Mouse::Left:
					log("left mouse released");
					break;
				case sf::Mouse::Right:
					log("right mouse released");
					break;
				default:
					log("some other mouse button released");
			}
			break;
		default:
			log("unhandled event");
	}
}
#elif defined ANDROID
void androidEvents (Event event)
{
	switch (event.type)
	{
		case sf::Event::TouchBegan:
			if (event.touch.finger == 0)
			{
				log("touch began");
			}
			else
					log("can't handle more than one finger");
			break;
		case sf::Event::TouchMoved:
			if (event.touch.finger == 0)
			{
				//log("finger moved");
			}
			else
				log("can't handle more than one finger");
			break;
		case sf::Event::TouchEnded:
			if (event.touch.finger == 0)
			{
				log("touch ended");
			}
			else
				log("can't handle more than one finger");
			break;
		default:
			log("unhandled event");
	}
}
#endif