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

/*
    Exemplo de uso da função find_max_right_and_disconnect:

           8
         /   \
        3     10
       / \      \
      1   6      14
         / \     /
        4   7   13

    Suponha que queremos remover o nó 8.
    Para isso, buscamos o maior nó da subárvore esquerda de 8 (ou seja, da subárvore com raiz 3).

    find_max_right_and_disconnect(&root->left) irá encontrar o nó 7 (maior valor da subárvore esquerda).
    O nó 7 será removido da posição original e retornado para substituir o nó 8.

    Após a operação, a subárvore esquerda de 8 ficará assim:

           3
         /   \
        1     6
             /
            4

    E a árvore resultante (após substituir 8 por 7) será:

           7
         /   \
        3     10
       / \      \
      1   6      14
         /      /
        4      13
*/

Node* find_max_right_and_disconnect(Node **root) {
  if (*root == NULL) {
    return NULL;
  }
  
  if ((*root)->right == NULL) {
    Node *max_node = *root;
    *root = (*root)->left;
    return max_node;
  }
  
  return find_max_right_and_disconnect(&(*root)->right);
}

//VERSÃO NÃO RECURSIVA
// Node* find_max_right_and_disconnect(Node **root) {
//   // Se a subárvore for vazia, não há nada para retornar
//   if (*root == NULL) {
//     return NULL;
//   }
  
//   Node *parent = NULL;
//   Node *walk = *root;

//   // Caso especial: o nó raiz da subárvore já é o maior (não tem filho à direita)
//   // Neste caso, desconectamos esse nó e promovemos seu filho esquerdo (se houver)
//   if (walk->right == NULL) {
//     *root = walk->left; // Atualiza o ponteiro do pai para apontar para o filho esquerdo
//     return walk;        // Retorna o nó removido (maior da subárvore)
//   }
  
//   // Caso geral: percorre para a direita até encontrar o maior nó
//   while (walk->right != NULL) {
//     parent = walk;
//     walk = walk->right;
//   }
  
//   // Desconecta o maior nó da subárvore
//   // O filho esquerdo do maior nó (se existir) passa a ser filho direito do pai dele
//   parent->right = walk->left;

//   //PERGUNTA: Pq sempre vai ser o filho esquerdo a ser atribuido?
  
//   return walk; // Retorna o maior nó encontrado e desconectado
// }

void remove_node(Node **root, int num) {
  if (*root == NULL) {
    printf("Numero nao existe na arvore!");
    return;
  }

  bool num_is_smaller_than_root = num < (*root)->data;
  bool num_is_bigger_than_root = num > (*root)->data;

  //Busca recursivamente para esquerda
  if (num_is_smaller_than_root) {
    remove_node(&(*root)->left, num);
    return;
  }

  //Busca recursivamente para direita
  if (num_is_bigger_than_root) {
    remove_node(&(*root)->right, num);
    return;
  }
  //OBS: Note que nós ignoramos o caso aonde o número é igual de propósito, a árvore não deve aceitar

  // At this point, we found the node to remove
  Node *walk = *root;

  // 01 - primary sem filhos (folha)
  /*
      Exemplo prático:
          Inserções: 10, 5, 15
          Remover: 5

          10
         /  \
       (5)  15   <--- Remover 5 (folha)

      Resultado esperado:
          10
            \
            15
  */
  bool left_node_is_null = (*root)->left == NULL;
  bool right_node_is_null = (*root)->right == NULL;

  if (left_node_is_null && right_node_is_null) {
    free(walk);
    *root = NULL;
    return;
  }

  // 02 - primary com filho direito
  /*
      Exemplo prático:

        Remover: 15

          10
            \
            (15) <-------
              \
              17

      Resultado esperado:

          10
            \
            17
  */
  if (left_node_is_null) {

    //Nó direito toma seu lugar
    *root = (*root)->right;
    walk->right = NULL;
    free(walk);
    return;
  }

  // 03 - primary com filho esquerdo
  /*
      Exemplo prático:
          Inserções: 10, 8, 7
          Remover: 8

          10
         /
       (8)
       /
      7

      Resultado esperado:
         10
         /
        7
  */
  if (right_node_is_null) {

    //Nó esquerdo toma seu lugar
    *root = (*root)->left;
    walk->left = NULL;
    free(walk);
    return;
  }

  // 04 - primary com dois filhos
  /*
      Exemplo prático:
          Inserções: 10, 8, 12, 7, 9, 11, 13
          Remover: 10

              (10)
             /    \
           8       12
          / \     /  \
         7   9  11  13

      Processo:
        - find_max_right_and_disconnect(&(*root)->left) retorna 9 (maior da subárvore esquerda)
        - 9 substitui 10, e 9 é removido da posição original

      Resultado esperado:
              9
            /   \
           8     12
          /     /  \
         7    11   13

  */
  walk = find_max_right_and_disconnect(&(*root)->left);
  //O que estiver a esquerda da árvore vai ser atribuido a walk->left
  walk->left = (*root)->left;

  //O que estiver a esquerda da árvore vai ser atribuido a walk->left
  walk->right = (*root)->right;
  free(*root);
  *root = walk;
}

int main() {
    Node *root = NULL;

    // Caso 1: Remover folha
    // Inserções: 10, 5, 15
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    printf("Antes de remover folha (5): ");
    inOrder(root); printf("\n");
    remove_node(&root, 5);
    printf("Depois: ");
    inOrder(root); printf("\n\n");

    // Caso 2: Remover nó com apenas filho direito (e garantir uso do ponteiro)
    // Inserções: 10, 12, 15, 17
    root = insert(root, 12);
    root = insert(root, 15);
    root = insert(root, 17);
    printf("Antes de remover nó com filho direito (15): ");
    inOrder(root); printf("\n");
    remove_node(&root, 15);
    printf("Depois: ");
    inOrder(root); printf("\n\n");

    // Caso 3: Remover nó com apenas filho esquerdo
    // Inserções: 8, 7
    root = insert(root, 8);
    root = insert(root, 7);
    printf("Antes de remover nó com filho esquerdo (8): ");
    inOrder(root); printf("\n");
    remove_node(&root, 8);
    printf("Depois: ");
    inOrder(root); printf("\n\n");

    // Caso 4: Remover nó com dois filhos
    // Inserções: 20, 18, 25, 10, 8, 12, 7, 9, 11, 13
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