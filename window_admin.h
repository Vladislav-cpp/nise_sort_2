#pragma once
#include <SFML/Graphics.hpp>
#include "base_sort_class.h"




class window_admin
{
private:
	sf::RenderWindow window;
	base_sort_class& sort;

	window_admin(base_sort_class& sort) :window(sf::VideoMode(500, 500), "SFMLworks"), sort(sort)
	{


	}

public:

	void show(std::vector<int> elem);


	void run();



}admin;


