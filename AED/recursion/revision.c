#include <stdio.h>

int fatorial(int n){

    if(n==1 || n==0){
        return 1;
    }
    return n*fatorial(n-1);
}
//função que pega um numero positivo n e pra cada numero inteiro multiplica por 2 e soma
//ex 4 : (1*2) + (2+2) + (3*2) + (4*2) = 2+4+6+8 = 20
//ex 5 : (1*2) + (2+2) + (3*2) + (4*2) + 5*2 = 2+4+6+8 +10= 30 

int numTimesTwo(int n){
    if(n==1){
        printf("caso base: %d*2\n", (n));

        return n*2;
    }
    printf("%d*2 + %d*2\n", n, n-1);

    return n*2+numTimesTwo((n-1));
}

int arraySum(int *arr, int n){
    if(n==1){
        printf("%d\n", arr[0]);
        return arr[0];
    }
    printf("%d +", arr[n-1]);
    return arr[n-1]+arraySum(arr, n-1);
}

int main(){
    printf("%d", fatorial(5));
    printf("\n");
    printf("%d\n", numTimesTwo(4));

    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = arraySum(arr, n);
    printf("\nSoma: %d\n", sum);

    printf("%d", arraySum(arr, n));
    return 0;
}