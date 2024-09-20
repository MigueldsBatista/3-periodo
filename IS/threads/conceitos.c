/*
estrutura geramente segue

int pthread_create(
pthread_t *thead,
const pthread_attr_t *attr,
void *(*start_routine)(void *),
void *arg)


*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* yourturn(){//ponteiro void é generico
    for(int i=0;i<5;i++){
    sleep(1);
    printf("myturn: %d\n", i);
    }

}


void* myturn(void *arg){
    int *iptr=(int*)arg;
    for(int i=0;i<3;i++){
    sleep(1);
    printf("yourturn: %d %d\n", i, *iptr);
    (*iptr)++;
    }
}

//funcoes de thread devem retornar um ponteiro void e receber um ponteiro void

int main(){
    int i=5;
    pthread_t newThread;
    pthread_create(&newThread, NULL, myturn, &i);//nessa versao daqui estamos passando um ponteiro para o argumento

    yourturn(i);
    pthread_join(newThread, NULL);//ou seja, nosso programa deve esperar newThread acabar pra finalizar o programa
    //NULL indica que nao ligamos pro retorno de myturn
    printf("Threads concluidas %d\n", i);
    return 0;
}