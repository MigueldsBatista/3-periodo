#include <stdio.h>
#include <stdlib.h>
// https://www.inf.ufsc.br/~aldo.vw/estruturas/simulador/AVL.html

typedef struct Node {
  int num;
  struct Node *left;
  struct Node *right;
} Node;

int level(Node *root);

void shift_right(Node **primary);

void shift_left(Node **primary);

void balance(Node **primary);

void inserir(Node **root, int data);

void preordem(Node *root);

void remover(Node **root, int numero);

Node *findMaxRight(Node *node);

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

int level(Node *root) {
  if (root == NULL)
    return 0;
  else {
    int ae = level(root->left);
    int ad = level(root->right);
    return 1 + (ae > ad ? ae : ad);
  }
}

void shift_right(Node **primary) {
  Node *newPrimary = (*primary)->left;
  (*primary)->left = newPrimary->right;
  newPrimary->right = (*primary);
  *primary = newPrimary;
}

void shift_left(Node **primary) {
  Node *newPrimary = (*primary)->right;
  (*primary)->right = newPrimary->left;
  newPrimary->left = (*primary);
  *primary = newPrimary;
}

void balance(Node **primary) {
  // Verifica se o nó atual não é nulo
  if(*primary != NULL){
    Node *aux; // Nó auxiliar para ajudar nas rotações

    // Calcula o fator de balanceamento: diferença entre os níveis da subárvore direita e esquerda
    int balance = level((*primary)->right) - level((*primary)->left);

    // Caso o fator de balanceamento seja menor ou igual a -2 (desbalanceamento à esquerda)
    if (balance <= -2) {
      aux = (*primary)->left; // Aponta para o nó filho esquerdo

      // Calcula o fator de balanceamento do filho esquerdo
      balance = level(aux->right) - level(aux->left);

      // Caso o filho esquerdo tenha um desbalanceamento positivo (direita), realizamos rotação dupla
      if (balance >= 1) {
        shift_left(&((*primary)->left)); // Rotação para a esquerda no filho esquerdo
        shift_right(primary);           // Rotação para a direita no nó atual
        printf("\nRotação: Dupla Direita");
      } else {
        // Caso contrário, realizamos apenas uma rotação simples para a direita
        shift_right(primary);
        printf("\nRotação: Direita Simples");
      }
    } 
    // Caso o fator de balanceamento seja maior ou igual a 2 (desbalanceamento à direita)
    else if (balance >= 2) {
      aux = (*primary)->right; // Aponta para o nó filho direito

      // Calcula o fator de balanceamento do filho direito
      balance = level(aux->right) - level(aux->left);

      // Caso o filho direito tenha um desbalanceamento negativo (esquerda), realizamos rotação dupla
      if (balance < 0) {
        shift_right(&((*primary)->right)); // Rotação para a direita no filho direito
        shift_left(primary);              // Rotação para a esquerda no nó atual
        printf("\nRotação: Dupla Esquerda");
        
      } else {//balanço == 0 por exemplo
        // Caso contrário, realizamos apenas uma rotação simples para a esquerda
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

int findLevel(Node **root){

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

Node *findMaxRight(Node *node) {
  // Caso o nó atual tenha um filho à direita, continuamos descendo à direita
  if (node->right != NULL)
    return findMaxRight(node->right); // Recursão para o filho à direita

  // Se chegamos aqui, significa que encontramos o nó mais à direita (sem filhos à direita)
  return node; // Retorna o nó mais à direita
}