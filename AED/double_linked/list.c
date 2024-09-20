#include <stdio.h>
typedef struct Node{
    int data;
    Node *next;
    Node *prev
}Node;


void insert_first(Node **head, int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data=data;//steps 

    new_node->next=*head;

    new_node->prev=NULL;

    if(*head){//caso a lista ja tenha elementos, precismaos linkar o anterior com o novo no
        (*head)->prev=new_node;
    }
    (*head)=new_node;//agora alteramos propiamente dito a lista

}

void insert_last(Node **head, int data){
Node *new_node=(Node*)malloc(sizeof(Node));
Node *temp=*head;

new_node->data=data;
new_node->next=NULL;

if(!(*head)){
*head=new_node;
new_node->prev=NULL;//ja que é o primeiro elemento
}

while(temp->next){
    temp->next;

}   temp->next=new_node;
    new_node->prev=temp;//ultimo atual
}

void insert_middle(Node **head, int data, int ant){
Node *newNode=(Node*)malloc(sizeof(Node));
//é o primeiro? next e prev são nulos entao
Node*walk=*head;
newNode->data=data;

if(!(*head)){
    newNode->prev=NULL;
    newNode->next=NULL;
}

while(walk->data!=ant && walk->next){
    walk=walk->next;
}
newNode->next=walk->next;
walk->next->prev;
walk->next=newNode;


}

void insert_ordered(Node **head, int data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;

    if(!(*head)){//lista esta vazia?
        
        newNode->next=  NULL;
        newNode->prev=NULL;
        *head=newNode;
    }
    else if(newNode->data < (*head)->data){//é menor que nosso primeiro elemento atual
        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;
    }

    else{
        Node *walk=head;//1 3 5 7 <- [4]
        while(walk->next && newNode->data < walk->next->data){
            walk=walk->next;
        }
        newNode->next=walk->next;

        walk->next->prev=newNode;

        newNode->prev=walk;

        walk->next=newNode;
    }

}
void delete_first(Node **head){

}
void delete_last(Node **head){

}

void delete_after_x(Node **head, int before_element){

}

void print_list(Node *head){
    
}

int main(){

}
