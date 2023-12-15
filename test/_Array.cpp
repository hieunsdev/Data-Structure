#include "array.h"

int main() {
	DynamicArray<int> da;
	int value;
	cout << "Set size of array: ";
	cin >> value;
	da.setSize(value);
	
	// check each space empty ?
	da.checkSpace();
	
	// check all array is empty ?
	cout << "Is empty: ";
	if (da.isAllEmpty()) cout << "True" << endl;
	else cout << "False" << endl;

	//************test insert
	//da.insertPosition(2, 5);
	//da.insertPosition(2, 6);
	//da.insertPosition(3, 8);
	for (int i = 0; i < da.getLength(); i++) {
		cout << "Value in position " << i << ": ";
		cin >> value;
		da.insertPosition(i, value);
	}
	da.checkSpace();
	da.print();

	//************test Sort
	//da.selectionSort();
	//da.insertSort();
	//da.bubbleSort();
	da.merge_sort(0, da.getLength() - 1);
	da.print();
	return 0;
}