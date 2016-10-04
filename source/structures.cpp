#include "structures.hpp"

Option::Option()
{
  OnClick = nullptr;
}

void Option::Clicked()
{
  if (OnClick != nullptr)
    (*OnClick)();
}


Screen::Screen(sf::Vector2f screenSize)
{
  int scrollBarPadding = 2; // the number of pixels between the scroll bar and the edge of the screen
  sf::Vector2f scrollBarSize(10,50); // the size, in pixels, of the scroll bar (x,y)
  sf::Color scrollBarColor(100,100,100,100); // the colour of the scroll bar (r,g,b,alpha) i think

  background.setPosition(sf::Vector2f(0,0));
  background.setOrigin(sf::Vector2f(screenSize.x/2,screenSize.y/2));
  background.setSize(screenSize);

  scrollBar.setSize(scrollBarSize);
  scrollBar.setPosition(sf::Vector2f(screenSize.x - scrollBar.getSize().x - scrollBarPadding, scrollBarPadding))
  scrollBar.setFillColor(scrollBarColor);


}
