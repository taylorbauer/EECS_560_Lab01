#ifndef MENU_H
#define MENU_H
#include "DoublyLinkedList.h"

class Menu{
public:
    Menu(DoublyLinkedList list);
    void run();
private:
    DoublyLinkedList m_list;
    int selection;
};

#endif