#ifndef TAD_SONDA_H_
#define TAD_SONDA_H_
#include "Compartimento/TAD_Compartimento.h"

typedef struct{
    int IdentificadorSonda;
    float CapacidadeMaximaSonda;
    GerenciadorCompartimento CompartimentoSonda;
} Sonda;

// Inicializa a Sonda com valores padrões
void InicializarSonda(Sonda* NovaSonda);

// Modifica os valores da sonda
void ModificarValoresSonda(Sonda* NovaSonda, float Capacidade);

#endif