#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "CentralDeComando/TAD_CentraDeComando.h"
#include "EntradaDeArquivo.h"


int main() {
    int escolha;
    printf("Deseja realizar a entrada de dados por (1-Arquivo 2-Terminal): ");
    scanf("%d", &escolha);
    if(escolha == 1){
    char nome[] = {"teste.txt"};
    clock_t Ticks[2];
    Ticks[0] = clock();
    arquivo(nome);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1.0000 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g segundos", Tempo);
    printf("\n");
    }
    else{
        Inicializador();
    }

    return 0;
}
