#include <stdio.h>
#include <stdlib.h>
#define TAM 7

void quicksort(int arr[], int startIndex, int endIndex);
void swap(int arr[], int i, int j);
int partition(int arr[], int startIndex, int endIndex);

int main() {
  int arr[] = {55, 25, 34, 10, -20, 68, 62};

  printf("Vetor de Entrada:\n");
  for (int i = 0; i < TAM; i++)
    printf("%d ", arr[i]);

  quicksort(arr, 0, TAM - 1);

  printf("\n\nVetor Ordenado:\n");
  for (int i = 0; i < TAM; i++)
    printf("%d ", arr[i]);

  return 0;
}


void quicksort(int arr[], int startIndex, int endIndex) {
  static int chamadas = 0;
  chamadas++;
  printf("\nChamada %d\n", chamadas);
  if (startIndex < endIndex) {
    printf("\nQuicksort chamado: startIndex=%d, endIndex=%d\n", startIndex, endIndex);

    int pivotIndex = partition(arr, startIndex, endIndex);

    printf("Pivot escolhido: %d (Index: %d)\n", arr[pivotIndex], pivotIndex);

    quicksort(arr, startIndex, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, endIndex);
    
  }
  else{
    printf("\nChamada %d finalizada\n", chamadas);
  }
}



int partition(int arr[], int startIndex, int endIndex) {
  int pivot = arr[startIndex];
  int pivotIndex = endIndex;

  printf("\nPartition iniciado: startIndex=%d, endIndex=%d, pivot=%d\n", startIndex, endIndex, pivot);

  for (int i = endIndex; i > startIndex; i--) {
    if (arr[i] >= pivot) {
      printf("Swap para mover %d para a direita\n", arr[i]);
      swap(arr, i, pivotIndex);
      pivotIndex--;
    }
  }

  swap(arr, startIndex, pivotIndex);
  printf("Pivot %d movido para a posição final: %d\n", pivot, pivotIndex);

  return pivotIndex;
}




//função auxiliar apenas pra realizar a troca
void swap(int arr[], int i, int j) {
  printf("Troca: %d (Index: %d) <-> %d (Index: %d)\n", arr[i], i, arr[j], j);
  int aux = arr[i];
  arr[i] = arr[j];
  arr[j] = aux;
}