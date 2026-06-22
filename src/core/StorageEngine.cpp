#include "../../include/core/StorageEngine.hpp"
#include "../../include/core/Table.hpp"

#include <fstream>
#include <filesystem>

StorageEngine::StorageEngine(const std::string& dataDir)
    : dataDirectory(dataDir)
{
    std::filesystem::create_directories(dataDir);
}

bool StorageEngine::saveTable(
    const std::string& tableName,
    const std::vector<Record>& records)
{
    std::ofstream file(dataDirectory + "/" + tableName + ".tbl");

    if(!file) return false;

    for(const auto& r : records)
    {
        auto v = r.toVector();

        for(size_t i = 0; i < v.size(); i++)
        {
            file << v[i];
            if(i < v.size() - 1) file << ",";
        }
        file << "\n";
    }

    return true;
}

std::vector<Record> StorageEngine::loadTable(
    const std::string& tableName)
{
    std::vector<Record> records;

    std::ifstream file(dataDirectory + "/" + tableName + ".tbl");

    if(!file) return records;

    std::string line;

    while(std::getline(file, line))
    {
        std::vector<std::string> values;
        std::string temp;

        for(char c : line)
        {
            if(c == ',')
            {
                values.push_back(temp);
                temp.clear();
            }
            else temp += c;
        }

        values.push_back(temp);

        records.push_back(Record::fromVector(values));
    }

    return records;
}

void StorageEngine::loadAllTables(
    std::unordered_map<std::string,
    std::unique_ptr<Table>>& tables)
{
    namespace fs = std::filesystem;

    for(const auto& entry : fs::directory_iterator(dataDirectory))
    {
        if(entry.path().extension() == ".tbl")
        {
            std::string name = entry.path().stem().string();

            auto table = std::make_unique<Table>(name);

            auto records = loadTable(name);

            for(const auto& r : records)
                table->insert(r);

            tables[name] = std::move(table);
        }
    }
}