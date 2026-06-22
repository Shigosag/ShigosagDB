#pragma once

#include <map>
#include <optional>

template<typename Key, typename Value>
class BPlusTree
{
public:

    void insert(
        const Key& key,
        const Value& value);

    bool contains(
        const Key& key) const;

    std::optional<Value> search(
        const Key& key) const;

    void remove(
        const Key& key);

    size_t size() const;

private:

    std::map<Key, Value> index;
};

#include "../../src/index/BPlusTree.cpp"