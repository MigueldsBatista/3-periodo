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
//Recebe como parametros o array, startIndex e o endIndex
void quicksort(int arr[], int startIndex, int endIndex) {

//garante que não vamos fazer besteira e serve de caso base!
  if (startIndex < endIndex) {
    
    int pivotIndex = partition(arr, startIndex, endIndex);

    //chamada recursiva pra organizar os elementos que vem antes do pivot
    quicksort(arr, startIndex, pivotIndex - 1);

    //chamada recursiva pra organizar os elementos que vem depois do pivot
    quicksort(arr, pivotIndex + 1, endIndex);
  }
}

//Retorna a posição do elemento pivot
int partition(int arr[], int startIndex, int endIndex) {
  int pivot, pivotIndex;

  //nessa versão do quicksort escolhemos o primeiro elemento como pivot
  pivot = arr[startIndex];

  pivotIndex = endIndex;

  for (int i = endIndex; i > startIndex; i--)
    if (arr[i] >= pivot) {
      swap(arr, i, pivotIndex);
      pivotIndex--;
    }

  // Colocamos o pivô na sua posição final
  swap(arr, startIndex, pivotIndex);

  //temos certeza de que essa é a posição final do pivot então retornamos seu indice
  return pivotIndex;
}

//função auxiliar apenas pra realizar a troca
void swap(int arr[], int i, int j) {
  int aux = arr[i];
  arr[i] = arr[j];
  arr[j] = aux;
}