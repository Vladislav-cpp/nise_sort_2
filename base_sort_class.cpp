#include "base_sort_class.h"



void base_sort_class::draw()
{
	//the number of elements
	//maximum element

//	window.draw();


}


bool base_sort_class::register_fun(void (*sort_fun)(std::vector<int>))
{
	return false;
}

int base_sort_class::update(sf::RenderWindow &window)
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


	return 0;
}
