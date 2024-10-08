﻿#include <stdio.h>
#include <stdlib.h>


typedef struct Node{ 
int data; 
struct Node *next; 
struct Node *prev; 
} Node;
void insertFirst(Node **head, int value);

void insertOrdered(Node **head, int value);

int main(){

return 0;
}

void insertOrdered(Node **head, int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(*head == NULL){  // Lista vazia
        *head = newNode; 
        return;
    }

    Node *current = *head;

    // Caso o novo valor deva ser inserido no início da lista
    if(current->data > value){
        newNode->next=current;

        current->prev=newNode;

        *head=newNode;
    }

    // Encontrar a posição correta para inserir
    while (current->next || current->data < value){
        current=current->next;
    }

    
    
    
    // Encontrar a posição correta para inserir

    // Inserir o novo nó na lista
    newNode->next = current->next;
    newNode->prev = current;

    if(current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;
}

void insertIntercalete(Node **head, Node **head2, int value){
    

}

void printNode(Node *head, int target){
    int before=0;
    int after=0;
    while(head){
        if(head->data!=target){//
            before++;
        }
        head=head->next;

    }
}