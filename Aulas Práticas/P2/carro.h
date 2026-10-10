#ifndef CARRO_H
#define CARRO_H

typedef struct{
    char nome[20];
    int mat;
}Fun;

typedef struct{
    int anoFab;
    int lugares;
    int numeroChassi;
    char modelo[20];
    Fun *responsavel;
}Carro;

int preencherStruct(int n, Carro *carros);
void alocarFuncionarios(int n, Carro *carros);
void alocarCarro(int n, Carro **carros);
int contarCarros(int n, Carro *carros, int Fab, int Lugar);
int imprimeCarros(int n, Carro *carros, char *nome);
void liberaCarros(Carro *carros);
void liberaFuncionarios(Fun *funcionarios);


#endif 