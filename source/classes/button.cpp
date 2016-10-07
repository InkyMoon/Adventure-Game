#include "button.hpp"
#include "../defaults.hpp"

Button::Button(Font& newFont)
{
	font = &newFont;

	shape.setFillColor(BUTTON_FILL_COLOUR);
	shape.setSize(BUTTON_SIZE);
	shape.CENTRE_ORIGIN; // note 1

	text.setString(BUTTON_TEXT);
	text.setCharacterSize(BUTTON_TEXT_SIZE);
	text.setFont(font);
	text.CENTRE_ORIGIN;
};

void Button::SetPosition(Vector2f pos)
{
	shape.setPosition(pos);
	text.setPosition(pos);
}

void Button::SetString(string newString)
{
	text.setString(newString);
	text.CENTRE_ORIGIN;
}

void Button::Draw(RenderWindow& window)
{
	window.draw(shape);
	window.draw(text);
}

void Button::Clicked()
{
	if (OnClick == nullptr)
		throw string("Button::Clicked()|can't call nullptr function");

	try
	{
		(*OnClick)(args);
	}
	catch (string e)
	{
		throw string("Button::Clicked()<" + e);
	}
	catch (...)
	{
		throw string("Button::Clicked()|unhandled error");
	}
}