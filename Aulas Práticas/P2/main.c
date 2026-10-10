#include "carro.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c; int n;
    Carro *carros;
    int Fab, Lugar;
    char nome[20];

    scanf("%d", &n);
    scanf(" %c", &c);

    if(c == 'C'){
        scanf("%d %d", &Fab, &Lugar);
    } else if(c == 'I'){
        scanf("%s", nome);
    }

    alocarCarro(n, &carros);
    preencherStruct(n, carros);

    switch(c){
        case 'C':
            printf("%d", contarCarros(n, carros, Fab, Lugar));
            break;
        case 'I':
            imprimeCarros(n, carros, nome);
            break;
        default:
            printf("Letra errada: por favor, tente novamente.\n");
            break;
    }

    liberaCarros(carros);

    return 0;
}