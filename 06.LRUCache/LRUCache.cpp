#include "LRUCache.h"
#include "Node.h"
#include <iostream>

LRUCache::LRUCache(unsigned capacity) : m_capacity(capacity)
{
    head = new Node(-1,-1);
    tail = new Node(-1,-1);
    head -> next = tail;
    tail -> prev = head;
}


void LRUCache::addNode(Node* node)
{
    Node* temp = head -> next;
    head -> next = node;
    node -> next = temp;
    temp -> prev = node;
    node -> prev = head;

}
void LRUCache::deleteNode(Node* node)
{
     Node* previous = node -> prev;
     Node* after = node -> next;
     previous -> next = after;
     after -> prev = previous;
}
auto LRUCache::get(int key) -> int 
{
    if(m_cache.find(key) == m_cache.end())
    {
        return -1;
    }
    Node* node = m_cache[key];
    deleteNode(node);
    addNode(node);
    m_cache[key] = head->next;
    return head->next->value;
}

void LRUCache::put(int key, int value)
{
    if(m_cache.find(key) != m_cache.end())
    {
        Node* temp = m_cache[key];
        deleteNode(temp);
        temp->value = value;
        addNode(temp);
        m_cache[key] = head -> next;
    }
    else
    {
        if(m_cache.size() == m_capacity)
        {
            Node* prev = tail ->prev;
            deleteNode(prev);
            Node* temp = new Node(key,value);
            addNode(temp);
            m_cache.erase(prev -> key);
            m_cache[key] = head -> next;
        }
        else
        {
            Node* temp = new Node(key, value);
            addNode(temp);
            m_cache[key] = head -> next;
        }
    }
    
}
void LRUCache::printAllValues() const
{
    if(head -> next == tail)
    {
        return;
    }
    for(auto it = head -> next; it != tail; it = it->next)
    {
        std::cout<< it -> value << ' ';
    }
}
