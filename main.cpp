#include "DoublyLinkedList.h"
#include "Node.h"
#include "Menu.h"

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2){
        cout << "Please include a file containing a list of integers.\n";
    }

    DoublyLinkedList myList;

    fstream myFile;
    myFile.open(argv[1]);

    int value;
    if (myFile.is_open()){
        while (myFile >> value){
            myList.insert(value);
        }
    }
    else {
        cout << "Error opening file\n";
    }

    // The following lines were used for early testing
    // cout << "Your first value is " << myList.getFirst()->getValue() << '\n';
    // cout << "Your last value is " << myList.getLast()->getValue() << '\n';

    Menu myMenu(myList);
    myMenu.run();

    return 0;

}