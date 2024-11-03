#define ARR_SIZE 6
#include <stdio.h>

void swap(int *arr, int i, int j);


void bubble_one(int *arr, int n);

void display(int *arr, int n){
    for(int i=0;i<n;i++){
        printf("[%d]", arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[ARR_SIZE]={1, 5, 8, 2, 3, 4};
    bubble_one(arr, ARR_SIZE);
    display(arr, ARR_SIZE);
    return 0;
}
// BUBBLE  one ele vai ao contrario percorrendo a lista, indo ate o ultimo elemento que fomos

void bubble_one(int *arr, int n){
    for(int i=0;i<n;i++){
        for(int j=n;j>i;j--){
            if(arr[j] < arr[j-1]){// 3 5
                swap(arr, j, j-1);
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