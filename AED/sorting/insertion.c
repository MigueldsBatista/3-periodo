
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int arr={9, 8, 7, 6, 5, 4, 3, 2, 1};

void insertionSort(int arr[], int n){

    for(int i=1;i<n;i++){
        
        int j=i;

        while(arr[j] < arr[j-1] && j > 0){
            int aux=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=aux;
            j--;
        }
    }

    for(int i=0;i<n;i++){
        printf("[%d]", arr[i]);
    }

    printf("\n");
}

void gerarValoresAleatorios() {
    int arr[10]; // Array de 10 elementos

    // Inicializa a semente do gerador de números aleatórios
    srand(time(0));

    // Gera 10 números aleatórios entre 0 e 100
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 101; // Gera números de 0 a 100
        printf("Valor gerado: %d\n", arr[i]);
    }

    // Chama a função de ordenação
    printf("\nValores ordenados:\n");
    insertionSort(arr, 10);
}

int main() {
    gerarValoresAleatorios();
    return 0;
}