#include "../../include/parser/Tokenizer.hpp"

#include <sstream>

std::vector<std::string>
Tokenizer::tokenize(
    const std::string& input)
{
    std::vector<std::string> tokens;

    std::stringstream ss(input);

    std::string token;

    while(ss >> token)
    {
        tokens.push_back(token);
    }

    return tokens;
}