#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include "../aliases.hpp"
#include "buttons.hpp"

struct Menu
{
	Image background;
	Vector<Button> buttons;
	bool visible = false;

	Menu(Vector2f size);
	void Draw(RenderWindow& window);
	void Clicked(Vector2f pos);
};

#endif // MENU_HPP