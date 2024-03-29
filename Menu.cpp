#include "Menu.h"
#include <iostream>
#include <sstream>
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

        if(cin.fail()){
            cin.ignore();
            selection = 0;
        }

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
                cout << "\nDeletion successfull!\n";
            }
            else {
                cout << "\nUnable to delete the value " << deletion << " from the list.  Make sure it's even in there!\n\n";
            }
        }

        // Smallest
        else if (selection == 3){
            if (m_list.getSize() < 1) {
                cout << "\nMake sure your list is populated!\n\n";
            }
            else {
                cout << "Smallest value is: " << m_list.smallest() << "\n\n";
            }
        }

        // Largest
        else if (selection == 4){
            if (m_list.getSize() < 1) {
                cout << "\nMake sure your list is populated!\n\n";
            }
            else {
                cout << "Largest value is: " << m_list.largest() << "\n\n";
            }
            
        }

        // Average
        else if (selection == 5){
            if (m_list.getSize() < 1) {
                cout << "\nMake sure your list is populated!\n\n";
            }
            else {
                cout << "\nAverage of list is: " << m_list.average() << "\n\n";
            }
        }

        // Merge
        else if (selection == 6){
            cin.ignore();
            char newListChars[256];
            cout << "\nType out the list you would like to merge.  Make sure each integer is separated by a space:\n";
            cin.getline(newListChars, 256);

            // Converting user input to stringstream
            string newListString(newListChars);
            DoublyLinkedList* userList = new DoublyLinkedList;
            if (newListString != "") {
                stringstream listStream;
                listStream << newListString;

                // Converting stringstream to new list
                int tempValue;
                while(!listStream.eof()) {
                    listStream >> tempValue;
                    userList->insert(tempValue);
                }
            }
            m_list.merge(userList);
        }

        // Print
        else if (selection == 7){
            m_list.print();
        }

        // Reverse
        else if (selection == 8){
            if (m_list.reverse()) {
                cout << "\nList successfully reversed.\n\n";
            }
            else
            {
                cout << "\nUnable to reverse list, make sure it is populated!\n\n";
            }
            
        }

        else{
            cout << "\nThat's not a valid selection! Please try again.\n\n";
        }
    }
    cout << "\nGoodbye!\n\n";
    return;
}