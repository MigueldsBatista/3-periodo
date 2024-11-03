#include <stdio.h>
#include <stdlib.h>
// https://www.inf.ufsc.br/~aldo.vw/estruturas/simulador/AVL.html

/**
 * @brief A node in an AVL tree.
 *
 * This struct represents a node in an AVL tree. The node contains an integer
 * value and pointers to its left and right children.
 */
typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

/**
 * @brief Computes the height of a child node in an AVL tree.
 *
 * This function takes a pointer to a node in an AVL tree and returns the height
 * of its child node. The height is used to maintain the balance of the AVL tree.
 *
 * @param root A pointer to the root node of the subtree.
 * @return The height of the child node.
 */
int childHeight(Node *root);

/**
 * @brief Shifts the root node to the right.
 *
 * This function takes a pointer to the root node of an AVL tree and shifts the
 * root node to the right. The function is used to balance the AVL tree.
 *
 * @param root A pointer to the root node of the AVL tree.
 */
void shiftRight(Node **root);

/**
 * @brief Shifts the root node to the left.
 *
 * This function takes a pointer to the root node of an AVL tree and shifts the
 * root node to the left. The function is used to balance the AVL tree.
 *
 * @param root A pointer to the root node of the AVL tree.
 */
void shiftLeft(Node **root);

/**
 * @brief Balances the AVL tree.
 *
 * This function takes a pointer to the root node of an AVL tree and balances the
 * tree. The function is used to maintain the balance of the AVL tree after an
 * insertion or removal.
 *
 * @param root A pointer to the root node of the AVL tree.
 */
void balance(Node **root);

/**
 * @brief Traverses the AVL tree in pre-order.
 *
 * This function takes a pointer to the root node of an AVL tree and traverses
 * the tree in pre-order. The function prints the data of each node in the AVL
 * tree.
 *
 * @param root A pointer to the root node of the AVL tree.
 */
void insert(Node **root, int data);

/**
 * @brief Finds the maximum value in the right subtree of a node.
 *
 * This function takes a pointer to a node in an AVL tree and finds the maximum
 * value in the right subtree of the node. The function is used to remove a node
 * from the AVL tree.
 *
 * @param no A pointer to the node in the AVL tree.
 * @return A pointer to the node with the maximum value in the right subtree.
 */
void preOrder(Node *root);

/**
 * @brief Removes a node from the AVL tree.
 *
 * This function takes a pointer to the root node of an AVL tree and a value to
 * remove from the tree. The function removes the node with the given value from
 * the AVL tree.
 *
 * @param root A pointer to the root node of the AVL tree.
 * @param value The value to remove from the AVL tree.
 */
void removeNode(Node **root, int value);

/**
 * @brief Finds the maximum value in the right subtree of a node.
 *
 * This function takes a pointer to a node in an AVL tree and finds the maximum
 * value in the right subtree of the node. The function is used to remove a node
 * from the AVL tree.
 *
 * @param no A pointer to the node in the AVL tree.
 * @return A pointer to the node with the maximum value in the right subtree.
 */
Node *maxRight(Node **no);

int main() {
  Node *root = NULL;

  insert(&root, 6);
  insert(&root, 10);
  insert(&root, 15);
  printf("\n>>Rotação devido a inserção do 15\n");

  insert(&root, 3);
  insert(&root, 1);
  printf("\n>>Rotação devido a inserção do 1\n");


  printf("\nPRE-ordem:");
  preOrder(root);
  printf("\n");




  return 0;
}

int childHeight(Node *root) {
  if (root == NULL)
    return 0;
  else {
    int alturaEsquerda = childHeight(root->left);
    int alturaDireita = childHeight(root->right);
    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
  }
}

void shiftRight(Node **root) {
  Node *walk = (*root)->left;// temp = valor do nó left

  (*root)->left = walk->right;// nó left do root recebe o nó right do temp

  walk->right = (*root);

  *root = walk;
}

//     1(root)
//    /  \
// null   2(right)
//       / \
//    null  3
void shiftLeft(Node **root) {//in example 1 2 3
  Node *walk = (*root)->right;// temp = 1

  (*root)->right = walk->left; // 2->right = 1->left(null)

  walk->left = (*root);

  *root = walk;
}
// Suponha que temos uma árvore com os nós 1, 2 e 3.
// Inserimos os números na seguinte ordem: 3, 2, 1.
// Isso causará um desequilíbrio à esquerda (fator de balanceamento < -1).

