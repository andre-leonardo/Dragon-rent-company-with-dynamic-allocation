#include "dragoes.h"
#include "elementos.h"
#include <stdlib.h>
#include <string.h>

int ARRSIZEDRAGAO =  5;

Dragao* dragao = NULL;
int i, qtdDragao = 0;


int inicializarDragoes()
{
    dragao = (Dragao*) malloc (ARRSIZEDRAGAO * sizeof(Dragao));
    if (dragao == NULL)
	{
        printf("Erro de alocacao dinamica");
		return 0;
	}

    for (i = 0; i < ARRSIZEDRAGAO; i++)
    {   	
        dragao[i].codigo = 0;
        // dragao[i].nome[0] = '\0';
        dragao[i].idade = 0;
        dragao[i].valor = 0;
        dragao[i].unidade = 0;
        // dragao[i].elemento[0] = '\0';
        dragao[i].checarLocacao = 0;
        dragao[i].unidadeAnterior[i] = 0;
    }
    	dragao[0].codigo = 1;
        strcpy(dragao[0].nome, "pedrao");
        dragao[0].idade = 25;
        dragao[0].valor = 48;
        dragao[0].unidade = 2;
        strcpy(dragao[0].elemento, "pedra");
        qtdDragao = 1;
        return 1;
}


int encerraDragoes()
{}

int salvarEstoque(int quantidade)
{
	for (i = 0; i < 10; i++)
	{
		if (dragao->unidadeAnterior[i] == 0)
			dragao->unidadeAnterior[i] = dragao->unidade;
			break;
	}
}

int diminuirEstoque(int quantidade)
{
	for (i = 0; i < 10; i++)
	{
	}
	if (quantidade <= dragao->unidade)
	{
		dragao->unidade -= quantidade;
		return 1;
	} else return 0;
}


int salvarDragao(Dragao dragon)
{ 
	if (dragao != NULL)
    {
    	if (qtdDragao == ARRSIZEDRAGAO)
    	{
    		Dragao* dragaoBKP = dragao;
    		dragao = realloc (dragao, (qtdDragao * 2)  * sizeof(Dragao));
    		if (dragao != NULL)
    		{
    			ARRSIZEDRAGAO = ARRSIZEDRAGAO *  2;
			}
			else {
				dragao = dragaoBKP;
				return 0;
			}
		}
        dragao[qtdDragao] = dragon;
        qtdDragao++;
        return 1;
	}else    
    	return 0;
}

int QuantidadeDragoes()
{
    return qtdDragao;
}

Dragao* obterDragaoPeloIndice(int indice)
{
    Dragao* dragon = (Dragao*) malloc (sizeof(Dragao));
	*dragon = dragao[indice];
	return dragon;
}

Dragao* obterDragaoPeloCodigo(int codigo)
{
	int i;
	Dragao* Dragon = (Dragao*) malloc (sizeof(Dragao));
	Dragon->codigo = codigo;
	for(i = 0; i < qtdDragao; i++)
	{
		Dragao* dragon = obterDragaoPeloIndice(i);
		if (codigo == dragon->codigo)
			*Dragon = *dragon;
	}
	
	return Dragon;
}

int atualizarDragao(int mudancaInt, char* mudanca, int m, int opcao,int codigo)
{
	Dragao* dragon = obterDragaoPeloCodigo(codigo);
	if (opcao == 1)
		strcpy(dragao->nome, mudanca);
	else if (opcao == 2)
		dragao->idade = mudancaInt;
	else if (opcao == 3)
	{
		Elemento* element = obterElementoPeloCodigo(mudancaInt);
		dragao->codigoElemento = element->nome;
		strcpy(dragao->elemento, element->nome);
	}
	else if (opcao == 4)
		dragao->valor = mudancaInt;
	else if (opcao == 5)
		dragao->unidade = mudancaInt;
	return 0;
}

Dragao* obterDragaoPeloNome (char* nome)
{
	int cont = 0;
	Dragao* Dragon = (Dragao*) malloc (sizeof(Dragao));
	
	for (i = 0; i < qtdDragao; i++)
    {
    	*Dragon = dragao[i];
        Dragao* dragon = obterDragaoPeloIndice(i);
        if (strcmpi(nome, dragon->nome) == 0)
        {
            return Dragon;
        }

    }
    if (cont == 0)
    {
    	Dragon = NULL;
	}
}

int ApagarDragaoPeloCodigo(int codigo)
{
    for(i = 0; i < qtdDragao; i++)
    {
        if (dragao[i].codigo == codigo)
        {
            dragao[i] = dragao[qtdDragao-1];
            dragao[qtdDragao - 1].codigo = 0;
            qtdDragao--;
            return 1;
        }
    }
    return 0;
}
