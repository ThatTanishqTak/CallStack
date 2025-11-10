#include "CommandParser.h"

#include <cctype>

// ParseInput walks through the raw input and tokenizes it into command and argument components.
CommandParser::Command CommandParser::ParseInput(const std::string& a_Input) const
{
    Command l_Result{};

    // l_Tokens collects every parsed segment (command name plus arguments).
    std::vector<std::string> l_Tokens{};
    // l_CurrentToken accumulates characters until a delimiter is reached.
    std::string l_CurrentToken{};
    // l_IsInsideQuotes tracks whether the parser is currently inside a quoted section.
    bool l_IsInsideQuotes{ false };
    // l_ActiveQuoteCharacter remembers the opening quote character to match it when closing.
    char l_ActiveQuoteCharacter{ '\0' };

    for (const char it_Character : a_Input)
    {
        if ((it_Character == '"') || (it_Character == '\''))
        {
            if (!l_IsInsideQuotes)
            {
                l_IsInsideQuotes = true;
                l_ActiveQuoteCharacter = it_Character;
            }
            else if (l_ActiveQuoteCharacter == it_Character)
            {
                l_IsInsideQuotes = false;
            }
            else
            {
                l_CurrentToken.push_back(it_Character);
            }
        }
        else if (std::isspace(static_cast<unsigned char>(it_Character)) && !l_IsInsideQuotes)
        {
            if (!l_CurrentToken.empty())
            {
                l_Tokens.push_back(l_CurrentToken);
                l_CurrentToken.clear();
            }
        }
        else
        {
            l_CurrentToken.push_back(it_Character);
        }
    }

    if (!l_CurrentToken.empty())
    {
        l_Tokens.push_back(l_CurrentToken);
    }

    if (l_IsInsideQuotes)
    {
        // Early exit: unmatched quotes invalidate the command.
        return l_Result;
    }

    if (l_Tokens.empty())
    {
        // No tokens were produced, so the input cannot yield a command.
        return l_Result;
    }

    l_Result.m_CommandName = l_Tokens.front();
    l_Result.m_IsValid = true;

    for (std::size_t l_Index = 1; l_Index < l_Tokens.size(); ++l_Index)
    {
        l_Result.m_Arguments.push_back(l_Tokens[l_Index]);
    }

    return l_Result;
}