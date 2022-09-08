#pragma once
#include <SFML/Graphics.hpp>





class window_admin
{
private:

	sf::RenderWindow window;

	sf::RectangleShape rectangle;

public:
	window_admin() :window(sf::VideoMode(800, 800), "SFMLworks")
	{


	}

	void window_check();

	void show(std::vector<int> &elem);

	void run();


};//admin;


