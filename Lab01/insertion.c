#include <stdio.h>
#include <time.h>
#define MAXN 1000

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

    /* Insertion */
    for( i = 1; i < n; i++){
        if( vetor[i] < vetor[i-1]){
            auxswap = vetor[i];
            j = 0;
            while( vetor[j] < vetor[i] ) j++;
            k = i;
            while( k > j) {
                vetor[k] = vetor[k-1];
                k--;
            }
            vetor[j] = auxswap;
        }
    }

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
