#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "TAD_CentraDeComando.h"

void Inicializador(){
    ListaSondas Espaconaves; 
    InicializaListaSondas(&Espaconaves);
    for (int i = 0; i < 3; i++){
        Sonda Venus;
        InicializarSonda(&Venus);
        InserirListaSondas(&Espaconaves,&Venus);
    }
    printf("Sondas Criadas\n");
    printf("\n");

    int count;
    printf("Digite quantas Rochas: ");
    scanf("%d",&count);
    RochaMineral ListaDeRocha[count];
    int Peso,Valor;
    for (int i = 0; i < count; i++){
        RochaMineral RochaInserida;
        printf("Digite o peso e o valor da rocha: ");
        scanf("%d %d",&Peso,&Valor);
        InicializaRochaMineral(&RochaInserida,Peso,Valor);
        ListaDeRocha[i] =  RochaInserida;
    }
    printf("\n");
    
    FuncaoE(&Espaconaves,ListaDeRocha,count);   
    ImprimeInformacoes(&Espaconaves);
}

void FuncaoE(ListaSondas *ListaDeSondas,RochaMineral ListaDeRochas[],int count){
    CelulaSonda *Aux;
    Aux = ListaDeSondas->Primeiro->prox;
    int RochasRetiradas = QuantidadeCombinacao(ListaDeRochas,count);

    for (int i = 0; i < 3; i++){
        if (RochasRetiradas > 0){    
            RecebeCombinacao(&Aux->sonda.CompartimentoSonda,&ListaDeRochas[0],count);     
            gerarTodasCombinacoes(ListaDeRochas,count,&ListaDeSondas->Primeiro->prox->sonda.CompartimentoSonda);
            printf("Quantidade Rochas no array %d\n",QuantidadeCombinacao(ListaDeRochas,count));
            RetiraCombinacao(&Aux->sonda.CompartimentoSonda,&ListaDeRochas,count);
            RochasRetiradas -= QuantidadeRochasCompartimento(&Aux->sonda.CompartimentoSonda);
            Aux = Aux->prox;
        }
        else{
            printf("Sem Rocha pra colocar\n");
        }
    }
}

void gerarCombinacoes(RochaMineral Array[], int Tamanho, int QuantidadeElementos, int Possicao, RochaMineral data[], int i,GerenciadorCompartimento *CompartimentoTemporario) {
    if (Possicao == QuantidadeElementos) {
        //printf("Peso da combinacao %d Valor da combincao %d Quantidade de rochas %d\n",PesoCombinacao(data,QuantidadeElementos),ValorCombinacao(data,QuantidadeElementos),QuantidadeCombinacao(data,QuantidadeElementos));       
        if (PesoCombinacao(data,QuantidadeElementos) <=40){
            if (ValorCombinacaoComparitmento(CompartimentoTemporario) < ValorCombinacao(Array,QuantidadeElementos));{
                LimpaCompartimento(CompartimentoTemporario);
                RecebeCombinacao(CompartimentoTemporario,Array,QuantidadeElementos);
            }
        }
       
        // for (int j = 0; j < QuantidadeElementos; j++) {
        //     printf("%d",data[j]);
        // }

        return;
    }

    if (i >= Tamanho) {
        return;
    }

    data[Possicao] = Array[i];
    gerarCombinacoes(Array, Tamanho, QuantidadeElementos, Possicao + 1, data, i + 1,CompartimentoTemporario);

    gerarCombinacoes(Array, Tamanho, QuantidadeElementos, Possicao, data, i + 1,CompartimentoTemporario);
}

void gerarTodasCombinacoes(RochaMineral arr[], int n,GerenciadorCompartimento *CompartimentoTemporario) {
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

void ImprimeInformacoes(ListaSondas *comp){
    CelulaSonda *Aux;
    Aux = comp->Primeiro->prox;
    int i = 1;
    while (Aux != NULL){
        printf("Sonda %d: Peso %d, Valor %d\n",i,PesoAtualCompartimento(&Aux->sonda.CompartimentoSonda),ValorCombinacaoComparitmento(&Aux->sonda.CompartimentoSonda));
        i ++;
        Aux = Aux->prox;
    }
}

void RetiraCombinacao(GerenciadorCompartimento *Comp,RochaMineral *Array[],int tamanho){
    Compartimento *Aux;
    Aux = Comp->PrimeiroRocha->Prox;
    printf("tese1\n");
    while (Aux != NULL){
        for (int i = 0; i < tamanho; i++){
            if (Aux->_RochaMineral.Peso == Array[i]->Peso && Aux->_RochaMineral.Valor == Array[i]->Valor){
                RetiraRocha(Array,i,&tamanho);
            }
        }
        Aux = Aux->Prox;
    }   
}

void RetiraRocha(RochaMineral *Array[],int Possicao,int *tamanho){
    int tamanhoaux = *tamanho;
    printf("tese2\n");
    if(Possicao == tamanhoaux - 1){
        *tamanho --;
    }
    else{
        printf("tese3\n");
        for (int i = 0; i < tamanhoaux; i++){
            if (i >= Possicao && i < tamanhoaux - 1){    
                Array[i] = Array[i+1];
            }
        }
    }
}
