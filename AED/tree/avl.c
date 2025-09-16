#include <stdio.h>
#include <stdlib.h>
// https://www.inf.ufsc.br/~aldo.vw/estruturas/simulaltura_direitaor/AVL.html
// https://www.inf.ufsc.br/~aldo.vw/estruturas/simulador/AVL.html


typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

int level(Node *root);

void shift_right(Node **primary);

void shift_left(Node **primary);

void balance(Node **primary);

void insert(Node **root, int valuevoid );

void display_pre_order(Node *root);

void remove_node(Node **root, int target);

Node *find_max_right(Node *node);

int main() {
  Node *root = NULL;

  insert(&root, 5);
  insert(&root, 3);
  insert(&root, 8);
  insert(&root, 4);
  printf("%d",level(root));

  insert(&root, 3);
  insert(&root, 1);

  printf("\nPRE-ordem:");
  display_pre_order(root);
  printf("\n");

  return 0;
}

int level(Node *root) {
  if (root == NULL) return 0;

    int altura_esquerda = level(root->left);
    int altura_direita = level(root->right);
    return 1 + (altura_esquerda > altura_direita ? altura_esquerda : altura_direita);
  
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
  if(*primary == NULL) return;

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
      printf("\nRotação: Dupla Esquerda no nó");
      
    } else {//balanço == 0 por exemplo
      // Caso contrário, realizamos apenas uma rotação simples para a esquerda
      shift_left(primary);
      printf("\nRotação: Esquerda Simples");
    }
  }

}


void display_pre_order(Node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    display_pre_order(root->left);
    display_pre_order(root->right);
  }
}

void insert(Node **root, int value){
  if(*root==NULL){
    *root = (Node*)malloc(sizeof(Node));
    (*root)->data=value;
    (*root)->left=NULL;
    (*root)->right=NULL;
  }
  if(value < (*root)->data){
    insert(&(*root)->left, value);
  }
  else if(value > (*root)->data){
    insert(&(*root)->right, value);
  }
  balance(root);
}

void remove_node(Node **root, int target) {
  if (*root == NULL) {
    printf("\nRemoção: Numero nao existe na arvore!");
    return;
  }
  else if (target < (*root)->data)
    remove_node(&(*root)->left, target);
  else if (target > (*root)->data)
    remove_node(&(*root)->right, target);
  else {
    Node *walk = *root;
    // 01 - node sem filhos
    if (((*root)->left == NULL) && ((*root)->right == NULL)) {
      free(walk);
      (*root) = NULL;
    } 
    else {
      // 02 - node com filho direito
      if ((*root)->left == NULL) {
        (*root) = (*root)->right;
        walk->right = NULL;
        free(walk);
        walk = NULL;
      } 
      else {
        // 02 - node com filho esquerdo
        if ((*root)->right == NULL) {
          (*root) = (*root)->left;
          walk->left = NULL;
          free(walk);
          walk = NULL;
        } else {
          // 03 - node com dois filhos
          walk = find_max_right((*root)->left);
          walk->left = (*root)->left;
          walk->right = (*root)->right;
          (*root)->left = (*root)->right = NULL;
          free((*root));
          *root = walk;
          walk = NULL;
        }
      }
    }
  }
  balance(root);
}

Node *find_max_right(Node *node) {
  // Caso o nó atual tenha um filho à direita, continuamos descendo à direita
  if (node->right != NULL)
    return find_max_right(node->right); // Recursão para o filho à direita

  // Se chegamos aqui, significa que encontramos o nó mais à direita (sem filhos à direita)
  return node; // Retorna o nó mais à direita
}