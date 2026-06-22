#include "../../include/transaction/TransactionManager.hpp"
#include "../../include/utils/Logger.hpp"

#include <fstream>

TransactionManager::TransactionManager()
    : active(false)
{
}

void TransactionManager::begin()
{
    if(active)
    {
        Logger::warning(
            "Transaction already active");
        return;
    }

    active = true;

    operations.clear();

    writeWal("BEGIN");

    Logger::info(
        "Transaction started");
}

void TransactionManager::commit()
{
    if(!active)
    {
        Logger::warning(
            "No active transaction");
        return;
    }

    writeWal("COMMIT");

    operations.clear();

    active = false;

    Logger::info(
        "Transaction committed");
}

void TransactionManager::rollback()
{
    if(!active)
    {
        Logger::warning(
            "No active transaction");
        return;
    }

    writeWal("ROLLBACK");

    operations.clear();

    active = false;

    Logger::info(
        "Transaction rolled back");
}

bool TransactionManager::isActive() const
{
    return active;
}

void TransactionManager::logOperation(
    const std::string& operation)
{
    if(!active)
        return;

    operations.push_back(operation);

    writeWal(operation);
}

void TransactionManager::writeWal(
    const std::string& message)
{
    std::ofstream wal(
        "data/wal/shigosagdb.wal",
        std::ios::app);

    wal << message << '\n';
}