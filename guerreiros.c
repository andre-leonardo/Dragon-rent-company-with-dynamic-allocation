#include "guerreiros.h"
#include "locacoes.h"
#include <stdlib.h>
#include <string.h>
int ARRSIZEGUERREIRO = 5;



Guerreiro *guerreiro = NULL;
int qtdGuerreiro = 0, codigoAtualGuerreiros = 0;


int inicializarGuerreiros()
{
	int i;
	
	guerreiro = (Guerreiro*) malloc (ARRSIZEGUERREIRO * sizeof(Guerreiro));
	if (guerreiro == NULL)
	{
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
    //  guerreiro[0].codigo = 1;
    //  strcpy(guerreiro[0].nome, "adalberto");
    //  strcpy(guerreiro[0].titulo, "adalbertius");
    //  strcpy(guerreiro[0].reino, "adalbertolandia");

    //  guerreiro[1].codigo = 2;
    //  strcpy(guerreiro[1].nome, "roberto");
    //  strcpy(guerreiro[1].titulo, "robertius");
    //  strcpy(guerreiro[1].reino, "robertolandia");
	
    //  guerreiro[2].codigo = 3;
    //  strcpy(guerreiro[2].nome, "eliberto");
    //  strcpy(guerreiro[2].titulo, "elibertius");
    //  strcpy(guerreiro[2].reino, "elibertolandia");

    //  guerreiro[3].codigo = 4;
    //  strcpy(guerreiro[3].nome, "florisberto");
    //  strcpy(guerreiro[3].titulo, "florisbertius");
    //  strcpy(guerreiro[3].reino, "florlandia");

    //  guerreiro[4].codigo = 5;
    //  strcpy(guerreiro[4].nome, "gilberto");
    //  strcpy(guerreiro[4].titulo, "gilbertius");
    //  strcpy(guerreiro[4].reino, "gilbertolandia");
    
   
    qtdGuerreiro = 0;
    
    return 1;
}


int encerraGuerreiros()
{
	free(guerreiro);
	guerreiro = NULL;
}

int salvarGuerreiro(Guerreiro warrior)
{
	int i;
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
		for(i = 0; i < ARRSIZEGUERREIRO; i++)
		{
			if(guerreiro[i].codigo > codigoAtualGuerreiros)//o c??digo deve ser gerado dentro da fun????o salvarGuerreiro. a quantidade de guerreiros n??o consegue gerar um c??digo v??lido sempre. ele pode gerar guerreiros com c??digos iguais.
				codigoAtualGuerreiros = guerreiro[i].codigo;
		}
		warrior.codigo = codigoAtualGuerreiros + 1;
        guerreiro[qtdGuerreiro] = warrior;
        qtdGuerreiro++;
        return 1;
	}else    
    	return 0;
}

int registrarLocacaoGuerr(int cod, int aumentarOuDiminuir)
{
	int i;

	if (aumentarOuDiminuir == 1)
	{
		for (i = 0; i < qtdGuerreiro; i++)
		{
			if (guerreiro[i].codigo == cod)
			{
				guerreiro[i].checarLocacao = guerreiro[i].checarLocacao + 1;
				break;
			}
		}	
	}
	else
	{
		for (i = 0; i < qtdGuerreiro; i++)
		{
			if (guerreiro[i].codigo == cod)
			{
				guerreiro[i].checarLocacao = guerreiro[i].checarLocacao - 1;
				break;
			}
		}	
	}
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
		if (guerreiro[i].codigo == codigo)
		{
			*Warrior = guerreiro[i];
			return Warrior;
		}		
	}
	
	return NULL;//quando chega no final da fun??????o (ap???s o FOR) precisa de return
}

int atualizarGuerreiro(char* mudanca, int m, int opcao,int codigo)
{
	int i;
	Guerreiro* warrior = obterGuerreiroPeloCodigo(codigo);
	for(i = 0; i < qtdGuerreiro; i++)
	{
		if (warrior->codigo == guerreiro[i].codigo)
		{
			break;
		}
	}
	if (opcao == 1)
	{
		strcpy(guerreiro[i].nome, mudanca);
	}
	else if (opcao == 2)
		strcpy(guerreiro[i].titulo, mudanca);
	else if (opcao == 3)
		strcpy(guerreiro[i].reino, mudanca);	
		
	free (warrior);//chamar free em DevolverLocacaoPeloCodigo e em atualizarGuerreiro
}

Guerreiro* obterGuerreiroPeloNome (char* nome)
{
	int i;
	Guerreiro* Warrior = (Guerreiro*) malloc (sizeof(Guerreiro));
	
	for (i = 0; i < qtdGuerreiro; i++)
    {
    	*Warrior = guerreiro[i];
        if (strcmpi(nome, guerreiro[i].nome) == 0)
        {
            return Warrior;
        }
    }

    return	Warrior = NULL;//quando chega no final da fun??????o (ap???s o FOR) precisa de return
}

int ApagarGuerreiroPeloCodigo(int codigo)
{
	int i;
	int porcentagemArrays = ARRSIZEGUERREIRO * 0.4;
	
    for(i = 0; i < qtdGuerreiro; i++)
    {

        if (guerreiro[i].codigo == codigo)
        {
			if (guerreiro[i].checarLocacao > 0)
				return 3;
            guerreiro[i] = guerreiro[qtdGuerreiro-1];
            guerreiro[qtdGuerreiro - 1].codigo = 0;
            qtdGuerreiro--;
            if (porcentagemArrays == qtdGuerreiro && ARRSIZEGUERREIRO > 5)
			{
	    		Guerreiro* ArrayMenor = realloc (guerreiro, (qtdGuerreiro)  * sizeof(Guerreiro));
	    		if (ArrayMenor != NULL)
	    		{
	    			ARRSIZEGUERREIRO = qtdGuerreiro;
	    			guerreiro = ArrayMenor;
	    			return 2;
				}else return 0;	
			}
			return 1;
        }
    }
    return 0;
}




