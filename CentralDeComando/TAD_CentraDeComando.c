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

    FuncaoE(&Espaconaves,&ListaDeRocha[0],count);   
    //ImprimirListaSondas(&Espaconaves);
}

void FuncaoE(ListaSondas *ListaDeSondas,RochaMineral *ListaDeRochas,int count){
    //int VetorDePossicoes[count];
    //RochaMineral ListaDeRochasOrganizadas[count];    
    for (int i = 0; i < count; i++){
        printf("peso %d valor %d ",ListaDeRochas[i].Peso,ListaDeRochas[i].Valor);
    }
    
}
