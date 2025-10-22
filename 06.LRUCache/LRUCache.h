#pragma once
#include <unordered_map>
#include <queue>
#include "Node.h"

class LRUCache{

    std::unordered_map<int,Node*> m_cache;

    unsigned m_capacity;

    Node* head = nullptr;
    Node* tail = nullptr;

public:
    explicit LRUCache(unsigned capacity);

    void deleteNode(Node* node);
    void addNode(Node* node);

    auto get(int key) -> int;
    void put(int key, int value);

    void printAllValues()const;
};