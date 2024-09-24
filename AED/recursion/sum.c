#include <stdio.h>
#include <stdlib.h>

int sum(int *arr, int size){
    //caso base
    if(size-1==0){//0 -> 1 -> 2 -> 3 -> 4
        return arr[0];
    }
    return arr[size-1]+sum(arr, size-1);
}
//querenos o enesimo numero de uma sequencia fibbo

int fibbonaci(int num){//1 1 2 3 5 8 implementado de cima pra baixo
    if(num==0){
        return 0;
    }
    if (num==1 || num==2){
        return 1;
    }

    return fibbonaci(num-1) + fibbonaci(num-2);
}

int main(){

int arr[]={1, 2, 3, 4, 5};
printf("%d\n", sum(arr, 6));
printf("%d\n", fibbonaci(6));
    return 0;
}