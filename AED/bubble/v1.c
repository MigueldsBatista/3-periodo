#include <stdio.h>
#include <stdlib.h>


void bubble_sort(int *arr, int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j<=i;j--){
            if(arr[j]>arr[j-1]){
                int temp =arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}