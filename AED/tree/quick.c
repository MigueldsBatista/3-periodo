#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

void quicksort(int arr[], int startIndex, int endIndex);

int partition(int arr[], int startIndex, int endIndex);

void swap(int arr[], int i, int j);


int main(){
    int arr[SIZE]={6, 5, 4, 3, 2, 1};

    quicksort(arr, 0, SIZE-1);
    
    for(int i=0;i<SIZE;i++){
        printf("[%d]", arr[i]);
    }
}

void swap(int arr[], int i, int j){
    int aux=arr[j];
    arr[j]=arr[i];
    arr[i]=aux;
}

void quicksort(int arr[], int startIndex, int endIndex){

if(startIndex < endIndex){
    int pivotIndex = partition(arr, startIndex, endIndex);

    quicksort(arr, startIndex, pivotIndex-1);

    quicksort(arr, pivotIndex+1, endIndex);

}
}

int partition(int arr[], int startIndex, int endIndex){
    int pivotIndex= endIndex;
    int pivot=arr[startIndex];

    for(int i = endIndex ; i > startIndex ; i--){
        if(arr[i]<=pivot){
            swap(arr, i, pivotIndex);
            pivotIndex--;
        }
    }
    swap(arr, startIndex, pivotIndex);
    
    return pivotIndex;
}