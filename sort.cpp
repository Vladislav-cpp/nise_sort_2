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

<<<<<<< HEAD
void quick_sort(std::vector<int>& elem, int last = elem.size() - 1, int first = 0)
{
    int middle = elem.at((first + last) / 2);
    int i = first;
    int j = last;

    do
    {
        while (elem.at(i) < middle)
            i++;
        while (elem.at(j) > middle)
            j++;

        if (i <= j)
        {
            std::swap(elem.at(i), elem.at(j));
            i++;
            j--;
        }

    } while (i <= j);

    if (i < last)
        quick_sort(&elem, last, i);
    if (j > first)
        quick_sort(&elem, j, first);

}

void selection_sort(std::vector<int>& elem)
{
    int i, j;
    for (i = 0; i < elem.size() - 1; i++)
        for (j = i+1; j < elem.size(); j++)
        {
            admin.window_check();
            if (elem.at(j) < elem.at(i))
            {
                std::swap(elem.at(j), elem.at(i));
            }
            admin.show(elem);
        }

}

void insertion_sort(std::vector<int>& elem)
{
    for (int i = 1; i < elem.size(); i++)
    {
        int key = elem.at(i);

        int j;
        for (j = i - 1; j >= 0 && elem.at(j) > key; j--)
        {
            admin.window_check();
            elem.at(j + 1) = elem.at(j);
            admin.show(elem);
        }
    }
}
=======
>>>>>>> 9dd8f53627e35bd2f0ce35506051c186490eba45
