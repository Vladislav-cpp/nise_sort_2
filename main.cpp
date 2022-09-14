#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <ctime>
#include "window_admin.h"


window_admin admin;

//
int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	admin.register_fun(1, bubble_sort);
	admin.register_fun(2, quick_sort);
	admin.register_fun(3, insertion_sort);
	admin.register_fun(4, selection_sort);
	admin.register_fun(5, merge_sort);
	admin.register_fun(6, heap_sort);

	admin.run();

	return 0;
}

