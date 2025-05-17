#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
    
}Node;

void insert_first(Node **head, int value);
void insert_last(Node **head, int value);
void insert_ordered(Node **head, int value);
void display(Node *head);
void remome_first(Node**head);
void delete_first(Node **head) ;
void delete_last(Node **head);
void delete_x(Node **head,  int value);


void insert_first(Node **head, int value){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=value;
    new_node->next=*head;
    new_node->prev=NULL;
    *head=new_node;
}

void insert_last(Node **head, int value){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->next=NULL;
    new_node->data=value;
    if(*head==NULL){
        new_node->prev=NULL;
        *head=new_node;
        return;
    }
    Node *walk=*head;

    while(walk->next){
        walk=walk->next;
    }
    new_node->prev=walk;
    walk->next=new_node;
    walk=new_node;
}
void insert_ordered(Node **head, int value){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=value;
    if(*head==NULL){
        new_node->next=NULL;
        new_node->prev=NULL;
        *head=new_node;
    }
    Node *walk=*head;

    while(walk->next && value > walk->next->data){
        walk=walk->next;
    }
    if(!walk->next){
        insert_last(head, value);
        return;
    }

    new_node->prev=walk;
    new_node->next=walk->next;

    walk->next=new_node;
    walk->next->prev=new_node;
    walk=new_node;

}
void display(Node *head){
    while (head){
        printf("%d -> ", head->data);
        head=head->next;
    }
    
}


void delete_first(Node **head) {
    if (*head == NULL) return;
    Node *delete = *head;
    
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(delete);
}

void delete_last(Node **head) {
    if (*head == NULL) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    
    Node *walk = *head;
    while (walk->next->next) {
        walk = walk->next;
    }
    
    Node *delete = walk->next;
    walk->next = NULL;
    free(delete);
}

void delete_x(Node **head, int value) {
    if (*head == NULL) return;

    if ((*head)->data == value) {
        delete_first(head);
        return;
    }

    if ((*head)->next == NULL) {
        printf("Valor não encontrado! \n");
        return;
    }

    Node *walk = *head;
    while (walk->next && walk->next->data != value) {
        walk = walk->next;
    }

    if (!walk->next) {
        printf("Valor não encontrado! \n");
        return;
    }

    Node *delete = walk->next;
    
    if (delete->next == NULL) {
        delete_last(head);
        return;
    } else {
        walk->next = delete->next;
        delete->next->prev = walk;
        free(delete);
    }
}
int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert In Order\n");
        printf("4. Remove First\n");
        printf("5. Delete Last\n");
        printf("6. Delete X\n");
        printf("7. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_first(&head, value);
                if (tail == NULL) tail = head;
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_last(&head, value);
                if (tail == NULL) {
                    tail = head;
                    while (tail && tail->next) tail = tail->next;
                } else {
                    Node *tmp = tail;
                    while (tmp && tmp->next) tmp = tmp->next;
                    tail = tmp;
                }
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_ordered(&head, value);
                if (tail == NULL) {
                    tail = head;
                    while (tail && tail->next) tail = tail->next;
                } else {
                    Node *tmp = tail;
                    while (tmp && tmp->next) tmp = tmp->next;
                    tail = tmp;
                }
                break;
            case 4:
                delete_first(&head);
                if (head == NULL) tail = NULL;
                break;
            case 5:
                delete_last(&head);
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete_x(&head, value);
                break;
            case 7:
                display(head);
                printf("\n");
                break;
            case 0:
                // Free all nodes before exit
                while (head) delete_first(&head);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}