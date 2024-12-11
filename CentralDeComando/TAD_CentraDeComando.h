#ifndef TAD_CENTRAL_DE_COMANDO_H_
#define TAD_CENTRAL_DE_COMANDO_H_
#define TAMMAX 1000
#include "ListaSonda/TAD_ListaSonda.h"

typedef struct {
    RochaMineral ArrayDeRochas[TAMMAX];
    int Primeiro;
    int UltimoLivre;
}ArrayDeRochas;


void CriarArrayDeRochas(ArrayDeRochas *ArrayDeRocha);

int VereficaSeArrayVazio(ArrayDeRochas *ListaDeRocha);

int InsereRochaNoArray(ArrayDeRochas *ListaDeRocha,RochaMineral Rocha);

int RetiraRochaNoArray(ArrayDeRochas *ListaDeRocha,int Possicao);

void ImprimeArrayDeRochas(ArrayDeRochas *ListaDeRocha);
/////////////
void Inicializador();

void FuncaoE(ListaSondas *ListaDeSondas,ArrayDeRochas ListaDeRocha,int QuantidadeDeRochas);

void gerarTodasCombinacoes(RochaMineral Array[], int TamanhoListaRocha,GerenciadorCompartimento *CompartimentoTemporario);

void gerarCombinacoes(RochaMineral Array[], int Tamanho, int QuantidadeElementos, int Possicao, RochaMineral data[], int i,GerenciadorCompartimento *CompartimentoTemporario);

int PesoCombinacao(RochaMineral Array[],int TamanhoArray);

int ValorCombinacao(RochaMineral Array[],int TamanhoArray);

int ValorCombinacaoComparitmento(GerenciadorCompartimento *Comp);

int QuantidadeCombinacao(RochaMineral Array[],int TamanhoArray);

void RecebeCombinacao(GerenciadorCompartimento *Comp,RochaMineral Array[],int Quantidade);

void ImprimeInformacoes(ListaSondas *comp,RochaMineral Array[],int tamanho);

void RetiraCombinacao(GerenciadorCompartimento *Comp,ArrayDeRochas *ListaDeRocha,int tamanho);

#endif