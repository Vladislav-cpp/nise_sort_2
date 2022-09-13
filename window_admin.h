#pragma once
#include <SFML/Graphics.hpp>



class window_admin
{
private:

	//typedef void (*func)(std::vector<int> v);           //we will not
	//std::map<int, void(*)(std::vector<int> v)> map_fun; //need replacement !!

	sf::RenderWindow window;
	sf::RectangleShape rectangle;
	std::vector<void(*)(std::vector<int>& v)> mas_sort_fun;

	
	std::vector<int> vector_of_values;

	// background;
	sf::Texture Tbackground;
	sf::Sprite Sprite_Tbackground;

	//buttons sort selection 
	sf::Texture Tbutton_number_sort;
	sf::Sprite STbutton_number_sort;

	//button for settings
	sf::Texture Tbutton_settings;
	sf::Sprite STbutton_settings;


	int login_window();// -delete!!!!!!!!

	int sort_selection_window();

	void vector_setup_window();
public:
	window_admin();// 

	bool register_fun(int i, void (*sort_fun)(std::vector<int>& V));

	void window_check();

	void show(std::vector<int>& elem);

	void run();

};



