#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#include <SFML/System.hpp> // for RectangleShape?

struct Option
{
  sf::RectangleShape shape; // the button's position, size, colour...
  sf::Text text; // the text inside the button
  void (*OnClick)(); // is run by Clicked()
  void Clicked(); // called when button is clicked

  Option()
}

struct Screen
{
  sf::Image background;
	/*
	background image:
	- drawn first
	- zoomed to fit the screen
	*/

  sf::RectangleShape scrollbar;
  /*
  the scroll bar
  - drawn after:
  	- the background
  - drawn before:
  	- embedded images
  	- dialog
  - no interactions with finger
  - can be dragged by mouse
 */

  std::vector<sf::Image> images;
  /*
	other images drawn around the screen
	- drawn after:
		- background
		- scroll bar
	- drawn before:
		- text -to make the text readable in the case of positioning errors
	- scaled before being drawn
	- can be scrolled with a scroll bar on the right
  */

  sf::Text text;
  /*
	dialog
	- drawn after the background
	- can contain tags for images such as <image1> which will be replaced with adiquate space for the image mentioned
	- text is broken above and below image tags according to image size
	- can be scrolled with a scroll bar on the right
  */

  std::vector<Option> options;
  /*
	the buttons
	- drawn last
	- drawn in order
	- draw .shape then .text
  */

  Clicked();
  /*
	handles all click or touch events
  */

  Released();
  /*
	handles all "unclick" or "untouch" events
  */

  Moved();
  /*
	handles all "mouse moved" or "finger moved" events only when something is in "drag mode"
  */

  Screen();
}

#endif // STRUCTURES_HPP