#pragma once

#include <memory>
#include <unordered_map>

#include "Table.hpp"
#include "StorageEngine.hpp"
#include "../utils/Logger.hpp"

class Database
{
public:
    Database();

    void loadDatabase();

    void createTable(const std::string& name);

    void insert(const std::string& tableName, const Record& record);

    void select(const std::string& tableName);

    void findById(int id);

    void showTables();

    void dropTable(const std::string& name);

private:
    std::unordered_map<std::string, std::unique_ptr<Table>> tables;

    StorageEngine storage;
};