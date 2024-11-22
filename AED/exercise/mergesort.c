#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

void mergesort(int arr[], int startIndex, int endIndex);

void merge(int arr[], int startIndex, int midIndex, int endIndex);

void mergesort(int arr[], int startIndex, int endIndex){

    int mid = (startIndex+endIndex)/2;

    mergesort(arr, startIndex, mid);

    mergesort(arr, mid+1, endIndex);

    merge(arr, startIndex, mid, endIndex);

}

void merge(int arr[], int startIndex, int midIndex, int endIndex){
int inicio_v01=startIndex;
int inicio_v02=midIndex+1;
int aux[SIZE];

int newIndex=0;

while(inicio_v01 <= midIndex && inicio_v02 <= endIndex){
    if(arr[inicio_v01] >= arr[inicio_v02]){
        aux[newIndex++]=arr[inicio_v01++];
    }else{
        aux[newIndex++]=arr[inicio_v02++];
    }
}

while(inicio_v01 <= midIndex){
    aux[newIndex++]=arr[inicio_v01++];
    }

while(inicio_v02<=endIndex){
    aux[newIndex++]=arr[inicio_v02++];    
}

for(inicio_v01 = startIndex ; inicio_v01 <= endIndex ; inicio_v01++){
    arr[inicio_v01]=aux[inicio_v01-startIndex];
}
}
int main(){
int arr[SIZE]={6,5,4,3,2,1};
mergesort(arr, 0, SIZE-1);
for(int i=0;i<SIZE;i++){
    printf("%d", arr[i]);
}
return 0;
}
