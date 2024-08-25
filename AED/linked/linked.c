#include <stdio.h>
struct Node{
    int data;
    struct Node *next;
};


void insert_first(struct Node **head, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;//steps 
    new_node->next=NULL;
    (*head)=new_node;

}
void insert_last(struct Node **head, int data){
struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
struct Node *temp=*head;

new_node->next=NULL;
new_node->data=data;

while(temp->next){
    temp->next;
}   temp->data=new_node;
}

void insert_middle(struct Node **head, int data, int next_element){

}

void delete_first(struct Node **head){

}
void delete_last(struct Node **head){

}

void delete_after_x(struct Node **head, int before_element){

}

void print_list(struct Node *head){
    
}

int main(){

}
