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
    ImprimeInformacoes(&Espaconaves,ListaDeRocha,count);
}

void FuncaoE(ListaSondas *ListaDeSondas,RochaMineral ListaDeRochas[],int count){
    CelulaSonda *Aux;
    Aux = ListaDeSondas->Primeiro->prox;
    int RochasRetiradas = QuantidadeCombinacao(ListaDeRochas,count);

    while (Aux != NULL){    
        if (RochasRetiradas > 0){    
            RecebeCombinacao(&Aux->sonda.CompartimentoSonda,&ListaDeRochas[count - 1],count);     
            gerarTodasCombinacoes(ListaDeRochas,count,&ListaDeSondas->Primeiro->prox->sonda.CompartimentoSonda);
            RetiraCombinacao(&Aux->sonda.CompartimentoSonda,&ListaDeRochas,count);
            printf("Quantidade Rochas no array %d\n",QuantidadeCombinacao(ListaDeRochas,count));
            RochasRetiradas -= QuantidadeRochasCompartimento(&Aux->sonda.CompartimentoSonda);
        }
        else{
            printf("Sem Rocha pra colocar\n");
        }
        Aux = Aux->prox;
    }
}

void gerarCombinacoes(RochaMineral Array[], int Tamanho, int QuantidadeElementos, int Possicao, RochaMineral data[], int i,GerenciadorCompartimento *CompartimentoTemporario) {
    if (Possicao == QuantidadeElementos) {
        //printf("Peso da combinacao %d Valor da combincao %d Quantidade de rochas %d\n",PesoCombinacao(data,QuantidadeElementos),ValorCombinacao(data,QuantidadeElementos),QuantidadeCombinacao(data,QuantidadeElementos));       
        if (PesoCombinacao(data,QuantidadeElementos) <=40){//SO É INSERIDA SE O PESO DE UMA COMBINACAO É MENOR QUE 40
            if (ValorCombinacaoComparitmento(CompartimentoTemporario) < ValorCombinacao(data,QuantidadeElementos)){// É TROCADA SE O VALOR DA COMBINACAO É MAIOR DO QUE A QUE ESTA GUARDADA NO COMPARTIMENTO DA SONDA
                printf("teste Valor\n");               
                LimpaCompartimento(CompartimentoTemporario);
                RecebeCombinacao(CompartimentoTemporario,data,QuantidadeElementos);
            }
            else if (ValorCombinacaoComparitmento(CompartimentoTemporario) == ValorCombinacao(data,QuantidadeElementos)){// CASO O VALORES SEJAM IQUAIS VERIFICA QUAL É A MAIS LEVE
                if (PesoAtualCompartimento(CompartimentoTemporario) > PesoCombinacao(data,QuantidadeElementos)){// CASO A COMBINACAO TENHA UM PESO MENOR
                    printf("teste Peso\n");
                    LimpaCompartimento(CompartimentoTemporario);
                    RecebeCombinacao(CompartimentoTemporario,data,QuantidadeElementos);
                }
                else if(PesoAtualCompartimento(CompartimentoTemporario) == PesoCombinacao(data,QuantidadeElementos)){// CASO OS PESOS DO COMPARTIMENTO E DA COMBINCAO SEJA IQUAIS OLHA A QUANTIDADE DE ROCHAS
                    printf("Teste Quantidade\n");
                    if (QuantidadeRochasCompartimento(CompartimentoTemporario) >= QuantidadeCombinacao(data,QuantidadeElementos)){// CASO A COMBINCAO TENHA MENOS ROCHAS DO QUE A DO COMPARTIMENTO
                        LimpaCompartimento(CompartimentoTemporario);
                        RecebeCombinacao(CompartimentoTemporario,data,QuantidadeElementos);
                    }
                }
            }
        }
        else{
            printf("Peso maior que 40\n");
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
                    printf(" %d,",i);       
                }  
            }
            CompAux = CompAux->Prox;    
        }
        printf(" ]\n");
        i ++;
        Aux = Aux->prox;
    }
}

void RetiraCombinacao(GerenciadorCompartimento *Comp,RochaMineral *Array[],int *tamanho){



}

void RetiraRocha(RochaMineral *Array[],int Possicao,int tamanho){


}
