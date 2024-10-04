#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
int data;
struct Node *next;
}Node;


//ex (1,2,3,4,5,6,7,8,9,10)
void multiplicacao(Node *head);

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

void display(Node *head){

    if(!head) return;

    Node *walk=head;
    do{
        printf("%d ->", walk->data);
        walk=walk->next;
    }
    while (head!=walk);
    
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

    display(head);
    multiplicacao(head);
}

void multiplicacao(Node *head) {
    if (!head) return; // Verifica se a lista está vazia

    Node *walk = head;
    int isEven = true; // Inicia com true para alternar no primeiro elemento
    int count = 0;

    // Conta o número de elementos na lista
    do {
        count++;
        walk = walk->next;
    } while (walk != head);

    walk = head; // Reinicia o ponteiro walk para o início da lista

    // Se a lista tiver apenas 1 elemento, imprime seu quadrado
    if (count == 1) {
        printf("[%d] ", head->data * head->data); // Elevando ao quadrado
        printf("\n"); // Nova linha após a multiplicação
        return;
    }

    //[1] [2] [3] [4]
    // Multiplicação de pares
    do {
        if (isEven) {
            printf("[%d] ", walk->data * walk->next->data); // Multiplica o elemento atual com o próximo
        }
        isEven = !isEven; // Alterna entre verdadeiro e falso
        walk = walk->next; // Avança para o próximo elemento
    } while (walk != head);

    // Se a lista tem um número ímpar de elementos, trata o último
    if (!isEven) {
        // walk agora é o último elemento da lista
        printf("[%d] ", walk->data * walk->data); // Eleva o último elemento ao quadrado
    }

    printf("\n"); // Nova linha após as multiplicações
}
