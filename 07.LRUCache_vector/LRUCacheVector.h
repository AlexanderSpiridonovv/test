#pragma once
#include <unordered_map>
#include <vector>

class LRUCache{

    struct Node
    {
        int key;
        int value;
        int nextIndex;
        int prevIndex;
    };
    int m_capacity;
    int m_headIndex;
    int m_tailIndex;
    std::vector<int> m_keyToIndex;
    std::vector<Node> m_order;
    void _moveToFront(int index);
    void _removeTail();

public:
    explicit LRUCache(int capacity);

    auto get(int key) -> int;
    void put(int key, int value);

    void printAllValues()const;
};