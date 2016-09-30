#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SFML/Graphics.hpp>

#if defined LINUX || defined WINDOWS
void computerEvents(sf::Event event);
#elif defined ANDROID
void androidEvents(sf::Event event);
#endif

#endif // EVENTS_HPP