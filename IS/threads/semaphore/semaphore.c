#include <semaphore.h>

#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

/*
PADRÃO POSIX

sem_init
sem_open
sem_wait
sem_post
sem_unlink
sem_close


*/
#define THREAD_NUM 4
sem_t semaphore;

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

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    sem_init(&semaphore, 0, 1 );

    for(int i=0;i<THREAD_NUM;i++){
        pthread_create(&th[i], NULL, myturn, NULL);
    }


    sem_destroy(&semaphore);
    return 0;
}