typedef struct {
	int codigoLocacao;
	int codigoGuerreiroLocador;
	int codigoDragaoLocado;
	char nomeGuerreiroLocador[30];
	char nomeDragaoLocado[30];
} Locacao;


int retornaTamanhoLocacoes();
int inicializarLocacoes();
int encerraLocacoes();
int salvarLocacao(Locacao c);
int QuantidadeLocacoes();
Locacao obterLocacaoPeloIndice(int codigoLocacao);
Locacao obterLocacaoPeloCodigo(int codigoLocacao);
int ApagarLocacaoPeloCodigo(int codigo);
