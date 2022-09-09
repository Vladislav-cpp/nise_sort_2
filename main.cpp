
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


	admin.register_fun(1, bubble_sort);




	//admin.run();


	//admin.show(vc);
	//admin.login_window();
     admin.run();




	return 0;





}

