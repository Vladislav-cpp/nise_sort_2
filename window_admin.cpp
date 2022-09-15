#include "window_admin.h"
#include <windows.h>
#include <iostream>


window_admin::window_admin() :window(sf::VideoMode(800, 800), "Zheka LOH"), vector_of_values(30, 5)
, button_sound(button_sound_Buffer), sorting_sound(sorting_sound_Buffer)
{
	Tbackground.loadFromFile("images/background/background.png");
	Sprite_Tbackground.setTexture(Tbackground);
	Sprite_Tbackground.setTextureRect(sf::IntRect(0, 0, 800,800));
	Sprite_Tbackground.setPosition(0, 0);

	Tbutton_number_sort.loadFromFile("images/buttons/m_merged (45).png");
	STbutton_number_sort.setTexture(Tbutton_number_sort);
	STbutton_number_sort.setScale(sf::Vector2f(0.25f, 0.25f));

	Tbutton_settings.loadFromFile("images/buttons/m_merged (55).png");
	STbutton_settings.setTexture(Tbutton_settings);
	STbutton_settings.setScale(sf::Vector2f(0.1f, 0.1f));

	button_sound_Buffer.loadFromFile("sound and music/alarm-clock-button-click_z17d0vno.ogg");
	sorting_sound_Buffer.loadFromFile("sound and music/ekstrennyiy-avariynyiy-uskoryayuschiysya-signal_K8YXbSgB.ogg");
}




int window_admin::sort_selection_window()
{
	int Wheel_delta = 0;
	bool sort_selection_window_is_open = true; 
	while (sort_selection_window_is_open)
	{																							
		Wheel_delta += window_check();			// window_check returns wheel movement now, assigning that as an increment to Wheel_delta 
		if (Wheel_delta > 0)					// checking boundaries
			Wheel_delta = 0;					//
		else if (Wheel_delta < -300)			//
			Wheel_delta = -300;					//
		window.draw(Sprite_Tbackground);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i <= 2560; i += 512)
			{
				if (sf::IntRect(100, 100 + i * 0.3 + Wheel_delta, 128, 128).contains(sf::Mouse::getPosition(window)))  //just adding Wheel_delta to y-coordinate 
				{
					//text_ = true;
					sort_selection_window_is_open = false;
					//number_sort = 0;
					return i / 512;
				}
			}
		}

		for (int i = 0; i <= 2560; i += 512)
		{
			STbutton_number_sort.setTextureRect(sf::IntRect(0, 0 + i, 512, 512));
			STbutton_number_sort.setPosition(100, 100 + i * 0.3 + Wheel_delta);				 //just adding Wheel_delta to y-coordinate
			window.draw(STbutton_number_sort);
		}
		window.display();
	}


}

bool window_admin::register_fun(int i, void (*sort_fun)(std::vector<int>& V))
{

	mas_sort_fun.push_back(sort_fun);
	//map_fun.insert(i, sort_fun);

	return true;
}

int window_admin::window_check()
{
	int Switcher = 0;
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == event.MouseWheelScrolled)								// checking if wheel is scrolled
			Switcher = event.mouseWheelScroll.delta * 20;						// assigning delta as an increment to Switcher	
	}

	return Switcher;		// it's a fix for now, advise me something better
}

