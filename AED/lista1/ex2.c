#include <stdio.h>
#include <malloc.h>

struct Queue{
char nome[50];
struct Queue *next;
};
void PosicaoPaciente(){
    
}

void enqueue(struct Queue **head, struct Queue **tail, char nomeInserido[50]){
    struct Queue *newNode=(struct Queue*)malloc(sizeof(struct Queue));

    strcpy(newNode->nome, nomeInserido);
    newNode->next=NULL;
    if (*head==NULL)
    {
        *head=*tail=newNode;
        return;
    }
    (*head)->next=newNode;
    *head=newNode;
}

void dequeue(struct Queue **head, struct Queue **tail){
    struct Queue *delete=*head;

    (*head)=(*head)->next;

    free(delete);

    if(*head==NULL){
        (*tail)=NULL;

    }
}