/*
    Antes da rotação:
          3
         /
        2
       /
      1

    Após uma rotação à direita:
          2
         / \
        1   3
*/

// Função de balanceamento
void balance(Node **root) {
  
  // Primeiro, verificamos se a árvore ou subárvore tem um nó válido (não NULL)
  if(*root != NULL) {
    Node *walk;

    // Calcula o fator de balanceamento (FB)
    // FB é a diferença entre a altura do filho direito e a altura do filho esquerdo
    int fb = childHeight((*root)->right) - childHeight((*root)->left);
    
    // Caso o FB seja menor que -1, significa que a subárvore esquerda é mais alta
    if (fb < -1) {
      // Vamos lidar com o desequilíbrio à esquerda
      walk = (*root)->left;
      
      // Calcula o FB da subárvore esquerda (para determinar o tipo de rotação)
      fb = childHeight(walk->right) - childHeight(walk->left);
      
      // Se FB da subárvore esquerda for positivo (> 0), 
      // significa que o desequilíbrio da esquerda está à direita (Rotação Dupla Direita)
      if (fb > 0) {
        shiftLeft(&((*root)->left)); // Rotaciona à esquerda o filho esquerdo
        shiftRight(root); // Rotaciona à direita a raiz
        printf("\nRotação: Dupla Direita");
      
      // Se FB da subárvore esquerda for <= 0, significa que o desequilíbrio está à esquerda (Rotação Simples Direita)
      } else {
        shiftRight(root); // Executa uma rotação simples à direita na raiz
        printf("\nRotação: Direita Simples");
      }
    } 
    
    // Caso o FB seja maior que 1, significa que a subárvore direita é mais alta (desequilíbrio à direita)
    else if (fb > 1) {
      // Vamos lidar com o desequilíbrio à direita
      walk = (*root)->right;
      
      // Calcula o FB da subárvore direita
      fb = childHeight(walk->right) - childHeight(walk->left);
      
      // Se o FB da subárvore direita for negativo (< 0), significa que o desequilíbrio da direita está à esquerda (Rotação Dupla Esquerda)
      if (fb < 0) {
        shiftRight(&((*root)->right)); // Rotaciona à direita o filho direito
        shiftLeft(root); // Rotaciona à esquerda a raiz
        printf("\nRotação: Dupla Direita Esquerda");
      
      // Se o FB da subárvore direita for >= 0, significa que o desequilíbrio está à direita (Rotação Simples Esquerda)
      } else {
        shiftLeft(root); // Executa uma rotação simples à esquerda na raiz
        printf("\nRotação: Esquerda Simples");
      }
    }
  }
}


void preOrder(Node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void insert(Node **root, int n) {
  if (*root == NULL) {
    *root = (Node *)malloc(sizeof(Node));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->data = n;
  } else if (n < (*root)->data)
    insert(&(*root)->left, n);
  else if (n > (*root)->data)
    insert(&(*root)->right, n);

  balance(root);
}

Node *maxRight(Node **no) {
  if ((*no)->right != NULL)
    return maxRight(&(*no)->right);
  else {
    Node *walk = *no;
    if ((*no)->left != NULL) {
      *no = (*no)->left;
    } else {
      *no = NULL;
    }
    return walk;
  }
}

void removeNode(Node **root, int value) {
  if (*root == NULL) {
    printf("\nRemoção: Numero nao existe na arvore!");
    return;
  }
  else if (value < (*root)->data)
    removeNode(&(*root)->left, value);
  else if (value > (*root)->data)
    removeNode(&(*root)->right, value);
  else {
    Node *walk = *root;
    // 01 - no sem filhos
    if (((*root)->left == NULL) && ((*root)->right == NULL)) {
      free(walk);
      (*root) = NULL;
    } 
    else {
      // 02 - no com filho direito
      if ((*root)->left == NULL) {
        (*root) = (*root)->right;
        walk->right = NULL;
        free(walk);
        walk = NULL;
      } 
      else {
        // 02 - no com filho leftuerdo
        if ((*root)->right == NULL) {
          (*root) = (*root)->left;
          walk->left = NULL;
          free(walk);
          walk = NULL;
        } else {
          // 03 - no com dois filhos
          walk = maxRight(&(*root)->left);
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