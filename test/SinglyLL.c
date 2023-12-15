#include <stdio.h>
#include<string.h>

// Singly Linked List

struct Node {
	int data;
	struct Node* next; // in C++ just Node *next;
};

struct Node* insertHead(struct Node* head, int value) { // return head
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	(*temp).data = value; //or temp->dheadthead = 2;
	(*temp).next = NULL; // or temp->next = NULL;
	if (head != NULL) temp->next = head;
	head = temp;
	return head;
}

struct Node* insertPos(struct Node* head, int position, int value) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;
	struct Node* travel = head;
	if (position == 1) {
		temp->next = head;
		head = temp;
		return;
	}
	for (int i = 0; i < position - 2; i++) { //i=1, i<=position-2 because i=0 or 1 just is how many times travel = travel->next
		travel = travel->next;
	}
	temp->next = travel->next;
	travel->next = temp;
	return head;
}

struct Node* insertTail(struct Node* head, int value) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;
	struct Node* travel = head;
	if (head == NULL) head = temp;
	else {
		while (travel->next != NULL) {
			travel = travel->next;
		}
		travel->next = temp;
	}
	return head;
}

void insertHead_reference(struct Node** phead, int value) { // reference head
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	(*temp).data = value; //or temp->dheadthead = 2;
	(*temp).next = NULL; // or temp->next = NULL;
	if (*phead != NULL) temp->next = *phead;
	*phead = temp;
}

void insertPos_reference(struct Node** phead, int position, int value) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;
	struct Node* travel = *phead;
	if (position == 1) {
		temp->next = *phead;
		*phead = temp;
		return;
	}
	for (int i = 0; i < position - 2; i++) {
		travel = travel->next;
	}
	temp->next = travel->next;
	travel->next = temp;
}

void insertTail_reference(struct Node** phead, int value) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;
	struct Node* travel = *phead;
	if (travel == NULL) *phead = temp;
	else {
		while (travel->next != NULL) {
			travel = travel->next;
		}
		travel->next = temp;
	}
}

// other manipulate with linked list
void reverse(struct Node** phead) {
	struct Node* prev, * current, * n_next;
	current = *phead;
	prev = NULL;
	while (current != NULL) {
		n_next = current->next;
		current->next = prev;
		prev = current;
		current = n_next;
	}
	*phead = prev;
}

void reverse_recursion(struct Node* travel) { //not working because it's reference
	if (travel->next == NULL) {
		struct Node* head = travel;
		return;
	}
	reverse_recursion(travel->next);
	travel->next->next = travel; // equivalent with below
	travel->next = NULL; //
	//struct Node* front = travel->next;
	//front->next = travel;
	//travel->next = NULL;
}


void deleteNode_reference(struct Node** phead, int position) {
	struct Node* travel1 = *phead;
	if (position == 1) {
		*phead = travel1->next;
		free(travel1);
		return;
	}
	for (int i = 0; i < position - 2; i++) {
		travel1 = travel1->next;
	}
	struct Node* travel2 = travel1->next;
	travel1->next = travel2->next;
	free(travel2);
}

void printLList(struct Node* head) {
	struct Node* temp = head;
	printf("List is: ");
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void printLList_recursion(struct Node* head) {
	if (head == NULL) return;	// exit recursion
	printf(" %d ", head->data);
	printLList_recursion(head->next);
}

void reversePrintLList_recursion(struct Node* head) {
	if (head == NULL) return; // return 0 still works ????
	reversePrintLList_recursion(head->next);
	printf(" %d ", head->data);
}

int main() {
	int number, insertVal;
	struct Node* head; // if head inside main function so the called function must a pointer to reference head 
	head = NULL;
	printf("How may number you want to insert: ");
	scanf_s("%d", &number);
	for (int i = 0; i < number; i++) {
		printf("Enter the number: ");
		scanf_s("%d", &insertVal);
		//insertPos_reference(&head, i+1, insertVal); //or head = insertPos(head, i+1, insertVal);
		//head = insertHead(head, insertVal); // or insertHead_reference(&head, insertVal);
		insertTail_reference(&head, insertVal); //head = insertTail(head, insertVal);
		printLList(head);
	}

	//deleteNode_reference(&head, 1);
	//printLList(head);
	//reverse(&head);
	reverse_recursion(&head); // not working
	printf("After reverse: \n");
	printLList(head);
	//printf("Using printList_recursion: \n");
	//printLList_recursion(head);
	//printf("\n Reverse print uses recursion: \n");
	//reversePrintLList_recursion(head);
	return 0;
}

