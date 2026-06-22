#pragma once

#include <string>
#include <vector>
#include "Record.hpp"

class Table
{
public:
    explicit Table(const std::string& name);

    void insert(const Record& record);

    const std::vector<Record>& getRecords() const;

    const std::string& getName() const;

private:
    std::string tableName;
    std::vector<Record> records;
};