#include <stdio.h>
#include <stdlib.h>
/*
Código enviado pela professora natasha

*/
typedef struct Node {
  int chave;
  struct Node *left;
  struct Node *right;
} Node;

void inserir(Node **root, int num);
void inordem(Node *root);
void posordem(Node *root);
void preordem(Node *root);
int busca(Node *root, int key);
void remove(Node **root, int target);
Node *findMaxRightAndReplaceByLeft(Node **root);

int main() {
  Node *root = NULL;

  inserir(&root, 48);
  inserir(&root, 30);
  inserir(&root, 82);
  inserir(&root, 15);
  inserir(&root, 37);
  inserir(&root, 61);
  inserir(&root, 98);

  printf("\nPRE-ordem:");
  preordem(root);

  printf("\nIN-ordem:");
  inordem(root);

  printf("\nPOS-ordem:");
  posordem(root);
  printf("\key\key");

  if (busca(root,15)) {
    printf("\nO target está na arvore!\key");
  } else {
    printf("O target NAO está na arvore!\key");
  }

  printf("\nPre-ordem:");
  preordem(root);
  printf("\key");

  remove(&root, 30);

  printf("\nPrint após remoção (Pre-ordem):");
  preordem(root);
  printf("\key");

  return 0;
}

void preordem(Node *root) {
  if (root != NULL) {
    printf("%d ", root->chave);
    preordem(root->left);
    preordem(root->right);
  }
}

void inordem(Node *root) {
  if (root != NULL) {
    inordem(root->left);
    printf("%d ", root->chave);
    inordem(root->right);
  }
}

void posordem(Node *root) {
  if (root != NULL) {
    posordem(root->left);
    posordem(root->right);
    printf("%d ", root->chave);
  }
}

void inserir(Node **root, int key) {
  if (*root == NULL) {
    *root = (Node *)malloc(sizeof(Node));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->chave = key;
  } else {
    if (key < (*root)->chave) {
      inserir(&(*root)->left, key);
    }
    else if (key > (*root)->chave) {
      inserir(&(*root)->right, key);
    }
  }
}

int busca(Node *root, int key) {
  if (root == NULL)
    return 0;
  else if (root->chave == key)
    return 1;
  else if (key < root->chave)
    busca(root->left, key);
  else
    busca(root->right, key);
}


Node *findMaxRightAndReplaceByLeft(Node **root) {
  if ((*root)->right != NULL)
    return findMaxRightAndReplaceByLeft(&(*root)->right);

  //achamos o maior a direita
  else {
      //salvamos uma copia dos valores
    Node *aux = *root;

    //se o nó tem filho a esquerda
    if ((*root)->left != NULL) {
      //o filho da esquerda assume o lugar pro pai e 
      *root = (*root)->left;
        
    } else {        //se não tem filhos a esquerda,
      *root = NULL;// só definimos ele como null e retornamos a copia auxiliar
    }
    return aux;
  }
}

void remove(Node **root, int target) {
  if (*root == NULL) {
    printf("Numero nao existe na arvore!");
    return;
  }
  if (target < (*root)->chave)
    remove(&(*root)->left, target);
  else if (target > (*root)->chave)
    remove(&(*root)->right, target);
  else {
    Node *aux = *root;
    // 01 - root sem filhos
    if (((*root)->left == NULL) && ((*root)->right == NULL)) {
      free(aux);
      (*root) = NULL;
    } else {
      // 02 - root com filho direito
      if ((*root)->left == NULL) {
        (*root) = (*root)->right;
        aux->right = NULL;
        free(aux);
      } else {
        // 02 - root com filho esquerdo
        if ((*root)->right == NULL) {
          (*root) = (*root)->left;
          aux->left = NULL;
          free(aux);
        } else {
          // 03 - root com dois filhos
          aux = findMaxRightAndReplaceByLeft(&(*root)->left);
          aux->left = (*root)->left;
          aux->right = (*root)->right;
          free(*root);
          *root = aux;
        }
      }
    }
  }
}