void window_admin::show(std::vector<int>& elem, indexInfo Info)
{
	std::cout << "-\n";
	window.clear();


	int interval = 0;
	int width = 0;
	int interval_plus_width = 0;
	const int MIN_interval_plus_width = 2;
	const int MAX_interval_plus_width = 20;

	interval_plus_width = 500 / elem.size();//500 - size is allocated to the graph - !!!! make constant !!!

	if (interval_plus_width < MIN_interval_plus_width) { return; }
	if (interval_plus_width > MAX_interval_plus_width) { interval_plus_width = MAX_interval_plus_width; }

	width = interval = interval_plus_width / 2;

	if (Info.sort_end == false)
	{
		for (int i = 0; i < elem.size(); i++)
		{
			int tmp = elem.at(i);

			rectangle.setSize(sf::Vector2f(10, -10 * tmp));
			if (i == Info.swap_index)
				rectangle.setFillColor(sf::Color(100, 100, 200));
			else if (i == Info.inner_pointer_index)
				rectangle.setFillColor(sf::Color(100, 200, 100));
			else if (i == Info.outer_pointer_index)
				rectangle.setFillColor(sf::Color(200, 0, 0));
			else
				rectangle.setFillColor(sf::Color(200, 200, 200));
			rectangle.setPosition(sf::Vector2f(20 + width * i * 3, 600));

			window.draw(rectangle);
			
		}
	}


	if (Info.sort_end == true)
	{

		//window.clear();
		window.display();
		window.clear();
		//window.display();
		for (int i = 0; i < elem.size(); i++)
		{
			int tmp = elem.at(i);

			rectangle.setSize(sf::Vector2f(10, -10 * tmp));
			rectangle.setFillColor(sf::Color(100, 100, 200));
			rectangle.setPosition(sf::Vector2f(20 + width * i * 3, 600));			

			window.draw(rectangle);
			window.display();
			Sleep(15);
			

		}
		Info.sort_end = false;
	}

	window.display();
	
	sorting_sound.play();

	
	Sleep(15);
	//Sleep(100);
}

void window_admin::draw_a_vector()
{
	
	int width = 250 / vector_of_values.size();
	for (int i = 0; i < vector_of_values.size(); i++)
	{
		int tmp = vector_of_values.at(i);

		rectangle.setSize(sf::Vector2f(10, -10 * tmp));
		rectangle.setFillColor(sf::Color(100, 100, 200));
		rectangle.setPosition(sf::Vector2f(20 + width * i * 3, 600));
		window.draw(rectangle);
	}
	
}

void window_admin::vector_setup_window()
{
	active_button_settings active_button = active_button_settings::nothing;//looks terrible//use a template or something else
	bool vector_setup_window_is_open = true;
	
	window.clear();
	window.display();

	while (vector_setup_window_is_open)
	{
		window_check();
		
		window.draw(Sprite_Tbackground);
		draw_a_vector();

		for (int i = 0; i <= 2103; i += 701)
		{
			STbutton_settings.setTextureRect(sf::IntRect(0, 0 + i, 701, 701));
			STbutton_settings.setPosition(100 + i * 0.2 + 60, 100);
			window.draw(STbutton_settings);
		}

		for (int i = 0; i <= 2103; i += 701)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (sf::IntRect(100+ i * 0.2 + 60, 100 , 70.1, 70.1).contains(sf::Mouse::getPosition(window)))
				{			
					active_button = active_button_settings(i / 701);
				}
			}
		}
		

		

		if (active_button != active_button_settings::nothing)
		{
			switch (active_button)
			{
			case active_button_settings::back: //difficult to implement //let's forget it for now
				button_sound.play();
				active_button = active_button_settings::nothing;break;

			case active_button_settings::run:
				button_sound.play();
				vector_setup_window_is_open = false;
				active_button = active_button_settings::nothing;break;

			case active_button_settings::to_mix:
				button_sound.play();
				for (int i = 0; i < vector_size; i++)//add a reboot timer
					vector_of_values.at(i) = rand() % values_in_a_vector + 1;			
				active_button = active_button_settings::nothing;break;

			case active_button_settings::sound_switching:
				button_sound.play();
				active_button = active_button_settings::nothing;break;
				
			}
		}
                 //vector_setup_window_is_open = false;


		window.display();

	}

}

void window_admin::run()
{
	while (window.isOpen())
	{

		int number_sort = sort_selection_window();//login_window();
		vector_setup_window();


		//size_t SIZE = 50;
		//std::vector<int> vc(SIZE);
		//for (int i = 0; i < SIZE; i++)
		//	vc.at(i) = rand() % SIZE + 1;
		mas_sort_fun.at(number_sort)(vector_of_values);



		//sort_selection_window(); //window.draw(Sprite_Tbackground); done +

		//vector_setup_window();

		//vector_sort_window();


	}
}