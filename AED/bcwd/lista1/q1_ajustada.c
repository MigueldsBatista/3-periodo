#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

// Função para empurrar um novo elemento para o stack
void push(Node **head, char value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Função para remover um elemento do stack
char pop(Node **head) {
    if (*head == NULL) return '\0'; // Use '\0' como valor padrão para caso de lista vazia

    Node *delete = *head;
    char temp = delete->data;
    *head = (*head)->next;
    free(delete);
    return temp;
}

int main() {
    int n;
    int balance = 0;
    int closing = 0;
    char diamonds[1000];
    Node *head = NULL;

    scanf("%d", &n);


    for (int testCases = 0; testCases < n; testCases++) {

        scanf("%s", diamonds);
        int len = strlen(diamonds);

    // Adiciona o array ao stack
        for (int i = len - 1; i >= 0; i--) {
            push(&head, diamonds[i]);
        }

            for (int i = 0; i < len; i++) {
                char ch = pop(&head);

                if (ch == '<') {
                    balance++;
                } else if (ch == '>') {
                    balance--;
                }

                if (balance >= 0 && ch == '>') {
                    closing++;
                }

                if (balance < 0 && ch == '<') {
                    balance = 1;
                }
            }
        }

    printf("%d", closing);

    return 0;
}
