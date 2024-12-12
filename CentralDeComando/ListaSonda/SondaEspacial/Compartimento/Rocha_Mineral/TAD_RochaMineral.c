#include "TAD_RochaMineral.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Gets
int GetValor(RochaMineral* Rocha){
    return Rocha->Valor;
}
int GetPeso(RochaMineral* Rocha){
    return Rocha->Peso;
}

//Sets
void SetValor(RochaMineral* Rocha, int valor){
    Rocha->Valor = valor;
}
void SetPeso(RochaMineral* Rocha, int PESO){
    Rocha->Peso = PESO;
}

//Seta os valores do struct
void InicializaRochaMineral(RochaMineral* Rocha, int PESO, int valor){
    SetValor(Rocha, valor);
    SetPeso(Rocha, PESO);
}

//Cria um Vetor De rochas Vazio
void CriarArrayDeRochas(ArrayDeRochas *ListaDeRocha){
    ListaDeRocha->Primeiro = 0;
    ListaDeRocha->UltimoLivre = ListaDeRocha->Primeiro;
}

//retorna um valor se o Vetor estiver vazio
int VereficaSeArrayVazio(ArrayDeRochas *ListaDeRocha){
    return(ListaDeRocha->Primeiro == ListaDeRocha->UltimoLivre );
}

//Insere um rocha na lista de rochas
int InsereRochaNoArray(ArrayDeRochas *ListaDeRocha,RochaMineral Rocha){
    if (ListaDeRocha->UltimoLivre == TAMMAX){
        printf("Array cheio\n");
        return 0;
    }
    ListaDeRocha->ArrayDeRochas[ListaDeRocha->UltimoLivre] = Rocha;
    ListaDeRocha->UltimoLivre ++;
    return 1;
}

//Retira uma rocha da lista em um posicao indicada
int RetiraRochaNoArray(ArrayDeRochas *ListaDeRocha,int Possicao){
    if (VereficaSeArrayVazio(ListaDeRocha) || Possicao >= ListaDeRocha->UltimoLivre || Possicao < 0){
        return 0;
    }
    int contador;
    for (contador = Possicao + 1; contador <= ListaDeRocha->UltimoLivre; contador++){
        ListaDeRocha->ArrayDeRochas[contador - 1] = ListaDeRocha->ArrayDeRochas[contador];
    }
    ListaDeRocha->UltimoLivre --;
    return 1;
}

//Imprime o Vetor de Rochas
void ImprimeArrayDeRochas(ArrayDeRochas *ListaDeRocha){
    if (VereficaSeArrayVazio(ListaDeRocha)){
        printf("Array Vazio\n");
        return;
    }
    for (int i = 0; i < ListaDeRocha->UltimoLivre; i++){
        printf("Rocha numero %d - Peso: %d - Valor: %d\n",i,ListaDeRocha->ArrayDeRochas[i].Peso,ListaDeRocha->ArrayDeRochas[i].Valor);
    }
}