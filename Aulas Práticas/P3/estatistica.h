#ifndef ESTATISTICA_H
#define ESTATISTICA_H

double *criarVetor(int n);
double calcularMedia(double *v, int n, int *ops);
double calcularDesvpad(double *v, int n, double media, int *ops);

#endif 