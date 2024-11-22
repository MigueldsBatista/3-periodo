/*
Ser um programador pragmático não é fácil, 
as vezes vc vai estar estudando o algoritimo de recursividade sem entender nada 
e vai achar que você não sabe programação. Talvez você de fato não saiba. 
Mas pra atingir grandeza é necessário esforço, é necessário desligar o copilot e o chat gpt as vezes.
Ninguém vira programador do dia pra noite. Eu não sei quando ou se alguem vai ler isso um dia, e provavelmente eu não vou conseguir implementar o código de primeira.
Mas eventualmente eu vou me tornar a melhor versão que eu posso ser
19/11/2024
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
  printf("swapped (%d) at index %d <=> (%d) at index %d\n", arr[i], i, arr[j], j);
}

int partition(int arr[], int startIndex, int endIndex){ //-> pivot index



//o indice do pivot começa de tras pra frente
int pivotIndex=endIndex;

//usamos o primeiro elemento como pivot
int pivot=arr[startIndex];

    for(int i = endIndex ; i > startIndex ; i--){         //o erro provavelmente esta aqui
        printf("startIndex=%d | endIndex =%d | pivot=%d\n", startIndex, endIndex, pivotIndex);
        if(arr[i]>=pivot){
            swap(arr, pivotIndex, i);
            pivotIndex--;
        }

    }

    swap(arr, startIndex, pivotIndex);

    return pivotIndex;
}



void quicksort(int arr[], int startIndex, int endIndex){

if(startIndex < endIndex){//ou aqui
int pivotIndex = partition(arr, startIndex, endIndex);

//organiza os elementos a esquerda do array
quicksort(arr, startIndex, pivotIndex-1);

// organiza os elementos a direita do array
quicksort(arr, pivotIndex+1, endIndex);

}

}

int main(){
    int array[SIZE]={
        2,15,4,3,7,1
    };
    
    quicksort(array, 0, SIZE-1);

    for(int i=0;i<SIZE;i++){
        printf("[%d]", array[i]);
    }


}
