/*
As ordens estão relacionadas a quando
vamos percorrer o nó da raiz

Pre Order - Percorremos a raiz antes dos outros
In Order - No meio do processo
Post Order - No final do processo


Left 
Right
Primary

*/

//Pre order primary left right(PLR)

//In Order left primary right(LPR)

//Post Order left right primary(LRP)

// if data menor  left and data maior right insert in root
//if data menor root and data menor que right insert in left
//if data maior root and data maiir left insert in right

/*
    1
   | |
   2 3
 | | | |
6  7 8  9
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
struct Node *left;
struct Node *right;
int data;
}Node;

void insert_in_order(Node **root, int data);
int get_level(Node **root);
void display_in_order(Node *root);
void display_post_order(Node *root);
void display_pre_order(Node *root);

static int flag=0;

int main(){
Node *root=NULL;

insert_in_order(&root, 3);
insert_in_order(&root, 1);
insert_in_order(&root, 4);
insert_in_order(&root, 2);
insert_in_order(&root, 5);


display_pre_order(root);
printf("\n");
flag=1;
display_in_order(root);
flag=1;
printf("\n");
display_post_order(root);
printf("\n");

printf("Altura: %d\n", get_level(&root));


return 0;
}

void display_in_order(Node *root){
if(root!=NULL){
    if (flag==0){
        printf("Root: %d\n", root->data);
        flag=1;
    }
    display_in_order(root->left);
    printf("%d - ", root->data);
    display_in_order(root->right);
}
}

void display_pre_order(Node *root){

if(root!=NULL){
    if (flag==0){
        printf("Root: %d\n", root->data);
        flag=1;
        return;
    }
    printf("%d -", root->data);
    display_pre_order(root->left);
    display_pre_order(root->right);
}

}

void display_post_order(Node *root){

if(root!=NULL){
        if (flag==0){
        printf("Root: %d\n", root->data);
        flag=1;
    }
    display_post_order(root->left);
    display_post_order(root->right);
    printf("%d -", root->data);
}

}

void insert_in_order(Node **root, int data){
    if(*root==NULL){
        if(flag==0){
            printf("Root: %d\n", data);
            flag=1;
        }
        (*root)=(Node*)malloc(sizeof(Node));
        (*root)->data=data;
        (*root)->left=NULL;
        (*root)->right=NULL;
        return;
    }

    if(data < (*root)->data){
        insert_in_order(&(*root)->left, data);
        printf("Node %d inserted at left!\n", (*root)->data);
        return;
    }
    
    else if(data > (*root)->data){
        insert_in_order(&(*root)->right, data);
        printf("Node %d inserted at right!\n", (*root)->data);
        return;
    }
    // desconsideramos aqui o caso onde eles são iguais
}
int findMax(Node *root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return -1; // Assuming all node values are positive
    }

    if (root->right == NULL) {
        return root->data;
    }

    return findMax(root->right);
}


int search(Node *root, int target){
    if(root->data==target){
        return 1;
    }
    else if (root==NULL){
        return 0;
    }
    else if(target > root->data){
        search(root->right, target);
    }
    else{
        search(root->left, target);
    }
}

/*
Nó não possui filhos
    - Se o nó a ser removido não possui filhos (é uma folha), 
    basta liberar a memória alocada para esse nó e ajustar o ponteiro do pai para NULL.

Nó possui um filho unico
    - Se o nó a ser removido possui um único filho, o ponteiro do pai do nó a ser removido deve ser ajustado para apontar para o filho do nó a ser removido. 
    Em seguida, liberar a memória alocada para o nó removido.

Nó possui dois filhos
    - Se o nó a ser removido possui dois filhos, deve-se encontrar o sucessor in-order (o menor nó na subárvore direita) ou o predecessor in-order (o maior nó na subárvore esquerda). 
    Copiar o valor do sucessor ou predecessor para o nó a ser removido e, em seguida, remover o sucessor ou predecessor, que terá no máximo um filho.


    Esquerda Vão os menores e direita Maiores
*/

int travel_right(Node *root, int get_level){
   if(root->right==NULL){
    return get_level++;
   }
   else{
    travel_right(root->right, get_level++);
   } 
}

int travel_left(Node *root, int get_level){
   if(root->left==NULL){
    return get_level++;
   }
   else{
    travel_left(root->left, get_level++);
   } 
}

int get_level(Node **root){

    if(*root==NULL) return -1;

    int left_height = get_level(&(*root)->left);
    int right_height = get_level(&(*root)->right);

    if(left_height > right_height){
        return left_height + 1;

    }else{
        return right_height + 1;
    }
}