#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void bubble_sort(std::vector<int>& elem);
void quick_sort(std::vector<int>& elem);
void selection_sort(std::vector<int>& elem);
void insertion_sort(std::vector<int>& elem);
void merge_sort(std::vector<int>& elem);
void heap_sort(std::vector<int>& elem);

struct indexInfo
{
	int swap_index = 0;
	int inner_pointer_index = 0;
	int outer_pointer_index = 0;
	bool sort_end = false;
};

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

	//music and sounds
	sf::SoundBuffer button_sound_Buffer;//-	
	sf::Sound button_sound;//-

	sf::SoundBuffer sorting_sound_Buffer;//-	
	sf::Sound sorting_sound;//-


	enum class active_button_settings { nothing=-1, back, run, to_mix, sound_switching};

	int login_window();// -delete!!!!!!!!

	int sort_selection_window();

	void vector_setup_window();

	void draw_a_vector();
public:
	
	window_admin();// 

	bool register_fun(int i, void (*sort_fun)(std::vector<int>& V));

	int window_check();

	void show(std::vector<int>& elem, indexInfo Info);

	void run();

};



