#include <stdio.h>
#include <malloc.h>
struct Queue{
int data;
struct Queue* next;
};

void enqueue(struct Queue **head, struct Queue **tail, int value){
struct Queue *newNode=(struct Queue*)malloc(sizeof(struct Queue));

newNode->data=value;
newNode->next=NULL;

if(*head==NULL){
*head=*tail=newNode;
return;
}

(*tail)->next=newNode;
(*tail)=newNode;

}

void dequeue(struct Queue **head, struct Queue **tail){
    struct Queue *delete=*head;
    if(*head==NULL){
        printf("Queue is empty!!");
    }
    (*head)=(*head)->next;
    free(delete);
    if(*head==NULL){
        (*tail)=NULL;
    }
}


void printQueue(struct Queue *head) {//Aqui nós não perdemos a referencia de head pois é um ponteiro apenas então nao afeta o conteudo do ponteiro

    while (head) {
        printf("[%d]", head->data);
        if (head->next) {
            printf(" -> ");
        }
        head = head->next;
    }printf(" -> NULL");
    printf("\n");
}
void intercalarFila(struct Queue *head1, struct Queue *tail1, struct Queue *head2, struct Queue *tail2, struct Queue **head3, struct Queue **tail3){
    //1 = vez da fila 1
    //2 = vez da fila 2

    while(head1 || head2){
        int vez=1;
       if (vez == 1 && head1) {
            enqueue(head3, tail3, head1->data);
            head1 = head1->next;
            vez = 2;
        } else if (vez == 2 && head2) {
            enqueue(head3, tail3, head2->data);
            head2 = head2->next; 
            vez = 1;
        } else if (head1) { // caso uma fila tenha terminado
            enqueue(head3, tail3, head1->data);
            head1 = head1->next;
        } else if (head2) {
            enqueue(head3, tail3, head2->data);
            head2 = head2->next;
        }

}
}

int main(){
    struct Queue *headPrimeiraFila=NULL;
    struct Queue *tailPrimeiraFila=NULL;

    struct Queue *headSegundaFila=NULL;
    struct Queue *tailSegundaFila=NULL;

    struct Queue *headFilaIntercalada=NULL;
    struct Queue *tailFilaIntercalada=NULL;

    int pessoasPrimeiraFila;
    int pessoasSegundaFila;
    int caixaVazio;
    int numeroPessoa;
    scanf("%d %d %d", &pessoasPrimeiraFila, &pessoasSegundaFila, &caixaVazio);

    for(int i=0; i<pessoasPrimeiraFila;i++){
        printf("DIGITE A PESSOA %d\n", i);
        scanf("%d", &numeroPessoa);
        enqueue(&headPrimeiraFila, &tailPrimeiraFila, numeroPessoa);
    }
    
    for(int i=0; i<pessoasSegundaFila;i++){
        printf("DIGITE A PESSOA DA SEGUNDA FILA%d\n", i);
        scanf("%d", &numeroPessoa);
        enqueue(&headSegundaFila, &tailSegundaFila, numeroPessoa);
    }
    intercalarFila(headPrimeiraFila, tailPrimeiraFila, headSegundaFila, tailSegundaFila, &headFilaIntercalada, &tailFilaIntercalada);

    printQueue(headPrimeiraFila);

    printQueue(headSegundaFila);

    printQueue(headFilaIntercalada);
}