/*
	Class of Stack store in Array and Stack Singly Linked List
	Tested and run fine---3/11/2022 (Month/Day/Year)
	Template format --- can use like personal library
*/
#ifndef STACK_H_
#define STACK_H_

#include"linkedList.h"
#include"template.h"

#define MAX_SIZE_STACK 100

// stack use array
template<typename type>
class StackArray {
private:
	type stack[MAX_SIZE_STACK];
	int top_stack;
public:
	StackArray() {
		top_stack = -1;
	}
	int getTopIndex() {
		return top_stack; //start from 0
	}
	void push(type value) {
		if (isFull()) {
			cout << "Already full!" << endl;
			return;
		}
		top_stack++;
		stack[top_stack] = value;
	}
	void pop() {
		if (isEmpty()) {
			cout << "Already empty!" << endl;
			return;
		}
		top_stack--;
	}
	type getTop() {
		return stack[top_stack];
	}
	bool isEmpty() {
		if (top_stack == -1) return true;
		else return false;
	}
	bool isFull() {
		if (top_stack == MAX_SIZE_STACK) return true;
		else return false;
	}
	void print() { // print from bottom of stack (left) to the top (-->right)
		for (int i = 0; i <= top_stack; i++) {
			cout << stack[i] << " ";
		}
		cout << endl;
	}
};

//stack use Singly Linked List
template<typename type>
class StackLL {
private:
	SinglyLinkedList<type> ll; // like head
public:
	StackLL() {
	}
	int getLength() {
		return ll.getLength(); // start from 1
	}
	void push(type value) { //push into head of linked list
		ll.insertHead(value);
	}
	void pop() {
		ll.deleteHead();
	}
	SinglyNode<type>* getTop() {
		return ll.getHead();
	}
	//print from bottom to top of stack (from tail to head of linked list)
	void print() {
		ll.reversePrint_useRecurtion(ll.getHead());
	}
};

#endif // !STACK_H_
