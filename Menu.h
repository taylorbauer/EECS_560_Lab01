#ifndef MENU_H
#define MENU_H
#include "DoublyLinkedList.h"

//  The menu class is constructed with a DoublyLinkedList parameter and handles
//  all user interaction and manipulation of list
class Menu{
public:

    //  @pre None.
    //  @param list - the linked list passed to the menu object to be operated on by the menu
    //  @post A menu object is created containing a member DoublyLinkedList
    Menu(DoublyLinkedList list);

   //   @pre None.
   //   @post The menu's run() method begins operation of user interface
    void run();
private:
    DoublyLinkedList m_list;
    int selection;
};

#endif