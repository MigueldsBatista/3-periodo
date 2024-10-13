
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

void insert(Node **head, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));

    newNode->data=value;//update value
    
    newNode->next=*head;//link next to head
    newNode->prev=NULL;
    if(*head!=NULL){
    (*head)->prev=newNode;
    }
    *head=newNode;

}
void swap(Node *firstNode, Node *secondNode){
    int temp = firstNode->data;
    firstNode->data = secondNode->data;
    secondNode->data = temp;
}

int bubble_sort(Node **head) {
    if (*head == NULL) {
        return 0; // Lista vazia, nada a ordenar
    }

    int swaps = 0;
    int swapped;
    Node *walk;

    do {
        swapped = 0;
        walk = *head;

        // Caminha pela lista, comparando e trocando se necessário
        while (walk->next != NULL) {
            if (walk->data > walk->next->data) {
                swap(walk, walk->next);
                swaps++;
                swapped = 1;
            }
            walk = walk->next;
        }

    } while (swapped); // Repete até que não haja mais trocas

    return swaps;
}

int main(int argc, char const *argv[])
{
    int cases;
    int elements;
    int value;
    Node *head=NULL;

    scanf("%d", &cases);
    for(int i=0;i<cases;i++){
        scanf("%d", &elements);
        for(int j=0;j<elements;j++){
            scanf("%d", &value);
            insert(&head, value);
        }
    }


    int swaps=bubble_sort(&head);
    printf("Optimal train swapping takes %d swaps.", swaps);

    return 0;
}
