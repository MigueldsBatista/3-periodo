#include <stdio.h>
#include <stdlib.h>

void insertion(int *arr, int n);


void swap(int *arr, int i, int j);


void main(){
    int *arr=(int*)malloc(sizeof(int)*5);

    for (int i = 0; i < 5; i++) {
        arr[i] = rand() % 101; // Gera números de 0 a 100
        printf("Valor gerado: %d\n", arr[i]);
    }
    insertion(arr, 5);
    for(int i=0;i<5;i++){
        printf("[%d]", arr[i]);
    }
}

            /* code */

void swap(int *arr, int i, int j){
    int aux=arr[i];
    arr[i]=arr[j];
    arr[j]=aux;
}

    /*
    *   Função que implementa o algoritmo de ordena o por insertion,
    *   recebe como par metro um vetor de inteiros e o seu tamanho
    *   n o retorna valor, pois ordena o vetor na propria função
    */
void insertion(int *arr, int n){

    for(int i=1;i < n;i++){
        int j=i;
        while (arr[j] < arr[j-1] && j>0){
            swap(arr, j, j-1);
            j--;
        }            

        
    }
}