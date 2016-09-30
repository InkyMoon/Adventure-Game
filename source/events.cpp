#include <stdlib.h>
#include <SFML/Graphics.hpp>

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
					printf("left mouse pressed\n");
					break;
				case sf::Mouse::Right:
					printf("right mouse pressed\n");
					break;
				default:
					printf("some other mouse button pressed\n");
			}
			break;
		case sf::Event::MouseMoved:
			printf("mouse button moved\n");
			break;
		case sf::Event::MouseButtonReleased:
			switch (event.mouseButton.button)
			{
				case sf::Mouse::Left:
					printf("left mouse released\n");
					break;
				case sf::Mouse::Right:
					printf("right mouse released\n");
					break;
				default:
					printf("some other mouse button released\n");
			}
			break;
		default:
			printf("unhandled event\n");
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
				printf("touch began\n");
			}
			else
					printf("can't handle more than one finger\n");
			break;
		case sf::Event::TouchMoved:
			if (event.touch.finger == 0)
			{
				printf("finger moved\n");
			}
			else
				printf("can't handle more than one finger\n");
			break;
		case sf::Event::TouchEnded:
			if (event.touch.finger == 0)
			{
				printf("touch ended\n");
			}
			else
				printf("can't handle more than one finger\n");
			break;
		default:
			printf("unhandled event\n");
	}
}
#endif