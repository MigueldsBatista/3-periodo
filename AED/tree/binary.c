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
int level(Node **root);
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

printf("Altura: %d\n", level(&root));


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
    // desconsideramos aqui o caso onde eles são iguais
}
int findMax(Node *root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return -1; // Assuming all node values are positive
    }

    if (root->right == NULL) {
        return root->data;
    }

    return findMax(root->right);
}


int busca(Node *root, int target){
    if(root->data==target){
        return 1;
    }
    else if (root==NULL){
        return 0;
    }
    else if(root->data < target){
        busca(root->right, target);
    }
    else{
        busca(root->left, target);
    }
}

/*
Nó não possui filhos
    - Se o nó a ser removido não possui filhos (é uma folha), 
    basta liberar a memória alocada para esse nó e ajustar o ponteiro do pai para NULL.

Nó possui um filho unico
    - Se o nó a ser removido possui um único filho, o ponteiro do pai do nó a ser removido deve ser ajustado para apontar para o filho do nó a ser removido. 
    Em seguida, liberar a memória alocada para o nó removido.

Nó possui dois filhos
    - Se o nó a ser removido possui dois filhos, deve-se encontrar o sucessor in-order (o menor nó na subárvore direita) ou o predecessor in-order (o maior nó na subárvore esquerda). 
    Copiar o valor do sucessor ou predecessor para o nó a ser removido e, em seguida, remover o sucessor ou predecessor, que terá no máximo um filho.


    Esquerda Vão os menores e direita Maiores
*/

int travelRight(Node *root, int level){
   if(root->right==NULL){
    return level++;
   }
   else{
    travelRight(root->right, level++);
   } 
}

int travelLeft(Node *root, int level){
   if(root->left==NULL){
    return level++;
   }
   else{
    travelLeft(root->left, level++);
   } 
}

int level(Node **root){

    if(*root==NULL) return -1;

    int alturaEsquerda = level(&(*root)->left);
    int alturaDireita = level(&(*root)->right);

    if(alturaEsquerda > alturaDireita){
        return alturaEsquerda + 1;

    }else{
        return alturaDireita + 1;
    }
}