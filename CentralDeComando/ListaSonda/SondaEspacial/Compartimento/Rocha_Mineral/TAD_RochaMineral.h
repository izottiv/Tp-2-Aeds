#ifndef TAD_ROCHAMINERAL_H
#define TAD_ROCHAMINERAL_H

//Struct dos Dados da Rocha Mineral
typedef struct {
    int Valor;
    int Peso;
} RochaMineral;

//Gets
int GetValor(RochaMineral* Rocha);
int GetPeso(RochaMineral* Rocha);

//Sets
void SetValor(RochaMineral* Rocha, int valor);
void SetPeso(RochaMineral* Rocha, int PESO);

//Seta os valores do struct
void InicializaRochaMineral(RochaMineral* Rocha, int PESO, int valor);  

#endif