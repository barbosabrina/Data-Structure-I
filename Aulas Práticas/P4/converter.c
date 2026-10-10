#include "converter.h"
#include <stdlib.h>
#include <stdio.h>

void Dec2Bin(int numero){

    if(numero != 0){
        Dec2Bin(numero/2);// caso de recursividade
        printf("%d", numero%2);//constante 
    }
    else{
        return;//caso base n <= 2;
    }
}