#include "Shell.h"

#include "CommandParser.h"

#include <iostream>

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
    // s_CommandParser persists across calls to reuse parsing logic without reallocation.
    static CommandParser s_CommandParser{};

    // l_Command captures the parsed representation of the raw user input.
    const CommandParser::Command l_Command = s_CommandParser.ParseInput(input);

    if (!l_Command.m_IsValid || l_Command.m_CommandName.empty())
    {
        // Inform the user that the input did not meet the parser's expectations.
        std::cout << "Unable to parse command." << std::endl;
        return;
    }

    if (l_Command.m_CommandName == "echo")
    {
        // l_Output assembles the original argument list with preserved spacing between tokens.
        std::string l_Output{};
        for (std::size_t l_Index = 0; l_Index < l_Command.m_Arguments.size(); ++l_Index)
        {
            if (l_Index > 0)
            {
                l_Output += ' ';
            }

            l_Output += l_Command.m_Arguments[l_Index];
        }

        std::cout << l_Output << std::endl;
    }
    else
    {
        // Fallback path covering unsupported commands.
        std::cout << "Unknown command: " << l_Command.m_CommandName << std::endl;
    }
}