#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Funções auxiliares
void insert(Node **root, int value);
void displayPre(Node *primary);
void displayIn(Node *primary);
void displayPost(Node *primary);
Node *findMaxRightAndReplaceByLeft(Node **root);
void delete(Node **root, int target);
int level(Node *root);
void shift_left(Node **root);
void shift_right(Node **root);
int search(Node *root, int target);
void balance(Node **root);

void balance(Node **root){
    if(*root==NULL) return;

    int balance = level((*root)->right)-level((*root)->left);


    if(balance<=-2){

        balance=level((*root)->left)-level((*root)->left->right);
        printf("\nRotação: Dupla Direita");
        if(balance>=1){
            shift_left(&(*root)->left);
            shift_right(root);
        }else{
            shift_right(root);
            printf("\nRotação: Direita Simples");

        }
    }

    else if(balance>=2){
        balance=level((*root)->right)-level((*root)->right->left);
            if(balance<0){
            shift_right(&(*root)->right);
            shift_left(root);
        printf("\nRotação: Dupla Esquerda");

        }else{
            shift_left(root);
        printf("\nRotação: Esquerda Simples");

        }

    }
}

int search(Node *root, int target){
    if(root ==NULL) return 0;

    else if(target == root->data) return 1;

    else if(target < root->data) return search(root->left, target);

    else return search(root->right, target);
}

void shift_left(Node **root){
    Node*new=(*root)->right;
    (*root)->right=new->left;
    new->left=*root;//recebe a raiz antiga com o ponteiro direito ajustado
    *root=new;
}

void shift_right(Node **root){
    Node *new=(*root)->left;
    (*root)->left=new->right;
    new->right=*root;
    *root=new;
}


// Função para inserir um valor na árvore
void insert(Node **root, int value) {
    if (*root == NULL) {
        *root = (Node *)malloc(sizeof(Node));
        (*root)->data = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (value < (*root)->data) {
            insert(&(*root)->left, value);
        } else if (value > (*root)->data) {
            insert(&(*root)->right, value);
        }
        balance(root);
    }
}


// Função para exibir a árvore em pré-ordem
void displayPre(Node *primary) {
    if (primary != NULL) {
        printf("[%d] ", primary->data);
        displayPre(primary->left);
        displayPre(primary->right);
    }
}

// Função para exibir a árvore em ordem (in-order)
void displayIn(Node *primary) {
    if (primary != NULL) {
        displayIn(primary->left);
        printf("[%d] ", primary->data);
        displayIn(primary->right);
    }
}

// Função para exibir a árvore em pós-ordem
void displayPost(Node *primary) {
    if (primary != NULL) {
        displayPost(primary->left);
        displayPost(primary->right);
        printf("[%d] ", primary->data);
    }
}

// Função para encontrar o maior valor à direita e substituir pelo filho à esquerda
Node *findMaxRightAndReplaceByLeft(Node **root) {
    if ((*root)->right != NULL) {
        return findMaxRightAndReplaceByLeft(&(*root)->right);
    } else {
        Node *aux = *root;
        if ((*root)->left != NULL) {
            *root = (*root)->left;
        } else {
            *root = NULL;
        }
        return aux;
    }
}

// Função para deletar um nó com valor específico
void delete(Node **root, int target) {
    if (*root == NULL) {
        printf("Árvore vazia!\n");
        return;
    }

    printf("Procurando o nó %d...\n", target);

    if (target < (*root)->data) {
        delete(&(*root)->left, target);
    } else if (target > (*root)->data) {
        delete(&(*root)->right, target);
    } else {
        Node *parent = *root;

        // Nó sem filhos
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(parent);
            *root = NULL;
            printf("Nó removido!\n");
        }
        // Nó com filho à esquerda
        else if ((*root)->right == NULL) {
            Node *temp = *root;
            *root = (*root)->left;
            free(temp);
            printf("Nó removido! O filho à esquerda agora ocupa o lugar.\n");
        }
        // Nó com filho à direita
        else if ((*root)->left == NULL) {
            Node *temp = *root;
            *root = (*root)->right;
            free(temp);
            printf("Nó removido! O filho à direita agora ocupa o lugar.\n");
        }
        // Nó com dois filhos
        else {
            Node *aux = findMaxRightAndReplaceByLeft(&(*root)->left);
            aux->left = (*root)->left;
            aux->right = (*root)->right;
            free(*root);
            *root = aux;
            printf("Nó removido! O nó máximo à direita foi promovido.\n");
        }
        balance(root);
    }
}

// Função para encontrar o nível da árvore
int level(Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_level = level(root->left);
        int right_level = level(root->right);

        return (left_level > right_level ? left_level : right_level) + 1;
    }
}

int main() {
    Node *root = NULL;
    int choice, value;

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir valor na árvore\n");
        printf("2. Deletar valor da árvore\n");
        printf("3. Exibir árvore em ordem (in-order)\n");
        printf("4. Exibir árvore em pré-ordem (pre-order)\n");
        printf("5. Exibir árvore em pós-ordem (post-order)\n");
        printf("6. Ver nível da árvore\n");
        printf("7. Buscar elemento\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &choice);
        system("clear");

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value);
                insert(&root, value);
                break;

            case 2:
                printf("Digite o valor a ser deletado: ");
                scanf("%d", &value);
                delete(&root, value);
                break;

            case 3:
                printf("Árvore em ordem (in-order): ");
                displayIn(root);
                printf("\n");
                break;

            case 4:
                printf("Árvore em pré-ordem (pre-order): ");
                displayPre(root);
                printf("\n");
                break;

            case 5:
                printf("Árvore em pós-ordem (post-order): ");
                displayPost(root);
                printf("\n");
                break;

            case 6:
                printf("Nível da árvore: %d\n", level(root));
                break;

            case 7:
                int target;
                printf("Digite o valor buscado: \n");
                scanf("%d", &target);
                search(root, target)?printf("Elemento %d encontrado com sucesso!", target):printf("Elemento %d não encontrado...", target);
                break;

            case 0:
                printf("Saindo...\n");
                return 0;

            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return 0;
}
