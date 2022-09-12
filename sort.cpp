#include "sort.h"
extern window_admin admin;
extern int global_swap_index;
extern int global_inner_pointer_index;
extern int global_outer_pointer_index;
extern bool global_sort_end;

std::vector<int> rt(10, 2);

void bubble_sort(std::vector<int>& elem)
{
    int i, j;
    for (i = 0; i < elem.size() - 1; i++)
    {
        global_outer_pointer_index = i;
        for (j = 0; j < elem.size() - i - 1; j++)
        {
            admin.window_check();
            global_inner_pointer_index = j;
            if (elem.at(j) > elem.at(j + 1))
            {
                global_swap_index = j;
                std::swap(elem.at(j), elem.at(j + 1));
                admin.show(elem);
            }
            else
                admin.show(elem);
        }
    }

    global_sort_end = true;
    admin.show(elem);

}

void quick_sort_next(std::vector<int>& elem, int first, int last)

{
    int middle = elem.at((first + last) / 2);
    int i = first;
    int j = last;

    do
    {
        while (elem.at(i) < middle)
        {
            i++;
            global_outer_pointer_index = i;
            admin.show(elem);
        }
            
        while (elem.at(j) > middle)
        {
            j--;
            global_inner_pointer_index = j;
            admin.show(elem);
        }

        if (i <= j)
        {
            admin.window_check();
            global_swap_index = j;
            std::swap(elem.at(i), elem.at(j));
            i++;
            j--;
            admin.show(elem);
        }

    } while (i <= j);


    if (i < last)
        quick_sort_next(elem, i, last);
    if (j > first)
        quick_sort_next(elem, first, j);
}
void quick_sort(std::vector<int>& elem)
{
    quick_sort_next(elem, 0, elem.size() - 1);
    global_sort_end = true;
    admin.show(elem);
}

void selection_sort(std::vector<int>& elem)
{
    int i, j;
    for (i = 0; i < elem.size() - 1; i++)
    {
        global_outer_pointer_index = i;
        for (j = i + 1; j < elem.size(); j++)
        {
            global_inner_pointer_index = j;
            admin.window_check();
            if (elem.at(j) < elem.at(i))
            {
                global_swap_index = j;
                std::swap(elem.at(j), elem.at(i));
            }
            admin.show(elem);
        }
    }

    global_sort_end = true;
    admin.show(elem);

}

void insertion_sort(std::vector<int>& elem)
{
    for (int i = 1; i < elem.size(); i++)
    {
        int key = elem.at(i);
        global_outer_pointer_index = i;

        int j;
        for (j = i - 1; j >= 0 && elem.at(j) > key; j--)
        {
            global_inner_pointer_index = j;
            admin.window_check();
            global_swap_index = j+1;
            elem.at(j + 1) = elem.at(j);
            admin.show(elem);
        }
        elem.at(j + 1) = key;
    }
    global_sort_end = true;
    admin.show(elem);
}

void merge(std::vector<int>& elem, int const left,int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    std::vector<int> leftArray(subArrayOne);
    std::vector<int> rightArray(subArrayTwo);

    for (int i = 0; i < subArrayOne; i++)
        leftArray.at(i) = elem.at(left+i);
    for (int j = 0; j < subArrayTwo; j++)
        rightArray.at(j) = elem.at(mid + 1 + j);

    int indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) 
        {
            global_inner_pointer_index = indexOfMergedArray;
            global_swap_index = indexOfSubArrayOne;
            admin.window_check();
            elem.at(indexOfMergedArray) = leftArray.at(indexOfSubArrayOne);
            indexOfSubArrayOne++;
            admin.show(elem);
        }
        else 
        {
            global_inner_pointer_index = indexOfMergedArray;
            global_swap_index = indexOfSubArrayTwo;
            admin.window_check();
            elem.at(indexOfMergedArray) = rightArray.at(indexOfSubArrayTwo);
            indexOfSubArrayTwo++;
            admin.show(elem);
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) 
    {
        global_inner_pointer_index = indexOfMergedArray;
        global_swap_index = indexOfSubArrayOne;
        admin.window_check();
        elem.at(indexOfMergedArray) = leftArray.at(indexOfSubArrayOne);
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        admin.show(elem);
    }

    while (indexOfSubArrayTwo < subArrayTwo) 
    {
        global_inner_pointer_index = indexOfMergedArray;
        global_swap_index = indexOfSubArrayTwo;
        admin.window_check();
        elem.at(indexOfMergedArray) = rightArray.at(indexOfSubArrayTwo);
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        admin.show(elem);
    }
}

void merge_sort_next(std::vector<int>& elem, int const begin, int const end)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    global_outer_pointer_index = mid;
    admin.window_check();
    merge_sort_next(elem, begin, mid);
    merge_sort_next(elem, mid + 1, end);
    merge(elem, begin, mid, end);
    admin.show(elem);
}

void merge_sort(std::vector<int>& elem)
{
    merge_sort_next(elem, 0, elem.size() - 1);
    global_sort_end = true;
    admin.show(elem);
}

void heapify(std::vector<int>& elem, int N, int i)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l<N && elem[l]>elem[largest])
        largest = l;
    if (r < N && elem[r] > elem[largest])
        largest = r;
    if (largest != i)
    {
        admin.window_check();
        std::swap(elem.at(i), elem.at(largest));
        heapify(elem, N, largest);
        global_swap_index = i;
        admin.show(elem);
    }

}

void heap_sort(std::vector<int>& elem)
{
    for (int i = elem.size() / 2 - 1; i >= 0; i--)
    {
        heapify(elem, elem.size(), i);
    }


    for (int i = elem.size() - 1; i > 0; i--)
    {
        admin.window_check();
        std::swap(elem.at(0), elem.at(i));
        global_inner_pointer_index = i;
        admin.show(elem);
        heapify(elem, i, 0);

    }
}

