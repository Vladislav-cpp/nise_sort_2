#include "window_admin.h"
#include <windows.h>
extern int global_swap_index;
extern int global_inner_pointer_index;
extern int global_outer_pointer_index;
extern bool global_sort_end;

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
		window.clear();
		window.display();
		window.clear();
		window.display();
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

void window_admin::run()
{
	while (window.isOpen())
	{

		int number_sort = login_window();
		size_t SIZE = 50;

		std::vector<int> vc(SIZE);
		for (int i = 0; i < SIZE; i++)
			vc.at(i) = rand() % SIZE + 1;
		mas_sort_fun.at(number_sort)(vc);

	}
}