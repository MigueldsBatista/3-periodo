#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Queue {
    int data;
    struct Queue* next;
};

void enqueue(struct Queue **head, struct Queue **tail, int value) {
    struct Queue *newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->data = value;
    newNode->next = NULL;

    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void dequeue(struct Queue **head, struct Queue **tail) {
    if (*head == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Queue *delete = *head;
    *head = (*head)->next;

    if (*head == NULL) { // Se a head agora é nula, só tínhamos 1 elemento, precisamos deixar a tail nula também
        *tail = NULL;
    }

    free(delete);
}

void printQueue(struct Queue *head) {//Aqui nós não perdemos a referencia de head pois é um ponteiro apenas então nao afeta o conteudo do ponteiro

    while (head) {
        printf("[%d]", head->data);
        if (head->next) {
            printf(" -> ");
        }
        head = head->next;
    }printf(" -> NULL");
    printf("\n");
}

int main(int argc, char const *argv[]) {
    struct Queue *head = NULL;
    struct Queue *tail = NULL;
    int choice, value;

    do {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&head, &tail, value);
                printQueue(head);
                break;
            case 2:
                dequeue(&head, &tail);
                printQueue(head);
                break;
            case 3:
                printQueue(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
