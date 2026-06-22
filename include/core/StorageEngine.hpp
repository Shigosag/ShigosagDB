#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "Record.hpp"

class Table;

class StorageEngine
{
public:
    explicit StorageEngine(const std::string& dataDir);

    bool saveTable(
        const std::string& tableName,
        const std::vector<Record>& records);

    std::vector<Record> loadTable(
        const std::string& tableName);

    void loadAllTables(
        std::unordered_map<std::string,
        std::unique_ptr<Table>>& tables);

private:
    std::string dataDirectory;
};