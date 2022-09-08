#include "window_admin.h"


void window_admin::run()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}





		window.clear();
		//window.draw();
		window.display();
	}
}
