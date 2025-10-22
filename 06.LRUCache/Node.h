#pragma once
struct Node
{
    int key;
    int value;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int key, int value);
};