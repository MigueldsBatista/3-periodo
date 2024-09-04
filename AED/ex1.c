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
        return;
    }
    (*head)=(*head)->next;
    free(delete);
    if(*head==NULL){
        (*tail)=NULL;
    }
}


void printQueue(struct Queue *head) {//Aqui nós não perdemos a referencia de head pois é um ponteiro apenas então nao afeta o conteudo do ponteiro

    while (head) {
        printf("%d", head->data);
        if (head->next) {
        }
        head = head->next;
    }
}
void intercalarFila(struct Queue *head1, struct Queue *head2){
int vez=0;

while(head1 || head2){
if(head1 && vez==0){
printf("%d", head1->data);
head1=head1->next;
vez=1;
}
else if(head2 && vez==1){
printf("%d", head2->data);
head2=head2->next;
vez=0;
}
else if (head1) { // Se uma das filas acabar, continua imprimindo da outra
            printf("%d", head1->data);
            head1 = head1->next;
        } else if (head2) {
            printf("%d", head2->data);
            head2 = head2->next;
        }
}

}

int main(){
    struct Queue *headPrimeiraFila=NULL;
    struct Queue *tailPrimeiraFila=NULL;

    struct Queue *headSegundaFila=NULL;
    struct Queue *tailSegundaFila=NULL;

 

    int pessoasPrimeiraFila;
    int pessoasSegundaFila;
    int caixaVazio;
    int numeroPessoa;
    scanf("%d %d %d", &pessoasPrimeiraFila, &pessoasSegundaFila, &caixaVazio);

    for(int i=0; i<pessoasPrimeiraFila;i++){
        scanf("%d", &numeroPessoa);
        enqueue(&headPrimeiraFila, &tailPrimeiraFila, numeroPessoa);
    }
    
    for(int i=0; i<pessoasSegundaFila;i++){
        scanf("%d", &numeroPessoa);
        enqueue(&headSegundaFila, &tailSegundaFila, numeroPessoa);
    }

    printQueue(headPrimeiraFila);

    printQueue(headSegundaFila);
    if(caixaVazio==2){
        intercalarFila(headPrimeiraFila, headSegundaFila);
    }
    else if (caixaVazio==1)
    {
        intercalarFila(headSegundaFila, headPrimeiraFila);
    }
    
}