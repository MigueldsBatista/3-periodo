#include <stdio.h>
#include <malloc.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

void insertFirst(Node **head, Node **tail, int num);

void insertLast(Node **head, Node **tail, int num);

int main(){
    Node *head=NULL;
    Node *tail=NULL;
    int op, num;
    do{
        printf("1- Inserir no final: \n");
        printf("2- Inserir no final: \n");
        printf("Escolha sua opção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Numero: ");
            scanf("%d", &num);
            insertFirst(&head, &tail, num);
            break;
        case 2:
            printf("Numero: ");
            scanf("%d", &num);
            insertLast(&head, &tail, num);
            break;
        default:
            break;
        }
    }while (op!=0);

    return 0;
}

void insertLast(Node **head, Node **tail, int num){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=num;
    newNode->next=*head;
    

    if(*head==NULL){
        *head=newNode;
        *tail=newNode;
        newNode->next=newNode;
        return;
    }
        (*tail)->next = newNode;  // O antigo último nó aponta para o novo nó
        *tail = newNode;          // Atualiza a cauda
        (*tail)->next = *head;    // A nova cauda aponta para a cabeça
    
}

void insertFirst(Node **head, Node **tail, int num){
Node *newNode=(Node*)malloc(sizeof(Node));

newNode->data=num;
newNode->next=*head;
if(*head==NULL){
    *head=newNode;
    *tail=*head;
    
}

(*head)=(*head)->next;

(*head)=newNode;

*tail=*head;

}

void removeFirst(struct Node **head, struct Node **tail){

    struct Node *delete=*head;
    if(!(*head)) return;

    if (*head == *tail) {
        *head = *tail = NULL;
    
    } else {
        (*head) = (*head)->next;
        (*tail)->next = (*head);
    }


    free(delete);

}


void removeLast(struct Node **head, struct Node **tail){
    if(!(*head)) return;

    struct Node *delete=*tail;
    struct Node *walk=*head;
    if (*head == *tail) {
        free(head);
        *head = *tail = NULL;
    
    } 
    while (walk->next != *tail)
    {
        walk=walk->next;
    }

    walk->next=*head;
    free(tail);
    *tail=walk;

}