#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

int main() {
    int cases, elements, value;
    Node *head = NULL, *newNode = NULL, *walk = NULL, *temp = NULL;

    // Leitura do número de casos
    scanf("%d", &cases);
    
    for (int i = 0; i < cases; i++) {
        head = NULL; // Reinicializa a lista para cada caso

        // Leitura do número de elementos para o caso atual
        scanf("%d", &elements);

        // Inserção dos elementos na lista
        for (int j = 0; j < elements; j++) {
            scanf("%d", &value);

            // Alocação do novo nó
            newNode = (Node*)malloc(sizeof(Node));
            newNode->data = value;
            newNode->next = head;
            newNode->prev = NULL;

            if (head != NULL) {
                head->prev = newNode;
            }

            head = newNode; // Atualiza o ponteiro head para o novo nó
        }

        // Ordenação usando Bubble Sort
        int swaps = 0;
        int swapped;

        do {
            swapped = 0;
            walk = head;

            // Caminha pela lista, comparando e trocando se necessário
            while (walk->next != NULL) {
                if (walk->data > walk->next->data) {
                    // Troca os valores dos nós adjacentes
                    int temp = walk->data;
                    walk->data = walk->next->data;
                    walk->next->data = temp;
                    
                    swaps++;
                    swapped = 1;
                }
                walk = walk->next;
            }
        } while (swapped); // Repete até que não haja mais trocas

        // Imprime o número de trocas realizadas
        printf("Optimal train swapping takes %d swaps.\n", swaps);
    }

    return 0;
}
