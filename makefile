Lab1: main.o DoublyLinkedList.o Node.o Menu.o
	g++ -std=c++11 main.o DoublyLinkedList.o Node.o Menu.o -o Lab1
main.o: main.cpp DoublyLinkedList.h Node.h
	g++ -std=c++11 -c main.cpp
DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -std=c++11 -c DoublyLinkedList.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
Menu.o: Menu.cpp Menu.h
	g++ -std=c++11 -c Menu.cpp
clean:
	rm -f test *.o