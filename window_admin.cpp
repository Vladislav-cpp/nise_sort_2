#include "window_admin.h"
#include <windows.h>

int window_admin::login_window()
{
	int number_sort = 0;
	sf::RectangleShape rectangle1;
	rectangle1.setSize(sf::Vector2f(300, 300));
	rectangle1.setFillColor(sf::Color(200, 100, 100));
	rectangle1.setPosition(sf::Vector2f(100, 100));

	sf::RectangleShape rectangle2;
	rectangle2.setSize(sf::Vector2f(50, 50));
	rectangle2.setFillColor(sf::Color(0, 127, 255));
	rectangle2.setPosition(sf::Vector2f(150, 250));

	sf::Font front;
	front.loadFromFile("type/Mistral.ttf");

	sf::Text text;
	text.setFont(front);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(35);
	text.setString(std::string("you are gay"));
    text.setPosition(250, 250 );


	bool login_window_is_open = true;
	bool text_ = false;


	while (login_window_is_open)
	{

	window_check();

	if (sf::IntRect(150, 250, 50, 50).contains(sf::Mouse::getPosition(window))) { rectangle2.setFillColor(sf::Color(255, 126, 0)); }

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (sf::IntRect(150, 250, 50, 50).contains(sf::Mouse::getPosition(window)))
		{ 
			//text_ = true;
			login_window_is_open = false; 
			number_sort = 0;
		}
	}


	window.clear();
	window.draw(rectangle1);
	window.draw(rectangle2);
	
	if(text_) window.draw(text);
	window.display();

    }

	return number_sort;
}

bool window_admin::register_fun(int i, void (*sort_fun)(std::vector<int> &V))
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

void window_admin::show(std::vector<int> &elem)
{
window.clear();

int interval = 0;
int width = 0;
int interval_plus_width = 0;
const int MIN_interval_plus_width = 2;
const int MAX_interval_plus_width = 20;

interval_plus_width = 460/elem.size() ;//460 - size is allocated to the graph - !!!! make constant !!!

if (interval_plus_width < MIN_interval_plus_width) { return ; }
if (interval_plus_width > MAX_interval_plus_width) { interval_plus_width = MAX_interval_plus_width; }

width = interval = interval_plus_width / 2;

for (int i=0;i< elem.size();i++)
{
	int tmp =elem.at(i);



	rectangle.setSize(sf::Vector2f(10, -10* tmp));
	rectangle.setFillColor(sf::Color(200, 100, 100));
	rectangle.setPosition(sf::Vector2f(20 + width * i*2,500));
	window.draw(rectangle);
}
	



	

	
	window.display();
	Sleep(10);
}

void window_admin::run()
{
	while (window.isOpen())
	{

		int number_sort = login_window();


		std::vector<int> vc{ 10,5,6,9,8,7,25,35,6,5,4,5, 5,4,8,1, 2, 3, 4, 5,2,3,4,5,6,7,8,9,5,7,8,9,6 };
		mas_sort_fun.at(number_sort)(vc);

		//void bubble_sort(std::vector<int> elem);



		////window.clear();
		//////window.draw();
		////window.display();
	}
}
