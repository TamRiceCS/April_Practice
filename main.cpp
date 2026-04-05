#include "sorting_alg.h"
#include "gen_array.h"
#include <iostream>
#include <string>
#include <vector>

bool generateMenu(std::vector<int> &sortable)
{

    std::string userInput = "";
    std::cout << "\nHow would you like to generate an array to sort?" << std::endl;
    std::cout << "   1. Randomly generated array..." << std::endl;
    std::cout << "   2. File generated array..." << std::endl;
    std::cout << "   3. Input values one-by-one..." << std::endl;
    std::cout << "   Press \'x\' to exit the program..." << std::endl;

    std::cin.clear();
    std::cout << "\nYour Input: ";
    std::cin >> userInput;

    if (!userInput.compare("1"))
    {
        sortable = genRandom();
    }
    else if (!userInput.compare("2"))
    {
        sortable = genFile();
    }
    else if (!userInput.compare("3"))
    {
        sortable = genUser();
    }
    else if (!userInput.compare("x"))
    {
        return true;
    }

    return false;
}

bool sortingMenu(std::vector<int> &sortable)
{
    std::string userInput = "";
    std::cout << "\nHow would you like to generate an array to sort?" << std::endl;
    std::cout << "   1. Bubble Sort..." << std::endl;
    std::cout << "   2. Insertion Sort..." << std::endl;
    std::cout << "   3. Selection Sort..." << std::endl;
    std::cout << "   4. Merge Sort..." << std::endl;
    std::cout << "   5. Quick Sort..." << std::endl;
    std::cout << "   Press \'b\' to enter another vector..." << std::endl;
    std::cout << "   Press \'x\' to exit the program..." << std::endl;

    std::cin.clear();
    std::cout << "\nYour Input: ";
    std::cin >> userInput;
    if (!userInput.compare("b"))
    {
        sortable.clear();
    }
    if (!userInput.compare("x"))
    {
        return true;
    }
    if (!userInput.compare("1"))
    {
        bubbleSort(sortable);
    }
    if (!userInput.compare("2"))
    {
        insertionSort(sortable);
    }
    if (!userInput.compare("3"))
    {
        selectionSort(sortable);
    }
    if (!userInput.compare("4"))
    {
        std::vector<int> copy = sortable;
        mergeSort(copy, 0, sortable.size() - 1);
    }

    return false;
}

int main()
{

    std::string userInput;
    std::vector<int> sortable;
    bool endState = false;

    std::cout << "***Welcome to April's Coding Challenge: Sorting Algorithms***" << std::endl;
    while (!endState)
    {
        if (sortable.size() == 0)
        {
            endState = generateMenu(sortable);
        }
        else
        {
            endState = sortingMenu(sortable);
        }
    }

    std::cout << "\nThat's it! Bye-bye..." << std::endl;
    return 0;
}