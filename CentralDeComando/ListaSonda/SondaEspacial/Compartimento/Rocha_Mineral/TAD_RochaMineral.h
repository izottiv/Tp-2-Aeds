#ifndef TAD_ROCHAMINERAL_H
#define TAD_ROCHAMINERAL_H
#define TAMMAX 1000

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

typedef struct {
    RochaMineral ArrayDeRochas[TAMMAX];
    int Primeiro;
    int UltimoLivre;
}ArrayDeRochas;


void CriarArrayDeRochas(ArrayDeRochas *ArrayDeRocha);

int VereficaSeArrayVazio(ArrayDeRochas *ListaDeRocha);

int InsereRochaNoArray(ArrayDeRochas *ListaDeRocha,RochaMineral Rocha);

int RetiraRochaNoArray(ArrayDeRochas *ListaDeRocha,int Possicao);

void ImprimeArrayDeRochas(ArrayDeRochas *ListaDeRocha);

#endif