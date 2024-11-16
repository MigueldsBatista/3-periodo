#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 6
void swap(int a, int b){
    int temp=a;
    a=b;
    b=temp;
}

void insertion(int *arr, int n){
    int i, j;
    //melhor caso O(n) - RARO
    //pior caso O(n^2) 

    for(i=1 ; i < n ;i++){
        j=i;

        while(arr[j] > arr[j-1] && j > 0){
            
            swap(arr[j], arr[j-1]);
            j--;

        }
    }

}

int main(){

int arr[ARR_SIZE] = {1, 3, 5, 6, 8, 2};
insertion(arr, ARR_SIZE);
for(int i=0;i<ARR_SIZE;i++){
    printf("[%d],", arr[i]);
}
printf("\n");


}