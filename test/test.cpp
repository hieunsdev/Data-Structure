#include<iostream>

using namespace std;

int* change(int* a) {
	a = new int(5);
	cout << a << endl;
	return a;
}

int* sum(int* a, int* b) {
	cout << "address of a: " << a << endl;
	*a = 3;
	int* c = new int(*a + *b);
	return c;
}

int* realloc(int* arr, int oldSize, int newSize) {
	int* temp = new int[newSize];
	for (int i = 0; i < oldSize; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = NULL;
	return temp;
}

int main() {
	//	int value = 6;
	//	int *b = &value;
	//	b  = change(b);
	//	cout<<*b<<"at: "<<b;

	//	int operator1 = 1;
	//	int *ptr1 = &operator1;
	//	cout<<"Address of ptr1: "<<ptr1<<endl;
	//	int operator2 = 5;
	//	int *c = sum(ptr1, &operator2);
	//	cout<<operator1<<". And sum: "<<*c;

	int* test = new int[6];
	for (int i = 0; i < 6; i++) {
		test[i] = i;
		cout << test + i << " .Value: " << test[i] << endl;
	}

	int* ptr1 = test + 2;
	cout << "Address ptr1: " << ptr1 << " .Value: " << *ptr1 << endl;

	cout << "Realloc coming..." << endl;
	test = realloc(test, 6, 8);
	for (int i = 0; i < 8; i++) {
		//test[i] = i + 10;
		cout << test + i << " .Value: " << *(test + i) << endl;
	}
	*(test + 6) = 6;
	*(test + 7) = 7;
	cout << "Address ptr1: " << ptr1 << " .Value: " << *ptr1 << endl;

	int* ptr = test + 6;
	cout << "Address ptr: " << ptr << " .Value: " << *ptr << endl;

	cout << "Second Realloc is coming..." << endl;
	test = realloc(test, 8, 10);
	for (int i = 0; i < 10; i++) {
		//test[i] = i + 30;
		cout << test + i << " .Value: " << *(test + i) << endl;
	}
	cout << "Address ptr: " << ptr << " .Value: " << *ptr << endl;
	return 0;
}