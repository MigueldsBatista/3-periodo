#include <stdio.h>

/* 
 * Função de ordenação quicksort
 *
 * Parâmetros:
 * arr[]: o array que será ordenado
 * left: o índice esquerdo do array
 * right: o índice direito do array
 */
void quickSort(int arr[], int left, int right) {
    // Variáveis para percorrer o array
    int i = left, j = right;
    // Variável temporária para troca de elementos
    int tmp;
    // Definindo o pivô como o elemento central do array
    int pivot = arr[(left + right) / 2];
    
    // Particionamento do array
    while (i <= j) {
        // Avança o índice 'i' até encontrar um elemento maior ou igual ao pivô
        while (arr[i] < pivot)
            i++;
        // Regride o índice 'j' até encontrar um elemento menor ou igual ao pivô
        while (arr[j] > pivot)
            j--;
        // Se os índices ainda não se cruzaram, trocamos os elementos
        if (i <= j) {
            // Troca os elementos arr[i] e arr[j]
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            // Move os índices
            i++;
            j--;
        }
    }
        
    // Recursão para a sublista da esquerda
    if (left < j) {
        quickSort(arr, left, j);
    }

    // Recursão para a sublista da direita
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    // Definição e inicialização do array
    int arr[] = {10, 7, 8, 9, 1, 5};
    // Determinando o tamanho do array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Chama a função quicksort para ordenar o array
    quickSort(arr, 0, n - 1);
    
    // Imprime o array ordenado
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
