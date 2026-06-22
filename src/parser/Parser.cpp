#include "../../include/parser/Parser.hpp"
#include "../../include/parser/Tokenizer.hpp"

Query Parser::parse(const std::string& sql)
{
    Query query;

    auto tokens = Tokenizer::tokenize(sql);

    // empty input → invalid
    if(tokens.empty())
        return query;

    // =========================
    // CREATE TABLE <name>
    // =========================
    if(tokens[0] == "CREATE")
    {
        if(tokens.size() < 3 || tokens[1] != "TABLE")
            return query;

        query.type = QueryType::CREATE_TABLE;
        query.tableName = tokens[2];

        return query;
    }

    // =========================
    // INSERT INTO <table> ...
    // =========================
    if(tokens[0] == "INSERT")
    {
        if(tokens.size() < 4 || tokens[1] != "INTO")
            return query;

        query.type = QueryType::INSERT;
        query.tableName = tokens[2];

        for(size_t i = 3; i < tokens.size(); i++)
            query.values.push_back(tokens[i]);

        return query;
    }

    // =========================
    // SELECT <table>
    // =========================
    if(tokens[0] == "SELECT")
    {
        if(tokens.size() < 2)
            return query;

        query.type = QueryType::SELECT;
        query.tableName = tokens[1];

        return query;
    }

    // =========================
    // FIND <id>
    // =========================
    if(tokens[0] == "FIND")
    {
        if(tokens.size() < 2)
            return query;

        query.type = QueryType::FIND;
        query.values.push_back(tokens[1]);

        return query;
    }

    // =========================
    // INVALID QUERY
    // =========================
    query.type = QueryType::UNKNOWN;
    return query;
}