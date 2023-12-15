/*
	Test BinarySearchTree.h // tested
*/
#include"BinarySearchTree.h"

using namespace std;

//for BST: Binary search root
//child left is always less or equal its parent
//child in the right is alway greater than its parent


int main() {
	BinarySearchTree<int> bst;
	int number, val;
	cout << "How many elements: ";
	cin >> number;
	for (int i = 0; i < number; i++) {
		cout << "Value " << i + 1 << ": ";
		cin >> val;
		bst.insert(val);
	}
	
	//*************test travelsal
	cout << "Travelsal Level Order: ";
	bst.travelsal_levelOrder();
	cout << endl << "Travelsal Level Order use Recurtion: ";
	bst.travelsal_levelOrder_useRecurtion(bst.getRoot());
	cout << endl;
	cout << "Travelsal InOrder: ";
	bst.travelsal_inOrder(bst.getRoot());
	cout << endl;
	cout << "Travelsal PostOrder: ";
	bst.travelsal_postOrder(bst.getRoot());
	cout << endl;
	cout << "Travelsal PreOrder: ";
	bst.travelsal_preOrder(bst.getRoot());
	cout << endl;

	//************test return min, max of tree
	cout << "Min: " << bst.returnMin() << endl;
	cout << "Max: " << bst.returnMax() << endl;
	cout << "Search for value: 9" << endl;
	
	//************test search value of tree, root s L-0 (level 0 or depth = 0
	bst.search(bst.getRoot(), 9);

	//************check if bst is really a BST, it's external function, not inside class
	if (isBinarySearchTree(bst.getRoot())) cout << "True!" << endl;
	else cout << "False" << endl;

	//************delete element
	//BSTNode<int>* travel = 	bst.deleteElements(bst.getRoot(), 5); // delete function return NULL ??
	cout << "After delete value 5: ";
	bst.travelsal_levelOrder_useRecurtion(bst.deleteElements(bst.getRoot(), 5));
	return 0;
}
