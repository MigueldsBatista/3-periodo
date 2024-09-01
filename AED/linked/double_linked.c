#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
//insere no ultimo nó de uma lista duplamente encadeada
void insertLast(Node **head, int value);

//insere no ultimo nó de uma lista duplamente encadeada com tail
void insertLastTail(struct Node **head, Node **tail, int value);

void printNode(Node *head);


void pritNodeReverse(Node* tail);

void removeLast(Node **head);

void removeLastTail(Node **head, Node**tail);

int main(int argc, char const *argv[])
{
    int op,
    num;
    Node *head=NULL;

    Node *head2=NULL;
    Node *tail2=NULL;

    do
    {
        printf("Programa lista duplamente encadeada\n");
        printf("LISTA 1: \n");
        printNode(head);
        printf("LISTA 2: \n");
        printNode(head2);
        printf("LISTA 2 Reversa: \n");
        pritNodeReverse(tail2);

        printf("1- Inserir no final (lista S/tail): \n");
        printf("2- Remoção no final (lista S/tail): \n");

        printf("3- inserir no final (lista C/tail): \n");
        printf("4- Remoção no final (lista C/tail): \n");
        printf("Escolha sua opção: ");
        scanf("%d", &op);
        
        switch (op)
        {
        case 1:
            printf("Digite um numero: ");
            scanf("%d", &num);
            insertLast(&head, num);
            break;
        case 2:

            removeLast(&head);

            break;
        
        case 3:
            printf("Digite um numero: ");
            scanf("%d", &num);
            insertLastTail(&head2, &tail2, num);
            break;
        case 4:
            removeLastTail(&head2, &tail2);
            break;
        case 9:
            printNode(head2);
            printNode(tail2);
            break;
        default:
            break;
        }
    } while (op!=0);
    
    return 0;
}

void insertLast(Node** head, int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    Node*walk=*head;
    newNode->data=value;
    newNode->next=NULL;//sempre
    if(*head==NULL){
        newNode->prev=NULL;
        *head=newNode;
        return;
    }
    while (walk->next)
    {
        walk=walk->next;
    }
    newNode->prev=walk;
    walk->next=newNode;
    
}

void insertLastTail(Node** head, Node **tail, int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    Node*walk=*head;
    newNode->data=value;
    newNode->next=NULL;//sempre
    if(*head==NULL){
        newNode->prev=NULL;
        *head=newNode;
        return;
    }
    while (walk->next)
    {
        walk=walk->next;
    }
    newNode->prev=walk;
    walk->next=newNode;
    *tail=newNode;
}


void printNode(Node *head){
    if(!head) return;

    while (head)
    {
        if(!head->prev){
            printf("NULL <-> ");
        }
        printf("%d", head->data);
        if(head->next){
        printf(" <-> ");
        }
        head=head->next;
    }
    printf(" <-> NULL\n");

}

void pritNodeReverse(Node* tail){


        while (tail)
        {
        printf("%d", tail->data);
        if(tail->prev){
        printf(" <-> ");
        }
        tail=tail->prev;
    }
    printf("\n");

}
void removeLast(Node **head){//remove last element without tail
    if(*head==NULL) return;//vazia

    if((*head)->next==NULL) {// 1 elemento
        free(*head);
        *head=NULL;
        return;
    }

    Node* walk=*head;
    Node* (prev_walk);
 
    while (walk->next)
    {
        (prev_walk)=walk;//penultimo elemento;
        walk=walk->next;
    }   (prev_walk)->next=NULL;

 
    free(walk);
    
}

void removeLastTail(Node **head, Node **tail){
    if(*head==NULL) return;//vazia

    if((*head)->next==NULL) {// 1 elemento
        free(*head);
        *head=NULL;
        *tail=NULL;
        return;
    }
    Node *walk=*head;
    Node *(prev_walk);
    while(walk->next){
        prev_walk=walk;
        walk=walk->next;

    }  
       *tail=prev_walk;// Atualiza o ponteiro tail para o penúltimo nó
       prev_walk->next=NULL;// Desconecta o último nó
       free(walk);
}