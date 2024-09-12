#include <stdio.h>
#include <stdlib.h>

typedef struct Node;

void insertFirst(Node **head, Node **tail, int value);
void insertLast(Node** head, Node** tail, int value);
void display(Node* head, Node* tail);
void displayReverse(Node* head, Node* tail);
void removeFirst(Node** head, Node** tail);
void removeLast(Node** head, Node** tail);


int main(){
	Node *head=NULL;
	Node *tail=NULL;
	int op, num;
	system("clear");
	do {
		printf("Normal\n");
		display(head, tail);
		printf("Reverse\n");
		displayReverse(head, tail);
		printf("1. Insert First\n2. Insert Last\n3. Remove First\n4. Remove Last\n0. Exit\n");
		printf("Enter your option: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				system("clear");
				printf("Enter number: ");
				scanf("%d", &num);
				insertFirst(&head, &tail, num);
				break;
			case 2:
				system("clear");
				printf("Enter number: ");
				scanf("%d", &num);
				insertLast(&head, &tail, num);
				break;
			case 3:
				system("clear");
				removeFirst(&head, &tail);
				break;
			case 4:
				system("clear");
				removeLast(&head, &tail);
				break;

			case 0:
				break;
		}
	}while (op!=0);


	return 0;
}

typedef struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
}Node;

void insertFirst(Node **head, Node **tail, int value){

Node *newNode=(Node*)malloc(sizeof(Node));

newNode->data=value;
newNode->next=*head;
newNode->prev=*tail;

if(*head==NULL){
	*head=*tail=newNode;
	return;
}
(*tail)->next=newNode;

(*head)->prev=newNode;

*head=newNode;

}

void insertLast(Node** head, Node** tail, int value){
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=value;
	newNode->next=*head;
	newNode->prev=*tail;

	if(*tail==NULL){
		newNode->next=newNode;
		newNode->prev=newNode;
		*head=*tail=newNode;
		return;
	}

	(*tail)->next=newNode;
	(*head)->prev=newNode;
	*tail=newNode;
}

void display(Node* head, Node* tail){
	if(head==NULL) return;
	do {
		printf("%d ->",head->data);
		head=head->next;
	} while(head!=tail->next);
	printf("\n");

}

void displayReverse(Node* head, Node* tail){
	if(tail==NULL) return;
	do {
		printf("%d ->", tail->data);
		tail=tail->prev;
	} while(tail!=head->prev);
	printf("\n");
}

void removeFirst(Node** head, Node** tail){
	if(*head==NULL) return;
	if((*head)->next==*head){
		free(*head);
		*head=*tail=NULL;
		return;
	}
	Node *delete=*head;
	*head=(*head)->next;
	(*tail)->next=*head;
	(*head)->prev=*tail;

	free(delete);//double linked list
}

void removeLast(Node** head, Node** tail){
	if(*tail==NULL) return;
	if((*tail)->prev==*tail){
		free(*tail);
		*head=*tail=NULL;
		return;
	}
	Node *delete=*tail;
	*tail=(*tail)->prev;
	(*head)->prev=*tail;
	(*tail)->next=*head;
	free(delete);//double linked list
}
