#include "guerreiros.h"
#include <stdlib.h>
#include <string.h>
int ARRSIZEGUERREIRO = 5;



Guerreiro *guerreiro = NULL;
int i, qtdGuerreiro = 0;


int inicializarGuerreiros()
{
	
	guerreiro = (Guerreiro*) malloc (ARRSIZEGUERREIRO * sizeof(Guerreiro));
	if (guerreiro == NULL)
	{
        printf("Erro de alocacao dinamica");
		return 0;
	}
	
    for (i = 0; i < ARRSIZEGUERREIRO; i++)
    {   	
        guerreiro[i].codigo = 0;
        guerreiro[i].nome[0] = '\0';
        guerreiro[i].titulo[0] = '\0';
        guerreiro[i].reino[0] = '\0';
        guerreiro[i].checarLocacao = 0;
    }
    guerreiro[0].codigo = 1;
    strcpy(guerreiro[0].nome, "adalberto");
    strcpy(guerreiro[0].titulo, "adalbertius");
    strcpy(guerreiro[0].reino, "adalbertolandia");
    
    guerreiro[1].codigo = 2;
    strcpy(guerreiro[1].nome, "roberto");
    strcpy(guerreiro[1].titulo, "robertius");
    strcpy(guerreiro[1].reino, "robertolandia");
    guerreiro[2].codigo = 3;
    strcpy(guerreiro[2].nome, "eliberto");
    strcpy(guerreiro[2].titulo, "elibertius");
    strcpy(guerreiro[2].reino, "elibertolandia");
    guerreiro[3].codigo = 4;
    strcpy(guerreiro[3].nome, "florisberto");
    strcpy(guerreiro[3].titulo, "florisbertius");
    strcpy(guerreiro[3].reino, "florlandia");
    guerreiro[4].codigo = 5;
    strcpy(guerreiro[4].nome, "gilberto");
    strcpy(guerreiro[4].titulo, "gilbertius");
    strcpy(guerreiro[4].reino, "gilbertolandia");
    
   
    qtdGuerreiro = 5;
    
    return 1;
}


int encerraGuerreiros()
{}

int salvarGuerreiro(Guerreiro warrior)
{
	if (guerreiro != NULL)
	{
    	if (qtdGuerreiro == ARRSIZEGUERREIRO)
    	{
    		Guerreiro* guerreiroBKP = guerreiro;
    		guerreiro = realloc (guerreiro, (qtdGuerreiro * 2)  * sizeof(Guerreiro));
    		if (guerreiro != NULL)
    		{
    			ARRSIZEGUERREIRO = ARRSIZEGUERREIRO *  2;
			}
			else {
				guerreiro = guerreiroBKP;
				return 0;
			}
		}
        guerreiro[qtdGuerreiro] = warrior;
        qtdGuerreiro++;
        return 1;
	}else    
    	return 0;
}

int QuantidadeGuerreiros()
{
    return qtdGuerreiro;
}

Guerreiro* obterGuerreiroPeloIndice(int indice)
{
	Guerreiro* warrior = (Guerreiro*) malloc (sizeof(Guerreiro));
	*warrior = guerreiro[indice];
	return warrior;
}

Guerreiro* obterGuerreiroPeloCodigo(int codigo)
{
	int i;
	Guerreiro* Warrior = (Guerreiro*) malloc (sizeof(Guerreiro));
	Warrior->codigo = codigo;
	for(i = 0; i < qtdGuerreiro; i++)
	{
		Guerreiro* warrior = obterGuerreiroPeloIndice(i);
		if (codigo == warrior->codigo)
			*Warrior = *warrior;
			
	}
	
	return Warrior;
}

int atualizarGuerreiro(char* mudanca, int m, int opcao,int codigo)
{
	Guerreiro* warrior = obterGuerreiroPeloCodigo(codigo);
	if (opcao == 1)
		strcpy(guerreiro->nome, mudanca);
	else if (opcao == 2)
		strcpy(guerreiro->titulo, mudanca);
	else if (opcao == 3)
		strcpy(guerreiro->reino, mudanca);	
}

Guerreiro* obterGuerreiroPeloNome (char* nome)
{
	int cont = 0;
	Guerreiro* Warrior = (Guerreiro*) malloc (sizeof(Guerreiro));
	
	for (i = 0; i < qtdGuerreiro; i++)
    {
    	*Warrior = guerreiro[i];
        Guerreiro* warrior = obterGuerreiroPeloIndice(i);
        if (strcmpi(nome, warrior->nome) == 0)
        {
            return Warrior;
        }

    }
    if (cont == 0)
    {
    	Warrior = NULL;
	}
}

int ApagarGuerreiroPeloCodigo(int codigo)
{
	int porcentagemArrays = ARRSIZEGUERREIRO * 0.4;
	printf("porcentagem %d\n", porcentagemArrays);
	
    for(i = 0; i < qtdGuerreiro; i++)
    {
        if (guerreiro[i].codigo == codigo)
        {
            guerreiro[i] = guerreiro[qtdGuerreiro-1];
            guerreiro[qtdGuerreiro - 1].codigo = 0;
            qtdGuerreiro--;
            if (porcentagemArrays == qtdGuerreiro + 1 && ARRSIZEGUERREIRO > 5)
			{
	    		Guerreiro* ArrayMenor = realloc (guerreiro, (qtdGuerreiro)  * sizeof(Guerreiro));
	    		printf("tamanho %d\n", sizeof(guerreiro));
	    		if (ArrayMenor != NULL)
	    		{
	    			ARRSIZEGUERREIRO = qtdGuerreiro;
	    			guerreiro = ArrayMenor;
	    			printf("arr size guerreiro %d\n", ARRSIZEGUERREIRO);
				}else return 0;
				
			}
			return 1;
        }
    }
    return 0;
}




