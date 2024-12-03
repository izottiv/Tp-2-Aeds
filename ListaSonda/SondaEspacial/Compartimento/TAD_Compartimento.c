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

// Retorna A quantidade de rocha que estao no compartimento
int RetornaTamanho(GerenciadorCompartimento *comp){
    Compartimento *aux;
    int x = 0;
    if (VerificaSeVazia(comp) == 0){ // Conta quantas rochas tem no compartimento e retorna este valor
        aux = comp->PrimeiroRocha->Prox;
        while (aux != NULL){
            x++;
            aux = aux->Prox; 
        }
        return x;
    }
    else{
        return 0;
    }   
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
            printf("Indentificador: %d\n",aux->_RochaMineral.Identificador);
            printf("Peso: %.2f\n",aux->_RochaMineral.Peso);
            printf("Categoria: ");
            TransformarCategoria(&aux->_RochaMineral);
            printf("\n");
            aux = aux->Prox; 
        }
    }
    else{
        printf("Compartimento Vazio\n");
    }
}

// Retorna o peso atual do compartimento
float PesoAtualCompartimento(GerenciadorCompartimento *comp){
    float Peso = 0;
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

// Insere uma rocha em um compartimento
void InserirRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha, float PESOTOTAL){ //Informar o peso total que a sonda espacial suporta
    if(PESOTOTAL >= PesoAtualCompartimento(comp) + Rocha->Peso){//Verifica se o peso máximo está excedido
        if (VerificaSeVazia(comp) == 1){// caso a lista esteja vazia coloca na ultima/primeira posicao da lista
            comp->UltimoRocha->Prox = (Compartimento*) malloc(sizeof(Compartimento));
            comp->UltimoRocha = comp->UltimoRocha->Prox;
            comp->UltimoRocha->_RochaMineral = *Rocha;
            comp->UltimoRocha->Prox = NULL;
        }
        else{// Caso nao esteja vazia procura uma rocha da mesma categoria
            Compartimento *ContadorLista;
            ContadorLista = comp->PrimeiroRocha;
            int repetidos = 0;
            while (ContadorLista->Prox != NULL){    
                if(Rocha->_Categorias == ContadorLista->_RochaMineral._Categorias){ // caso tenha uma rocha da mesma categoria ela subistitui essa rocha pela recebida
                    if (Rocha->Peso < ContadorLista->_RochaMineral.Peso){ // verifica se a rocha e mais leve doq ja esta no compartimento
                        ContadorLista->_RochaMineral = *Rocha;
                    }
                    repetidos = 1;
                }
                ContadorLista = ContadorLista->Prox;
            }
            if(repetidos == 0){// caso a lista nao tenha uma rocha de categoria iqual a recebida coloca a recebida na ultima possicao
                comp->UltimoRocha->Prox = (Compartimento*) malloc(sizeof(Compartimento));
                comp->UltimoRocha = comp->UltimoRocha->Prox;
                comp->UltimoRocha->_RochaMineral = *Rocha;   
                comp->UltimoRocha->Prox = NULL;
            }
        }
    }
}

// Insere uma rocha sem nenhuma limitacao
void InserirRochaMedia(GerenciadorCompartimento *comp, RochaMineral *Rocha){
    if (VerificaSeVazia(comp) == 1){// caso a lista esteja vazia coloca na ultima/primeira posicao da lista
        comp->UltimoRocha->Prox = (Compartimento*) malloc(sizeof(Compartimento));
        comp->UltimoRocha = comp->UltimoRocha->Prox;
        comp->UltimoRocha->_RochaMineral = *Rocha;
        comp->UltimoRocha->Prox = NULL;
    }
    else{// Caso nao esteja vazia procura uma rocha da mesma categoria
        Compartimento *ContadorLista;
        ContadorLista = comp->PrimeiroRocha;
        int repetidos = 0;
        while (ContadorLista->Prox != NULL){    
            if(Rocha->_Categorias == ContadorLista->_RochaMineral._Categorias){ // caso tenha uma rocha da mesma categoria ela subistitui essa rocha pela recebida
                if (Rocha->Peso < ContadorLista->_RochaMineral.Peso){ // verifica se a rocha e mais leve doq ja esta no compartimento
                    ContadorLista->_RochaMineral = *Rocha;
                }
                repetidos = 1;
            }
            ContadorLista = ContadorLista->Prox;
        }
        if(repetidos == 0){// caso a lista nao tenha uma rocha de categoria iqual a recebida coloca a recebida na ultima possicao
            comp->UltimoRocha->Prox = (Compartimento*) malloc(sizeof(Compartimento));
            comp->UltimoRocha = comp->UltimoRocha->Prox;
            comp->UltimoRocha->_RochaMineral = *Rocha;   
            comp->UltimoRocha->Prox = NULL;
        }
    }
}

