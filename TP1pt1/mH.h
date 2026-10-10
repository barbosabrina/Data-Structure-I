#ifndef montyhall_h
#define montyhall_h

//Struct principal para o evento de Montyhall com as portas e a escolha de porta do carro
typedef struct mH
{
    int portas[3];
    int escolha;
}MontyHall;

//Função para alocar a struct de Montyhall e escolher qual será a porta em que o carro esta
MontyHall* criaMH();´
//Função para liberar a alocação
MontyHall* destroiMH(MontyHall* e);
//Função para sorteio da escolha inicial do usuario
void escolhaInicialMH(MontyHall* e);
//Função para trocar a porta escolhida pelo usuario por 0
void revelaPortaMH(MontyHall* e);
//Função para trocar a escolha do usuario para a outra porta 
void trocarPortaMH(MontyHall* e);
//Função para verificar se o usuario escolheu a porta com o carro
int verificarCarroMH(MontyHall* e);

#endif // montyhall.h   