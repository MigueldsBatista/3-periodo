#include <stdio.h>

//Re
int partition(int arr[], int startIndex, int endIndex);

void quickSort(int arr[], int startIndex, int endIndex);

void swap(int arr[], int i, int j);




int main() {
    // Definição e inicialização do array
    int arr[] = {10, 7, 8, 9, 1, 5};
    // Determinando o tamanho do array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Chama a função quicksort para ordenar o array
    quickSort(arr, 0, n - 1);
    
    // Imprime o array ordenado
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

int partition(int arr[], int startIndex, int endIndex) {
    int pivot, pivotIndex;
    pivot=arr[startIndex];
    pivotIndex=endIndex;

    for(int i= endIndex; i > startIndex;i--) {
        if(arr[i] >= pivot) {
            swap(arr, i , pivotIndex);
            pivotIndex--;
    }

    }
    swap(arr, startIndex, pivotIndex);
    return pivotIndex;
}


void quickSort(int arr[], int startIndex, int endIndex) {

    if (startIndex > endIndex) return;

    int pivot = partition(arr, startIndex, endIndex);
    
    quickSort(arr, startIndex, pivot - 1);
    
    quickSort(arr, pivot + 1, endIndex);

    }

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

