#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

void bubble(int *arr, int n);

void swap(int *arr, int i, int j);

// essa versão inicial não possui qualquer verificação se o array finalizou ou etc, nos apenas 
//percorremos os elementos do array, trocando de lugar caso o anterior seja maior q o atual
//complexidade O(n²) nos dois casos
// ou o teorema mestre O(n * n-1)

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

    for(int i=0; i< n ; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
}