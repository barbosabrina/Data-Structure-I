#include "mH.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//=============Funcionamento do sistema================

//Para tranformar a escolha de "cabra" e "carro" no 
//programa, utilazaremos de 1 - para carro e 2 - para
//cabra. Assim, o numero 0 nos ajudou como fosse "nulo".

//=====================================================


MontyHall* criaMH() {

    //alocando a struct e conferindo se foi alocada corretamente
    MontyHall* e = (MontyHall*) malloc(sizeof(MontyHall));
    if (!e){
        printf(" Memória insuficiente!\n");
        return NULL;
    }

    //preenchendo todas portas com o numero 2 pré-selecionado
    for (int i = 0; i < 3; i++)
    {
        e->portas[i] = 2;
    }

    //sorteando uma porta para conter o "carro"
    e->portas[rand() % 3] = 1;

    //retorna a struct alocada
    return e;
}

MontyHall* destroiMH(MontyHall* e) {
    //libera a struct alocada dinamicamente
    free(e);
    return NULL;
}

void escolhaInicialMH(MontyHall* e) {
    //sorteia a escolha aleatoria do usuario
    e->escolhand() % 3;
}

void revelaPortaMH(MontyHall* e) {
    
    //for para trocar a porta escolhida do usuario
    //por 0 para mostrar a escolha
    for (int i = 0; i < 3; i++)
    {
        if(e->portas[i] == 2 && i != e->escolha){
            e->portas[i] = 0;
            break;
        }
    }
}
void trocarPortaMH(MontyHall* e) {
    
    //for para trocar as duas portas restantes para 
    //validar a teoria de Montyhall com porcentagens
    for (int j = 0; j < 3; j++){
        if(e->portas[j] != 0 && j != e->escolha){
            e->escolha = j;
            break;
        }
    }
}

int verificarCarroMH(MontyHall* e) {
    //verificar de a nova escolha do usuario é o carro
    //assim, irá retornar 0 ou 1 de acordo com a resposta
    if (e->portas[e->escolha] == 1){
        return 1;
    } else {
        return 0;
    }
}