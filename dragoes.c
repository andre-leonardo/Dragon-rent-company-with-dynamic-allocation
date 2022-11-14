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
        // dragao[i].unidadeAnterior[i] = 0;
    }
    	dragao[0].codigo = 1;
        strcpy(dragao[0].nome, "pedrao");
        dragao[0].idade = 25;
        dragao[0].valor = 48;
        dragao[0].unidade = 40;
        strcpy(dragao[0].elemento, "fogo");
        dragao[0].codigoElemento = 1;
        qtdDragao = 1;
        return 1;
}


int encerraDragoes()
{}



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
int registrarMudancaDrag(int qtd, int cod)//alterar o valor de unidade
{
	int i;
	Dragao* dragon = obterDragaoPeloCodigo(cod);
	for (i = 0; i < qtdDragao; i++)
		{

			if (dragao[i].codigo == dragon->codigo)
			{
				dragao[i].unidade = qtd;
				return 0;
			}
		}
	return 1;
}

int registrarLocacaoDrag(int cod, int aumentarOuDiminuir)
{
	int i;

	if (aumentarOuDiminuir == 1)
	{
		for (i = 0; i < qtdDragao; i++)
		{
			if (dragao[i].codigo == cod)
			{
				dragao[i].checarLocacao = dragao[i].checarLocacao + 1;
				return 1;
			}
		}	
	}
	if (aumentarOuDiminuir == 2)
	{
		for (i = 0; i < qtdDragao; i++)
		{
			if (dragao[i].codigo == cod)
			{
				dragao[i].checarLocacao = dragao[i].checarLocacao - 1;
				return 2;
			}
		}	
	}
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
	for(i = 0; i < qtdDragao; i++)
	{
		if (dragao[i].codigo == codigo)
		{
			*Dragon = dragao[i];
			return Dragon;
		}		
	}
}

int atualizarDragao(int mudancaInt, char* mudanca, int m, int opcao,int codigo)
{
	if (opcao == 1)
		strcpy(dragao[codigo-1].nome, mudanca);
	else if (opcao == 2)
		dragao[codigo-1].idade = mudancaInt;
	else if (opcao == 3)
	{
		Elemento* element = obterElementoPeloCodigo(mudancaInt);
		dragao[codigo-1].codigoElemento = element->codigo;
		strcpy(dragao[codigo-1].elemento, element->nome);
	}
	else if (opcao == 4)
		dragao[codigo-1].valor = mudancaInt;
	else if (opcao == 5)
		dragao[codigo-1].unidade = mudancaInt;
	return 0;
}

Dragao* obterDragaoPeloNome (char* nome)
{
	int cont = 0;
	Dragao* Dragon = (Dragao*) malloc (sizeof(Dragao));
	
	for (i = 0; i < qtdDragao; i++)
    {
    	*Dragon = dragao[i];
        if (strcmpi(nome, dragao[i].nome) == 0)
        {
            return Dragon;
        }

    }
    if (cont == 0)
    {
    	return Dragon = NULL;
	}
}

int ApagarDragaoPeloCodigo(int codigo)
{
	int porcentagemArrays = ARRSIZEDRAGAO * 0.4;

    for(i = 0; i < qtdDragao; i++)
    {
        if (dragao[i].codigo == codigo)
        {
			if (dragao[i].checarLocacao > 0)
				return 3;
            dragao[i] = dragao[qtdDragao-1];
            dragao[qtdDragao - 1].codigo = 0;
            qtdDragao--;
			if (porcentagemArrays == qtdDragao && ARRSIZEDRAGAO > 5)
			{
				Dragao* ArrayMenor = realloc (dragao, (qtdDragao) * sizeof(Dragao));
				if (ArrayMenor != NULL)
				{
					ARRSIZEDRAGAO = qtdDragao;
					dragao = ArrayMenor;
					return 2;
				}else return 0;
			}
            return 1;
        }
    }
    return 0;
}


//  ⣿⣿⣿⣿⣿⡏⠉⠄⠄⠄⠄⠄⠄⠄⠄⠈⠉⠉⠉⠉⠉⠉⠉⢿⣿⣿⣿⣿⣿⣿ 
//  ⣿⣿⣿⣿⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠸⣿⣿⣿⣿⣿⣿ 
//  ⣿⣿⣿⣿⣿⠄⠄⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⣿⣿⣿ 
//  ⣿⣿⣿⣿⣿⠄⢠⡏⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⣿⣿⣿ 
//  ⣍⡉⠙⠛⠛⠄⠾⢀⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠙⠛⠛⠛⠛⣛ 
//  ⣿⣿⣶⣦⣄⢀⣀⡀⠄⠉⠉⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⡀⠄⣤⣤⣶⣶⣾⣿ 
//  ⣿⣿⣿⣿⠛⠸⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣟⣻⣾⣿⣿⣿⡅⠄⢻⢿⣿⣿⣿⣿ 
//  ⣿⣿⣿⣧⡃⠄⢀⠤⠄⠄⠄⠄⠄⢀⡀⠄⢠⡤⠄⠄⠄⠄⠄⠄⡇⢠⣿⣿⣿⣿ 
//  ⣿⣿⣿⣿⡇⠄⢹⠄⠄⠄⠄⠄⠄⢸⣿⠄⠘⠄⠄⠄⠄⠄⠄⢸⢀⣿⣿⣿⣿⣿ 
//  ⣿⣿⣿⣿⡝⡇⢄⣀⣀⣀⣀⣠⣴⣸⣿⠄⠈⢀⠄⢀⣀⡀⠄⢨⣾⣿⣿⣿⣿⣿ 
//  ⣿⣿⣿⣿⣿⣅⠸⣿⣿⣿⣿⣹⡿⠿⡿⠇⠋⡻⣿⣿⠟⠄⠄⣦⣿⣿⣿⣿⣿⣿ 
//  ⣿⣿⣿⣿⣿⣿⠄⣿⡽⣿⠗⠋⠉⠁⠈⠄⠉⠘⠛⣿⢠⠄⠄⣿⣿⣿⣿⣿⣿⣿ 
//  ⣿⣿⣿⣿⣿⣿⣧⡘⣿⠏⠄⣠⣤⣄⣠⣤⣀⣠⣄⠻⢸⠃⣼⣿⣿⣿⣿⣿⣿⣿ 
//  ⣿⣿⣿⣿⣿⣿⣿⣷⣸⠄⢐⢿⡏⠁⠄⠈⢹⠿⠟⢀⣾⣾⣿⣿⣿⣿⣿⣿⣿⣿ 
//  ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣄⠃⠈⠁⠄⠄⠄⠈⠄⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ 

