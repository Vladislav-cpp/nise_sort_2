#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class base_sort_class
{
private:
	void draw();
	//void(*mas_sort_fun[5])();
	std::vector<bool(*)(std::vector<int> v)> mas_sort_fun;
	//sf::RenderWindow &window;





public:
	base_sort_class()
	{


	}
	bool register_fun(void (*sort_fun)(std::vector<int>));
	int update(sf::RenderWindow& window);




};

