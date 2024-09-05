#include <stdio.h>
#include <stdlib.h>


typedef struct Node{ 
int data; 
struct Node *next; 
struct Node *prev; 
} Node;
void insertFirst(Node **head, int value);

void insertOrdered(Node **head, int value);

int main(){

return 0;
}

void insertOrdered(Node **head, int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(*head == NULL){  // Lista vazia
        *head = newNode; 
        return;
    }

    Node *current = *head;

    // Caso o novo valor deva ser inserido no início da lista
    if(current->data > value){
        newNode->next = current;
        current->prev = newNode;
        *head = newNode;
        return;
    }

    // Encontrar a posição correta para inserir
    while(current->next != NULL && current->next->data < value){
        current = current->next;
    }

    // Inserir o novo nó na lista
    newNode->next = current->next;
    newNode->prev = current;

    if(current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;
}

void insertFirst(Node **head, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=*head;//proximo é a nossa head atual
    newNode->prev=NULL;//sempre null pois é o primeiro elemento

    if(*head!=NULL){
        (*head)->prev=newNode;
    }
    *head=newNode;
}

Node* intercalar(Node *head1, Node *head2){
    Node *head3=NULL;
    while (head1 || head1)
    {
        if(head1){
            insertFirst(&head3, head1->data);
            head1=head1->next;

        }
        if(head2){
            insertFirst(&head3, head2->data);
            head2=head2->next;

        }
    }
    return head3;
}

void printNode(Node *head){
    while(head){
        printf("%d", head->data);
        head=head->next;
    }
}

void searchElement(Node *head, int value){
    int encontrado = 0;
    int before = 0;
    int after = 0;

    if(head == NULL){  // Lista vazia
        printf("0 elementos antes.\n0 elementos depois.\n"); 
        return;
    }

    // Encontrar o valor na lista
    while(head != NULL){
        if(head->data == value){
            encontrado = 1;
            break;
        }
        head = head->next;
        before++;
    }

    if(encontrado){
        Node *temp = head->next; // Posição do próximo elemento
        while(temp != NULL){
            after++;
            temp = temp->next;
        }
        printf("%d elementos antes.\n%d elementos depois.\n", before, after);
    } else {
        printf("%d elementos antes.\n0 elementos depois.\n", before);
    }
}



    // Inserir o novo nó na lista

