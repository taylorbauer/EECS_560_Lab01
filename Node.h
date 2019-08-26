#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(int value);
    int getValue();
    Node* getNext();
    void setNext(Node* next);
    Node* getPrev();
    void setPrev(Node* prev);

private:
    int m_value;
    Node* m_prev;
    Node* m_next;
    
};

#endif