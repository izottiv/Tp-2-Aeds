#include <stdio.h>
#include <stdlib.h>
#include "TAD_ListaSonda.h"

//Inicializa a lista de Sondas
void InicializaListaSondas(ListaSondas* lista){
    lista->Primeiro = (CelulaSonda*)malloc(sizeof(CelulaSonda));
    lista->Ultimo = lista->Primeiro;
    lista->Primeiro->prox = NULL;
}

//Insere uma sonda na lista
void InserirListaSondas(ListaSondas* lista, Sonda* sonda){
    lista->Ultimo->prox = (CelulaSonda*)malloc(sizeof(CelulaSonda));
    lista->Ultimo = lista->Ultimo->prox;
    lista->Ultimo->sonda = *sonda;
    lista->Ultimo->prox = NULL;
}

//Remove uma sonda da lista com base no identificador
void RemoverListaSondas(ListaSondas* lista, int identificador, Sonda* Sondaremovida){
    if(lista->Primeiro != lista->Ultimo){//verifica se é vazia
    CelulaSonda* aux = lista->Primeiro;
    CelulaSonda* Remover = NULL;
    while (aux && aux->prox && aux->prox->sonda.IdentificadorSonda != identificador)
    {
        aux = aux->prox; 
    }
    if(aux && aux->prox){
        Remover = aux->prox;
        aux->prox =Remover->prox;
        *Sondaremovida = Remover->sonda;
    }
    if(Remover){
        free(Remover);
    }
    }
    
}

//Imprime a lista de Sondas
void ImprimirListaSondas(ListaSondas* lista){
    CelulaSonda* aux;
    aux = lista->Primeiro->prox;
    while(aux){
        printf("Identificador: %d\n", aux->sonda.IdentificadorSonda);
        printf("Capacidade Maxima: %.2f\n", aux->sonda.CapacidadeMaximaSonda);
        ImprimeConteudoCompartimento(&(aux->sonda.CompartimentoSonda));
        aux = aux->prox;
        printf("\n");
    }
}