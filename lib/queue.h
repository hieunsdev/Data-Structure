/*
	Class of Queue use Ring algorithm and Queue use Singly Linked List
	Tested and run fine---3/11/2022 (Month/Day/Year)
	Template format --- can use like personal library
*/
#ifndef QUEUE_H_
#define QUEUE_H_

#include"template.h"
#include"linkedList.h"

//use ring algorithm
template<typename type>
class QueueRing {
private:
	type* front;
	type* rear;
	int size;
	type* ring;
public:
	QueueRing() {
		cout << "Please set size of ring!! By using QueueRing<data type>(size_of_ring);" << endl;
		system("pause");
	}
	QueueRing(int size_ring) {
		size = size_ring;
		ring = new type[size];
		front = ring;
		rear = ring;
		*front = NULL; // *rear = NULL; as well without define
	}
	void increase_pointer(type** pointer) { // to guarantee ring 
		if (*pointer == &ring[size - 1]) *pointer = &ring[0];
		else *pointer += 1;
	}
	void enQueue(type value) {
		if (isFull()) {
			cout << "Already full!" << endl;
			return;
		}
		else if (isEmpty()) {
			*front = value;
		}
		else {
			increase_pointer(&rear);
			*rear = value;
		}
	}
	void deQueue() {
		if (isEmpty()) {
			cout << "Already empty!" << endl;
			return;
		}
		else if (front == rear) {
			*front = NULL;
			return;
		}
		else increase_pointer(&front);
	}
	type frontQueue() {
		return *front;
	}
	void print() {
		type* travel = front;
		if (rear == front && *front == NULL) {
			cout << "Queue is empty!";
		}
		else {
			while (travel != rear + 1) { // rear + 1 to print when travel == rear
				cout << *travel << " ";
				travel++;
			}
		}
		cout << endl;
	}
	bool isFull() {
		if (rear + 1 == front) return true;
		else if (rear == &ring[size - 1] && front == &ring[0]) return true;
		else return false;
	}
	bool isEmpty() { // not really is empty, it's just a condition to make sure rear cant be behind front without having front value 
		if (rear == front && *front == NULL) return true;
		else return false;
	}
};

template<typename type>
class QueueLL {
private:
	SinglyLinkedList<type> ll;
public:
	QueueLL() {
	}
	void enQueue(type value) {
		ll.insertTail(value);
	}
	void deQueue() {
		ll.deleteHead();
	}
	SinglyNode<type>* frontQueue() { // return the whole SinglyNode
		return ll.getHead();
	}
	bool isEmpty() {
		if (ll.getLength() == 0) return true;
		else return false;
	}
	void print() { // from head to tail, head is Firt in and First out as well
		ll.print();
	}
	int getLength() {
		return ll.getLength();
	}
};

#endif // !QUEUE_H_
