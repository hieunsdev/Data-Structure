/*
	Class of Singly Linked List and Doubly Linked List
	Tested and run fine---3/11/2022 (Month/Day/Year)
	Template format --- can use like personal library
*/
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include"template.h"

template<typename type>
class SinglyLinkedList {
private:
	SinglyNode<type>* head;
public:
	SinglyLinkedList() {
		head = NULL;
	}
	int getLength() {
		if (head == NULL) return 0;
		int count = 0;
		SinglyNode<type>* travel = head;
		while (travel != NULL) {
			travel = travel->next;
			count += 1;
		}
		return count;
	}
	SinglyNode<type>* getHead() {
		return head;
	}
	SinglyNode<type>* newSinglyNode(type value) {
		SinglyNode<type>* newNode = new SinglyNode<type>;
		newNode->data = value;
		newNode->next = NULL;
		return newNode;
	}
	void insertHead(type value) {
		SinglyNode<type>* insert = newSinglyNode(value);
		if (head != NULL) insert->next = head;
		head = insert;
	}
	void insertPosition(type value, int position) {
		int length = getLength();
		if (position == 1) {
			insertHead(value);
			return;
		}
		if (position > length + 1 || position <= 0) {
			cout << "Curent length of linked list: " << length << endl;
			return;
		}
		SinglyNode<type>* insert = newSinglyNode(value);
		SinglyNode<type>* travel = head;
		for (int i = 0; i < position - 2; i++) {
			travel = travel->next;
		}
		insert->next = travel->next;
		travel->next = insert;
	}
	void insertTail(type value) {
		SinglyNode<type>* insert = newSinglyNode(value);
		if (head == NULL) head = insert;
		else {
			SinglyNode<type>* travel = head;
			while (travel->next != NULL) {
				travel = travel->next;
			}
			travel->next = insert;
		}
	}
	void deleteHead() {
		if (head == NULL) return;
		SinglyNode<type>* travel = head;
		head = travel->next;
		delete travel;
	}
	void deletePosition(int position) {
		if (head == NULL) return;
		int length = getLength();
		if (position == 1) {
			deleteHead();
			return;
		}
		if (position > length || position <= 0) {
			cout << "Curent length of linked list: " << length << " ,start from 1" << endl;
			return;
		}
		SinglyNode<type>* travel1 = head;
		for (int i = 0; i < position - 2; i++) {
			travel1 = travel1->next; // point to (n-1)th element
		}
		SinglyNode<type>* travel2 = travel1->next; // travel2 point to nth element
		travel1->next = travel2->next; // fix the link
		delete travel2; // delete nth element
	}
	void deleteTail() {
		if (head == NULL) return;
		SinglyNode<type>* travel = head;
		while (travel->next->next != NULL) {
			travel = travel->next;
		}
		delete travel->next;
		travel->next = NULL;
	}
	void reverse() {
		if (head == NULL) return;
		SinglyNode<type>* prev, * current, * n_next;
		current = head;
		prev = NULL;
		while (current != NULL) {
			n_next = current->next;
			current->next = prev;
			prev = current;
			current = n_next;
		}
		head = prev;
	}
	// How to use: reverse_useRecurtion("name of class SLL".getHead());
	void reverse_useRecurtion(SinglyNode<type>* travel) {
		if (travel == NULL) return;
		if (travel->next == NULL) {
			head = travel;
			return;
		}
		reverse_useRecurtion(travel->next);
		travel->next->next = travel;
		travel->next = NULL;
	}
	void print() {
		if (head == NULL) {
			cout << "NULL" << endl;
			return;
		}
		SinglyNode<type>* travel = head;
		while (travel != NULL) {
			cout << travel->data << " ";
			travel = travel->next;
		}
		cout << endl;
	}
	// How to use: "name of class SLL".print_useRecursion("name of class SLL".getHead());
	// just print, dont change the link
	void print_useRecurtion(SinglyNode<type>* travel) {
		if (travel == NULL) {
			cout << endl;
			return;
		}
		cout << travel->data << " ";
		print_useRecurtion(travel->next);
	}
	// How to use: "name of class SLL".reversePrint_useRecursion("name of class SLL".getHead());
	// just print, dont reverse the linked list
	void reversePrint_useRecurtion(SinglyNode<type>* travel) {
		if (travel == NULL) {
			cout << endl;
			return;
		}
		reversePrint_useRecurtion(travel->next);
		cout << travel->data << " ";
	}
};

