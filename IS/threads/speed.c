#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

#define BIG 1000000000UL
uint32_t counter =0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* count_to_big(void *arg){
    for(uint32_t i=0;i<BIG;i++){
    pthread_mutex_lock(&lock);//isso resolve o problema porem torna ele muito mais lento
        counter++;            //Concorrencia x Paralelismo
    pthread_mutex_unlock(&lock);//Concorrencia simula um paralelismo, fica mudando rapidamente a thread que esta sendo usada
                                //Por exemplo um pc que so tem um core
                                //E paralelismo de fato são duas tarefas ao mesmo tempo
    }
    printf("DONE");
    return NULL;
}

/*

isso na realidade torna o programa mais lento,
as funcoes competem pra ver
quem vai escrever no valor por vez

precisamos tornar as mudanças atomicas

ou melhor dizendo MUTEX LOCKS!
*/


/*
Auxilio do GNU Debugger (GDB)

gdb ./program

display - variable

break main - add a breakpoint in main func

r - run the program

n - next command

info threads- informacoes da thread atual

break count_to_big

watch counter >= 4500 - adiciono uma condição

*/
int main(){
    pthread_t count;
    pthread_create(&count, NULL, count_to_big, NULL);
    
    count_to_big(NULL);
    pthread_join(count, NULL);
}