#pragma once

#include "AST.hpp"

class Parser
{
public:
    static Query parse(
        const std::string& sql);
};