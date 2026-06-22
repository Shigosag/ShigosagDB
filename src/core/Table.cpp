#include "../../include/core/Table.hpp"

Table::Table(const std::string& name)
    : tableName(name)
{
}

void Table::insert(const Record& record)
{
    records.push_back(record);
}

const std::vector<Record>& Table::getRecords() const
{
    return records;
}

const std::string& Table::getName() const
{
    return tableName;
}