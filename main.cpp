#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>
#include <ctime>
#include "window_admin.h"
#include "sort.cpp"


//
int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	admin.register_fun(1, insertion_sort);
	admin.register_fun(1, bubble_sort);
	admin.register_fun(2, quick_sort);
	admin.register_fun(3, selection_sort);
	admin.register_fun(4, insertion_sort);




	//admin.run();


	//admin.show(vc);
	//admin.login_window();
     admin.run();




	return 0;





}

