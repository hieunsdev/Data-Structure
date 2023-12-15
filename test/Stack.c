#include<stdio.h>

#define MAX_SIZE_STACK 101
int a[MAX_SIZE_STACK];

//use pointer 
int* pointer = a; // &a[0] ~ position -1 

void pop() {
	if (pointer == &a[0]) {
		printf("From called function pop(): Already empty !\n");
		return;
	}
	else pointer--;
}

void push(int value) {
	pointer++;
	*pointer = value;
}

void top() {
	printf("Top of stac: %d\n", *pointer);
}

void IsEmpty() {
	if (pointer == &a[0]) {
		printf("Stack is empty!\n");
	}
	else {
		printf("Stack still has element\n");
	}
}

void printStack() {
	int i = 0;
	if (pointer == &a[0]) {
		printf("Stack is empty now!");
	}
	else {
		printf("Stack right now:");
		while (pointer != &a[i]) {
			printf(" %d ", a[i+1]);
			i++;
		}
	}
}

// use argument easier
//int top_argu = -1;
//void push(int value) {
//	top_argu += 1;
//	a[top_argu] = value;
//}
//
//void pop() {
//	top_argu -= 1;
//}
//
//void top() {
//	printf("Top of the stack: %d\n", a[top_argu]);
//}
//
//void IsEmpty() {
//	if (top_argu == -1) {
//		printf("Stack is empty!");
//	}
//	else printf("Stack still has elements");
//}
//
//void printStack() {
//	if (top_argu == -1) {
//		printf("Stack is empty!\n");
//	}
//	else {
//		printf("Stack right now:");
//		for (int i = 0; i <= top_argu; i++) {
//			printf(" %d ", a[i]);
//		}
//		printf("\n");
//	}
//}

int main() {
	push(4);
	push(5);
	push(1);
	pop();
	top();
	printStack();
	return 0;
}