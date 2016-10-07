#include "menu.hpp"
#include "../defaults.hpp"

Menu::Menu(Vector2f size)
{
	background.create(size.x, size.y, MENU_BACKGROUND_COLOUR);
	background.CENTRE_ORIGIN;
}

void Menu::Draw(RenderWindow& window)
{
	if (!visible)
		return;

	window.draw(background);

	for (auto& button:buttons)
		button.Draw(window);
}

int Menu::Clicked(Vector2f pos)
{
	for (auto& button:buttons)
	{
		if (button.shape.getGlobalBounds().contains(pos))
		{
			try
			{
				button.Clicked();
			}
			catch (string e)
			{
				throw string("Menu::Clicked()<" + e);
			}
			catch (...)
			{
				throw string("Menu::Clicked()|unhandled error");
			}

			return 1; // a button was clicked on
		}
	}

	return 0; // no buttons were clicked on
}