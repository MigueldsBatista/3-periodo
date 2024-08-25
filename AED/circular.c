#include <stdio.h>
#include <malloc.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

void insertFirst(Node **head, Node **tail, int num){
Node *newNode=(Node*)malloc(sizeof(Node));

newNode->data=num;
newNode->next=*head;
if(*head==NULL){
    head=newNode;
    tail=head;
    
}
(*head)=(*head)->next;
(*head)=newNode;
*tail=head;
}

void insertLast(Node **head, Node **tail, int num);

int main(){
    Node *head=NULL;
    Node *tail=NULL;
    return 0;
}