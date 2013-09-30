#include <stdio.h>
#include <time.h>
#define MAXN 1000

void heapifyBottomUp(int * vetor, int n);
void downHeap(int *vetor, int i, int n);
void removeFromTop(int *vetor, int n);

int main() {

  int i,n,j,k,auxswap ;
  int vetor[MAXN];
  while (scanf("%d", &n) != EOF) {
    // Le a entrada
    for (i = 0; i < n; i++)
      scanf(",%d", &vetor[i]);


    /* Ordenacao aqui
     * Lembre-se de executar varias vezes.
     */


    clock_t start = clock() ;

    /* HeapSort */
    heapifyBottomUp(vetor, n);
    for( i = n; i > 0 ; i--) removeFromTop(vetor, i);

    clock_t end = clock() ;
    double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC ;
    printf("Time: %f\n",elapsed_time);

    // Imprime a saida
    printf("%d", n);
    for (i = 0; i < n; i++)
      printf(",%d", vetor[i]);
    printf("\n");
  }

  return 0;
}

void heapifyBottomUp(int *vetor, int n){
    int i = (n-1)/2;
    int j;

    while(i >= 0) {
        downHeap(vetor, i, n);
        i--;
    }
}

void downHeap(int *vetor, int i, int n){
    int auxswap;

    if(i >= n/2) return;
    //Folhas nao possuem filhos

    //nao existe filho direito
    if(2*i+2 > n-1){
        if( vetor[i] < vetor[2*i+1]){
            auxswap = vetor[i];
            vetor[i] = vetor[2*i+1];
            vetor[2*i+1] = auxswap;
            downHeap(vetor,2*i+1,n);
        }
        else return;
    }
    else if( vetor[i] < vetor[2*i+1]){
        if( vetor[2*i+1] < vetor[2*i+2]) {
            auxswap = vetor[i];
            vetor[i] = vetor[2*i+2];
            vetor[2*i+2] = auxswap;
            downHeap(vetor,2*i+2,n);
        }
        else {
            auxswap = vetor[i];
            vetor[i] = vetor[2*i+1];
            vetor[2*i+1] = auxswap;
            downHeap(vetor,2*i+1,n);
        }
    }
    else if( vetor[i] < vetor[2*i+2]){
        auxswap = vetor[i];
        vetor[i] = vetor[2*i+2];
        vetor[2*i+2] = auxswap;
        downHeap(vetor,2*i+2,n);
    }
    else return;
}

void removeFromTop(int *vetor, int n){
    int auxswap;
    int i;
    auxswap = vetor[0];
    vetor[0] = vetor[n-1];
    vetor[n-1] = auxswap;
    downHeap(vetor,0,n-1);
    return;
}
