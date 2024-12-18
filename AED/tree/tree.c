#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

void inserir(Node **root, int value);

void displayInOrder(Node *root);
void displayPostOrder(Node *root);
void displayPreOrder(Node *root);

int search(Node *root, int n);
void remove(Node **root, int num);

Node *findMaxRight(Node *primary);

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
  displayPreOrder(root);

  printf("\nIN-ordem:");
  displayInOrder(root);

  printf("\nPOS-ordem:");
  displayPostOrder(root);
  printf("\n\n");

  if (search(root,15)) {
    printf("\nO num está na arvore!\n");
  } else {
    printf("O num NAO está na arvore!\n");
  }

  printf("\nPre-ordem:");
  displayPreOrder(root);
  printf("\n");

  remove(&root, 30);

  printf("\nPrint após remoção (Pre-ordem):");
  displayPreOrder(root);
  printf("\n");

  return 0;
}

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

void inserir(Node **root, int n) {
  
  if (*root == NULL) {
    *root = (Node *)malloc(sizeof(Node));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->data = n;
  }
   else {
    if (n < (*root)->data) {
      inserir(&(*root)->left, n);
    }
    else if (n > (*root)->data) {
      inserir(&(*root)->right, n);
    }

  }
}

int search(Node *root, int n) {
  if (root == NULL) return 0;

  else if (root->data == n) return 1;

  //
  else if (n < root->data){
    search(root->left, n);
  }else{
    search(root->right, n);
  }
}




void remove(Node **root, int num) {
  if (*root == NULL) {
    printf("Numero nao existe na arvore!");
    return;
  }
  //numero é menor que o numero da raiz
  if (num < (*root)->data)
    remove(&(*root)->left, num);

    //numero é maior que o numero da raiz
  else if (num > (*root)->data)
    remove(&(*root)->right, num);


  else {
    Node *walk = *root;
    // 01 - primary sem filhos

    //se o primary for uma folha ele é removido
    if (((*root)->left == NULL) && ((*root)->right == NULL)) {
      free(walk);
      (*root) = NULL;

    }
     else {
    
      // 02 - primary com filho direito
      if ((*root)->left == NULL) {
        (*root) = (*root)->right;
        walk->right = NULL;
        free(walk);

      } else {
        // 02.5 - primary com filho esquerdo
        if ((*root)->right == NULL) {
          (*root) = (*root)->left;
          walk->left = NULL;
          free(walk);

        }
         else {
          // 03 - primary com dois filhos
          walk = findMaxRight(&(*root)->left);
          walk->left = (*root)->left;
          walk->right = (*root)->right;
          free(*root);
          *root = walk;
        }
      }

    }
  }
}
