#include <iostream>
#ifndef GEN_ARRAY_H
#define GEN_ARRAY_H
#include "gen_array.h"
#endif

void bubbleSort(std::vector<int> sortable)
{

    for (int i = 0; i < sortable.size(); i++)
    {
        for (int j = 0; j < sortable.size() - (1 + i); j++)
        {
            if (sortable[j] > sortable[j + 1])
            {
                std::swap(sortable[j], sortable[j + 1]);
                std::cout << "A swap has occured: ";
                printVector(sortable);
            }
        }
    }

    std::cout << "\nYour final sorted array is: ";
    printVector(sortable);
}

void insertionSort(std::vector<int> sortable)
{
    int place;
    int smallest;
    for (int i = 0; i < sortable.size(); i++)
    {
        place = i;
        smallest = i;

        for (int j = i; j < sortable.size(); j++)
        {
            smallest = (sortable[smallest] > sortable[j]) ? j : smallest;
        }

        std::swap(sortable[smallest], sortable[place]);
        std::cout << "A swap has occureed: ";
        printVector(sortable);
    }
    std::cout << "\nYour final sorted array is: ";
    printVector(sortable);
}

void selectionSort();
void mergeSort();
void quickSort();