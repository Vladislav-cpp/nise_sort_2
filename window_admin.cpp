#include "window_admin.h"
#include <windows.h>

bool window_admin::register_fun(int i, void (*sort_fun)(std::vector<int> V))
{

	mas_sort_fun.push_back(sort_fun);
	//map_fun.insert(i, sort_fun);

	return true;
}

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

int interval = 0;
int width = 0;
int interval_plus_width = 0;
const int MIN_interval_plus_width = 2;
const int MAX_interval_plus_width = 20;

interval_plus_width = 460/elem.size() ;//460 - size is allocated to the graph - !!!! make constant !!!

if (interval_plus_width < MIN_interval_plus_width) { return ; }
if (interval_plus_width > MAX_interval_plus_width) { interval_plus_width = MAX_interval_plus_width; }

width = interval = interval_plus_width / 2;

for (int i=0;i< elem.size();i++)
{
	int tmp =elem.at(i);



	rectangle.setSize(sf::Vector2f(10, -10* tmp));
	rectangle.setFillColor(sf::Color(200, 100, 100));
	rectangle.setPosition(sf::Vector2f(20 + width * i*2,500));
	window.draw(rectangle);
}
	



	

	
	window.display();
	Sleep(2000);
}

void window_admin::run()
{
	while (window.isOpen())
	{



		//void bubble_sort(std::vector<int> elem);



		////window.clear();
		//////window.draw();
		////window.display();
	}
}