// Retorna valores que simbolizam alguns caso de entrada
int VerificasePodeInserirRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha, float PESO, int Categoria){ // Esse Peso pode ser o peso maximo da sonda ou uma media 
    Compartimento *contadorlista;
    int contador;
    switch(Categoria){
        case 0: // caso vc queira ver se um o compartimento aceita a rocha
            if(VerificaSeVazia(comp) == 1){// Caso o compartimento esteja vazio pode inserir Caso 1
                //printf("Compartimento Vazio\n");
                return 1;
            }
            if(PesoAtualCompartimento(comp) + Rocha->Peso <= PESO){// Pecore o vetor em busca da mesma categoria
                contadorlista = comp->PrimeiroRocha->Prox;
                int aux = 0;
                while (contadorlista != NULL){
                    if (Rocha->_Categorias == contadorlista->_RochaMineral._Categorias){// caso tenha a mesma categoria da rocha inserida verifica outras coisas
                        if (Rocha->Peso < contadorlista->_RochaMineral.Peso){// caso o peso da rocha que esta fora da sonda seja menor que a que ja esta na sonda ela sera substituida Caso 2
                            //printf("Pedra da mesma categoria mas leve\n");
                            return 2;
                        }
                        else{
                            //printf("Rocha da mesma categoria mas é mais pesada\n");
                            aux = 0;
                        }
                        
                    }
                    else{// caso a rocha nao seja da mesma categoria aux = 1 e continua a pecorer o vetor ate acabar ou achar uma rocha do mesmo tipo
                        aux = 1;
                    }
                    contadorlista = contadorlista->Prox;
                }
                if (aux == 1){// caso nao tenha nenhuma categoria repitida Caso 1 pode ser inseirda na ultima possicao da lista
                    //printf("Nao vazio mas inserida no final\n");
                    return 1;
                }
            }
            else{// caso o peso execeda o limete informado Caso 0 Nao pode inserir
                //printf("Peso exedido\n");
                return 0;
            }
            break;
        case 1:// caso vc queira quantos compari
            if(VerificaSeVazia(comp) == 1){// Caso o compartimento esteja vazio pode inserir Caso 1
                return 1;
            }
            if(PesoAtualCompartimento(comp) + Rocha->Peso <= PESO){// Pecore o vetor em busca da mesma categoria
                contadorlista = comp->PrimeiroRocha->Prox;
                int aux = 0;
                while (contadorlista != NULL){
                    if (Rocha->_Categorias == contadorlista->_RochaMineral._Categorias){// caso tenha a mesma categoria da rocha inserida verifica outras coisas
                        if (Rocha->Peso < contadorlista->_RochaMineral.Peso){// caso o peso da rocha que esta fora da sonda seja menor que a que ja esta na sonda ela sera substituida Caso 2
                            return 1;
                        }
                        else{
                            //printf("Rocha da mesma categoria mas é mais pesada\n");
                            aux = 0;
                        }
                    }
                    else{// caso a rocha nao seja da mesma categoria aux = 1 e continua a pecorer o vetor ate acabar ou achar uma rocha do mesmo tipo
                        aux = 1;
                    }
                    contadorlista = contadorlista->Prox;
                }
                if (aux == 1){// caso nao tenha nenhuma categoria repitida Caso 1 pode ser inseirda na ultima possicao da lista
                    return 1;
                }
            }
            else{// caso o peso execeda o limete informado Caso 0 Nao pode inserir
                return 0;
            }
            break;
    }
}

