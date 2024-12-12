#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "TAD_CentraDeComando.h"

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

//Inicaliza o progama
void Inicializador(){
    // Cria as 3 sondas
    ListaSondas Espaconaves; 
    InicializaListaSondas(&Espaconaves);
    for (int i = 0; i < 3; i++){
        Sonda Venus;
        InicializarSonda(&Venus);
        InserirListaSondas(&Espaconaves,&Venus);
    }
    printf("Sondas Criadas\n");
    printf("\n");

    //Recebe as N rochas e as insere em um vetor de rochas
    int count;
    printf("Digite quantas Rochas: ");
    scanf("%d",&count);
    ArrayDeRochas VetorDeRochas;
    CriarArrayDeRochas(&VetorDeRochas);
    int Peso,Valor;
    printf("Digite o peso e o valor das rochas:\n");
    for (int i = 0; i < count; i++){
        printf("%d - ",i);
        RochaMineral RochaInserida;
        scanf("%d %d",&Peso,&Valor);
        InicializaRochaMineral(&RochaInserida,Peso,Valor);
        InsereRochaNoArray(&VetorDeRochas,RochaInserida);
    }
    printf("\n");

    //Funcao E e depois Imprime os resultados
    clock_t Ticks[2];
    Ticks[0] = clock();
    FuncaoE(&Espaconaves,VetorDeRochas,VetorDeRochas.UltimoLivre);
    ImprimeInformacoes(&Espaconaves,VetorDeRochas.ArrayDeRochas,VetorDeRochas.UltimoLivre);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1.0000 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g segundos", Tempo);
}

void FuncaoE(ListaSondas *ListaDeSondas,ArrayDeRochas ListaDeRocha,int UltimaPosicao){
    CelulaSonda *Aux;
    Aux = ListaDeSondas->Primeiro->prox;
    //Percore a lista de sondas procurando a melhor combinacao e quardando essa combincao 
    while (Aux != NULL){
        gerarTodasCombinacoes(ListaDeRocha.ArrayDeRochas,UltimaPosicao,&Aux->sonda.CompartimentoSonda);
        RetiraCombinacao(&Aux->sonda.CompartimentoSonda,&ListaDeRocha);        
        Aux = Aux->prox;
    }
}

void gerarCombinacoes(RochaMineral Array[], int Tamanho, int QuantidadeElementos, int Possicao, RochaMineral data[], int i,GerenciadorCompartimento *CompartimentoTemporario) {
    if (Possicao == QuantidadeElementos) {
        //printf("Peso da combinacao %d Valor da combincao %d Quantidade de rochas %d\n",PesoCombinacao(data,QuantidadeElementos),ValorCombinacao(data,QuantidadeElementos),QuantidadeCombinacao(data,QuantidadeElementos));       
        if (PesoCombinacao(data,QuantidadeElementos) <=40){//SO É INSERIDA SE O PESO DE UMA COMBINACAO É MENOR QUE 40
            if (ValorCombinacaoComparitmento(CompartimentoTemporario) < ValorCombinacao(data,QuantidadeElementos)){// É TROCADA SE O VALOR DA COMBINACAO É MAIOR DO QUE A QUE ESTA GUARDADA NO COMPARTIMENTO DA SONDA
                LimpaCompartimento(CompartimentoTemporario);
                RecebeCombinacao(CompartimentoTemporario,data,QuantidadeElementos);
            }
            else if (ValorCombinacaoComparitmento(CompartimentoTemporario) == ValorCombinacao(data,QuantidadeElementos)){// CASO O VALORES SEJAM IQUAIS VERIFICA QUAL É A MAIS LEVE
                if (PesoAtualCompartimento(CompartimentoTemporario) > PesoCombinacao(data,QuantidadeElementos)){// CASO A COMBINACAO TENHA UM PESO MENOR
                    LimpaCompartimento(CompartimentoTemporario);
                    RecebeCombinacao(CompartimentoTemporario,data,QuantidadeElementos);
                }
                else if(PesoAtualCompartimento(CompartimentoTemporario) == PesoCombinacao(data,QuantidadeElementos)){// CASO OS PESOS DO COMPARTIMENTO E DA COMBINCAO SEJA IQUAIS OLHA A QUANTIDADE DE ROCHAS
                    if (QuantidadeRochasCompartimento(CompartimentoTemporario) >= QuantidadeCombinacao(data,QuantidadeElementos)){// CASO A COMBINCAO TENHA MENOS ROCHAS DO QUE A DO COMPARTIMENTO
                        LimpaCompartimento(CompartimentoTemporario);
                        RecebeCombinacao(CompartimentoTemporario,data,QuantidadeElementos);
                    }
                }
            }
        }
        return;
    }
 
    if (i >= Tamanho) {
        return;
    }

    data[Possicao] = Array[i];
    gerarCombinacoes(Array, Tamanho, QuantidadeElementos, Possicao + 1, data, i + 1,CompartimentoTemporario);

    gerarCombinacoes(Array, Tamanho, QuantidadeElementos, Possicao, data, i + 1,CompartimentoTemporario);
}

