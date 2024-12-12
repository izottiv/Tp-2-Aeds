#include "EntradaDeArquivo.h"
#include <stdio.h>
#include <stdlib.h>

void InicializadorArquivo(FILE *file){
    // Cria as 3 sondas
    ListaSondas Espaconaves; 
    InicializaListaSondas(&Espaconaves);
    for (int i = 0; i < 3; i++){
        Sonda Venus;
        InicializarSonda(&Venus);
        InserirListaSondas(&Espaconaves,&Venus);
    }
    //Recebe as N rochas e as insere em um vetor de rochas
    int count;
    fscanf(file,"%d", &count);
    ArrayDeRochas VetorDeRochas;
    CriarArrayDeRochas(&VetorDeRochas);
    int Peso,Valor;
    for (int i = 0; i < count; i++){
        RochaMineral RochaInserida;
        fscanf(file,"%d %d",&Peso,&Valor);
        InicializaRochaMineral(&RochaInserida,Peso,Valor);
        InsereRochaNoArray(&VetorDeRochas,RochaInserida);
    }
    printf("\n");

    //Funcao E e depois Imprime os resultados
    FuncaoE(&Espaconaves,VetorDeRochas,VetorDeRochas.UltimoLivre);
    ImprimeInformacoes(&Espaconaves,VetorDeRochas.ArrayDeRochas,VetorDeRochas.UltimoLivre);
    printf("\n");
}

void arquivo(char f[]){
    FILE *file = fopen(f, "r");

    if(file){
        InicializadorArquivo(file);
        fclose(file);
        
    }
    else{
        printf("\nERRO ao abrir arquivo!\n");
    }
}