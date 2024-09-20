#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void enqueue(Node **head, Node **tail, int value){
Node* newNode=(Node*)malloc(sizeof(Node));

newNode->data=value;
newNode->next=NULL;

if(*head==NULL){
*head=*tail=newNode;
return;
}

(*tail)->next=newNode;
(*tail)=newNode;
}

int dequeue(Node **head, Node **tail){//usado pra fila
    if(*head==NULL) return -1;

    Node* delete=*head;

    int deletado=delete->data;


    (*head)=(*head)->next;

    free(delete);

    if(*head==NULL){
        *tail=*head;
    }
    return deletado;
}


void printNode(Node *head){
    while(head){
        printf("[%d]\n", head->data);
        head=head->next;
    }
}
void push(Node **top, int value){//usado pra pilha
Node* newNode=(Node*)malloc(sizeof(Node));
newNode->data=value;
newNode->next=*top;

*top=newNode;
}

void pop(Node **top){//usado pra pilha
    if(*top==NULL) return;

    Node* delete=*top;


    (*top)=(*top)->next;

    free(delete);

}
void CopyAll(Node *head, Node **saida){
    
    while(head){
    push(saida, head->data);
    head=head->next;
    }
}

int main(){
    Node *fila1=NULL;
    Node *tail1=NULL;

    Node *tail2=NULL;
    Node *fila2=NULL;

    Node *pilha=NULL;
    int num;
    printf("Elementos da fila 1: \n");
    for(int i=0;i<10;i++){
        scanf("%d", &num);
        enqueue(&fila1, &tail1, num);
    }
    printf("Elementos da fila 2: \n");
    for(int j=0;j<10;j++){
    scanf("%d", &num);
    enqueue(&fila2, &tail2, num);
    }
    printf("Elementos da fila 1 na pilha: \n");

    CopyAll(fila1, &pilha);
    printNode(pilha);
    printf("\n");
    printf("Elementos da fila 1 e 2 na pilha: \n");

    CopyAll(fila2, &pilha);
    printNode(pilha);
    
    return 0;
}