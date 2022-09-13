#include "window_admin.h"
#include <windows.h>
#include <iostream>

extern int global_swap_index;
extern int global_inner_pointer_index;
extern int global_outer_pointer_index;
extern bool global_sort_end;

window_admin::window_admin() :window(sf::VideoMode(800, 800), "Zheka LOH"), vector_of_values(30, 5)
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

}

//remove this horror
int window_admin::login_window()
{
	int number_sort = 0;
	sf::RectangleShape rectangle1;
	rectangle1.setSize(sf::Vector2f(300, 650));
	rectangle1.setFillColor(sf::Color(200, 100, 100));
	rectangle1.setPosition(sf::Vector2f(100, 100));

	sf::RectangleShape rectangle2;
	rectangle2.setSize(sf::Vector2f(50, 50));
	rectangle2.setFillColor(sf::Color(0, 127, 255));
	rectangle2.setPosition(sf::Vector2f(150, 150));

	sf::RectangleShape rectangle3;
	rectangle3.setSize(sf::Vector2f(50, 50));
	rectangle3.setFillColor(sf::Color(0, 127, 255));
	rectangle3.setPosition(sf::Vector2f(150, 250));

	sf::RectangleShape rectangle4;
	rectangle4.setSize(sf::Vector2f(50, 50));
	rectangle4.setFillColor(sf::Color(0, 127, 255));
	rectangle4.setPosition(sf::Vector2f(150, 350));

	sf::RectangleShape rectangle5;
	rectangle5.setSize(sf::Vector2f(50, 50));
	rectangle5.setFillColor(sf::Color(0, 127, 255));
	rectangle5.setPosition(sf::Vector2f(150, 450));

	sf::RectangleShape rectangle6;
	rectangle6.setSize(sf::Vector2f(50, 50));
	rectangle6.setFillColor(sf::Color(0, 127, 255));
	rectangle6.setPosition(sf::Vector2f(150, 550));

	sf::RectangleShape rectangle7;
	rectangle7.setSize(sf::Vector2f(50, 50));
	rectangle7.setFillColor(sf::Color(0, 127, 255));
	rectangle7.setPosition(sf::Vector2f(150, 650));

	sf::Font front;
	front.loadFromFile("type/Mistral.ttf");

	sf::Text text;
	text.setFont(front);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(35);
	text.setString(std::string("you are gay"));
	text.setPosition(250, 250);


	bool login_window_is_open = true;
	bool text_ = false;


	while (login_window_is_open)
	{

		window_check();

		if (sf::IntRect(150, 150, 50, 50).contains(sf::Mouse::getPosition(window))) { rectangle2.setFillColor(sf::Color(255, 126, 0)); }

		if (!(sf::IntRect(150, 150, 50, 50).contains(sf::Mouse::getPosition(window)))) { rectangle2.setFillColor(sf::Color(0, 127, 255)); }

		if (sf::IntRect(150, 250, 50, 50).contains(sf::Mouse::getPosition(window))) { rectangle3.setFillColor(sf::Color(255, 126, 0)); }

		if (!(sf::IntRect(150, 250, 50, 50).contains(sf::Mouse::getPosition(window)))) { rectangle3.setFillColor(sf::Color(0, 127, 255)); }

		if (sf::IntRect(150, 350, 50, 50).contains(sf::Mouse::getPosition(window))) { rectangle4.setFillColor(sf::Color(255, 126, 0)); }

		if (!(sf::IntRect(150, 350, 50, 50).contains(sf::Mouse::getPosition(window)))) { rectangle4.setFillColor(sf::Color(0, 127, 255)); }

		if (sf::IntRect(150, 450, 50, 50).contains(sf::Mouse::getPosition(window))) { rectangle5.setFillColor(sf::Color(255, 126, 0)); }

		if (!(sf::IntRect(150, 450, 50, 50).contains(sf::Mouse::getPosition(window)))) { rectangle5.setFillColor(sf::Color(0, 127, 255)); }

		if (sf::IntRect(150, 550, 50, 50).contains(sf::Mouse::getPosition(window))) { rectangle6.setFillColor(sf::Color(255, 126, 0)); }

		if (!(sf::IntRect(150, 550, 50, 50).contains(sf::Mouse::getPosition(window)))) { rectangle6.setFillColor(sf::Color(0, 127, 255)); }

		if (sf::IntRect(150, 650, 50, 50).contains(sf::Mouse::getPosition(window))) { rectangle7.setFillColor(sf::Color(255, 126, 0)); }

		if (!(sf::IntRect(150, 650, 50, 50).contains(sf::Mouse::getPosition(window)))) { rectangle7.setFillColor(sf::Color(0, 127, 255)); }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (sf::IntRect(150, 150, 50, 50).contains(sf::Mouse::getPosition(window)))
			{
				//text_ = true;
				login_window_is_open = false;
				number_sort = 0;
			}
			if (sf::IntRect(150, 250, 50, 50).contains(sf::Mouse::getPosition(window)))
			{
				//text_ = true;
				login_window_is_open = false;
				number_sort = 1;
			}
			if (sf::IntRect(150, 350, 50, 50).contains(sf::Mouse::getPosition(window)))
			{
				//text_ = true;
				login_window_is_open = false;
				number_sort = 2;
			}
			if (sf::IntRect(150, 450, 50, 50).contains(sf::Mouse::getPosition(window)))
			{
				//text_ = true;
				login_window_is_open = false;
				number_sort = 3;
			}
			if (sf::IntRect(150, 550, 50, 50).contains(sf::Mouse::getPosition(window)))
			{
				//text_ = true;
				login_window_is_open = false;
				number_sort = 4;
			}
			if (sf::IntRect(150, 650, 50, 50).contains(sf::Mouse::getPosition(window)))
			{
				//text_ = true;
				login_window_is_open = false;
				number_sort = 5;
			}
		}



		window.clear();
		window.draw(rectangle1);
		window.draw(rectangle2);
		window.draw(rectangle3);
		window.draw(rectangle4);
		window.draw(rectangle5);
		window.draw(rectangle6);
		window.draw(rectangle7);

		if (text_) window.draw(text);
		window.display();

	}

	return number_sort;
}

