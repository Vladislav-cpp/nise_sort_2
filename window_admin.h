#pragma once
#include <SFML/Graphics.hpp>





class window_admin
{
private:

	typedef void (*func)(std::vector<int> v);

	sf::RenderWindow window;

	sf::RectangleShape rectangle;

	std::vector<void(*)(std::vector<int> v)> mas_sort_fun;

	//std::map<int, void(*)(std::vector<int> v)> map_fun;


public:
	window_admin() :window(sf::VideoMode(800, 800), "SFMLworks")
	{


	}

	bool register_fun(int i,void (*sort_fun)(std::vector<int> V));

	void window_check();

	void show(std::vector<int> &elem);

	void run();


};//admin;


