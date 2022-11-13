typedef struct {
	int codigo;
	char nome[30];
	char reino[30];
	char titulo[30];
} Guerreiro;


int inicializarGuerreiros();
int encerraGuerreiros();
int salvarGuerreiro(Guerreiro c);
int QuantidadeGuerreiros();
Guerreiro* obterGuerreiroPeloIndice(int indice);
Guerreiro* obterGuerreiroPeloCodigo(int codigo);
Guerreiro* obterGuerreiroPeloNome (char* nome);
int ApagarGuerreiroPeloCodigo(int codigo);
int atualizarGuerreiro(char* mudanca, int m,int opcao,int codigo);

//int registrarMudancaGuerr(int loc, int cod);
