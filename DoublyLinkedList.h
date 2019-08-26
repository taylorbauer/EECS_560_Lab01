#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Node.h"

class DoublyLinkedList
{
public:
    DoublyLinkedList();
    int getSize();
    bool insert(int value);
    bool isEmpty();
    Node* getFirst(); // temporary, used for testing
    Node* getLast(); // same here
    void print();
    bool remove(int value);
    int smallest();
private:
    Node* m_first;
    Node* m_last;
    int m_size;
};

#endif