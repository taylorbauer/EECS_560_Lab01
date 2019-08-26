Lab1: main.o DoublyLinkedList.o Node.o
	g++ main.o DoublyLinkedList.o Node.o -o Lab1
main.o: main.cpp DoublyLinkedList.h Node.h
	g++ -c main.cpp
DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -c DoublyLinkedList.cpp
Node.o: Node.cpp Node.h
	g++ -c Node.cpp
clean:
	rm -f test *.o