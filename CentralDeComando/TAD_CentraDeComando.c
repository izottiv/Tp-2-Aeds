#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "TAD_CentraDeComando.h"

void Inicializador(){
    ListaSondas Espaconaves; 
    InicializaListaSondas(&Espaconaves);
    for (int i = 0; i < 3; i++){
        Sonda Venus;
        InicializarSonda(&Venus);
        InserirListaSondas(&Espaconaves,&Venus);
    }
    printf("Sondas Criadas\n");
    printf("\n");

    int count;
    printf("Digite quantas Rochas: ");
    scanf("%d",&count);
    RochaMineral ListaDeRocha[count];
    int Peso,Valor;
    for (int i = 0; i < count; i++){
        RochaMineral RochaInserida;
        printf("Digite o peso e o valor da rocha: ");
        scanf("%d %d",&Peso,&Valor);
        InicializaRochaMineral(&RochaInserida,Peso,Valor);
        ListaDeRocha[i] =  RochaInserida;
    }
    printf("\n");
    
    FuncaoE(&Espaconaves,ListaDeRocha,count);   
    //ImprimirListaSondas(&Espaconaves);
}

void FuncaoE(ListaSondas *ListaDeSondas,RochaMineral ListaDeRochas[],int count){

    RochaMineral CombinacoesDeRochas[1][1];
    gerarTodasCombinacoes(ListaDeRochas,count);

}



void gerarCombinacoes(RochaMineral Array[], int Tamanho, int QuantidadeElementos, int Possicao, RochaMineral data[], int i) {
    if (Possicao == QuantidadeElementos) {
        int PesoCombinacao = 0;
        for (int j = 0; j < QuantidadeElementos; j++) {
            PesoCombinacao += data[j].Peso; 
        }
        printf("Peso total da combinacao %d\n",PesoCombinacao);
        return;
    }

    if (i >= Tamanho) {
        return;
    }

    data[Possicao] = Array[i];
    gerarCombinacoes(Array, Tamanho, QuantidadeElementos, Possicao + 1, data, i + 1);

    gerarCombinacoes(Array, Tamanho, QuantidadeElementos, Possicao, data, i + 1);
}

void gerarTodasCombinacoes(RochaMineral arr[], int n) {
    for (int r = 1; r <= n; r++) {
        RochaMineral data[r]; 
        gerarCombinacoes(arr, n, r, 0, data, 0);
    }
}