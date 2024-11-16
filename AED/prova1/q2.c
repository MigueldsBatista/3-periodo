#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
      int data;
      struct Node *next;
} Node;

void enqueue(Node **head, Node **tail, int n);

void doubleFila(int delimitador, 
Node *head, Node *tail, 
Node **newHead1, Node** newTail1, Node **newHead2, Node **newTail2);

int length(Node *head);

void display(Node *head);

int main() {
Node *head = NULL;
Node *tail = NULL;

Node *new1=NULL;
Node *new2=NULL;
Node *newT1=NULL;
Node *newT2=NULL;

  enqueue(&head, &tail, 44);
  enqueue(&head, &tail, 87);
  enqueue(&head, &tail, 23);
  enqueue(&head, &tail, 26);
  //enqueue(&head, &tail, 23);
    display(head);
    
    doubleFila(87, head, tail, &new1, &newT1, &new2, &newT2);

    printf("Lista 1 \n");
    display(new1);
    printf("Lista 2 \n");
    display(new2);


  return 0;
}


void enqueue(Node **head, Node **tail, int n) {
  Node *novo = (Node *)malloc(sizeof(Node));
  if (novo != NULL) {
    novo->data = n;
    novo->next = NULL;

    if (*head == NULL) {
      *head = novo;
      *tail = novo;
    } else {
      (*tail)->next = novo;
      *tail = novo;
    }
  } 
}

int length(Node *head){
    if(head==NULL){
        return 0;
    }
    int cont=0;
    while (head){
        head=head->next;
        cont++;
    }
    return cont;
    
}

void doubleFila(int delimitador, 
Node *head, Node *tail, 
Node **newHead1, Node** newTail1, Node **newHead2, Node **newTail2){

int len=length(head);

if(len<2) return;

Node *walk=head;

while (walk->next && walk->next->data != delimitador)
{
    walk=walk->next;
}

if(!walk->next){// não encontrado
    walk=head;//reboot the list
    int n=0;
    while (n < len)
    {
        if(n < len/2){
            enqueue(newHead1, newTail1, walk->data);
        }
        if(n >= len/2){
            enqueue(newHead2, newTail2, walk->data);
        }
        n++;
        walk=walk->next;
    }
    return;
}

//else 
walk=head;

while(walk->next){

    if(walk->data==delimitador){
        enqueue(newHead1, newTail1, delimitador);
        walk=walk->next;
        break;
    }

    enqueue(newHead1, newTail1, walk->data);

    walk=walk->next;
}
while (walk){
    enqueue(newHead2, newTail2, walk->data);
    walk=walk->next;
}
}

void display(Node *head){
    if(head==NULL) return;

    while(head){
        printf("%d ->", head->data);
        head=head->next;
    }
    printf("\n");
}