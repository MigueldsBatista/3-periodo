/*
03 - Considere que um programa em C manipula duas Filas (Fila01 e Fila02) 

agora é necessário que seja implementada uma nova função que realiza a troca do primeiro elemento entre as filas 
(o primeiro nó que está na Fila01 vai para a Fila02 E o primeiro nó que estava na Fila02 vai para a Fila01).

Protótipo da função: void troca(Node **head1, Node **tail1, Node **head2, Node **tail2);
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
int data;
struct Node *next;
struct Node *prev;
}Node;

void insertFirst(Node **head, Node**tail, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;

    if(*head==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        *head=newNode;
        *tail=newNode;
        return;
        //nesse caso é redundante atualizar o ponteiro anterior da head pois é a tail
    }

    newNode->next=*head;
    newNode->prev=*tail;
    (*head)->prev=newNode;
    *head=newNode;
    (*tail)->next=newNode;

}

void switchFirstElement(Node **head1, Node **head2){
    //preciso fazer 4 atualizações
    if(*head1==NULL || head2==NULL) return;

    int temp=(*head1)->data;
    (*head1)->data=(*head2)->data;
    (*head2)->data=temp;

}
void display(Node *head){
    if(head==NULL) return;
    Node *walk=head;

    do{
        printf("%d <->", walk->data);
        walk=walk->next;

    }while(walk!=head);
}
void display_reverse(Node *tail){
    if(tail==NULL) return;
    Node *walk=tail;

    do{
        printf("%d <->", walk->data);
        walk=walk->prev;

    }while(walk!=tail);
}


int main(){
    Node *head1=NULL;
    Node *tail1=NULL;

    Node *head2=NULL;
    Node *tail2=NULL;

    insertFirst(&head1, &tail1, 3);
    insertFirst(&head1, &tail1, 4);

    insertFirst(&head2, &tail2, 3);
    insertFirst(&head2, &tail2, 5);
    printf("Lista normal 1: \n");
    display(head1);
    printf("\n");


    printf("Lista normal 2: \n");

    display(head2);
    printf("\n");

    printf("REVERTIDO \n");

    switchFirstElement(&head1, &head2);

    printf("Lista normal: \n");
    display(head1);
    printf("\n");


    printf("Lista normal 2: \n");
    display(head2);
    printf("\n");



}