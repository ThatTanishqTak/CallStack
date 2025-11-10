#pragma once

#include <string>
#include <vector>

// The CommandParser class transforms raw input into a structured command model for the shell.
class CommandParser
{
public:
    // Command represents a parsed shell command with its name, arguments, and validity flag.
    struct Command
    {
        // m_CommandName stores the parsed command keyword provided by the user.
        std::string m_CommandName;
        // m_Arguments stores every argument supplied to the command, excluding the name itself.
        std::vector<std::string> m_Arguments;
        // m_IsValid indicates whether the parsing step succeeded without syntax errors.
        bool m_IsValid{ false };
    };

    // ParseInput converts the given raw input into a structured Command instance.
    [[nodiscard]] Command ParseInput(const std::string& a_Input) const;
};