#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
  int data;
  struct Node *left;
  struct Node *right;
}Node;

Node* insert(Node *root, int data) {
  if (root == NULL) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
  }
  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);
  return root;
}

void inOrder(Node *root) {
  if (root == NULL) return;
  inOrder(root->left);
  printf("%d ", root->data);
  inOrder(root->right);
}

Node* find_max_right_and_disconnect(Node **root) {
  if (*root == NULL) {
    return NULL;
  }
  
  Node *parent = NULL;
  Node *walk = *root;

  if (walk->right == NULL) {
    *root = walk->left;
    return walk;
  }
  
  while (walk->right != NULL) {
    parent = walk;
    walk = walk->right;
  }
  
  parent->right = walk->left;
  
  return walk;
}

void remove_node(Node **root, int num) {
  if (*root == NULL) {
    printf("Numero nao existe na arvore!");
    return;
  }

  bool num_is_smaller_than_root = num < (*root)->data;
  bool num_is_bigger_than_root = num > (*root)->data;

  if (num_is_smaller_than_root) {
    remove_node(&(*root)->left, num);
    return;
  }

  if (num_is_bigger_than_root) {
    remove_node(&(*root)->right, num);
    return;
  }

  Node *walk = *root;

  bool left_node_is_null = (*root)->left == NULL;
  bool right_node_is_null = (*root)->right == NULL;

  if (left_node_is_null && right_node_is_null) {
    free(walk);
    *root = NULL;
    return;
  }

  if (left_node_is_null) {
    *root = (*root)->right;
    walk->right = NULL;
    free(walk);
    return;
  }

  if (right_node_is_null) {
    *root = (*root)->left;
    walk->left = NULL;
    free(walk);
    return;
  }

  walk = find_max_right_and_disconnect(&(*root)->left);
  walk->left = (*root)->left;
  walk->right = (*root)->right;
  free(*root);
  *root = walk;
}

int main() {
  Node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 15);
  printf("Antes de remover folha (5): ");
  inOrder(root); printf("\n");
  remove_node(&root, 5);
  printf("Depois: ");
  inOrder(root); printf("\n\n");

  root = insert(root, 12);
  root = insert(root, 15);
  root = insert(root, 17);
  printf("Antes de remover nó com filho direito (15): ");
  inOrder(root); printf("\n");
  remove_node(&root, 15);
  printf("Depois: ");
  inOrder(root); printf("\n\n");

  root = insert(root, 8);
  root = insert(root, 7);
  printf("Antes de remover nó com filho esquerdo (8): ");
  inOrder(root); printf("\n");
  remove_node(&root, 8);
  printf("Depois: ");
  inOrder(root); printf("\n\n");

  root = insert(root, 20);
  root = insert(root, 18);
  root = insert(root, 25);
  root = insert(root, 10);
  root = insert(root, 8);
  root = insert(root, 12);
  root = insert(root, 7);
  root = insert(root, 9);
  root = insert(root, 11);
  root = insert(root, 13);
  printf("Antes de remover nó com dois filhos (10): ");
  inOrder(root); printf("\n");
  remove_node(&root, 10);
  printf("Depois: ");
  inOrder(root); printf("\n");

  return 0;
}
