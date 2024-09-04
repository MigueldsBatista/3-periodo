#include <stdio.h>
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
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(*head==NULL){//lista vazia
        *head=newNode;
        return;
    }

    Node *current=*head;
    // Caso o novo valor deva ser inserido no início da lista
    if(current->data > value){
        newNode->next=current;
        
        current->prev=newNode;

        *head=newNode;
    }


    // Encontrar a posição correta para inserir

    // Encontrar a posição correta para inserir

    // Inserir o novo nó na lista


    /*    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;*/

}

void insertFirst(Node **head, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=*head;//proximo é a nossa head atual
    newNode->prev=NULL;//sempre null pois é o primeiro elemento

    if(*head!=NULL){
        (*head)->prev=newNode;
    }
    *head=newNode;
    
}
