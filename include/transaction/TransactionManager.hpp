#pragma once

#include <string>
#include <vector>

class TransactionManager
{
public:

    TransactionManager();

    void begin();

    void commit();

    void rollback();

    bool isActive() const;

    void logOperation(
        const std::string& operation);

private:

    bool active;

    std::vector<std::string> operations;

    void writeWal(
        const std::string& message);
};