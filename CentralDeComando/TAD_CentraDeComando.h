#ifndef TAD_CENTRAL_DE_COMANDO_H_
#define TAD_CENTRAL_DE_COMANDO_H_

#include "ListaSonda/TAD_ListaSonda.h"

void Inicializador();

void FuncaoE(ListaSondas *ListaDeSonda,RochaMineral ListaDeRochas[],int count);

void gerarTodasCombinacoes(RochaMineral Array[], int TamanhoListaRocha);

void gerarCombinacoes(RochaMineral Array[], int Tamanho, int QuantidadeElementos, int Possicao, RochaMineral data[], int i);



#endif