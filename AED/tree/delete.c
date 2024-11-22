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

  //numero é menor que o numero da raiz
  if (num < (*root)->data)
    remove(&(*root)->left, num);

    //numero é maior que o numero da raiz
  else if (num > (*root)->data)
    remove(&(*root)->right, num);


  else {
    Node *walk = *root;
    // 01 - primary sem filhos
    /*
             5
            / \
           3   7
          / \
  --->   (2)   4


    */
    //se o primary for uma folha ele é removido
    if (((*root)->left == NULL) && ((*root)->right == NULL)) {
      free(walk);
      (*root) = NULL;

    }
     else {
    
      // 02 - primary com filho direito
      /*
            10
            /
            5
            \
            (7) <-----
      
      */
      if ((*root)->left == NULL) {
        (*root) = (*root)->right;
        walk->right = NULL;
        free(walk);

      } else {
        // 02.5 - primary com filho esquerdo

/*
                 10
                /
               5
              /
       --->  (3)

*/

        if ((*root)->right == NULL) {
          (*root) = (*root)->left;
          walk->left = NULL;
          free(walk);

        }
         else {
          // 03 - primary com dois filhos
/*
      15
     /  \
-->(10)   20
   / \
  8   12
       \
        13



*/
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
