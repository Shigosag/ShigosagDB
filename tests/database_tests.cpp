#include <catch2/catch_test_macros.hpp>

#include "../include/core/Table.hpp"
#include "../include/core/Record.hpp"
#include "../include/index/BPlusTree.hpp"

TEST_CASE("Table Insert")
{
    Table users("users");

    Record r;
    r.values = {"1", "John"};

    users.insert(r);

    REQUIRE(
        users.getRecords().size() == 1);
}

TEST_CASE("Multiple Records")
{
    Table users("users");

    Record r1;
    r1.values = {"1", "John"};

    Record r2;
    r2.values = {"2", "Mary"};

    users.insert(r1);
    users.insert(r2);

    REQUIRE(
        users.getRecords().size() == 2);
}

TEST_CASE("Index Insert")
{
    BPlusTree<int, int> index;

    index.insert(1, 100);

    REQUIRE(
        index.contains(1));
}

TEST_CASE("Index Search")
{
    BPlusTree<int, int> index;

    index.insert(5, 500);

    auto result =
        index.search(5);

    REQUIRE(result.has_value());

    REQUIRE(
        result.value() == 500);
}

TEST_CASE("Index Remove")
{
    BPlusTree<int, int> index;

    index.insert(10, 200);

    index.remove(10);

    REQUIRE(
        !index.contains(10));
}