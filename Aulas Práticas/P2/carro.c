#include "carro.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void alocarFuncionarios(int n, Carro *carros){
    for(int i = 0; i < n; i++){
        carros[i].responsavel = (Fun *) malloc(sizeof(Fun));
    }    
}

void alocarCarro(int n, Carro **carros){    
    *carros = (Carro *) malloc (n*sizeof(Carro));
}

void liberaCarros(Carro *carros){
    free(carros);
}

void liberaFuncionarios(Fun *responsavel){
    free(responsavel);
}

int contarCarros(int n, Carro *carros, int Fab, int Lugar){

    if(carros == NULL){
        printf("\nErro de alocação de memoria! ");
        return 0;
    }

    int quant = 0;
    for(int i = 0; i < n; i++){
        if(carros[i].anoFab > Fab){
            if(carros[i].lugares > Lugar){
                quant += 1;
            }
        }
    }
    return quant;
}

int imprimeCarros(int n, Carro *carros, char *nome){

    if(carros == NULL){
        printf("\nErro de alocação de memoria! ");
        return 0;
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(carros[j].anoFab < carros[j+1].anoFab){
                Carro temp = carros[j];
                carros[j] = carros[j+1];
                carros[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(strcmp(nome, carros[i].responsavel->nome) == 0){
            printf("%s [%d|%d|%d]\n", carros[i].modelo, carros[i].anoFab, carros[i].lugares, carros[i].numeroChassi);
        }
    }

    return 0;
}

int preencherStruct(int n, Carro *carros){

    if(carros == NULL){
        printf("\nErro de alocação de memoria! ");
        return 0;
    }

    alocarFuncionarios(n, carros);

    for(int i = 0; i < n; i++){
        scanf("%d %s %d %d %s %d", &carros[i].numeroChassi,
            carros[i].modelo,
            &carros[i].lugares,
            &carros[i].anoFab,
            carros[i].responsavel->nome,
            &carros[i].responsavel->mat);
    }

    return 0;
}