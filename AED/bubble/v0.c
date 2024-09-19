#include <stdio.h>
#include <stdlib.h>
/*
Versãoa inicial do algoritimo, não tem verificações de parada 
caso o array ja esteja ordenado nos continuamos iterando
e ele sempre compara todos os pares

Melhor caso O(n^2)
Pior caso O(n^2)

*/

void bubble_sort(int *arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}