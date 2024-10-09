#include <stdio.h>
#include <malloc.h>
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

void insertFirst(Node **head, Node **tail, int num);

void insertLast(Node **head, Node **tail, int num);
void insertOrdered(Node **head, Node **tail, int value);
void display(Node *head, Node *tail);

int main(){
    Node *head=NULL;
    Node *tail=NULL;
    int op, num, before;
    do{
        display(head, tail);
        printf("1- Inserir no final: \n");
        printf("2- Inserir no final: \n");
        printf("3- Inserir Ordenado: \n");
        printf("2- Inserir no final: \n");
        printf("Escolha sua opção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Numero: ");
            scanf("%d", &num);
            insertFirst(&head, &tail, num);
            break;
        case 2:
            printf("Numero: ");
            scanf("%d", &num);
            insertLast(&head, &tail, num);
            break;
        case 3:
            printf("Numero: ");
            scanf("%d", &num);
            insertOrdered(&head, &tail, num);
            break;
        default:
            break;
        }
    }while (op!=0);

    return 0;
}

void insertLast(Node **head, Node **tail, int num){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=num;
    newNode->next=*head;
    newNode->prev=*tail;
    
// [3] <-> [4] <-> [6] <-> [3] <--> *(2)

    if(*head==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        *head=newNode;
        *tail=newNode;
        return;
    }
        (*tail)->next = newNode;  // O antigo último nó aponta para o novo nó
        (*head)->prev=newNode;
        *tail=newNode;        
    
}

void insertFirst(Node **head, Node **tail, int num){
Node *newNode=(Node*)malloc(sizeof(Node));

newNode->data=num;
newNode->next=*head;
newNode->prev=*tail;

if(*head==NULL){
    newNode->next=newNode;
    newNode->prev=newNode;
    *head=newNode;
    *tail=*head;
    return;
}
(*head)->prev=newNode;
(*tail)->next=newNode;
*head=newNode;

// *(2) <--> [3] <-> [4] <-> [6] <-> [3] ^

}
void insertBeforeX(Node **head, Node **tail,int element_after , int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;

    if(*head==NULL || element_after ==(*head)->data){
        insertFirst(head, tail, value);
        return;
    }
    Node *walk=head;
    //ex: [3] <-> *(4) <-> [5] <-> [7]
    while(walk->next && walk->next->data != element_after ){
       walk=walk->next; 
    }
    if(!walk->next){
        insertLast(head, tail, value);
        return;
    }
    newNode->prev=walk;
    newNode->next=walk->next;
    walk->next->prev=newNode;
    walk->next=newNode;
 
}

void insertAfterX(Node **head, Node **tail,int element_before , int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;

    if(*head==NULL){
        insertFirst(head, tail, value);
        return;
    }
    if((*head)->data ==element_before){

        newNode->prev=*head;
        newNode->next=(*head)->next;
        (*head)->next->prev=newNode;
        (*head)->next=newNode;
        
    }
    Node *walk=head;
    while(walk->next && walk->data!=element_before){
        walk=walk->next;
    }
    if(!walk->next){
        insertLast(head, tail, value);
        return;
    }

    Node *walk=head;
    //ex: [3] <-> *(4) <-> [5] <-> [7]
    while(walk->next && walk->next->data != element_before ){
       walk=walk->next; 
    }
    if(!walk->next){
        insertLast(head, tail, value);
        return;
    }
    newNode->prev=walk;
    newNode->next=walk->next;
    walk->next->prev=newNode;
    walk->next=newNode;
 
}

void insertOrdered(Node **head, Node **tail, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;

    if(*head==NULL || (*head)->data > value){
        insertFirst(head, tail, value);
        return;
    }
    Node *walk=*head;

    while(walk->next && walk->next->data < value){//3 <-> 6 <-> 7
        walk=walk->next;                        //*(4)
    }
    if(!walk->next){
        insertLast(head, tail, value);
        return;
    }
    //     ~~~
    // <-> [3] <--> *(4) <-> [6] <-> [4] <-> 

    newNode->prev=walk;

    newNode->next=walk->next;
    
    walk->next->prev=newNode;

    walk->next=newNode;

}

void removeFirst(struct Node **head, struct Node **tail){

    struct Node *delete=*head;
    if(!(*head)) return;

    if (*head == *tail) {
        *head = *tail = NULL;
    
    } else {
        (*head) = (*head)->next;
        (*tail)->next = (*head);
    }


    free(delete);

}

void removeLast(struct Node **head, struct Node **tail){
    if(!(*head)) return;

    struct Node *walk = *head;
    if (*head == *tail) {
        free(head);
        *head = *tail = NULL;
    
    } 
    while (walk->next != *tail)
    {
        walk=walk->next;
    }

    walk->next=*head;
    free(tail);

    *tail=walk;

}

void removeX(Node **head, Node **tail, int target){
    if(*head == NULL) return;

    Node *delete = NULL;
    Node *walk = *head;

    // If the node to be deleted is the head node
    if((*head)->data == target) {
        removeFirst(head, tail);
        return;
    }

    // Traverse the list to find the node to delete
    while(walk->next != *head && walk->next->data != target) {
        walk = walk->next;
    }

    // If the node to be deleted is the tail node
    if((*tail)->data == target) {
        removeLast(head, tail);
        return;
    }

    // If the node was not found
    if(walk->next == *head) {
        printf("Not found!\n");
        return;
    }

    // Node found, perform deletion
    delete = walk->next;
    walk->next = delete->next;
    delete->next->prev = walk;

    free(delete);
}

void display(Node *head, Node *tail){
    if(head==NULL) return;
    
    Node *walk=head;
    printf("NORMAL: \n");
    do{
        printf("%d  <-> ", walk->data);
        walk=walk->next;
    }while(walk!=head);
    printf("\n");

    walk=tail;

    printf("INVERTIDA: \n");
    do{
        printf("%d  <-> ", walk->data);
        walk=walk->prev;
    }while(walk!=tail);
    printf("\n");


}

/*
void display(Node *head, Node *tail){
    if(head==NULL) return;
    
    Node *walk=head;
    printf("NORMAL: \n");
    do{
        printf("%d  <-> ", walk->data);
        walk=walk->next;
    }while(walk!=head);
    printf("\n");

    walk=tail;

    printf("INVERTIDA: \n");
    do{
        printf("%d  <-> ", walk->data);
        walk=walk->prev;
    }while(walk!=tail);
    printf("\n");
}*/