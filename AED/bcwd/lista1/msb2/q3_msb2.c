#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char plane[100];
    struct Node* next;
} Node;

void enqueue(Node** head, Node** tail, char* plane) {
    Node *newNode =(Node*)malloc(sizeof(Node));
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


int main() {
    Node *westHead = NULL, *westTail = NULL;
    Node *southHead = NULL, *southTail = NULL;
    Node *eastHead = NULL, *eastTail = NULL;
    Node *northHead = NULL, *northTail = NULL;

    char input[100];
    int cardinal = 0;

    // Loop principal de entrada
    while (1) {
        scanf("%s", input);

        // Se a entrada for 0, o programa encerra
        if (strcmp(input, "0") == 0) break;

        // Verifica se a entrada é um ponto cardeal
        int num = atoi(input);

        if (num >= -4 && num <= -1) {
            cardinal = atoi(input);
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

    // Saída na ordem de prioridade
    int first=1;
    while (westHead || northHead || southHead || eastHead) {
        if (westHead) {
            // Primeiro imprime 1 da fila Oeste
            if(!first) printf(" ");//uma mera frescura do beecrowd
            printf("%s", westHead->plane);
            westHead=westHead->next;
        }
        if (northHead) {
            // Depois imprime 1 da fila Norte
            if(!first) printf(" ");//uma mera frescura do beecrowd

            printf("%s", northHead->plane);
            northHead=northHead->next;
        }
        if (southHead) {
            // Em seguida, 1 da fila Sul
            if(!first) printf(" ");//uma mera frescura do beecrowd

            printf("%s", southHead->plane);
            southHead=southHead->next;

        }
        if (eastHead) {
            // Por último, 1 da fila
            if(!first) printf(" ");//uma mera frescura do beecrowd
            
            printf("%s", eastHead->plane);
            eastHead=eastHead->next;
        }
        first=0;
    }
    printf("\n");
    return 0;

}
