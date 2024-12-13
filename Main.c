#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "CentralDeComando/TAD_CentraDeComando.h"
#include "Arquivo/EntradaDeArquivo.h"


int main() {
    int escolha, escolhaarquivo;
    printf("Deseja realizar a entrada de dados por (1- Arquivo 2- Terminal): ");
    scanf("%d", &escolha);
    char nome[50];
    if(escolha == 1){
        printf("Deseja utilizar um arquivo com quantas rochas ?\n 1- 10 Rochas\n 2- 15 Rochas\n 3- 20 Rochas\n 4- 25 Rochas\n 5- 50 Rochas\n");
        printf("Escolha: ");
        scanf("%d", &escolhaarquivo);
        switch (escolhaarquivo)
        {
        case 1:
            strcpy(nome,"Arquivo/10Rochas.txt");
            break;
        case 2:
            strcpy(nome,"Arquivo/15Rochas.txt");
            break;
        case 3:
            strcpy(nome,"Arquivo/20Rochas.txt");
            break;
        case 4:
            strcpy(nome,"Arquivo/25Rochas.txt");
            break;
        case 5:
            strcpy(nome,"Arquivo/50Rochas.txt");
            break;
        default:
            break;
        }
    clock_t Ticks[2];
    Ticks[0] = clock();
    arquivo(nome);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1.0000 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g segundos", Tempo);
    }
    else{
        Inicializador();
    }

    return 0;
}
