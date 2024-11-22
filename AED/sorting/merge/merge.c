//aplica a tecnica divisão e conquista

/*

Divisão: divide o array na metade

Conquista

Combinação: intercalar as duas subsequencias ordenadas pra produzir a solução
*/
#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

void mergesort(int arr[], int startIndex, int endIndex);

void merge(int arr[], int startIndex, int mid, int endIndex);

int main() {
    // Definição e inicialização do array
    int arr[] = {10, 7, 8, 9, 1, 5};
    // Determinando o tamanho do array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Chama a função mergesort para ordenar o array
    mergesort(arr, 0, n - 1);
    
    // Imprime o array ordenado
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}





void mergesort(int arr[], int startIndex, int endIndex){
    //caso base INICIO > FIM
    if (startIndex > endIndex) return;
        
    //pega o meio do array
    int mid = (startIndex + endIndex) / 2;
    
    mergesort(arr, startIndex, mid);
    mergesort(arr, mid + 1, endIndex);
    
    merge(arr, startIndex, mid, endIndex);
    
}   


void merge(int arr[], int startIndex, int mid, int endIndex){
    int inicio_v01=startIndex;
    int inicio_v02=mid+1;
    int posLivre=0;

    int aux[SIZE];

    while(inicio_v01 <= mid && inicio_v02 <= endIndex){
        if(arr[inicio_v01] <= arr[inicio_v02]){
            aux[posLivre++] = arr[inicio_v01++];
        }
        else{
            aux[posLivre++] = arr[inicio_v02];

        }
    }

    // Adiciona os elementos caso a lista da direita tenha acabado primeiro
    while (inicio_v01 <= mid) {
        newArr[newIndex++] = arr[inicio_v01++];
    }

    // Adiciona os elementos caso a lista da esquerda tenha acabado primeiro
    while (inicio_v02 <= endIndex) {
        newArr[newIndex++] = arr[inicio_v02++];
    }

    for(inicio_v01 = startIndex ; inicio_v01 <= endIndex; inicio_v01++){
        arr[inicio_v01]= aux[inicio_v01-startIndex];
    }

}