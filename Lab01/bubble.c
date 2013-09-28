#include <stdio.h>
#include <time.h>
#define MAXN 1000

int main() {

  int i,n, newn, auxn, auxswap ;
  int vetor[MAXN];
  while (scanf("%d", &n) != EOF) {
    // Le a entrada
    for (i = 0; i < n; i++)
      scanf(",%d", &vetor[i]);


    /* Ordenacao aqui
     * Lembre-se de executar varias vezes.
     */


    clock_t start = clock() ;

    /* Bubble Sort */
    auxn = n ;
    do{
        newn = 0 ;
        for( i = 1; i < auxn; i++) {
            if( vetor[i-1] > vetor[i]) {
                    auxswap = vetor[i];
                    vetor[i] = vetor[i-1];
                    vetor[i-1] = auxswap;
                    newn = i ;
            }
        }
        auxn = newn;
    } while ( newn != 0);

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
