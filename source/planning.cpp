// this is my skeleton - terrence

#define NET_LOGGING 1
// if (NET_LOGGING) then it uses ncat and printf to log, other wise only printf

#include <vector>
#include <SFML/Graphics.hpp>
#include "structures.hpp"

checkOptions(Vector2f& c, std::vector<Option>& os)
{
  // checks if things are clicked and if so, executes the function pointed to by function
  for (auto& o : os)
  {
    if (o.shape.getGlobalBounds().contains(c))
    {
      *(o.function()); // how do you run a function from a pointer? that or *o.function(?
      break;
    }
  }
}

loadScreen(Screen s)
{
  // switches to another screen?
}

main()
{
  Screen s;
  sf:RenderWindow window;

  while (window.isOpen())
  {
    drawScreen(s);

    sf::Event e;
    while (window.pollEvent(e))
    {
      switch (e.type)
      {
        case sf::Event::MouseButtonPressed:
          checkOptions(s.options);
          break;
      }
    }
  }

}