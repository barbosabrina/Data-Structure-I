#include "estatistica.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);
    
    if ( n!= 1) 
        return 0;

    for (int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);

        double *v = criarVetor(n);

        int ops = 0;
        double media   = calcularMedia(v, k, &ops);
        double desvpad = calcularDesvpad(v, k, media, &ops);

        printf("%.3f %.3f %d\n", media, desvpad, ops);
        free(v);
    }

    return 0;
}