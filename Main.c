#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "CentralDeComando/TAD_CentraDeComando.h"


//#include <stdio.h>

// void gerarCombinacoes(int arr[], int n, int r, int Possicao, int data[], int i) {
//     if (Possicao == r) {
//         for (int j = 0; j < r; j++) {
//             printf("%d ", data[j]);
//         }
//         printf("\n");
//         return;
//     }

//     if (i >= n) {
//         return;
//     }

//     data[Possicao] = arr[i];
//     gerarCombinacoes(arr, n, r, Possicao + 1, data, i + 1);

//     gerarCombinacoes(arr, n, r, Possicao, data, i + 1);
// }

// void gerarTodasCombinacoes(int arr[], int n) {
//     for (int r = 1; r <= n; r++) {
//         int data[r]; 
//         gerarCombinacoes(arr, n, r, 0, data, 0);
//     }
// }

int main() {
    clock_t Ticks[2];
    Ticks[0] = clock();
    //O código a ter seu tempo de execução medido ficaria neste ponto.
    Inicializador();
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1.0000 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.", Tempo);
    getchar();
    return 0;
}
