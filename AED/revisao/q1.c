#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
int data;
struct Node *next;
}Node;


//ex (1,2,3,4,5,6,7,8,9,10)
void multiplicacao(Node *head, Node *tail);

void insertFirst(Node **head, Node **tail, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {  // Lista vazia
        *head = newNode;
        *tail = newNode;
        newNode->next = newNode;  // Aponta para ele mesmo para criar a circularidade
    } else {
        newNode->next = *head;
        *head = newNode;
        (*tail)->next = newNode; // Mantém a circularidade
    }
}
void display(Node *head, Node *tail){

    if(!head) return;

    do{
        printf("%d ->", head->data);
        head=head->next;
    }
    while (head!=tail);
printf("\n");

    
}

int main()
{
    Node *head=NULL;    
    Node *tail=NULL;
    insertFirst(&head, &tail, 3);
    insertFirst(&head, &tail, 4);
    insertFirst(&head, &tail, 5);
    insertFirst(&head, &tail, 7);

    display(head, tail);
    multiplicacao(head, tail);
}

void multiplicacao(Node *head, Node *tail){
    int isEven=true;
    do{
        isEven=!isEven;
        if(head==tail && isEven==false){
            printf("[%d]", head->data*head->data);
            return;
        }
        printf("[%d]", head->data*head->next->data);

        head=head->next->next;
    }while (head!=tail);
}