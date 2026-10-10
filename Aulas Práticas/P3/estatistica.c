#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "estatistica.h"

double *criarVetor(int n) {
    double *v = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++){
        scanf("%lf", &v[i]);
    }
    return v;
}

double calcularMedia(double *v, int n, int *ops){
    double media = 0;
    (*ops)++;                    

    for (int i = 0; i < n; i++){
        media = media + v[i] / n;
        (*ops)++;                 
    }

    return media;
}

double calcularDesvpad(double *v, int n, double media, int *ops){
    double desvpad = 0;
    (*ops)++;                  

    for (int i = 0; i < n; i++){
        desvpad = desvpad + (v[i] - media) * (v[i] - media) / (n - 1);
        (*ops)++;             
    }

    desvpad = sqrt(desvpad);
    (*ops)++;                   

    return desvpad;
}