/*
As ordens estão relacionadas a quando
vamos percorrer o nó da raiz

Pre Order - Percorremos a raiz antes dos outros
In Order - No meio do processo
Post Order - No final do processo


Left 
Right
Primary

*/

//Pre order primary left right(PLR)

//In Order left primary right(LPR)

//Post Order left right primary(LRP)

// if data menor  left and data maior right insert in root
//if data menor root and data menor que right insert in left
//if data maior root and data maiir left insert in right

/*
    1
   | |
   2 3
 | | | |
6  7 8  9
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
struct Node *left;
struct Node *right;
int data;
}Node;

void insertInOrder(Node **root, int data);

void displayInOrder(Node *root);
void displayPostOrder(Node *root);
void displayPreOrder(Node *root);


int main(){
Node *root=NULL;

insertInOrder(&root, 3);
insertInOrder(&root, 4);
insertInOrder(&root, 5);
insertInOrder(&root, 7);
insertInOrder(&root, 8);
insertInOrder(&root, 9);
insertInOrder(&root, 10);

displayPreOrder(root);
printf("\n");
displayInOrder(root);
printf("\n");
displayPostOrder(root);
printf("\n");


return 0;
}

void displayInOrder(Node *root){
if(root!=NULL){
    printf("%d - ", root->data);
    displayInOrder(root->left);
    displayInOrder(root->right);
}
}

void displayPreOrder(Node *root){

if(root!=NULL){
    displayPreOrder(root->left);
    displayPreOrder(root->right);
    printf("%d -", root->data);
}

}

void displayPostOrder(Node *root){

if(root!=NULL){
    displayPostOrder(root->left);
    printf("%d -", root->data);
    displayPostOrder(root->right);
    
}

}

void insertInOrder(Node **root, int data){
    if(*root==NULL){
        (*root)=(Node*)malloc(sizeof(Node));
        (*root)->data=data;
        (*root)->left=NULL;
        (*root)->right=NULL;
        printf("Node %d inserted!\n", (*root)->data);
        return;
    }

    if((*root)->data < data){
        insertInOrder(&(*root)->left, data);
        return;
    }
    
    else if((*root)->data > data){
        insertInOrder(&(*root)->right, data);
        return;

    }
    //desconsideramos aqui o caso onde eles são iguais
}