#include "TAD_RochaMineral.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Gets
int GetValor(RochaMineral* Rocha){
    return Rocha->Valor;
}
int GetPeso(RochaMineral* Rocha){
    return Rocha->Peso;
}

//Sets
void SetValor(RochaMineral* Rocha, int valor){
    Rocha->Valor = valor;
}
void SetPeso(RochaMineral* Rocha, int PESO){
    Rocha->Peso = PESO;
}

//Seta os valores do struct
void InicializaRochaMineral(RochaMineral* Rocha, int PESO, int valor){
    SetValor(Rocha, valor);
    SetPeso(Rocha, PESO);
}
