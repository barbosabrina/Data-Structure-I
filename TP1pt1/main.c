#include "mH.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    
    //ponteiro para entrada da struct alocada dinamicamente
    MontyHall *evento;
    //vetor de resultados para armazenar todos antes de printar
    float resultados[2] = { 0, 0};
    //variaveis para numero de execuções e numero da semente
    int n, s;
    //variaveis para tranformação de vitorias e derrotas em porcentagens
    float vit, der;

    //leitura da semente e numero de execuções 
    scanf("%d %d", &s, &n);

    //geração da semente aleatoria
    srand(s);

    //execução do evento de acordo com numero de execuçoes lidos
    for (int i = 0; i < n; i++){
        evento = criaMH();
        escolhaInicialMH(evento);
        revelaPortaMH(evento);
        trocarPortaMH(evento);

        //controla e joga os zeros e uns para dentro dos vetores
        //contabilizando a quantidade exata
        if (verificarCarroMH(evento) == 1){
            resultados[0]++;
        } else {
            resultados[1]++;
        }
        evento = destroiMH(evento);
    }

    //operações para tranformação em porcentagem
    vit = (resultados[0] / n) * 100;
    der = (resultados[1] / n) * 100;

    printf("\nPorcentagem de vitórias: %.2f%%", vit);
    printf("\nPorcentagem de derrotas: %.2f%%", der);

    return 0;
}