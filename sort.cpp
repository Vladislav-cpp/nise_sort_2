#include "window_admin.h"
extern window_admin admin;


void bubble_sort(std::vector<int>& elem)
{
    indexInfo Info;
    int i, j;
    for (i = 0; i < elem.size() - 1; i++)
    {
        Info.outer_pointer_index = i;
        for (j = 0; j < elem.size() - i - 1; j++)
        {
            admin.window_check();
            Info.inner_pointer_index = j;
            if (elem.at(j) > elem.at(j + 1))
            {
                Info.swap_index = j;
                std::swap(elem.at(j), elem.at(j + 1));
                admin.show(elem, Info);
            }
            else
                admin.show(elem, Info);
        }
    }

    Info.sort_end = true;
    admin.show(elem, Info);

}


void selection_sort(std::vector<int>& elem)
{
    indexInfo Info;
    int i, j;
    for (i = 0; i < elem.size() - 1; i++)
    {
        Info.outer_pointer_index = i;
        for (j = i + 1; j < elem.size(); j++)
        {
            Info.inner_pointer_index = j;
            admin.window_check();
            if (elem.at(j) < elem.at(i))
            {
                Info.swap_index = j;
                std::swap(elem.at(j), elem.at(i));
            }
            admin.show(elem, Info);
        }
    }

    Info.sort_end = true;
    admin.show(elem, Info);

}


void insertion_sort(std::vector<int>& elem)
{
    indexInfo Info;
    for (int i = 1; i < elem.size(); i++)
    {
        int key = elem.at(i);
        Info.outer_pointer_index = i;

        int j;
        for (j = i - 1; j >= 0 && elem.at(j) > key; j--)
        {
            Info.inner_pointer_index = j;
            admin.window_check();
            Info.swap_index = j + 1;
            elem.at(j + 1) = elem.at(j);
            admin.show(elem, Info);
        }
        elem.at(j + 1) = key;
    }
    Info.sort_end = true;
    admin.show(elem, Info);
}


void quick_sort_next(std::vector<int>& elem, int first, int last, indexInfo Info)

{
 
    int middle = elem.at((first + last) / 2);
    int i = first;
    int j = last;

    do
    {
        while (elem.at(i) < middle)
        {
            i++;
            Info.outer_pointer_index = i;
            admin.show(elem, Info);
        }
            
        while (elem.at(j) > middle)
        {
            j--;
            Info.inner_pointer_index = j;
            admin.show(elem, Info);
        }

        if (i <= j)
        {
            admin.window_check();
            Info.swap_index = j;
            std::swap(elem.at(i), elem.at(j));
            i++;
            j--;
            admin.show(elem, Info);
        }

    } while (i <= j);


    if (i < last)
        quick_sort_next(elem, i, last, Info);
    if (j > first)
        quick_sort_next(elem, first, j, Info);
}

void quick_sort(std::vector<int>& elem)
{
    indexInfo Info;
    quick_sort_next(elem, 0, elem.size() - 1, Info);
    Info.sort_end = true;
    admin.show(elem, Info);
}


void merge(std::vector<int>& elem, int const left,int const mid, int const right, indexInfo Info)
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
            Info.inner_pointer_index = indexOfMergedArray;
            Info.swap_index = indexOfSubArrayOne;
            admin.window_check();
            elem.at(indexOfMergedArray) = leftArray.at(indexOfSubArrayOne);
            indexOfSubArrayOne++;
            admin.show(elem, Info);
        }
        else 
        {
            Info.inner_pointer_index = indexOfMergedArray;
            Info.swap_index = indexOfSubArrayTwo;
            admin.window_check();
            elem.at(indexOfMergedArray) = rightArray.at(indexOfSubArrayTwo);
            indexOfSubArrayTwo++;
            admin.show(elem, Info);
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) 
    {
        Info.inner_pointer_index = indexOfMergedArray;
        Info.swap_index = indexOfSubArrayOne;
        admin.window_check();
        elem.at(indexOfMergedArray) = leftArray.at(indexOfSubArrayOne);
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        admin.show(elem, Info);
    }

    while (indexOfSubArrayTwo < subArrayTwo) 
    {
        Info.inner_pointer_index = indexOfMergedArray;
        Info.swap_index = indexOfSubArrayTwo;
        admin.window_check();
        elem.at(indexOfMergedArray) = rightArray.at(indexOfSubArrayTwo);
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        admin.show(elem, Info);
    }
}

void merge_sort_next(std::vector<int>& elem, int const begin, int const end, indexInfo Info)
{

    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    Info.outer_pointer_index = mid;
    admin.window_check();
    merge_sort_next(elem, begin, mid, Info);
    merge_sort_next(elem, mid + 1, end, Info);
    merge(elem, begin, mid, end, Info);
    admin.show(elem, Info);
}

void merge_sort(std::vector<int>& elem)
{
    indexInfo Info;
    merge_sort_next(elem, 0, elem.size() - 1, Info);
    Info.sort_end = true;
    admin.show(elem, Info);
}


void heapify(std::vector<int>& elem, int N, int i, indexInfo Info)
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
        heapify(elem, N, largest, Info);
        Info.swap_index = i;
        admin.show(elem, Info);
    }

}

void heap_sort(std::vector<int>& elem)
{
    indexInfo Info;
    for (int i = elem.size() / 2 - 1; i >= 0; i--)
    {
        heapify(elem, elem.size(), i, Info);
    }


    for (int i = elem.size() - 1; i > 0; i--)
    {
        admin.window_check();
        std::swap(elem.at(0), elem.at(i));
        Info.inner_pointer_index = i;
        admin.show(elem, Info);
        heapify(elem, i, 0, Info);

    }
}

