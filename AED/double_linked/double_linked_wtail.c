#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
    
}Node;
void insertFirst(Node **head, Node**tail, int value);
void insertLast(Node **head, Node**tail, int value);
void insertInOrder(Node **head, Node**tail, int value);

void deleteFirst(Node **head, Node** tail);

void deleteLast(Node **head, Node **tail);
void deleteX(Node **head, Node **tail,  int value);

void display(Node *head);
void displayReverse(Node *tail);

int main(){
    Node *head=NULL;
    Node *tail=NULL;
    int op, num;

    do{

        system("clear");

        printf("Lista normal: \n");
        display(head);
        printf("\n");
        printf("Lista invertida: \n");
        displayReverse(tail);  
        printf("\n");

        printf("1- first\n");
        printf("2- last\n");
        printf("3- ordered\n");
        printf("4- delete f\n");
        printf("5- delete l\n");
        printf("6- delete X\n");


        printf("\n");     

        scanf("%d", &op);

       
        switch (op)
        {
        
        default:
            printf("Opção inválida!\n");
            break;
        case 1:
        printf("Digite um número! \n");
        scanf("%d", &num);
        insertFirst(&head, &tail, num);
            break;
        case 2:
        printf("Digite um número! \n");
        scanf("%d", &num);
        insertLast(&head, &tail, num);
            break;
        case 3:
        printf("Digite um número! \n");
        scanf("%d", &num);
        insertInOrder(&head, &tail, num);
            break;
        case 4:
        deleteFirst(&head, &tail);
            break;
        case 5:
        deleteLast(&head, &tail);
        break;

        case 6:
        printf("Digite um número! \n");
        scanf("%d", &num);
        deleteX(&head, &tail, num);
        break;
        }
    }while(op!=0);

}

void insertFirst(Node **head, Node **tail, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    
    newNode->data=value;
    newNode->next=*head;
    newNode->prev=NULL;

    //[3]
    if(*head != NULL){//preciso atualizar o prev tb
        (*head)->prev = newNode;
    }

    *head=newNode;

    if((*head)->next==NULL){
        *tail=newNode;
    }



}

void insertLast(Node **head, Node **tail, int value){
    
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->next=NULL;
    newNode->data=value;
    if(*head==NULL){
        newNode->prev=NULL;
        *head=newNode;
        *tail=newNode;
        return;
    }
    Node *walk=*head;

    while(walk->next){
        walk=walk->next;
    }
    newNode->prev=walk;
    
    walk->next=newNode;
    walk=newNode;

    *tail=walk;


    //3 <-> 4 <-> 2 <-> [1]
}
void insertInOrder(Node **head, Node **tail, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));

    newNode->data=value;
    newNode->next=NULL;

    if(*head==NULL){
        newNode->next=NULL;
        newNode->prev=NULL;
        *head=*tail=newNode;
        return;
    }

    if((*head)->data > value){
        newNode->next=*head;
        newNode->prev=NULL;
        *head=newNode;
        return;
    }
    Node *walk=*head;
    while(walk->next && value > walk->next->data){
        walk=walk->next;
    }
    if(!walk->next){//inserção no final
        newNode->prev=walk;
        walk->next=newNode;
        walk=newNode;

        *tail=walk;

        return;
    }
    //inserção apos o elemento de parada]
    //ex [3] -> [4] -> [7]
    //              6 ^
    //value not bigger than walk->next
    newNode->prev=walk;
    newNode->next=walk->next;

    walk->next=newNode;
    walk->next->prev=newNode;
    walk=newNode;

}
void display(Node *head){
    if(head==NULL) return;

    while (head)
    {
        printf("%d -> ", head->data);
        head=head->next;
    }
    
}

void displayReverse(Node *head){
    if(head==NULL) return;

    while(head->next){
        head=head->next;
    }
    while (head)
    {
        printf("%d -> ", head->data);
        head=head->prev;
    }
    
}

void deleteFirst(Node **head, Node** tail){

if(*head==NULL) return;

if(*head==*tail){
    free(*head);
    *head=*tail=NULL;
    return;
}

Node *delete=*head;
(*head)=(*head)->next;
(*head)->prev=NULL;

free(delete);

}

void deleteLast(Node **head, Node **tail){

if(*head==NULL) return;

if(*head==*tail){
    free(*head);
    *head=NULL;
    *tail=NULL;
    return;
}
Node *delete=*head;
Node *walk=*head;

while(walk->next->next){//vamos até o penultimo elemento, caso não tenhamos tail
    walk=walk->next;
}
delete=walk->next;

*tail=walk;//caso tenhamos tail so adicionar aq

walk->next=NULL;

free(delete);
}

void deleteX(Node **head, Node **tail,  int value){
    if(*head==NULL) return;


    if((*head)->data == value){//caso a lista nao tenha 1 elemento mas a head seja o noso alvo
        deleteFirst(head, tail);
        return;
        
    }

    if(*head == *tail && value != (*head)->data){//caso a lista tenha um elemento e ele nao seja nosso alvo
        printf("Valor não encontrado! \n");
        return;
    }

    Node *walk=*head;

    while(walk->next && walk->next->data != value){
        walk=walk->next;
    }

    if(!walk->next){
        printf("Valor não encontrado! \n");
        return;
    }

    if(walk->next == *tail){
        deleteLast(head, tail);
        return;
    }
    //else
    Node *delete=walk->next;

    walk->next=walk->next->next;

    walk->next->prev=walk;

    free(delete);

    
}