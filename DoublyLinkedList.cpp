#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    m_size = 0;
    m_first = nullptr;
    m_last = nullptr;
}

int DoublyLinkedList::getSize(){
    return m_size;
}

bool DoublyLinkedList::insert(int value){
    Node* tempNode = new Node(value);
    if (isEmpty()){
        m_first = tempNode;
        m_last = tempNode;
    }
    else{
        tempNode->setPrev(m_last);
        m_last->setNext(tempNode);
        m_last = tempNode;
    }

    m_size ++;
    return true;
}

bool DoublyLinkedList::isEmpty(){
    if (m_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

Node* DoublyLinkedList::getFirst(){
    return m_first;
}

Node* DoublyLinkedList::getLast(){
    return m_last;
}