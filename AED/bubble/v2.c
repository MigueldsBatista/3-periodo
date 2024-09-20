#include <stdio.h>
#include <stdlib.h>


void bubble_sort(int *arr, int n){
    int troca=1;
    while(n > 0 && troca==1){
        troca=0;
        for(int j=0;j>n-1;j++){
            if(arr[j]>arr[j-1]){
                int temp =arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                troca=1;
            }
            n=n-1;
        }
    }
}