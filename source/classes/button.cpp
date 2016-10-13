#include "button.hpp"
#include "../defaults.hpp"

Button::Button(Font& newFont)
{
	font = &newFont;

	shape.setFillColor(BUTTON_FILL_COLOUR);
	shape.setSize(BUTTON_SIZE);
	centre_origin(shape); // note 1

	text.setString(BUTTON_TEXT);
	text.setCharacterSize(BUTTON_TEXT_SIZE);
	text.setFont(*font);
	centre_origin(text); // note 1
};

void Button::SetPosition(Vector2f pos)
{
	shape.setPosition(pos);
	text.setPosition(pos);
}

void Button::SetString(string newString)
{
	text.setString(newString);
	centre_origin(text);
}

void Button::Draw(Window& window)
{
	window.draw(shape);
	window.draw(text);
}

void Button::Press()
{
	Color c = shape.getFillColor();

	c.r -= c.r*.3;
	c.g -= c.g*.3;
	c.b -= c.b*.3;

	shape.setFillColor(c);
}

void Button::Release()
{
	if (PressPtr == nullptr)
		throw string("Button::" + string(__FUNCTION__) + "()|can't call nullptr function");

	try
	{
		(*PressPtr)(args);
	}
	catch (string e)
	{
		throw string("Button::" + string(__FUNCTION__) + "()<" + e);
	}
	catch (...)
	{
		throw string("Button::" + string(__FUNCTION__) + "()|unhandled error");
	}
}