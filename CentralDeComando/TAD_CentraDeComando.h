#ifndef TAD_CENTRAL_DE_COMANDO_H_
#define TAD_CENTRAL_DE_COMANDO_H_

#include "ListaSonda/TAD_ListaSonda.h"

void Inicializador();

void FuncaoE(ListaSondas *ListaDeSonda,RochaMineral ListaDeRochas[],int count);

void gerarTodasCombinacoes(RochaMineral Array[], int TamanhoListaRocha,GerenciadorCompartimento *CompartimentoTemporario);

void gerarCombinacoes(RochaMineral Array[], int Tamanho, int QuantidadeElementos, int Possicao, RochaMineral data[], int i,GerenciadorCompartimento *CompartimentoTemporario);

int PesoCombinacao(RochaMineral Array[],int TamanhoArray);

int ValorCombinacao(RochaMineral Array[],int TamanhoArray);

int ValorCombinacaoComparitmento(GerenciadorCompartimento *Comp);

int QuantidadeCombinacao(RochaMineral Array[],int TamanhoArray);

void RecebeCombinacao(GerenciadorCompartimento *Comp,RochaMineral Array[],int Quantidade);

void ImprimeInformacoes(ListaSondas *comp,RochaMineral Array[],int tamanho);

void RetiraCombinacao(GerenciadorCompartimento *Comp,RochaMineral *Array[],int *tamanho);

void RetiraRocha(RochaMineral *Array[],int Possicao,int tamanho);

#endif