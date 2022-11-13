#include "locacoes.h"
#include "guerreiros.h"
#include "dragoes.h"
#include <stdlib.h>
#include <string.h>



// char* time()
// {
//     struct tm *tempo;
//     time_t segundos;
//     time(&segundos); 
//     tempo = localtime(&segundos);
//     return asctime(tempo);
// }

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
        strcpy(locacao[i].dataFim, "\0");
        strcpy(locacao[i].dataInicio, "\0");
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
                registrarLocacaoGuerr(codGuerr, 1);
                strcpy(locacao[qtdLocacao].nomeGuerreiroLocador, warrior->nome);
                locacao[qtdLocacao].codigoGuerreiroLocador = warrior->codigo;
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
                int b;
                for (b = 0; b < ARRSIZELOCACAO; b++)
                {
                    if (locacao[b].codigoLocacao == 0)
                    {
                        dragon->unidade = dragon->unidade - qtd;
                        strcpy(locacao[b].nomeDragaoLocado, dragon->nome);
                        registrarMudancaDrag(dragon->unidade, dragon->codigo);
                        registrarLocacaoDrag(dragon->codigo, 1);
                        locacao[b].valorDiario = dragon->valor * qtd;
                        locacao[b].codigoLocacao = qtdLocacao + 1;
                        locacao[b].quantidadeLocada = qtd;
                        locacao[b].codigoDragaoLocado = dragon->codigo;
                        //<data
                        struct tm *tempo;
                        time_t segundos;
                        time(&segundos); 
                        tempo = localtime(&segundos);

                        strcpy(locacao[b].dataInicio, asctime(tempo)); 
                        //data>
                        qtdLocacao++;
                        return 1;
                    }
                }
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
    int i;
	Locacao* Location = (Locacao*) malloc (sizeof(Locacao));
	for(i = 0; i < qtdLocacao; i++)
	{
		if (locacao[i].codigoLocacao == codigo)
		{
			*Location = locacao[i];
			return Location;
		}		
	}
}


int DevolverLocacaoPeloCodigo(int codigo)
{
    int i, b;
    Locacao* location = obterLocacaoPeloCodigo(codigo);

    Guerreiro* guerreiro = obterGuerreiroPeloCodigo(location->codigoGuerreiroLocador);

    Dragao* dragao = obterDragaoPeloCodigo(location->codigoDragaoLocado);
    dragao->unidade = dragao->unidade + location->quantidadeLocada;
    registrarMudancaDrag(dragao->unidade, dragao->codigo);

    registrarLocacaoGuerr(guerreiro->codigo, 2);
    registrarLocacaoDrag(dragao->codigo, 2);

    //<data
    
    struct tm *tempo;
    time_t segundos;
    time(&segundos); 
    tempo = localtime(&segundos);
    for (i = 0; i < qtdLocacao; i++)
    {
        if (locacao[i].codigoLocacao == location->codigoLocacao)
        {
            strcpy(locacao[i].dataFim, asctime(tempo)); 
            break;
        } 
    }
    
    //data>
    return 1;
            
        
    return 0;
}
