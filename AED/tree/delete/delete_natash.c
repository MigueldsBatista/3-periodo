#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *left;
  struct Node *right;
}Node;

void remove(Node **root, int num) {
  if (*root == NULL) {
  printf("Numero nao existe na arvore!");
  return;
  }

  if (num < (*root)->data){
  remove(&(*root)->left, num);
  return;
  }

  if (num > (*root)->data){
  remove(&(*root)->right, num);
  return;
  }

  Node *walk = *root;

  if (((*root)->left == NULL) && ((*root)->right == NULL)) {
  free(walk);
  (*root) = NULL;
  }
  else {
  if ((*root)->left == NULL) {
    (*root) = (*root)->right;
    walk->right = NULL;
    free(walk);
  } else {
    if ((*root)->right == NULL) {
    (*root) = (*root)->left;
    walk->left = NULL;
    free(walk);
    }
    else {
    walk = findMaxRight(&(*root)->left);
    walk->left = (*root)->left;
    walk->right = (*root)->right;
    free(*root);
    *root = walk;
    }
  }
  }
}
