#ifndef TAD_COMPARTIMENTO_H
#define TAD_COMPARTIMENTO_H
#include "Rocha_Mineral/TAD_RochaMineral.h"

typedef struct PreCelulaMineral{
    RochaMineral _RochaMineral;
    struct PreCelulaMineral *Prox;
} Compartimento;

typedef struct {
    Compartimento *PrimeiroRocha;
    Compartimento *UltimoRocha;
} GerenciadorCompartimento;

// Inicializa um Compartimento
void InicializadorCompartimento(GerenciadorCompartimento *Comp);

// Verifica se o compartimento esta vazio
int VerificaSeVazia(GerenciadorCompartimento *comp);

// Imprime as informaçoes do Compartimento
void ImprimeConteudoCompartimento(GerenciadorCompartimento *comp);

// Retorna o peso atual do compartimento
int PesoAtualCompartimento(GerenciadorCompartimento *comp);

// Insere uma rocha em um compartimento
void InserirRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha);

void LimpaCompartimento(GerenciadorCompartimento *comp);

int QuantidadeRochasCompartimento(GerenciadorCompartimento *comp);

#endif