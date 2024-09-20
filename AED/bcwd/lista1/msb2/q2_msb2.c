#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[100];
    int pos;
    struct Node* next;
    struct Node* prev;
} Node;

// Função para inserir ordenadamente na lista
void insertOrdered(Node** head, char* name, int pos) {
    // Verifica se o nome já foi inserido
    Node* current = *head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) return; // Nome duplicado
        current = current->next;
    }

    // Cria um novo nó
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->pos = pos;
    newNode->next = NULL;
    newNode->prev = NULL;

    // Se a lista está vazia
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Se o nome deve ser inserido no início
    if (strcmp((*head)->name, name) > 0) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // Inserção ordenada no meio ou final
    Node* temp = *head;
    while (temp->next != NULL && strcmp(temp->next->name, name) < 0) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Função para exibir a lista


// Função para determinar o vencedor (baseado no tamanho do nome e ordem de inserção)


int main() {
    Node* yesList = NULL;
    Node* noList = NULL;

    int pos = 0;
    char input[105], name[100], choice[5];

    // Lendo a entrada
    while (true) {
        scanf("%s", input);
        if (strcmp(input, "FIM") == 0) break;
        scanf("%s", choice);

        // Separando nome e escolha (YES ou NO)
        strcpy(name, input);

        if (strcmp(choice, "YES") == 0) {
            insertOrdered(&yesList, name, pos++);
        } else {
            insertOrdered(&noList, name, pos++);
        }
    }
    //FIND WINNER STEP

    Node*winner=yesList;
    
    // Exibe as listas
    while (yesList != NULL) {
        if (strlen(yesList->name) > strlen(winner->name) || 
           (strlen(yesList->name) == strlen(winner->name) && yesList->pos < winner->pos)) {
            winner = yesList;
    }
        printf("%s\n", yesList->name);//print YES list
        yesList = yesList->next;
    }

    while (noList != NULL) {
        printf("%s\n", noList->name);// print NO list
        noList = noList->next;
    }

    printf("\nAmigo do Habay:\n");
    printf("%s\n", winner->name); 
    return 0;

}