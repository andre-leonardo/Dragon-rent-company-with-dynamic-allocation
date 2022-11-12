#include "locacoes.h"
#include "guerreiros.h"
#include "dragoes.h"
#include <stdlib.h>
#include <string.h>


int ARRSIZELOCACAO =  5;

Locacao* locacao = NULL;
int i, qtdLocacao = 0;


int inicializarLocacoes()
{
	locacao = (Locacao*) malloc (ARRSIZELOCACAO * sizeof(Locacao));
    if (locacao == NULL)
	{
        printf("Erro de alocacao dinamica");
		return 0;
	}
	
    for (i = 0; i < ARRSIZELOCACAO; i++)
    {   	
        locacao[i].codigoLocacao = 0;
        locacao[i].codigoGuerreiroLocador = 0;
        locacao[i].codigoDragaoLocado = 0;
    }

}

int retornaTamanhoLocacoes()
{
	return ARRSIZELOCACAO;
}

int encerraLocacoes()
{}

int salvarLocacao(Locacao location)
{
    if (locacao != NULL)
    {
    	if (qtdLocacao == ARRSIZELOCACAO)
    	{
    		Locacao* locacaoBKP = locacao;
    		locacao = realloc (locacao, (qtdLocacao * 2)  * sizeof(Locacao));
    		if (locacao != NULL)
    		{
    			ARRSIZELOCACAO = ARRSIZELOCACAO *  2;
			}
			else {
				locacao = locacaoBKP;
				return 0;
			}
		}
        locacao[qtdLocacao] = location;
        qtdLocacao++;
        return 1;
	}else    
    	return 0;
}

int QuantidadeLocacoes()
{
    return qtdLocacao;
}

Locacao obterLocacaoPeloIndice(int indice)
{
    return locacao[indice];
}

Locacao obterLocacaoPeloCodigo(int codigo)
{

}


int ApagarLocacaoPeloCodigo(int codigo)
{
    for(i = 0; i < qtdLocacao; i++)
    {
    	Dragao* dragao = obterDragaoPeloIndice(i);
        if (locacao[i].codigoLocacao == codigo)
        {
            locacao[i] = locacao[qtdLocacao-1];
            locacao[qtdLocacao - 1].codigoLocacao = 0;
            int b;
            for (b = 0; b < 8; b++)
            {
            	if (dragao->unidadeAnterior[b] != 0)
            	{
            		dragao->unidade = dragao->unidadeAnterior[b];
            		break;
				}	
			}
            qtdLocacao--;
            return 1;
        }
    }
    return 0;
}
