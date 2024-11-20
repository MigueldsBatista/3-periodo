//aplica a tecnica divisão e conquista

/*

Divisão: divide o array na metade

Conquista

Combinação: intercalar as duas subsequencias ordenadas pra produzir a solução
*/
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
    
    //inicia chamada recursiva pros elementos a esquerda
    mergesort(arr, startIndex, mid);
    //inicia uma chamada recursiva pros elementos a direita
    mergesort(arr, mid + 1, endIndex);
    

    merge(arr, startIndex, mid, endIndex);
    
}   


void merge(int arr[], int startIndex, int mid, int endIndex){
//      ~      _     -
    // (4, 7, 2) (5 ,1)
    // Representa o início da primeira parte do array a ser mesclado
    int inicio_v01 = startIndex;

    // Representa o início da segunda parte do array (após o meio)
    int inicio_v02 = mid + 1;

    // Posição livre no array auxiliar, onde serão armazenados os elementos ordenados
    int newIndex = 0;

    // Array auxiliar para armazenar os elementos mesclados temporariamente
    int newArr[SIZE];

    // Combina os elementos das duas partes ordenadas do array original
    while (inicio_v01 <= mid && inicio_v02 <= endIndex) {

        // Se o elemento da primeira parte for menor ou igual ao da segunda parte
        if (arr[inicio_v01] <= arr[inicio_v02]) {
            newArr[newIndex++] = arr[inicio_v01++]; // Adiciona o elemento da primeira parte no array auxiliar
            //obs so incrementa o indice atual caso seja adicionado, caso contrario comparamos ele com o proximo do outro array
        } else {
            newArr[newIndex++] = arr[inicio_v02++]; // Adiciona o elemento da segunda parte no array auxiliar
            //obs so incrementa o indice atual caso seja adicionado, caso contrario comparamos ele com o proximo do outro array
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

    // Copia os elementos do array auxiliar de volta para o array original
    for (inicio_v01 = startIndex; inicio_v01 <= endIndex; inicio_v01++) {
        arr[inicio_v01] = newArr[inicio_v01 - startIndex]; 
        // `inicio_v01 - startIndex` ajusta o índice relativo ao array auxiliar
        //ex no inicio os dois são iguais então é zero
        // dps inicio v01 aumenta ai fica 1, dps 2 e assim sucessivamente
    }
}
