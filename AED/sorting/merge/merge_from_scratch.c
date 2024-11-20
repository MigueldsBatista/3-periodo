#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

void mergesort(int arr[], int startIndex, int endIndex);
void merge(int arr[], int startIndex, int mid, int endIndex);

int main(){
    int array[SIZE] = {2, 4, 5, 1, 3, 7};

    mergesort(array, 0, SIZE-1);

    for(int i=0;i<SIZE;i++){
        printf("[%d]", array[i]);
    }
}




void mergesort(int arr[], int startIndex, int endIndex){

if(startIndex<endIndex){

int mid = (startIndex+endIndex)/2;


mergesort(arr, startIndex, mid);

mergesort(arr, mid+1, endIndex);

merge(arr, startIndex, mid, endIndex);
    }
}

void merge(int arr[], int startIndex, int mid, int endIndex){
    //representa o inicio da esquerda
    int inicio_v01=startIndex;
    int inicio_v02=mid+1;
    int newIndex=0;

    int newArr[SIZE]={};

    //representa o inicio do array da direita
    while(inicio_v01 <= mid && inicio_v02 <= endIndex){
        if(arr[inicio_v01]<=arr[inicio_v02]){
            newArr[newIndex++]=arr[inicio_v01++];
        }
        else{
            newArr[newIndex++]=arr[inicio_v02++];
        }
    }

    while(inicio_v01 <= mid){
        newArr[newIndex++]=arr[inicio_v01++];
    }

    while (inicio_v02 <= endIndex)
    {
        newArr[newIndex++]=arr[inicio_v02++];
    }


    //finally
    for(inicio_v01=startIndex; inicio_v01 <= endIndex ; inicio_v01++){
        arr[inicio_v01]=newArr[inicio_v01-startIndex];
    }


}