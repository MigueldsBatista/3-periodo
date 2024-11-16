#include <stdio.h>
#include <stdlib.h>
// https://www.inf.ufsc.br/~aldo.vw/estruturas/simulador/AVL.html

typedef struct Node {
  int num;
  struct Node *left;
  struct Node *right;
} Node;

int filhosAlt(Node *root);

void shift_right(Node **primary);
void shift_left(Node **primary);

void balance(Node **primary);

void inserir(Node **root, int data);

void preordem(Node *root);

void remover(Node **root, int numero);

Node *findMaxRight(Node **node);

int main() {
  Node *root = NULL;

  inserir(&root, 6);
  inserir(&root, 10);
  inserir(&root, 15);
  printf("\n>>Rotação devido a inserção do 15\n");

  inserir(&root, 3);
  inserir(&root, 1);
  printf("\n>>Rotação devido a inserção do 1\n");


  printf("\nPRE-ordem:");
  preordem(root);
  printf("\n");




  return 0;
}

int filhosAlt(Node *root) {
  if (root == NULL)
    return 0;
  else {
    int ae = filhosAlt(root->left);
    int ad = filhosAlt(root->right);
    return 1 + (ae > ad ? ae : ad);
  }
}

void shift_right(Node **primary) {
  Node *aux = (*primary)->left;
  (*primary)->left = aux->right;
  aux->right = (*primary);
  *primary = aux;
}

void shift_left(Node **primary) {
  Node *aux = (*primary)->right;
  (*primary)->right = aux->left;
  aux->left = (*primary);
  *primary = aux;
}

void balance(Node **primary) {
  if(*primary != NULL){
    Node *aux;
    int fb = filhosAlt((*primary)->right) - filhosAlt((*primary)->left);

    if (fb <= -2) {
      aux = (*primary)->left;

      fb = filhosAlt(aux->right) - filhosAlt(aux->left);

      if (fb >= 1) {
        shift_left(&((*primary)->left));
        shift_right(primary);
        printf("\nRotação: Dupla Direita");
      } else {
        shift_right(primary);
        printf("\nRotação: Direita Simples");
      }
    } else if (fb >= 2) {
      aux = (*primary)->right;
      fb = filhosAlt(aux->right) - filhosAlt(aux->left);

      if (fb < 0) {
        shift_right(&((*primary)->right));
        shift_left(primary);
        printf("\nRotação: Dupla Esquerda");
      } else {
        shift_left(primary);
        printf("\nRotação: Esquerda Simples");
      }
    }
  }
}

void preordem(Node *root) {
  if (root != NULL) {
    printf("%d ", root->num);
    preordem(root->left);
    preordem(root->right);
  }
}

void inserir(Node **root, int n) {
  if (*root == NULL) {
    *root = (Node *)malloc(sizeof(Node));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->num = n;
  } else if (n < (*root)->num)
    inserir(&(*root)->left, n);
  else if (n > (*root)->num)
    inserir(&(*root)->right, n);

  balance(root);
}

Node *findMaxRight(Node **node) {
  if ((*node)->right != NULL)
    return findMaxRight(&(*node)->right);
  else {
    Node *aux = *node;
    if ((*node)->left != NULL) {
      *node = (*node)->left;
    } else {
      *node = NULL;
    }
    return aux;
  }
}

void remover(Node **root, int numero) {
  if (*root == NULL) {
    printf("\nRemoção: Numero nao existe na arvore!");
    return;
  }
  else if (numero < (*root)->num)
    remover(&(*root)->left, numero);
  else if (numero > (*root)->num)
    remover(&(*root)->right, numero);
  else {
    Node *pAux = *root;
    // 01 - node sem filhos
    if (((*root)->left == NULL) && ((*root)->right == NULL)) {
      free(pAux);
      (*root) = NULL;
    } 
    else {
      // 02 - node com filho direito
      if ((*root)->left == NULL) {
        (*root) = (*root)->right;
        pAux->right = NULL;
        free(pAux);
        pAux = NULL;
      } 
      else {
        // 02 - node com filho esquerdo
        if ((*root)->right == NULL) {
          (*root) = (*root)->left;
          pAux->left = NULL;
          free(pAux);
          pAux = NULL;
        } else {
          // 03 - node com dois filhos
          pAux = findMaxRight(&(*root)->left);
          pAux->left = (*root)->left;
          pAux->right = (*root)->right;
          (*root)->left = (*root)->right = NULL;
          free((*root));
          *root = pAux;
          pAux = NULL;
        }
      }
    }
  }
  balance(root);
}