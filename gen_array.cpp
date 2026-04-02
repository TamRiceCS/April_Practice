#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void printVector(std::vector<int> &output)
{

    if (output.size() == 0)
    {
        std::cout << "{}" << std::endl;
        return;
    }

    std::cout << "[";
    for (int i = 0; i < output.size() - 1; i++)
    {
        std::cout << output[i] << ", ";
    }
    std::cout << output[output.size() - 1] << "]" << std::endl;
}

std::vector<int> genRandom()
{

    std::vector<int> vRand;
    int size = (std::rand() % 26) + 5; // [5, 25]

    for (int i = 0; i < size; i++)
    {
        vRand.push_back((rand() % 101) - 50); // [-50, 50]
    }

    std::cout << "Your randomly generated array is: ";
    printVector(vRand);

    return vRand;
}

std::vector<int> genFile()
{
    std::vector<int> vFile;
    std::string fileName;

    std::cout << "Enter \'b\' to go back to the main menu or..." << std::endl;
    std::cout << "Please enter the name of a file: ";
    std::cin.clear();
    std::cin >> fileName;

    if (fileName.compare("b") == 0)
    {
        return vFile;
    }

    std::ifstream arrayFile(fileName);

    if (!arrayFile.is_open())
    {
        std::cout << "The file could not be opened..." << std::endl;
        return vFile;
    }
    else
    {
        std::string fileLine;
        std::getline(arrayFile, fileLine);
        int num = 0;
        int sign = 1;

        for (int i = 0; i < fileLine.size(); i++)
        {
            if (std::isdigit(fileLine[i]))
            {
                num *= 10;
                num += fileLine[i] - '0';
            }
            else if (fileLine[i] == '-')
            {
                sign = -1;
            }
            else if ((fileLine[i] == ',' || fileLine[i] == '}') && num != 0)
            {
                vFile.push_back(num * sign);
                num = 0;
                sign = 1;
            }
        }
    }

    std::cout << "Your file generated array is: ";
    printVector(vFile);

    return vFile;
}
std::vector<int> genUser()
{
    std::vector<int> vUser = {};
    std::string userInput;

    while (true)
    {
        std::cout << "\nEnter \'x\' to complete your user generated array..." << std::endl;
        std::cout << "Please enter the value for " << vUser.size() << "'s index: ";
        std::cin.clear();
        std::cin >> userInput;

        if (userInput.compare("x") == 0)
        {
            return vUser;
        }

        else
        {
            int num = 0;
            int sign = 1;
            for (int i = 0; i < userInput.size(); i++)
            {
                if (std::isdigit(userInput[i]))
                {
                    num *= 10;
                    num += userInput[i] - '0';
                }
                else if (userInput[i] == '-')
                {
                    sign = -1;
                }
            }

            vUser.push_back(num * sign);
            sign = 1;
        }

        printVector(vUser);
    }

    return vUser;
}