// Troca uma rocha por outra no compartimento 
void TrocaRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha){
    RochaMineral RochaAux;
    RochaAux.Peso = 0;
    int pos = 1;
    int posrocha;
    Compartimento *auxcomp;
    auxcomp = comp->PrimeiroRocha->Prox;
    while (auxcomp->Prox != NULL){ // Procura a rocha mais pesada e da mesma categoria, depois guarda a posição
        if(RochaAux.Peso < auxcomp->_RochaMineral.Peso && Rocha->_Categorias == auxcomp->_RochaMineral._Categorias){
            RochaAux.Peso = auxcomp->_RochaMineral.Peso;
            posrocha = pos;
        }
        pos++;
        auxcomp = auxcomp->Prox; 
    }
    pos = 1;
    auxcomp = comp->PrimeiroRocha->Prox;
    while (auxcomp->Prox != NULL){ // Procura a posição da mais pesada, e é substituida pela rocha inserida
        if (pos == posrocha){
            auxcomp->_RochaMineral.Identificador = Rocha->Identificador;
            auxcomp->_RochaMineral.Peso = Rocha->Peso;
            auxcomp->_RochaMineral._ListaMineral = Rocha->_ListaMineral;
            auxcomp->_RochaMineral._Localizacao= Rocha->_Localizacao;
            auxcomp->_RochaMineral._DataColeta = Rocha->_DataColeta;
        }
        pos++;
        auxcomp = auxcomp->Prox;
    }
}

// Remove uma rocha de uma categoria e retorna a mesma para ser usada
void RemoverRochaPorCategoria(GerenciadorCompartimento*comp, RochaMineral *RochaRetirada, Categorias Categoria){
    Compartimento *aux, *AuxCont,*AuxContAnterior;
    if (VerificaSeVazia(comp) == 1){
        printf("LISTA VAZIA\n");
        return;
    }
    int possicaosecundaria;
    int pos = 1;
    int cancel = 0;
    AuxContAnterior = comp->PrimeiroRocha;
    AuxCont = comp->PrimeiroRocha->Prox;
    while (AuxCont != NULL){  // Procura a primeira rocha que tem a mesma categoria dada, tira ela da lista e aloca ela em RochaRetirada
        if (AuxCont->_RochaMineral._Categorias == Categoria){
            *RochaRetirada = AuxCont->_RochaMineral;    
            if(pos == 1){ // No caso do primeiro elemento da lista ser da mesma categoria
                aux = comp->PrimeiroRocha;
                comp->PrimeiroRocha = comp->PrimeiroRocha->Prox;
                free(aux);
                break;
            }
            if(pos == RetornaTamanho(comp)){   // No caso do ultimo elemento da lista ser da mesma categoria
                    aux = AuxContAnterior->Prox;
                    AuxContAnterior->Prox = NULL;
                    free(aux);
                break;
            }
            if(pos < RetornaTamanho(comp) && pos > 1){ // Se o elemento da lista que for da mesma categoria estiver no meio
                aux = AuxCont;
                AuxContAnterior->Prox = AuxCont->Prox;
                free(aux); 
                break;
            }
        }
    pos++;
    AuxContAnterior = AuxContAnterior->Prox;
    AuxCont = AuxCont->Prox;
    }
}

// Retorna quantas rocha tem em um compartimento 
int QuantasRochasEmCompartimento(GerenciadorCompartimento *comp){
    Compartimento *AuxCont;
    int QuantidadeRocha = 0;
    AuxCont = comp->PrimeiroRocha->Prox;
    while (AuxCont != NULL){
        QuantidadeRocha++;
        AuxCont = AuxCont->Prox;
    }
    return QuantidadeRocha;
}

// Imprime as categorias e pesos de um compartimento
void ImprimeCategoriaPeso(GerenciadorCompartimento* comp){
    Compartimento *aux;   
    aux = comp->PrimeiroRocha->Prox;
    while(aux != NULL){
        printf("-");
        TransformarCategoria(&aux->_RochaMineral);
        printf(" %.1f\n", aux->_RochaMineral.Peso);
        aux = aux->Prox; 
    }
}