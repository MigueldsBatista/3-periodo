#define ARR_SIZE 6
#include <stdio.h>

void swap(int *arr, int i, int j);

void bubble_two(int *arr, int n);

void display(int *arr, int n){
    for(int i=0;i<n;i++){
        printf("[%d]", arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[ARR_SIZE]={1, 5, 8, 2, 3, 4};
    bubble_two(arr, ARR_SIZE);
    display(arr, ARR_SIZE);
    return 0;
}

void bubble_two(int *arr, int n){
    int i = 0;
    int troca = 1;

    while(i < n && troca == 1){
        troca = 0;
        for(int j = n - 1; j > i; j--){
            if(arr[j] < arr[j - 1]){
                swap(arr, j, j - 1);
                troca = 1;
            }
        }
        i++;
    }
}

void swap(int *arr, int i, int j){
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}
