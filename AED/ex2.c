#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
struct Queue{
char nome[50];
struct Queue *next;
};
int pacientesAtendidos=0;

void enqueue(struct Queue **head, struct Queue **tail, char nomeInserido[]){
    struct Queue *newNode=(struct Queue*)malloc(sizeof(struct Queue));

    strcpy(newNode->nome, nomeInserido);
    newNode->next=NULL;
    if (*head==NULL)
    {
        *head=*tail=newNode;
        pacientesAtendidos++;
        
        return;
    }
    (*tail)->next=newNode;//é uma fila
    *tail=newNode;
    pacientesAtendidos++;
}

void dequeue(struct Queue **head, struct Queue **tail){
    struct Queue *delete=*head;
    if(!(*head)) return;
    (*head)=(*head)->next;

    free(delete);

    if(*head==NULL){
        (*tail)=NULL;

    }
}
void printQueue(struct Queue *head){
    if(!head) return;
    while(head){
        printf("[%s]", head->nome);
        if(head->next){
            printf("<-");
        }
        
        head=head->next;
        
    }
    printf("\n");
}

void SearchQueue(struct Queue *head, char nomePaciente[]){
    int posicaoPaciente=1;
    if(head==NULL){
        printf("Fila vazia");
        return;
    }
       
        while(head){
            if(strcmp(head->nome, nomePaciente)==0){
                printf("Posição do(a) %s :%d\n", head->nome, posicaoPaciente);
                return;
            }
        posicaoPaciente++;
        head=head->next;    

        }
        printf("Paciente %s não encontrado!\n", nomePaciente);
        

}
int main(){
    int op;
    char nome[50];
    struct Queue *head=NULL;
    struct Queue *tail=NULL;
    do{
        printQueue(head);
        printf("1. Incluir paciente\n");
        printf("2. Realizar atendimento do paciente da vez\n");
        printf("3. Posição do paciente\n");
        printf("4. Quantidade de pacientes já atendidos\n");
        printf("5. Exit\n");
        printf("Digite a opção desejada\n");
        scanf("%d", &op);
        system("clear");


        switch (op)
        {
            
        case 1:
            printf("Digite o nome do paciente\n");

            scanf("%s", nome);
            enqueue(&head, &tail, nome);
            break;
        case 2:
            dequeue(&head, &tail);
            break;
        case 3:
            printf("Digite o nome do paciente\n");
            scanf("%s", nome);
            SearchQueue(head, nome);  
            break;      
        case 4:
            printf("Quantidade de pacientes atendidos: %d\n", pacientesAtendidos);
            break;
        case 5:
            return 0;
        default:
            printf("Opção inválida!\n");
            break;

        }
    }while(op!=5);
}