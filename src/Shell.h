#pragma once

#include <string>

class Shell
{
public:
    void Run();
    
private:
    void ExecuteCommand(const std::string& input);
};