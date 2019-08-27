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
            if (m_size == 1){
                m_first = nullptr;
                m_last = nullptr;
            }
            else if (nodeCount == 0){
                m_first = m_first->getNext();
                m_first->setPrev(nullptr);
            }
            else if (nodeCount == (m_size - 1)){
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

int DoublyLinkedList::smallest(){
    Node* nodeTracker = m_first;
    int smallest = nodeTracker->getValue();
    nodeTracker = nodeTracker->getNext();
    for (int i = 1; i < m_size; i ++) {
        if (nodeTracker->getValue() < smallest){
            smallest = nodeTracker->getValue();
        }
        nodeTracker = nodeTracker->getNext();
    }
    return smallest;
}

int DoublyLinkedList::largest(){
    Node* nodeTracker = m_first;
    int largest = nodeTracker->getValue();
    nodeTracker = nodeTracker->getNext();
    for (int i = 1; i < m_size; i ++) {
        if (nodeTracker->getValue() > largest){
            largest = nodeTracker->getValue();
        }
        nodeTracker = nodeTracker->getNext();
    }
    return largest;
}

float DoublyLinkedList::average(){
    int sum = 0;
    Node* nodeTracker = m_first;
    for (int i = 0; i < m_size; i++) {
        sum = sum + nodeTracker->getValue();
        nodeTracker = nodeTracker->getNext();
    }
    return ((float)sum / m_size);
}

bool DoublyLinkedList::reverse(){
    if (m_size < 1){
        return false;
    }
    else {
        Node* nodeTracker = m_last;
        int lastValue = 0;
        int staticSize = m_size;  // Forces our loop to work
        for (int i = 0; i < staticSize; i++) {
            insert(nodeTracker->getValue());
            nodeTracker = nodeTracker->getPrev();
        }
        for (int i = 0; i < staticSize; i++) {
            remove(m_first->getValue());
        }
        return true;
    }
}