#include "../../include/core/Database.hpp"
#include "../../include/utils/Logger.hpp"

#include <iostream>

Database::Database()
    : storage("data/tables")
{
    loadDatabase();
}

void Database::loadDatabase()
{
    storage.loadAllTables(tables);
    Logger::info("Database loaded from disk");
}

void Database::createTable(const std::string& name)
{
    tables[name] = std::make_unique<Table>(name);
    Logger::info("Table created: " + name);
}

void Database::insert(
    const std::string& tableName,
    const Record& record)
{
    auto it = tables.find(tableName);

    if(it == tables.end())
    {
        Logger::error("Table not found");
        return;
    }

    it->second->insert(record);

    storage.saveTable(tableName, it->second->getRecords());

    Logger::info("Record inserted");
}

void Database::select(const std::string& tableName)
{
    auto it = tables.find(tableName);

    if(it == tables.end())
    {
        Logger::error("Table not found");
        return;
    }

    for(const auto& r : it->second->getRecords())
    {
        std::cout
            << r.id << " "
            << r.firstName << " "
            << r.lastName << " "
            << r.otherName << " "
            << r.metadata << "\n";
    }
}

void Database::findById(int id)
{
    auto it = tables.find("users");

    if(it == tables.end())
    {
        Logger::error("Table not found");
        return;
    }

    for(size_t i = 0; i < it->second->getRecords().size(); i++)
    {
        if(std::stoi(it->second->getRecords()[i].id) == id)
        {
            Logger::info("Record found at row " + std::to_string(i));
            return;
        }
    }

    Logger::warning("Record not found");
}

void Database::showTables()
{
    for(const auto& [name, _] : tables)
        std::cout << "- " << name << "\n";
}

void Database::dropTable(const std::string& name)
{
    tables.erase(name);
    Logger::info("Table dropped: " + name);
}