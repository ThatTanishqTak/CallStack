#include "Shell.h"

#include <iostream>
#include <sstream>

void Shell::Run()
{
    std::string input;
    while (true)
    {
        std::cout << "CallStack> ";
        if (!std::getline(std::cin, input))
        {
            break;
        }

        if (input == "exit")
        {
            break;
        }
    
        ExecuteCommand(input);
    }
}

void Shell::ExecuteCommand(const std::string& input)
{
    std::istringstream iss(input);
    std::string command;
    iss >> command;

    if (command == "echo")
    {
        std::string rest;
        std::getline(iss, rest);
        std::cout << rest << std::endl;
    }
    else
    {
        std::cout << "Unknown command: " << command << std::endl;
    }
}