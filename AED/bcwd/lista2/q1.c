/*
Na estação de trem você ainda pode encontrar o último dos “organizadores de vagões”. 
Um Organizador de vagões um empregado cujo trabalho é apenas reordenar os vagões do trem, 
trocando-os de posição. Uma vez que os vagões são organizados em uma ordem considerada ótima, 
o condutor pode desconectar cada vagão e colocá-los na estação.

O título “organizador de vagões” é dado à pessoa que realiza esta tarefa, 
cuja estação fica perto de uma ponte. Ao invés da ponte poder subir ou descer, 
ela roda sobre um pilar que fica no centro do rio. Após rodar 90 graus, 
os barcos podem passar na esquerda ou direita dela. 
O Primeiro organizador de vagões descobriu que girando a ponte 180 graus com dois vagões em cima dela, 
é possível a troca de lugar entre os dois vagões. 
Obviamente a ponte pode operar no máximo com dois vagões sobre ela.

Agora que quase todos os organizadores de vagões já faleceram, a estação gostaria de automatizar esta operação. Parte do programa a ser desenvolvido é uma rotina que decide para um dado trem com um determinado número de vagões, o número de trocas entre trens adjacentes que são necessárias para que o  trem fique ordenado. Sua tarefa é criar tal rotina.

Entrada
A entrada contém na primeira linha o número de caso de testes (N). Cada caso de teste consiste de duas linhas de entrada. A primeira linha de um caso de teste contém um inteiro L, determinando o tamanho do trem (0 ≤ L ≤ 50). A segunda linha de um caso de teste contém uma permutação dos números 1 até L, indicando a ordem corrente dos vagões. Os vagões devem ser ordenados de forma que o vagão 1 venha por primeiro, depois o 2, etc, com o vagão L vindo por último.

Saída
Para cada caso de teste imprima a sentença: 'Optimal train swapping takes S swaps.' onde S é um inteiro.

*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

void insert(Node **head, int value){
    Node *newNode=(Node*)malloc(sizeof(Node));

    newNode->data=value;//update value
    
    if(*head==NULL){
    newNode->next=*head;//link next to head
    newNode->prev=NULL;
    *head=newNode;
    return;
    }
    newNode->next=*head;//link next to head
    newNode->prev=NULL;
    (*head)->prev=newNode;

    *head=newNode;

}
void swap(Node *firstNode, Node *secondNode){
    int temp = firstNode->data;
    firstNode->data = secondNode->data;
    secondNode->data = temp;
}

int bubble_sort(Node **head) {
    if (*head == NULL) {
        return 0; // Lista vazia, nada a ordenar
    }

    int swaps = 0;
    int swapped;
    Node *walk;

    do {
        swapped = 0;
        walk = *head;

        // Caminha pela lista, comparando e trocando se necessário
        while (walk->next != NULL) {
            if (walk->data > walk->next->data) {
                swap(walk, walk->next);
                swaps++;
                swapped = 1;
            }
            walk = walk->next;
        }

    } while (swapped); // Repete até que não haja mais trocas

    return swaps;
}



void display(Node *head){
    while (head)
    {
        printf("[%d] <->", head->data);
        head=head->next;
    }
    
}

int main(int argc, char const *argv[])
{
    int cases;
    int elements;
    int value;
    Node *head=NULL;

    scanf("%d", &cases);
    for(int i=0;i<cases;i++){
        scanf("%d", &elements);
        for(int j=0;j<elements;j++){
            scanf("%d", &value);
            insert(&head, value);
        }
    }

    display(head);
    printf("\n");
    int swaps=bubble_sort(&head);
    printf("Optimal train swapping takes %d swaps.", swaps);
    printf("\n");
    display(head);
    return 0;
}