int window_admin::sort_selection_window()
{
	bool sort_selection_window_is_open = true;
	while (sort_selection_window_is_open)
	{
		window_check();
		window.draw(Sprite_Tbackground);

		for (int i = 0; i <= 1536; i += 512)
		{
			STbutton_number_sort.setTextureRect(sf::IntRect(0,0+i, 512, 512));		
			STbutton_number_sort.setPosition(100, 100+i*0.3);
			window.draw(STbutton_number_sort);
		}


		for (int i = 0; i <= 1536; i += 512)
		{
		    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		    {
		    	  if (sf::IntRect(100, 100 + i * 0.3, 128, 128).contains(sf::Mouse::getPosition(window)))
		    	  {
		    	  	//text_ = true;
		    	  	sort_selection_window_is_open = false;
		    	  	//number_sort = 0;
					return i / 512;
		    	  }
		    }
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

void window_admin::window_check()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}


}

void window_admin::show(std::vector<int>& elem)
{
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

	if (global_sort_end == false)
	{
		for (int i = 0; i < elem.size(); i++)
		{
			int tmp = elem.at(i);

			rectangle.setSize(sf::Vector2f(10, -10 * tmp));
			if (i == global_swap_index)
				rectangle.setFillColor(sf::Color(100, 100, 200));
			else if (i == global_inner_pointer_index)
				rectangle.setFillColor(sf::Color(100, 200, 100));
			else if (i == global_outer_pointer_index)
				rectangle.setFillColor(sf::Color(200, 0, 0));
			else
				rectangle.setFillColor(sf::Color(200, 200, 200));
			rectangle.setPosition(sf::Vector2f(20 + width * i * 3, 600));
			window.draw(rectangle);
		}
	}


	if (global_sort_end == true)
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
		global_sort_end = false;
	}







	window.display();

	Sleep(15);

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
				active_button = active_button_settings::nothing;break;

			case active_button_settings::run:			
				active_button = active_button_settings::nothing;break;

			case active_button_settings::to_mix:
				for (int i = 0; i < vector_size; i++)//add a reboot timer
					vector_of_values.at(i) = rand() % values_in_a_vector + 1;			
				active_button = active_button_settings::nothing;break;

			case active_button_settings::sound_switching:
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
		//mas_sort_fun.at(number_sort)(vc);



		//sort_selection_window(); //window.draw(Sprite_Tbackground); done +

		//vector_setup_window();

		//vector_sort_window();


	}
}