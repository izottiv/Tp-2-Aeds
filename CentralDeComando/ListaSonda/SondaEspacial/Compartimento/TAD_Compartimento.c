#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TAD_Compartimento.h"

// Inicializa um compartimento
void InicializadorCompartimento(GerenciadorCompartimento *Comp){
    Comp->PrimeiroRocha = (Compartimento*) malloc(sizeof(Compartimento));
    Comp->UltimoRocha = Comp->PrimeiroRocha;
    Comp->PrimeiroRocha->Prox = NULL;
}

// Verifica se o compartimento esta vazio
int VerificaSeVazia(GerenciadorCompartimento *comp){
    return(comp->PrimeiroRocha == comp->UltimoRocha);
}

// Imprime as informaçoes do Compartimento
void ImprimeConteudoCompartimento(GerenciadorCompartimento *comp){
     if(VerificaSeVazia(comp) == 0){
        Compartimento *aux;   
        aux = comp->PrimeiroRocha->Prox;
        while(aux != NULL){
            printf("=================================\n");
            printf("Valor: %d\n",aux->_RochaMineral.Valor);
            printf("Peso: %d\n",aux->_RochaMineral.Peso);
            aux = aux->Prox; 
        }
    }
    else{
        printf("Compartimento Vazio\n");
    }
}

// Retorna o peso atual do compartimento
int PesoAtualCompartimento(GerenciadorCompartimento *comp){
    int Peso = 0;
    Compartimento *aux;
    aux = comp->PrimeiroRocha->Prox;
    if (VerificaSeVazia(comp) == 1){
        return 0;
    }
    else{ 
        while (aux != NULL){
            Peso += aux->_RochaMineral.Peso;
            aux = aux->Prox;
        }
        return Peso;
    }
}

// Insere uma rocha em um compartimento na ultima possicao
void InserirRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha){ 
    if(40 >= PesoAtualCompartimento(comp) + Rocha->Peso){//Verifica se o peso máximo está excedido
        comp->UltimoRocha->Prox = (Compartimento*)malloc(sizeof(Compartimento));
        comp->UltimoRocha = comp->UltimoRocha->Prox;
        comp->UltimoRocha->_RochaMineral = *Rocha;
        comp->UltimoRocha->Prox = NULL;
    }
    else{
    }
}

void LimpaCompartimento(GerenciadorCompartimento *comp){
    comp->UltimoRocha = comp->PrimeiroRocha;
    comp->PrimeiroRocha->Prox = NULL;
}

int QuantidadeRochasCompartimento(GerenciadorCompartimento *comp){
    Compartimento *Aux;
    int quantidade = 0;
    Aux = comp->PrimeiroRocha->Prox;
    while (Aux != NULL){
        quantidade ++;
        Aux = Aux->Prox;
    }
    return quantidade;
}