buildas: Main.c ListaSonda/TAD_ListaSonda.c ListaSonda/SondaEspacial/TAD_Sonda.c ListaSonda/SondaEspacial/Compartimento/TAD_Compartimento.c ListaSonda/SondaEspacial/Compartimento/Rocha_Mineral/TAD_RochaMineral.c
	gcc Main.c ListaSonda/TAD_ListaSonda.c ListaSonda/SondaEspacial/TAD_Sonda.c ListaSonda/SondaEspacial/Compartimento/TAD_Compartimento.c ListaSonda/SondaEspacial/Compartimento/Rocha_Mineral/TAD_RochaMineral.c -o Programa && .\Programa.exe