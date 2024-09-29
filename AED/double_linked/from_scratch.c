#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
    
}Node;

void insertFirst(Node **head, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    
    newNode->data=value;
    newNode->next=*head;
    newNode->prev=NULL;

    *head=newNode;
}

void insertLast(Node **head, int value){
    
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->next=NULL;
    newNode->data=value;
    if(*head==NULL){
        newNode->prev=NULL;
        *head=newNode;
        return;
    }
    Node *walk=*head;

    while(walk->next){
        walk=walk->next;
    }
    newNode->prev=walk;
    
    walk->next=newNode;

    walk=newNode;

    //3 <-> 4 <-> 2 <-> [1]
}
void insertInOrder(Node **head, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));

    newNode->data=value;
    if(*head==NULL){
        newNode->next=NULL;
        newNode->prev=NULL;
        *head=newNode;
    }
    Node *walk=*head;
    while(walk->next && value > walk->next->data){
        walk=walk->next;
    }
    if(!walk->next){//inserção no final
        newNode->prev=walk;
        walk->next=newNode;
        walk=newNode;
        return;
    }

    newNode->prev=walk;
    newNode->next=walk->next;

    walk->next=newNode;
    walk->next->prev=newNode;
    walk=newNode;

}
void display(Node *head){
    while (head)
    {
        printf("%d -> ", head->data);
        head=head->next;
    }
    
}
int main(){
    Node *head=NULL;
    //insertFirst(&head, 2);
    insertLast(&head, 3);
    insertLast(&head, 4);
    insertLast(&head, 7);
    insertInOrder(&head, 5);
    display(head);

}