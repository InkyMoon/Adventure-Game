#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <vector>
#include <SFML/System.hpp>
#include "../aliases.hpp"

struct Button
{
	RectangleShape shape;
	Font* font = nullptr;
	Text text;
	void (*OnClick)(Vector<void*> args) = nullptr;
	Vector<void*> args;

	Button(Font& newFont);
	void SetPosition(Vector2f pos); // sets the position of the shape and the text.
	void SetString(string newString); // sets the string and corrects it's position.
	void Draw(Window& window); // draws the shape and it's text in that order.
	void Clicked(); // calls the function in OnClick with args as the arguments.
};

#endif // BUTTON_HPP