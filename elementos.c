#include "elementos.h"
#include <stdlib.h>
#include <string.h>


int ARRSIZEELEMENTO =  5;

Elemento* elemento = NULL;
int i, qtdElemento = 0;



int inicializarElementos()
{
	elemento = (Elemento*) malloc (ARRSIZEELEMENTO * sizeof(Elemento));
    if (elemento == NULL)
	{
        printf("Erro de alocacao dinamica");
		return 0;
	}
	
    for (i = 0; i < ARRSIZEELEMENTO; i++)
    {   	
        elemento[i].codigo = 0;
//        elemento[i].nome[0] = '\0';
//        elemento[i].vulnerabilidade[0] = '\0';
    }
		elemento[0].codigo = 1;
        strcpy(elemento[0].nome, "fogo"); 
        strcpy(elemento[0].vulnerabilidade, "agua");
        qtdElemento = 1;
        
        return 1;
}

int retornaTamanhoElementos()
{
	return ARRSIZEELEMENTO;
}

int encerraElementos()
{}

int salvarElemento(Elemento element)
{
    if (elemento != NULL)
    {
    	if (qtdElemento == ARRSIZEELEMENTO)
    	{
    		Elemento* elementoBKP = elemento;
    		elemento = realloc (elemento, (qtdElemento * 2)  * sizeof(Elemento));
    		if (elemento != NULL)
    		{
    			ARRSIZEELEMENTO = ARRSIZEELEMENTO *  2;
			}
			else {
				elemento = elementoBKP;
				return 0;
			}
		}
        elemento[qtdElemento] = element;
        qtdElemento++;
        return 1;
	}else    
    	return 0;
}

int QuantidadeElementos()
{
    return qtdElemento;
}

Elemento* obterElementoPeloIndice(int indice)
{
    Elemento* element = (Elemento*) malloc (sizeof(Elemento));
	*element = elemento[indice];
	return element;
}

Elemento* obterElementoPeloCodigo(int codigo)
{
    int i;
	Elemento* Element = (Elemento*) malloc (sizeof(Elemento));
	Element->codigo = codigo;
	for(i = 0; i < qtdElemento; i++)
	{
		Elemento* element = obterElementoPeloIndice(i);
		if (codigo == element->codigo)
			*Element = *element;
	}
	
	return Element;
}

Elemento* obterElementoPeloNome (char* nome)
{
	
}

int ApagarElementoPeloCodigo(int codigo)
{
    for(i = 0; i < qtdElemento; i++)
    {
        if (elemento[i].codigo == codigo)
        {
            elemento[i] = elemento[qtdElemento-1];
            elemento[qtdElemento - 1].codigo = 0;
            qtdElemento--;
            return 1;
        }
    }
    return 0;
}
