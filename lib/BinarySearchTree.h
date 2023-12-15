/*
	Class of Binary Search Tree, and chack is Binayry Search Tree ?
	Tested and run fine---3/16/2022 (Month/Day/Year)
	Template format --- can use like personal libruary
*/
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "template.h"
#include "queue.h"

using namespace std;

template<typename type>
class BinarySearchTree {
private:
	BSTNode<type>* root;
public:
	BinarySearchTree() {
		root = NULL;
	}
	BSTNode<type>* getRoot() {
		return root;
	}
	BSTNode<type>* newBSTNode(type value) {
		BSTNode<type>* newNode = new BSTNode<type>;
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	void insert(type value) {
		BSTNode<type>* insert = newBSTNode(value);
		if (root == NULL) {
			root = insert;
			return;
		}
		BSTNode<type>* travel = root;
		while (travel != NULL) {
			if (value <= travel->data) {
				if (travel->left == NULL) {
					travel->left = insert;
					return;
				}
				else {
					travel = travel->left;
					continue;
				}
			}
			if (value > travel->data) {
				if (travel->right == NULL) {
					travel->right = insert;
					return;
				}
				else {
					travel = travel->right;
					continue;
				}
			}
		}
	}
	BSTNode<type>* insert_useRecurtion(BSTNode<type>* travel, type value) {
		if (travel == NULL) {
			travel = newBSTNode(value);
		}
		else if (travel->data <= value) travel->left = insert_useRecurtion(travel->left, value);
		else travel->right = insert_useRecurtion(travel->right, value);
		return travel;
	}
	void search(BSTNode<type>* travel, type value) {
		static int depth = 0;
		if (travel == NULL) {
			cout << "Search done !!" << endl;
			return;
		}
		if (value < travel->data) {
			depth += 1;
			search(travel->left, value);
		}
		else if (value > travel->data) {
			depth += 1;
			search(travel->right, value);
		}
		else {
			cout << "In depth (level) " << depth << " found the value " << value << endl;
			depth += 1;
			search(travel->left, value);
		}
	}
	type returnMin() {
		if (root == NULL) return 0;
		BSTNode<type>* travel = root;
		while (travel->left != NULL) {
			travel = travel->left;
		}
		return travel->data;
	}
	BSTNode<type>* findMin_useRecurtion(BSTNode<type>* travel) {
		if (travel == NULL) return NULL;
		if (travel->left == NULL) return travel;
		findMin_useRecurtion(travel->left);
	}
	type returnMax() {
		if (root == NULL) return 0;
		BSTNode<type>* travel = root;
		while (travel->right != NULL) {
			travel = travel->right;
		}
		return travel->data;
	}
	BSTNode<type>* findMax_useRecurtion(BSTNode<type>* travel) {
		if (travel == NULL) return NULL;
		if (travel->right == NULL) return travel;
		findMax_useRecurtion(travel->right);
	}
	//replace the deleted node by its right node. So we just must only fix link of right sub tree
	BSTNode<type>* deleteElements(BSTNode<type>* travel, type value) {  // still not working
		if (travel == NULL) return travel;
		else if (value < travel->data) deleteElements(travel->left, value);
		else if (value > travel->data) deleteElements(travel->right, value);
		else {
			// case 2 NULL (leaf of tree)
			if (travel->left == NULL && travel->right == NULL) {
				travel == NULL;
				delete travel;
			}
			// case 1 NULL
			else if (travel->left == NULL) {
				travel->data = travel->right->data; // replace the deleted node by its own right node
				travel->right = NULL;
				delete travel->right;
			}
			else if (travel->right == NULL) {
				travel->data = travel->left->data; // replace the deleted node by its own right node
				travel->left = NULL; // is neccessary ?
				delete travel->left;
			}
			else {
				BSTNode<type>* temp = findMin_useRecurtion(travel->right);
				travel->data = temp->data;
				travel->right = deleteElements(travel->right, temp->data);
			}
		}
		return travel;
	}
	void travelsal_levelOrder() {
		if (root == NULL) return;
		QueueLL<BSTNode<type>*> q;
		q.enQueue(root);
		while (!q.isEmpty()) {
			BSTNode<type>* travel = q.frontQueue()->data;
			cout << travel->data << " ";
			if (travel->left != NULL) q.enQueue(travel->left);
			if (travel->right != NULL) q.enQueue(travel->right);
			q.deQueue();
		}
	}
	void travelsal_levelOrder_useRecurtion(BSTNode<type>* travel) {
		if (travel == NULL) return;
		static QueueLL<BSTNode<type>*> q;
		cout << travel->data << " ";
		if (travel->left != NULL) q.enQueue(travel->left);
		if (travel->right != NULL) q.enQueue(travel->right);
		if (!q.isEmpty()) {
			BSTNode<type>* current = q.frontQueue()->data;
			q.deQueue();
			travelsal_levelOrder_useRecurtion(current);
		}
	}
	void travelsal_preOrder(BSTNode<type>* travel) { //DLR -- Data Left -Right
		if (travel == NULL) return;
		cout << travel->data << " ";
		travelsal_preOrder(travel->left);
		travelsal_preOrder(travel->right);
	}
	void travelsal_inOrder(BSTNode<type>* travel) { // LDR -- Left Data Right
		if (travel == NULL) return;
		travelsal_inOrder(travel->left);
		cout << travel->data << " ";
		travelsal_inOrder(travel->right);
	}
	void travelsal_postOrder(BSTNode<type>* travel) { // LRD -- Left Right Data
		if (travel == NULL) return;
		travelsal_postOrder(travel->left);
		travelsal_postOrder(travel->right);
		cout << travel->data << " ";
	}

};

template<typename type>
bool isSubTreeLesser(BSTNode<type>* travel, type value) {
	if (travel == NULL) return true;
	if (travel->data <= value
		&& isSubTreeLesser(travel->left, value) // check two branches of this element right after IBST function
		&& isSubTreeLesser(travel->right, value)) { // the right branch of this node (element)
		return true;
	}
	else return false;
}

template<typename type>
bool isSubTreeGreater(BSTNode<type>* travel, type value) {
	if (travel == NULL) return true;
	if (travel->data > value
		&& isSubTreeGreater(travel->left, value) // check two branches of this element right after IBST function
		&& isSubTreeGreater(travel->right, value)) { // the right branch of this node (element)
		return true;
	}
	else return false;
}

template<typename type>
bool isBinarySearchTree(BSTNode<type>* check) {
	if (check == NULL) return true;
	if (isSubTreeLesser(check->left, check->data)
		&& isSubTreeGreater(check->right, check->data)
		&& isBinarySearchTree(check->left)
		&& isBinarySearchTree(check->right)) {
		return true;
	}
	else return false;
}

#endif