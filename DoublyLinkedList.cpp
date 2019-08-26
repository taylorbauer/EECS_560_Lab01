#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

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

void DoublyLinkedList::print(){
    if (isEmpty()) {
        cout << "The list is empty!\n";
        return;
    }

    Node* tempPtr = m_first;
    cout << '\n';
    for (int i = 0; i < m_size; i++) {
        cout << tempPtr->getValue() << ' ';
        tempPtr = tempPtr->getNext();
    }
    cout << "\n\n";
}

bool DoublyLinkedList::remove(int value){
    Node* nodePtr = m_first;
    int nodeCount = 0;
    for (int i = 0; i < m_size; i++){
        if (nodePtr->getValue() == value){
            if (nodeCount == 0 && m_size == 1){
                m_first = nullptr;
                m_last = nullptr;
            }
            else if (nodeCount == 0){
                cout << "I think it's at the beginning";
                m_first = m_first->getNext();
                m_first->setPrev(nullptr);
            }
            else if (nodeCount == (m_size - 1)){
                cout << "I think it's at the end";
                m_last = m_last->getPrev();
                m_last->setNext(nullptr);
            }
            else {
                nodePtr->getPrev()->setNext(nodePtr->getNext());
                nodePtr->getNext()->setPrev(nodePtr->getPrev());
            }

            delete[] nodePtr;

            m_size --;
            return true;
        }
        
        nodeCount ++;
        nodePtr = nodePtr->getNext();
    }
    return false;
}