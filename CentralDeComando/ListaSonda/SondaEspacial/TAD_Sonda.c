#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD_Sonda.h"

// Inicializa a Sonda com valores padrões
void InicializarSonda(Sonda* NovaSonda){
    NovaSonda->CapacidadeMaximaSonda = 40;
    NovaSonda->IdentificadorSonda = 1 + rand() % 100;
    InicializadorCompartimento(&NovaSonda->CompartimentoSonda);
}

// Modifica os valores da sonda
void ModificarValoresSonda(Sonda* NovaSonda, float Capacidade){
    NovaSonda->CapacidadeMaximaSonda = Capacidade;
}