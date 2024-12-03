#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD_Sonda.h"

// Inicializa a Sonda com valores padrões
void InicializarSonda(Sonda* NovaSonda){
    NovaSonda->EstaLigada = 0;
    NovaSonda->CapacidadeMaximaSonda = 0.0;
    NovaSonda->VelocidadeSonda = 0.0;
    NovaSonda->NivelIncialCombustivel = 0.0;
    NovaSonda->IdentificadorSonda = 1 + rand() % 100;
    NovaSonda->LocalizacaoSonda.Latitude = 0.0;
    NovaSonda->LocalizacaoSonda.Longitude = 0.0;
    InicializadorCompartimento(&NovaSonda->CompartimentoSonda);
}

// Modifica os valores da sonda
void ModificarValoresSonda(Sonda* NovaSonda, Localizacao local, float Capacidade, float velocidade, float compustivel){
    NovaSonda->LocalizacaoSonda = local;
    NovaSonda->CapacidadeMaximaSonda = Capacidade;
    NovaSonda->VelocidadeSonda = velocidade;
    NovaSonda->NivelIncialCombustivel = compustivel;
}

//Liga a sonda
void LigarSonda(Sonda* NovaSonda){
    NovaSonda->EstaLigada = 1;
}

//Desliga a sonda
void DesligarSonda(Sonda* NovaSonda){
    NovaSonda->EstaLigada = 0;
    printf("Sonda Desligada\n");
}

//Move a sonda de posição
void MoverSonda(Sonda* NovaSonda, float latitude, float longitude){
    NovaSonda->LocalizacaoSonda.Latitude = latitude;
    NovaSonda->LocalizacaoSonda.Longitude = longitude;
}  