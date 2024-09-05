#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef struct Node{
    char nomeAluno[50];
    struct Node* next;
}Node;

//inserir , printar e imprimir so os pares
void push(Node** head, char nome[50]){
    Node* newNode=(Node*)malloc(sizeof(Node));

    strcpy(newNode->nomeAluno, nome);

    newNode->next=*head;
    *head=newNode;
}

void printNode(Node *head){
    while (head->next)
    {   
        head=head->next;
    }
    printf("[%s]\n", head->nomeAluno);

}

bool isEven(int num){
    if(num%2==0) return true;
    return false;
}

void printPar(Node *head){
    int posicao=1;

    while(head){
        if(isEven(posicao)) {
            printf("%s", head->nomeAluno);
        }
        head=head->next;
        posicao++;
    }
}

int main(){
    Node* head=NULL;
    char nome[50];
    int op;
    do
    {
        printf("Escolha uma opção:\n");
        printf("1. Inseririr\n");
        printf("2. Imprimir\n");
        printf("3. Imprimir os pares\n");
        printf("4. Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Nome: ");
            scanf("%s", nome);
            push(&head, nome);
            break;
        case 2:
            printNode(head);
            break;
        case 3:
            printPar(head);
            break;
        case 4:
            break;
        default:
            printf("Opção invalida!\n");
            break;
        }
    } while (op!=4);
    return 0;
}