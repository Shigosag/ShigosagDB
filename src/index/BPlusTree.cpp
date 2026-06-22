#pragma once

template<typename Key, typename Value>
void BPlusTree<Key, Value>::insert(
    const Key& key,
    const Value& value)
{
    index[key] = value;
}

template<typename Key, typename Value>
bool BPlusTree<Key, Value>::contains(
    const Key& key) const
{
    return index.contains(key);
}

template<typename Key, typename Value>
std::optional<Value>
BPlusTree<Key, Value>::search(
    const Key& key) const
{
    auto it = index.find(key);

    if(it == index.end())
    {
        return std::nullopt;
    }

    return it->second;
}

template<typename Key, typename Value>
void BPlusTree<Key, Value>::remove(
    const Key& key)
{
    index.erase(key);
}

template<typename Key, typename Value>
size_t BPlusTree<Key, Value>::size() const
{
    return index.size();
}