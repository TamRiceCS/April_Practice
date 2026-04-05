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
    int foundFlag;
    for (int i = 0; i < sortable.size(); i++)
    {
        foundFlag = 0;
        for (int j = 0; j <= i; j++)
        {
            if (sortable[j] > sortable[i])
            {
                sortable.insert(sortable.begin() + j, sortable[i]);
                sortable.erase(sortable.begin() + i + 1);
                std::cout << "\nFound correct insert point: ";
                foundFlag = 1;
                break;
            }
        }

        if (!foundFlag)
        {
            std::cout << "\nNo swap needed for this index: ";
        }
        printVector(sortable);
    }
}

void selectionSort(std::vector<int> sortable)
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
void merge(std::vector<int> &sortable, int start, int mid, int end)
{
    std::vector<int> original = sortable;
    int low = start;
    int high = mid + 1;
    int place = start;

    while (low <= mid || high <= end)
    {
        std::cout << "\nlow: " << low << " mid: " << mid << " high: " << high << " end: " << end << std::endl;
        printVector(sortable);
        std::cout << "\n";
        if (low == mid + 1)
        {
            sortable[place++] = original[high++];
            std::cout << "   low == mid: ";
            printVector(sortable);
        }
        else if (high == end + 1)
        {
            sortable[place++] = original[low++];
            std::cout << "   high == end: ";
            printVector(sortable);
        }
        else if (original[low] < original[high])
        {
            sortable[place++] = original[low++];
            std::cout << "   low < high: ";
            printVector(sortable);
        }
        else
        {
            sortable[place++] = original[high++];
            std::cout << "   low >= high: ";
            printVector(sortable);
        }
    }

    std::cout << "\n***Your finished merge is: ";
    printVector(sortable);
}
void mergeSort(std::vector<int> &sortable, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    mergeSort(sortable, start, mid);
    mergeSort(sortable, mid + 1, end);
    merge(sortable, start, mid, end);
}
void quickSort();