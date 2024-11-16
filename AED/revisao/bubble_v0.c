#define ARR_SIZE 6
#include <stdio.h>

void swap(int *arr, int i, int j);


void bubble_zero(int *arr, int n);

void display(int *arr, int n){
    for(int i=0;i<n;i++){
        printf("[%d]", arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[ARR_SIZE]={1, 5, 8, 2, 3, 4};
    bubble_zero(arr, ARR_SIZE);
    display(arr, ARR_SIZE);
    return 0;
}

void bubble_zero(int *arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1]){// 3 5
                swap(arr, j, j+1);
            }
        }
    }
}
//cru, quick and dirty, sem verificações, sem flags, so força bruta!
void swap(int *arr, int i, int j){
    int temp=arr[j];
    arr[j]=arr[i];
    arr[i]=temp;
}