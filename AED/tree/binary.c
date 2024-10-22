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
int getLevel(Node **root);
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

printf("Altura: %d\n", getLevel(&root));


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
/**
 * @brief Calculates the height of a binary tree.
 *
 * This function computes the height (or level) of a binary tree recursively.
 * The height of a binary tree is the number of edges on the longest path from 
 * the root node to a leaf node. An empty tree has a height of -1.
 *
 * @param root A double pointer to the root node of the binary tree.
 * @return The height of the binary tree. Returns -1 if the tree is empty.
 */

int getLevel(Node **root){

    if(*root==NULL) return -1;

    int alturaEsquerda = getLevel(&(*root)->left);
    int alturaDireita = getLevel(&(*root)->right);

    if(alturaEsquerda > alturaDireita){
        return alturaEsquerda + 1;

    }else{
        return alturaDireita + 1;
    }
}