#include <stdio.h>
#define LEN 7

int main(){
  int vetor [LEN] = { 791,  122,  419,  922,  959,  855,  838 };

  //inclua o algoritmo de ordenação aqui
  for(int i=0 ; i<LEN ; i++){
    int j=i;
    while (vetor[j]<vetor[j-1] && j > 0)
    {
        int temp=vetor[j];
        vetor[j]=vetor[j-1];
        vetor[j-1]=temp;
        j--;

    }
    
  }
  
  printf("\n\n");
  for(int i = 0; i < LEN; i++){
     printf(" %d ", vetor[i]);
  }
  return 0;
}   	