#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    Node *left;
    Node *right;
}Node;

//preciso nem comentar sobre essas funções né...
//o prefixo do nome se refere a quando o nó raiz é percorrido
//ou seja, pré ordem ele é impresso antes, em ordem, durante a mudança de lado
//pós ordem, depois de percorrer os dois lados

void displayPreOrder(Node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    displayPreOrder(root->left);
    displayPreOrder(root->right);
  }

}

void displayInOrder(Node *root) {
  if (root != NULL) {
    displayInOrder(root->left);
    printf("%d ", root->data);
    displayInOrder(root->right);
  }
}

void displayPostOrder(Node *root) {
  if (root != NULL) {
    displayPostOrder(root->left);
    displayPostOrder(root->right);
    printf("%d ", root->data);
  }
}