#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

void inserir(Node **head, Node **tail, int value);
void display(Node *head);
void delete_first(Node **head, Node **tail);
void deleteX(Node **head, Node **tail, int target);

void delete_last(Node **head, Node **tail);
void excluieIguais(Node **head, Node **tail, Node **head2, Node **tail2);

int main() {
  Node *head = NULL;
  Node *tail = NULL;

  Node *head2=NULL;
  Node *tail2 = NULL;

  inserir(&head, &tail, 60);
  inserir(&head, &tail, 73);
  inserir(&head, &tail, 27);
  //deleteX(&head, &tail, 45);
  display(head);
    printf("\n");

    printf("Nova lista!\n");

  inserir(&head2, &tail2, 27);
  inserir(&head2, &tail2, 73);
  inserir(&head2, &tail2, 60);
    printf("\n");

  printf("Nova lista!\n");

  display(head2);

  printf("\n");

  excluieIguais(&head, &tail, &head2, &tail2);

}

void inserir(Node **head, Node **tail, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  if (*head == NULL) {
    *head = newNode;
    *tail = newNode;
    newNode->prev = newNode;
    newNode->next = newNode;
    return;
  } 

    newNode->next = *head;
    newNode->prev = *tail;
    (*head)->prev = (*tail)->next = newNode;
    *head = newNode;
  
}

void display(Node *head){
if(head==NULL){
    printf("Vazio");
    return;
}
Node *walk=head;
do{
  printf("%d <->", walk->data);
  walk=walk->next;
}while(walk!=head);

}
void deleteX(Node **head, Node **tail, int target){
if(*head==NULL){
  printf("Not found!\n");
  return;
}
if((*head)->data==target){
  delete_first(head, tail);
  return;
}

if((*tail)->data==target){
  delete_last(head, tail);
  return;
}

Node *delete;
Node *walk=*head;

while(walk->next->data!=target){
  walk=walk->next;
}

if(walk->next==*head){
  printf("Not found!\n");
  return;
}
delete=walk->next;

walk->next=delete->next;

delete->next->prev=walk;

free(delete);

}

void delete_first(Node **head, Node **tail){
Node *delete=*head;

(*tail)->next=(*head)->next;
(*head)->next->prev=*tail;

(*head)=(*head)->next;

free(delete);
}

void delete_last(Node **head, Node **tail){
Node *delete=*tail;

(*head)->prev=(*tail)->prev;
(*tail)->prev->next=*head;

(*tail)=(*tail)->prev;

free(delete);
}

void excluieIguais(Node **head1, Node **tail1, Node **head2, Node **tail2){

if(*head1==NULL || *head2 == NULL) return;

if((*head1)->data == (*head2)->data){
  int target= (*head1)->data;
  delete_first(head2, tail2);
  printf("Elemento %d excluido\n", target);
  display(*head2);

}

if((*head1)->data == (*tail2)->data){
  int target= (*head1)->data;
  delete_last(head2, tail2);
  printf("Elemento %d excluido\n", target);
  display(*head2);
}
for(Node *walk1=(*head1) ; walk1->next!=*head1 ; walk1=walk1->next){

  for(Node *walk2 = (*head2); walk2->next!=*head2; walk2=walk2->next){

    if(walk1->data==walk2->data){
      
      int target=walk1->data;
      printf("Elemento %d excluido\n", target);
      deleteX(head2, tail2, target);
      display(*head2);

    }

  }
}

}


