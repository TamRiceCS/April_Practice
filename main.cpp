#include <iostream>
#include <string>
#include <vector>
#include "sorting_alg.h"
#include "gen_array.h"

bool generateMenu()
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

    return true;
}

bool sortingMenu()
{
    std::string userInput = "";
    std::cout << "\nHow would you like to generate an array to sort?" << std::endl;
    std::cout << "   1. Bubble Sort..." << std::endl;
    std::cout << "   2. Insertion Sort..." << std::endl;
    std::cout << "   3. Selection Sort..." << std::endl;
    std::cout << "   4. Merge Sort..." << std::endl;
    std::cout << "   5. Quick Sort..." << std::endl;
    std::cout << "   Press \'x\' to exit the program..." << std::endl;

    std::cin.clear();
    std::cout << "\nYour Input: ";
    std::cin >> userInput;

    return true;
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
            generateMenu();
        }
        else
        {
            sortingMenu();
        }
        break; // TO-DO: remove this breakpoint, it is to prevent inf looping.
    }

    std::cout << "That's it! Bye-bye..." << std::endl;
    return 0;
}