#include<stdio.h>

// Doubly Linked List

struct doublyNode {
	int data;
	struct doublyNode* prev;
	struct doublyNode* next;
};

struct doublyNode* newNode(int value) {
	struct doublyNode* temp = (struct doublyNode*)malloc(sizeof(struct doublyNode));
	temp->data = value;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void insertHead_reference(struct doublyNode** phead, int value) {
	struct doublyNode* insert = newNode(value);
	if (*phead == NULL) {
		*phead = insert;
		return;
	}
	insert->next = *phead;
	(*phead)->prev = insert;
	*phead = insert;
}

void insertPos_reference(struct doublyNode** phead,int position, int value) { // not working ???
	struct doublyNode* insert = newNode(value);
	if (position == 1) {
		insert->next = *phead;
		(*phead)->prev = insert;
		*phead = insert;
		return;
	}
	struct doublyNode* travel = *phead;
	for (int i = 0; i < position - 2; i++) {
		travel = travel->next;
	}
	insert->next = travel->next;
	travel->next->prev = insert;
	travel->next = insert;
	insert->prev = travel;
}

void insertTail_reference(struct doublyNode** phead, int value) {
	struct doublyNode* insert = newNode(value);
	if (*phead == NULL) {
		*phead = insert;
		return;
	}
	struct doublyNode* travel = *phead;
	while (travel->next != NULL) {
		travel = travel->next;
	}
	travel->next = insert;
	insert->prev = travel;
}



void printDLL(struct doublyNode* head) {
	struct doublyNode* travel = head;
	printf("List is:");
	while (travel != NULL) {
		printf(" %d ", travel->data);
		travel = travel->next;
	}
	printf("\n");
}

void reversePrintDLL(struct doublyNode *head) {
	struct doublyNode* travel = head;
	printf("List after reversePrintDLL:");
	while (travel->next != NULL) {
		travel = travel->next;
	}
	while (travel != NULL) {
		printf(" %d ", travel->data);
		travel = travel->prev;
	}
	printf("\n");
}

int main() {
	struct doublyNode* head;
	head = NULL;
	int value, number;
	printf("How many number you want to insert? ");
	scanf_s("%d", &number);
	for (int i = 0; i < number; i++) {
		printf("Value: ");
		scanf_s("%d", &value);
		//insertTail_reference(&head, value);
		//insertHead_reference(&head, value);
		//insertPos_reference(&head, i + 1, value); //not working
		printDLL(head);
		//reversePrintDLL(head);
	}
	//reversePrintDLL(head);
	return 0;
}