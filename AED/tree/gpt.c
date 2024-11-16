#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura para representar o nó da árvore
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para imprimir a árvore em formato de árvore (tree-style)
void printTree(struct Node* node, char* prefix, bool isLeft) {
    if (node != NULL) {
        // Imprime o valor atual com o prefixo correto
        printf("%s", prefix);
        printf(isLeft ? "└── " : "├── ");
        printf("%d\n", node->value);

        // Prepara o novo prefixo para os filhos
        char newPrefix[100];
        sprintf(newPrefix, "%s%s", prefix, isLeft ? "    " : "│   ");

        // Chama recursivamente para a subárvore esquerda e direita
        printTree(node->left, newPrefix, true);
        printTree(node->right, newPrefix, false);
    }
}

int main() {
    // Exemplo de construção da árvore
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Imprime a árvore
    printTree(root, "", true);

    return 0;
}
