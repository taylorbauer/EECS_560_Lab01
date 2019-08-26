#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(DoublyLinkedList list){
    selection = 0;
    m_list = list;
}

void Menu::run() {
    int insertion;
    int deletion;
    while (selection != 9) {
        cout << "Choose one operation from the options below:\n";
        cout << "   1.  Insert\n";
        cout << "   2.  Delete\n";
        cout << "   3.  Find smallest number\n";
        cout << "   4.  Find largest number\n";
        cout << "   5.  Average of numbers\n";
        cout << "   6.  Merge two lists\n";
        cout << "   7.  Print\n";
        cout << "   8.  Reverse list\n";
        cout << "   9.  Exit\n\n";
        cout << "Your selection (1-9): ";

        cin >> selection;

        // Insert
        if (selection == 1){
            cout << "What number would you like to insert? ";
            cin >> insertion;
            m_list.insert(insertion);
        }

        // Delete
        else if (selection == 2){
            cout << "What number would you like to delete? ";
            cin >> deletion;
            if(m_list.remove(deletion)){
                cout << "Deletion successfull!\n";
            }
            else {
                cout << "Unable to delete " << deletion << " from the list.  Make sure it's even in there!\n";
            }
        }

        // Smallest
        else if (selection == 3){
            if (m_list.getSize() < 1) {
                cout << "Make sure your list is populated!";
            }
            else {
                cout << "Smallest value is: " << m_list.smallest() << '\n';
            }
        }

        // Largest
        else if (selection == 4){
            
        }

        // Average
        else if (selection == 5){
            
        }

        // Merge
        else if (selection == 6){
            
        }

        // Print
        else if (selection == 7){
            m_list.print();
        }

        // Reverse
        else if (selection == 8){
            
        }
    }
    cout << "Goodbye!\n";
    return;
}