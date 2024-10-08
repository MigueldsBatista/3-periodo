#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void bubble(int *arr, int n);

void swap(int *arr, int i, int j);

int main(){

    int *arr=(int*)malloc(sizeof(int)*SIZE);

    for (int i = 0; i < SIZE; i++) {

        arr[i] = rand() % 101; // Gera números de 0 a 100

        printf("Valor gerado: %d\n", arr[i]);

    }

    bubble(arr, SIZE);

    for(int i=0;i<SIZE;i++){
        printf("[%d]", arr[i]);
    }
        
    return 0;
}

void swap(int *arr, int i, int j){
    int aux=arr[i];
    arr[i]=arr[j];
    arr[j]=aux;
}

void bubble(int *arr, int n){

    for(int i = 0; i < n-1 ; i++){
        for(int j = n-1; j > i ; j--){
            if(arr[j-1]>arr[j]){
                swap(arr, j, j-1);
            }
        }
    }
}