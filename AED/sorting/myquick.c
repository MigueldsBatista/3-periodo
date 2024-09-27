#include <stdio.h>
#include <stdlib.h>
#define TAM 7

void swap(int arr[], int i, int j) {
  int aux = arr[i];
  arr[i] = arr[j];
  arr[j] = aux;
}

void partition(int *arr, int startIndex, int endIndex){
    int pivotIndex, pivot;

    pivot=arr[startIndex];
    pivotIndex=endIndex;

    for(int i=endIndex;i>startIndex;i--){// (-) -> i ||||| (~) -> j
                                      //  ~                   _
        if(arr[i] >= arr[pivotIndex]){// [1] [3] [6] [4] [2] [7]

            swap(arr, pivotIndex, i);
            pivotIndex--;

        }
    }
}