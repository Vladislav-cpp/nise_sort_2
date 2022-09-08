#include "window_admin.h"


void window_admin::window_check()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void window_admin::show(std::vector<int> elem)
{


	window.clear();
	//window.draw();
	window.display();
}

void window_admin::run()
{
	while (window.isOpen())
	{



		void bubble_sort(std::vector<int> elem);



		////window.clear();
		//////window.draw();
		////window.display();
	}
}
