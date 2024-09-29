#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

void insertFirst(Node **head, int data);

int main(){

Node *head=NULL;
insertFirst(&head, 1);
insertFirst(&head, 1);
insertFirst(&head, 1);

system("clear");




return 0;

}

void insertFirst(Node **head, int value){
    //aloca memoria para um novo No
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=*head;
    newNode->prev=NULL;

    if(*head!=NULL){
        (*head)->prev=newNode;
    }
    *head=newNode;
}

void insertLast(Node **head, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(*head!=NULL){

    }
    (*head)->next->prev;
}

void removeFirst(Node**head){
    Node* delete=*head;
    if(*head==NULL) return;

    *head=(*head)->next;
    free(delete);
    if(*head!=NULL){
        (*head)->prev=NULL;
    }
}


