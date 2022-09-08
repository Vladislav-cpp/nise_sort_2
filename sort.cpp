#include <iostream>
#include <vector>
#include "window_admin.h"

window_admin admin;

void bubble_sort(std::vector<int> &elem)
{
    int i, j;
    for (i = 0; i < elem.size() - 1; i++)
        for (j = 0; j < elem.size() - i - 1; j++)
        {
            admin.window_check();

            if (elem.at(j) > elem.at(j + 1))
            {
                std::swap(elem.at(j), elem.at(j + 1));
                //int tmp = elem.at(j);
                //elem.at(j) = elem.at(j + 1);
                //elem.at(j + 1) = tmp;
            }
            admin.show(elem);


        }

}