void gerarTodasCombinacoes(RochaMineral arr[], int n,GerenciadorCompartimento *CompartimentoTemporario){
    for (int r = 1; r <= n; r++) {
        RochaMineral data[r]; 
        gerarCombinacoes(arr, n, r, 0, data, 0,CompartimentoTemporario);
    }
}

int PesoCombinacao(RochaMineral Array[],int TamanhoArray){
    int Peso = 0;
    for (int i = 0; i < TamanhoArray; i++){
        Peso += Array[i].Peso;
    }
    return Peso;
}

int ValorCombinacao(RochaMineral Array[],int TamanhoArray){
    int Valor = 0;
    for (int i = 0; i < TamanhoArray; i++){
        Valor += Array[i].Valor;
    }
    return Valor;
}

int QuantidadeCombinacao(RochaMineral Array[],int TamanhoArray){
    int Quantidade = 0;
    for (int i = 0; i < TamanhoArray; i++){
        Quantidade ++;
    }
    return Quantidade;   
}

void RecebeCombinacao(GerenciadorCompartimento *Comp,RochaMineral Array[],int Quantidade){
    for (int i = 0; i < Quantidade; i++){
        InserirRocha(Comp,&Array[i]);
    }
}

int ValorCombinacaoComparitmento(GerenciadorCompartimento *Comp){
    Compartimento* Aux;
    int Valor = 0;
    Aux = Comp->PrimeiroRocha->Prox;
    while (Aux != NULL){
        Valor += Aux->_RochaMineral.Valor;
        Aux =Aux->Prox;
    }
    return Valor;
}

void ImprimeInformacoes(ListaSondas *comp,RochaMineral Array[],int tamanho){
    CelulaSonda *Aux;
    Aux = comp->Primeiro->prox;
    int i = 1;
    while (Aux != NULL){
        Compartimento *CompAux;
        CompAux = Aux->sonda.CompartimentoSonda.PrimeiroRocha->Prox;
        printf("Sonda %d: Peso %d, Valor %d, Solucao ",i,PesoAtualCompartimento(&Aux->sonda.CompartimentoSonda),ValorCombinacaoComparitmento(&Aux->sonda.CompartimentoSonda));
        printf("[");
        while (CompAux != NULL){    
            for (int i = 0; i < QuantidadeCombinacao(Array,tamanho); i++){
                if (CompAux->_RochaMineral.Peso == Array[i].Peso && CompAux->_RochaMineral.Valor == Array[i].Valor){
                    printf("%d",i);
                    if (i != QuantidadeCombinacao(Array,tamanho-1)){
                        printf(", ");
                    }      
                }  
            }
            CompAux = CompAux->Prox;    
        }
        printf("]\n");
        i ++;
        Aux = Aux->prox;
    }
}

void RetiraCombinacao(GerenciadorCompartimento *Comp,ArrayDeRochas *ListaDeRocha){
    Compartimento *CompAux;
    CompAux = Comp->PrimeiroRocha->Prox;
    while (CompAux != NULL){
        for (int i = 0; i < ListaDeRocha->UltimoLivre; i++){
            if (CompAux->_RochaMineral.Peso == ListaDeRocha->ArrayDeRochas[i].Peso && CompAux->_RochaMineral.Valor == ListaDeRocha->ArrayDeRochas[i].Valor){
                RetiraRochaNoArray(ListaDeRocha,i);
            }
        }   
        CompAux = CompAux->Prox;
    }
}
