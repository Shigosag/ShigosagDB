#pragma once

#include <string>
#include <vector>

enum class QueryType
{
    CREATE_TABLE,
    INSERT,
    SELECT,
    FIND,
    UNKNOWN
};

struct Query
{
    QueryType type = QueryType::UNKNOWN;

    std::string tableName;

    // CREATE TABLE columns (future use)
    std::vector<std::string> columns;

    // INSERT values (id, firstName, lastName, otherName, metadata)
    std::vector<std::string> values;
};