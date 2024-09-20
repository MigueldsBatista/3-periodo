#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char plane[100];
    struct Node* next;
} Node;

void enqueue(Node** head, Node** tail, const char* plane) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->plane, plane);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void printQueue(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s ", current->plane);
        current = current->next;
    }
}

void freeQueue(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void processQueues(Node* west, Node* north, Node* south, Node* east) {
    while (west || north || south || east) {
        if (west) {
            printf("%s ", west->plane);
            Node* temp = west;
            west = west->next;
            free(temp);
        }
        if (north) {
            printf("%s ", north->plane);
            Node* temp = north;
            north = north->next;
            free(temp);
        }
        if (south) {
            printf("%s ", south->plane);
            Node* temp = south;
            south = south->next;
            free(temp);
        }
        if (east) {
            printf("%s ", east->plane);
            Node* temp = east;
            east = east->next;
            free(temp);
        }
    }
    printf("\n");
}

int main() {
    Node *westHead = NULL, *westTail = NULL;
    Node *southHead = NULL, *southTail = NULL;
    Node *eastHead = NULL, *eastTail = NULL;
    Node *northHead = NULL, *northTail = NULL;

    char input[100];
    int cardinal = 0;

    while (1) {
        scanf("%s", input);

        // Se a entrada for 0, o programa encerra
        if (strcmp(input, "0") == 0) break;

        // Verifica se a entrada é um ponto cardeal
        int num = atoi(input);

        if (num >= -4 && num <= -1) {
            cardinal = num;  // Atualiza o ponto cardeal atual
        } else {
            // Caso contrário, é um identificador de avião, enfileira de acordo com o último ponto cardeal
            switch (cardinal) {
                case -4:
                    enqueue(&eastHead, &eastTail, input);
                    break;
                case -3:
                    enqueue(&northHead, &northTail, input);
                    break;
                case -2:
                    enqueue(&southHead, &southTail, input);
                    break;
                case -1:
                    enqueue(&westHead, &westTail, input);
                    break;
            }
        }
    }

    // Processa as filas na ordem de prioridade e imprime
    processQueues(westHead, northHead, southHead, eastHead);

    // Libera memória alocada
    freeQueue(westHead);
    freeQueue(northHead);
    freeQueue(southHead);
    freeQueue(eastHead);

    return 0;
}
