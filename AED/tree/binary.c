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

static int flag=0;

int main(){
Node *root=NULL;

insertInOrder(&root, 3);
insertInOrder(&root, 1);
insertInOrder(&root, 4);
insertInOrder(&root, 2);
insertInOrder(&root, 5);


displayPreOrder(root);
printf("\n");
flag=1;
displayInOrder(root);
flag=1;
printf("\n");
displayPostOrder(root);
printf("\n");


return 0;
}

void displayInOrder(Node *root){
if(root!=NULL){
    if (flag==0){
        printf("Root: %d\n", root->data);
        flag=1;
    }
    displayInOrder(root->left);
    printf("%d - ", root->data);
    displayInOrder(root->right);
}
}

void displayPreOrder(Node *root){

if(root!=NULL){
    if (flag==0){
        printf("Root: %d\n", root->data);
        flag=1;
        return;
    }
    printf("%d -", root->data);
    displayPreOrder(root->left);
    displayPreOrder(root->right);
}

}

void displayPostOrder(Node *root){

if(root!=NULL){
        if (flag==0){
        printf("Root: %d\n", root->data);
        flag=1;
    }
    displayPostOrder(root->left);
    displayPostOrder(root->right);
    printf("%d -", root->data);
}

}

void insertInOrder(Node **root, int data){
    if(*root==NULL){
        if(flag==0){
            printf("Root: %d\n", data);
            flag=1;
        }
        (*root)=(Node*)malloc(sizeof(Node));
        (*root)->data=data;
        (*root)->left=NULL;
        (*root)->right=NULL;
        return;
    }

    if(data < (*root)->data){
        insertInOrder(&(*root)->left, data);
        printf("Node %d inserted at left!\n", (*root)->data);
        return;
    }
    
    else if(data > (*root)->data){
        insertInOrder(&(*root)->right, data);
        printf("Node %d inserted at right!\n", (*root)->data);
        return;
    }
    //desconsideramos aqui o caso onde eles são iguais
}


//3) Crie uma função (recursiva) que retorne o nó que apresentar a chave de maior valor na árvore
Node* findMax(Node *root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->right == NULL) {
        return root;
    }
    return findMax(root->right);
}

/*
01 - Crie uma função em C que indique a altura de uma árvore.


02 - Considere a função de remoção de nós e explique todo o trecho de código que trata do caso de remoção quando o nó:
a) não tem filhos
b) tem apenas um dos filhos
c) tem os dois filhos

*/