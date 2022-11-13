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
		return 0;
	}
	
    for (i = 0; i < ARRSIZELOCACAO; i++)
    {   	
        locacao[i].codigoLocacao = 0;
        locacao[i].codigoGuerreiroLocador = 0;
        locacao[i].codigoDragaoLocado = 0;
        locacao[i].quantidadeLocada = 0;
    }

}

int retornaTamanhoLocacoes()
{
	return ARRSIZELOCACAO;
}

int encerraLocacoes()
{}

int salvarLocacao(Locacao location, int codDrag, int codGuerr, int qtd)
{
    int i; 

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
        for (i = 0; i < QuantidadeGuerreiros(); i++)
        {
            Guerreiro* warrior = obterGuerreiroPeloIndice(i);
            if (codGuerr == warrior->codigo)
            {
                strcpy(locacao[qtdLocacao].nomeGuerreiroLocador, warrior->nome);
                // warrior->checarLocacao = 1;
                // registrarMudancaGuerr(warrior->checarLocacao, warrior->codigo);
                break;
            }
        }

        for (i = 0; i < QuantidadeDragoes(); i++)
        {
            Dragao* dragon = obterDragaoPeloIndice(i);
            if (codDrag == dragon->codigo)
            {
                if(qtd > dragon->unidade || qtd < 0)
                {
                    return 2;
                }
                dragon->unidade = dragon->unidade - qtd;
                strcpy(locacao[qtdLocacao].nomeDragaoLocado, dragon->nome);
                registrarMudancaDrag(dragon->unidade, dragon->codigo);
                locacao[qtdLocacao].valorDiario = dragon->valor * qtd;
                locacao[qtdLocacao].codigoLocacao = qtdLocacao + 1;
                locacao[qtdLocacao].quantidadeLocada = qtd;
                qtdLocacao++;
                return 1;
                break;
            }
        }
	}else    
    	return 0;
}

int QuantidadeLocacoes()
{
    return qtdLocacao;
}

Locacao* obterLocacaoPeloIndice(int indice)
{
    Locacao* location = (Locacao*) malloc (sizeof(Locacao));
	*location = locacao[indice];
	return location;
}

Locacao* obterLocacaoPeloCodigo(int codigo)
{

}


int ApagarLocacaoPeloCodigo(int codigo)
{
    int porcentagemArrays = ARRSIZELOCACAO * 0.4;

    for(i = 0; i < qtdLocacao; i++)
    {
    	Dragao* dragao = obterDragaoPeloIndice(i);
        if (locacao[i].codigoLocacao == codigo)
        {
            locacao[i] = locacao[qtdLocacao-1];
            locacao[qtdLocacao - 1].codigoLocacao = 0;
            int b;
            qtdLocacao--;
            return 1;
        }
    }
    return 0;
}
