/*

	Declare struct
	Template format --- can use like personal library
*/
#ifndef TEMPLATE_H_
#define TEMPLATE_H_

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

template<typename type>
void mySwap(type value1, type value2) {
	type temp = value1;
	value1 = value2;
	value2 = temp;
}

// Node for Singly Linked List
template<typename type>
struct SinglyNode {
	type data;
	SinglyNode* next;
};

// Node for Doubly Linked List
template<typename type>
struct DoublyNode {
	type data;
	DoublyNode* prev;
	DoublyNode* next;
};

// Binary Search Tree Node for node of a binarytree
template<typename type>
struct BSTNode {
	type data;
	BSTNode* left;
	BSTNode* right;
};

#endif // !TEMPLATE_H_