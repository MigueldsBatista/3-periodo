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

void yourturn(){//ponteiro void é generico
    for(int i=0;i<5;i++){
    sleep(1);
    printf("myturn: %d\n", i);
    }

}


void* myturn(void *arg){
    int *iptr=(int*)malloc(sizeof(int));
    *iptr=0;
    for(int i=0;i<3;i++){
    sleep(1);
    printf("yourturn: %d %d\n", i, *iptr);
    (*iptr)++;
    }
    return iptr;
}

//funcoes de thread devem retornar um ponteiro void e receber um ponteiro void

int main(){
    int i=5;
    pthread_t newThread;
    pthread_create(&newThread, NULL, myturn, NULL);
    int *result;

    yourturn();

    pthread_join(newThread, (void*)&result);//nessa versão queremos aguardar o retorno das threads a partir da funcao myturn
    //void* é um ponteiro generico e pode ser qualquer tipo
    printf("Threads concluidas %d\n", *result);
    return 0;
}