#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    Node *left;
    Node *right;
}Node;


void inserir(Node **primary, int value) {
  
  //se chegamos numa folha, alocamos memoria e 
  //fazemos a inserção
  if (*primary == NULL) {
    *primary = (Node *)malloc(sizeof(Node));
    (*primary)->left = NULL;
    (*primary)->right = NULL;
    (*primary)->data = value;
  }//se não, vamos percorrendo a árvore seguindo a logica de arvóres binárias
  //ou seja raiz maior que esquerda e menor que direita
   else {

    //caso o valor seja menor que o nó atual
    if (value < (*primary)->data) {
      inserir(&(*primary)->left, value);
    }
    //caso o valor seja maior que o nó atual da arvóre
    else if (value > (*primary)->data) {
      inserir(&(*primary)->right, value);
    }

  }
}