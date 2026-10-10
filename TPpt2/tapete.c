#include <stdio.h>
#include <stdlib.h>

#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"

#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET



void tapeteSierpinski(int i, int j, int size, int **m );

int main(){

    int **m;
    
    //entrada de p, i, j, e o size da matriz
    int p, i, j, size;
    scanf("%d", &p);

    //calculo do valor de n com a potencia de p fornecida
    int n = 1;
    for(int i = 1; i <= p; i++){
        n *= 3;//n = n * 3
    }

    i = (n - 1) / 2;
    j = (n - 1) / 2;

    size = n;

    //alocacao da matriz nxn dinamicamente 
    m = (int **) malloc(n * sizeof(int *));
        for(int k = 0; k < n; k++){
            m[k] = (int *) malloc(n * sizeof(int));
        }

//================================VERIFICAÇAO DE MEMORIA ALOCADA================================

    //verificar se há algo no vetor antes de passar
    if (!m){
        printf(" Memória insuficiente!\n");
        return -1;
    }

//=============================PREENCHER MATRIZ=================================================
    //inicializar tudo com 1 para depois remover
    for(int k = 0; k < n; k++){
        for(int s = 0; s < n; s++){
            m[k][s] = 1;
        }
    }

//=============================PARTE FUNCIONAL DO TAPETE========================================
    tapeteSierpinski(i, j, size, m );

//=====================================IMPRIMIR MATRIZ==========================================

    for(int k = 0; k < n; k++){
        for(int s = 0; s < n; s++){
            if (m[k][s] == 1)
                printf(YELLOW("%d "), m[k][s]);
            else
                printf(RED("%d "), m[k][s]);
        }
    printf("\n");
    }

//==================================LIBERAR MATRIZ==============================================

    for(int i = 0; i < n; i++){
        free(m[i]);
    }
    free(m);

    return 0;
}

//=========================IMPLEMENTAÇÃO DA FUNÇÃO==============================================
void tapeteSierpinski(int i, int j, int size, int **m ){

    if (size == 1){
        return;
    } else{
        //novo valor de size 
        size = size/3;
        
        //parametros para saber de onde ate onde ira ser zerado
        //o proximo subquadrado
        int i2 = i + size/2;
        int j2 = j + size/2;

        //zerando o bloco central escolhido
        for(int i1 = i - size/2; i1 <= i2; i1++){
            for(int j1 = j - size/2; j1 <= j2; j1++){
                m[i1][j1] = 0;
            }
        }

        //pelos possiveis deslocamentos percorre os novos centros
        //direita, esquerda e centro = 0
        for(int vi = -1; vi <= 1; vi++){
            for(int vj = -1; vj <= 1; vj++){
                //se for o centro 0,0 nao sera preciso remover
                if(vi == 0 && vj == 0){
                    continue;

                }//se nao for, atualiza os indices e chama a funçao de novo 
                else{
                    int newi = i + vi * size;
                    int newj = j + vj * size;
                    tapeteSierpinski( newi, newj, size, m);
                }           
            }
        }
}
}