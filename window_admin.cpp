#include "window_admin.h"
#include <windows.h>

void window_admin::window_check()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void window_admin::show(std::vector<int> &elem)
{
window.clear();
//elem.size();



for (int i=0;i< elem.size();i++)
{
	int tmp =elem.at(i);



	rectangle.setSize(sf::Vector2f(10, 10* tmp));
	rectangle.setFillColor(sf::Color(200, 100, 100));
	rectangle.setPosition(sf::Vector2f(50 + i * 20,500));
	window.draw(rectangle);
}
	



	

	
	window.display();
	Sleep(2000);
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
