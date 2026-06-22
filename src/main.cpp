#include <iostream>

#include "../include/core/Database.hpp"
#include "../include/parser/Parser.hpp"
#include "../include/utils/Logger.hpp"

int main()
{
    Database db;

    Logger::banner();

    std::cout
        << "Type 'HELP' | 'EXIT' to quit\n\n";

    Logger::info("ShigosagDB started");

    std::string sql;

    while(true)
    {
        std::cout << "ShigosagDB > ";
        std::getline(std::cin, sql);

        // =========================
        // EXIT
        // =========================
        if(sql == "EXIT")
            break;

        // =========================
        // HELP
        // =========================
        if(sql == "HELP")
        {
            std::cout <<
            "\nShigosagDB Commands\n"
            "--------------------\n"
            "CREATE TABLE <name>\n"
            "INSERT INTO <table> <id firstName lastName otherName metadata>\n"
            "SELECT <table>\n"
            "FIND <id>\n"
            "SHOW TABLES\n"
            "DROP TABLE <name>\n"
            "EXIT\n\n";
            continue;
        }

        // =========================
        // SHOW TABLES
        // =========================
        if(sql == "SHOW TABLES")
        {
            db.showTables();
            continue;
        }

        // =========================
        // DROP TABLE
        // =========================
        if(sql.rfind("DROP TABLE", 0) == 0)
        {
            if(sql.size() <= 11)
            {
                Logger::error("Invalid query");
                continue;
            }

            std::string name = sql.substr(11);
            db.dropTable(name);
            continue;
        }

        // =========================
        // EMPTY INPUT CHECK
        // =========================
        if(sql.empty())
        {
            Logger::error("Invalid query");
            continue;
        }

        // =========================
        // PARSE QUERY
        // =========================
        Query query = Parser::parse(sql);

        // =========================
        // EXECUTE QUERY
        // =========================
        switch(query.type)
        {
            case QueryType::CREATE_TABLE:
                db.createTable(query.tableName);
                break;

            case QueryType::INSERT:
            {
                if(query.values.size() < 5)
                {
                    Logger::error("Invalid INSERT format");
                    break;
                }

                Record r;

                r.id = query.values[0];
                r.firstName = query.values[1];
                r.lastName = query.values[2];
                r.otherName = query.values[3];
                r.metadata = query.values[4];

                db.insert(query.tableName, r);
                break;
            }

            case QueryType::SELECT:
                db.select(query.tableName);
                break;

            case QueryType::FIND:
                if(query.values.empty())
                {
                    Logger::error("Invalid FIND query");
                    break;
                }

                db.findById(std::stoi(query.values[0]));
                break;

            case QueryType::UNKNOWN:
            default:
                Logger::error("Invalid query");
                break;
        }
    }

    return 0;
}