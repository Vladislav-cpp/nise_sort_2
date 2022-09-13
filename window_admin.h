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

	//points relating to the vector of values
	std::vector<int> vector_of_values; // ----std::iota()----
	int vector_size = 30;
	int values_in_a_vector = 30;

	// background;
	sf::Texture Tbackground;
	sf::Sprite Sprite_Tbackground;

	//buttons sort selection 
	sf::Texture Tbutton_number_sort;
	sf::Sprite STbutton_number_sort;

	//button for settings
	sf::Texture Tbutton_settings;
	sf::Sprite STbutton_settings;
	
	enum class active_button_settings { nothing=-1, back, run, to_mix, sound_switching};

	int login_window();// -delete!!!!!!!!

	int sort_selection_window();

	void vector_setup_window();

	void draw_a_vector();
public:
	
	window_admin();// 

	bool register_fun(int i, void (*sort_fun)(std::vector<int>& V));

	void window_check();

	void show(std::vector<int>& elem);

	void run();

};



