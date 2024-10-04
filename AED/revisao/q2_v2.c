/*
02 - Um determinado programa implementado em C deve permitir manipular números em uma lista circular duplamente encadeada, 
mas, possui apenas a função que insere nós. 

a)Inclua no programa uma nova funcionalidade para imprimir todos os elementos que são precedidos por uma sequência de dois números ímpares. 

b)Se o elemento não tiver dois nós antecedentes, 
verifique se os dois nós que o sucedem são ímpares para só então imprimir o elemento. 

c) E se a lista tiver menos que 3 nós, exiba a seguinte mensagem: “Tamanho da lista é insuficiente :(”.
Protótipo da função: void sequencia(Node *head, Node *tail);
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



void insertFirst(Node **head, Node **tail, int value){
    Node *newNode= (Node*)malloc(sizeof(Node));
    newNode->data=value;
    if(*head==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        *head=newNode;
        *tail=newNode;
        return;
    }
    newNode->next=*head;
    newNode->prev=*tail;

    (*head)->prev=newNode;
    
    *head=newNode;
    (*tail)->next=newNode;

}
void precessors(Node *head, Node *tail){
    Node *walk=head;
    int cont=0;
    do{
        cont++;
        walk=walk->next;
    }while(walk!=head);
    walk=head;//reboot
    if(cont<3){
        printf("Tamanho da lista é insuficiente :(");
        return;
    }
    // 3 5 7
    do {
    if(
        walk->prev->data % 2 == 1 && 
        walk->prev!=head &&
        walk->prev->prev->data % 2 == 1 &&
        walk->prev->prev!=tail
        ){
        printf("[%d]", walk->data);
    }
    
    else if (
        walk->next->data %2 == 1 && 
        walk->next!=tail &&
        walk->next->next->data %2 == 1 &&
        walk->next->next!=head
        ){
        printf("[%d]", walk->data);
        
    }
    else{
        printf("Não atendido para [%d]\n", walk->data);
    }
    walk=walk->next;
}while(walk!=head);
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
    Node *head=NULL;
    Node *tail=NULL;

    insertFirst(&head, &tail, 7);
    insertFirst(&head, &tail, 5);
    insertFirst(&head, &tail, 3);
    insertFirst(&head, &tail, 1);
    display(head);
    printf("\n ao contrario \n");
    display_reverse(tail);
    printf("\n");
    printf("precessores: \n");
    precessors(head, tail);
    
}   