template<typename type>
class DoublyLinkedList {
private:
	DoublyNode<type>* head;
public:
	DoublyLinkedList() {
		head = NULL;
	}
	DoublyNode<type>* getHead() {
		return head;
	}
	int getLength() {
		if (head == NULL) return 0;
		DoublyNode<type>* travel = head;
		int count = 0;
		while (travel != NULL) {
			travel = travel->next;
			count += 1;
		}
		return count;
	}
	DoublyNode<type>* newDoublyNode(type value) {
		DoublyNode<type>* newNode = new DoublyNode<type>;
		newNode->data = value;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
	void insertHead(type value) {
		DoublyNode<type>* insert = newDoublyNode(value);
		if (head != NULL) {
			head->prev = insert;
			insert->next = head;
		}
		head = insert;
	}
	void insertPosition(type value, int position) {
		int length = getLength();
		if (position == 1) {
			insertHead(value);
			return;
		}
		if (position > length + 1 || position < 0) {
			cout << "Current length of Doubly linked list: " << length << endl;
			return;
		}
		DoublyNode<type>* insert = newDoublyNode(value);
		DoublyNode<type>* travel = head;
		for (int i = 0; i < position - 2; i++) {
			travel = travel->next;
		}
		insert->next = travel->next;
		if (travel->next != NULL) travel->next->prev = insert;
		travel->next = insert;
		insert->prev = travel;
	}
	void insertTail(type value) {
		DoublyNode<type>* insert = newDoublyNode(value);
		if (head == NULL) head = insert;
		else {
			DoublyNode<type>* travel = head;
			while (travel->next != NULL) {
				travel = travel->next;
			}
			travel->next = insert;
			insert->prev = travel;
		}
	}
	void deleteHead() {
		if (head == NULL) return;
		DoublyNode<type>* travel = head;
		head = travel->next;
		travel->next->prev = NULL;
		delete travel;
	}
	void deletePosition(int position) {
		int length = getLength();
		if (position == 1) {
			deleteHead();
			return;
		}
		if (position > length || position < 0) {
			cout << "Current length of Doubly linked list: " << length << endl;
			return;
		}
		DoublyNode<type>* travel = head;
		for (int i = 0; i < position - 2; i++) {
			travel = travel->next;
		}
		DoublyNode<type>* temp = travel->next;
		travel->next = temp->next;
		temp->next->prev = travel;
		delete temp;
	}
	void deleteTail() {
		if (head == NULL) return;
		DoublyNode<type>* travel = head;
		while (travel->next->next != NULL) {
			travel = travel->next;
		}
		travel->next->prev = NULL;
		delete travel->next;
		travel->next = NULL;
	}
	// dont need to fix the link, just reverse the data
	void reverse() {
		if (head == NULL) return;
		DoublyNode<type>* travelH = head; // travelHead, run from head to tail
		DoublyNode<type>* travelT = head; // travelTail, run from tail to head
		type temp; // temporary variable to swap data
		int length = getLength();
		while (travelT->next != NULL) {
			travelT = travelT->next;
		}
		for (int i = 0; i < (length / 2); i++) {
			temp = travelH->data;
			travelH->data = travelT->data;
			travelT->data = temp;
			travelH = travelH->next;
			travelT = travelT->prev;
		}
	}
	void print() {
		if (head == NULL) {
			cout << "NULL" << endl;
			return;
		}
		DoublyNode<type>* travel = head;
		while (travel != NULL) {
			cout << travel->data << " ";
			travel = travel->next;
		}
		cout << endl;
	}
	//How to use: "name of DLL class".print_useRecurtion("name of DLL class".getHead());
	// DLL: Doubly Linked List
	void print_useRecurtion(DoublyNode<type>* travel) {
		if (travel == NULL) {
			cout << endl;
			return;
		}
		cout << travel->data << " ";
		print_useRecurtion(travel->next);
	}
	// just print, dont fix link
	//How to use: "name of DLL class".reversePrint_useRecurtion("name of DLL class".getHead());
	// DLL: Doubly Linked List
	void reverseprint_useRecurtion(DoublyNode<type>* travel) {
		if (travel == NULL) {
			cout << endl;
			return;
		}
		reverseprint_useRecurtion(travel->next);
		cout << travel->data << " ";
	}
};

#endif // !LINKEDLIST_H_
