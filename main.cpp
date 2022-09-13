#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <ctime>
#include "window_admin.h"
#include "sort.h"

int global_swap_index = 0;
int global_inner_pointer_index = 0;
int global_outer_pointer_index = 0;
bool global_sort_end = false;
window_admin admin;

//
int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	admin.register_fun(1, bubble_sort);
	admin.register_fun(2, insertion_sort);
	admin.register_fun(3, quick_sort);
	admin.register_fun(4, selection_sort);
	admin.register_fun(5, merge_sort);
	admin.register_fun(6, heap_sort);

	admin.run();

	return 0;
}

