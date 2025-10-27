#include "LRUCacheVector.h"
#include <iostream>

LRUCache::LRUCache(int capacity)
    : m_capacity(capacity),
      m_headIndex(-1),
      m_tailIndex(-1),
      m_keyToIndex(10000, -1)
{
}


void LRUCache::_moveToFront(int index)
{
    if(index == m_headIndex)
    {
        return;
    }
    int prev = m_order[index].prevIndex;
    int next = m_order[index].nextIndex;

    if(prev != -1)
    {
        m_order[prev].nextIndex = next;
    }
    if(next != -1)
    {
        m_order[next].prevIndex = prev;
    }

    if(index == m_tailIndex)
    {
        m_tailIndex = prev;
    }

    m_order[index].prevIndex = -1;
    m_order[index].nextIndex = m_headIndex;

    if(m_headIndex != -1)
    {
        m_order[m_headIndex].prevIndex = index;
    }
    m_headIndex = index;
}

void LRUCache::_removeTail()
{
    if(m_tailIndex == -1)
    {
        return;
    }

    Node tail =  m_order[m_tailIndex];
    int oldKey = tail.key;
    m_keyToIndex[oldKey] = -1;

    if(tail.prevIndex != -1)
    {
        m_order[tail.prevIndex].nextIndex = -1;
        m_tailIndex = tail.prevIndex;
    }
    else
    {
        m_headIndex = m_tailIndex = -1;
    }
    
}
auto LRUCache::get(int key) -> int 
{
    int index = m_keyToIndex[key];

    if(index == -1)
    {
        return -1;
    }

    _moveToFront(index);
    return m_order[index].value;
    
}

void LRUCache::put(int key, int value)
{
    int index = m_keyToIndex[key];
    if(index != -1)
    {
        m_order[index].value = value;
        _moveToFront(index);
        return;
    }

    if ((int)m_order.size() < m_capacity)
    {
        Node node = {key, value, m_headIndex, -1};

        if (m_headIndex != -1)
        {
            m_order[m_headIndex].prevIndex = m_order.size();
        }

        m_order.push_back(node);
        m_keyToIndex[key] = m_order.size() - 1;
        m_headIndex = m_order.size() - 1;

        if (m_tailIndex == -1)
        {
            m_tailIndex = m_headIndex;
        }
    }

    else
    {
        int oldTail = m_tailIndex;
        _removeTail();

        m_order[oldTail].key = key;
        m_order[oldTail].value = value;

        _moveToFront(oldTail);
        m_keyToIndex[key] = oldTail;
    }
}
void LRUCache::printAllValues() const
{
    if (m_headIndex == -1)
    {
        std::cout << "[empty]\n";
        return;
    }

    int current = m_headIndex;
    while (current != -1)
    {
        const Node& node = m_order[current];
        std::cout << node.value;
        current = node.nextIndex;
        if (current != -1)
            std::cout << " -> ";
    }
    std::cout << '\n';
}

