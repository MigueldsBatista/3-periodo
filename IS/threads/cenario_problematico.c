#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void myturn(){
    while(1){
    sleep(1);
    printf("myturn\n");        
    }

}

void yourturn(){
    while(1){
    sleep(1);
    printf("yourturn\n");        
    }

}

void* myturn2(){
    for(int i=0;i<5;i++){
    sleep(1);
    printf("myturn\n");
    }

}

void yourturn2(){
    for(int i=0;i<3;i++){
    sleep(1);
    printf("yourturn\n");
}
}
//nesse cenario a thread 1 acaba primeiro e em tese o programa acaba, porem a thread 2 ainda vai executar

int main(){
    myturn();
    yourturn();

    //isso nao vai funcionar pois é necessario uma thread

}
