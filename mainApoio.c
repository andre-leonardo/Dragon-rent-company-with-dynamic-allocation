#include <stdio.h>
#include <string.h>
#include <time.h>




int opcao;



void funcaoCadastroGuerreiro()
{
	Guerreiro warrior;

	printf("Digite o codigo do guerreiro: ");
    scanf("%d", &warrior.codigo);

	fflush(stdin);
	printf("Digite o nome do guerreiro: ");
    scanf("%[^\n]s", warrior.nome);
    fflush(stdin);

    printf("Digite o reino do guerreiro: ");
    scanf("%[^\n]s", warrior.reino);
    fflush(stdin);

    printf("Digite o titulo do guerreiro: ");
    scanf("%[^\n]s", warrior.titulo);
    fflush(stdin);
}

void funcaoPesquisarGuerreiro()
{

}

void funcaoExcluirGuerreiro()
{

}
	
	
void menuPrincipal()
{
	printf("0 - Sair\n1 - Listar Guerreiros\n2 - Cadastrar guerreiro via codigo\n3 - Pesquisar guerreiro via nome\n4 - Excluir guerreiro via codigo\n5 - Listar dragoes\n6 - Cadastrar dragao via codigo\n7 - Pesquisar dragao via nome\n8 - Excluir dragao via codigo\n9 - Listar dragoes locados\n10 - Locar dragao\n11 - Devolver dragao via codigo do guerreiro\n12 - Historico de locacoes\n\n\n");
}
void subMenuGuerreiro()
{
	printf("0 - Sair\n1 - Cadastrar\n2 - Pesquisar\n3 - Excluir\n");
}

void subMenuDragao()
{
	printf("0 - Sair\n1 - Cadastrar\n2 - Pesquisar\n3 - Devolver\n");
}

int main(int argc, char *argv[]){
	//horario do sistema
	struct tm *tempo;
	time_t segundos;
	time(&segundos); 
	tempo = localtime(&segundos);  
	printf("%d/%d/%d\n", tempo->tm_mday, tempo->tm_mon+1, tempo->tm_year+1900);

	

    printf("-------------------\n");
    printf("LOCADORA DA KAHLEESI\n");
    printf("-------------------\n");

    do
    {
		menuPrincipal();
        scanf("%d", &opcao);
        if (opcao == 0)
        {
            printf("Obrigado por utilizar este programa!");
            break;
        }

        if (opcao == 1)//Guerreiros
        {
			subMenuGuerreiro();
			scanf("%d", &opcao);
			switch (opcao)
			{
			case 0:
				break;
			case 1:
				funcaoCadastroGuerreiro();
				break;
			case 2:
				funcaoPesquisarGuerreiro();
				break;
			case 3:
				funcaoExcluirGuerreiro();
				break;
			default:
				print("Opcao invalida");
				break;
			}
			
        }

        else if (opcao == 2)//cadastro guerreiros
        {
        	while(tentarNovamente == 0)
            {
	            printf("Digite o codigo do guerreiro que nao esteja sendo usado(um numero de 0 ate %d): ", ARRSIZEGUERREIRO-1);
	            scanf("%d", &codigoGuerreiro);
	            if (codigoGuerreiro >= 0 && codigoGuerreiro < ARRSIZEGUERREIRO)
            	{
	            	if (checarCadastroGuerreiro[codigoGuerreiro] == 1)
	            	{
	            		printf("Um guerreiro ja esta cadastrado com esse codigo, digite 0 para tentar novamente ou qualquer outro numero para voltar ao menu principal: ");
	            		scanf("%d", &tentarNovamente);
					}
					else
					{
						funcaoCadastroGuerreiro();
						checarCadastroGuerreiro[codigoGuerreiro] = 1;
	                	break;
					}
            	}
	            else
	            {
	                printf("Codigo invalido, digite 0 para tentar novamente ou qualquer outro numero para voltar ao menu principal: ");
	                scanf("%d", &tentarNovamente);
	            }
            }
            tentarNovamente = 0;
        }

        else if (opcao == 3)//pesquisar guerreiro
        {
			for (i = 0; i < ARRSIZEGUERREIRO; i++)
			{
				if (nomeGuerreiro[i][0] != '\0')
				{
					contar++;
				}
			}
			
        	if (contar == 0)
        	{
        		printf("Nenhum guerreiro cadastrado ate o momento\n\n");
			}
			else
			{
				while (tentarNovamente == 0)
				{
					fflush(stdin);
					printf("Digite o nome do guerreiro: ");
					scanf("%[^\n]s", guerreiroProcurado[0]);

					for (i = 0; i < ARRSIZEGUERREIRO; i++)
					{
						if (strcmpi(guerreiroProcurado[0], nomeGuerreiro[i]) == 0)
						{
							printf("Guerreiro encontrado na posicao %d\n", i);
							printf("Seu reino eh: %s\n", reino[i]);
							printf("Seu titulo eh: %s\n", titulo[i]);
							tentarNovamente = 1;
							i = ARRSIZEGUERREIRO + 1;
							break;
						}
					}
					if (i!=ARRSIZEGUERREIRO+1)
					{
							
						printf("Guerreiro nao encontrado, digite 0 para pesquisar novamente ou qualquer outro numero para voltar ao menu principal: ");
						scanf("%d", &tentarNovamente);		
					}
				}
			}
			contar = 0;
			tentarNovamente = 0;
		}

		if (opcao == 4)//Excluir guerreiro via codigo
		{
			for (i = 0; i < ARRSIZEGUERREIRO; i++)
			{
				if (nomeGuerreiro[i][0] != '\0')
				{
					contar++;
				}
			}
			
        	if (contar == 0)
				{
					printf("Nenhum guerreiro cadastrado ate o momento\n\n");
				}
			else
			{
				while (tentarNovamente == 0)
				{
					for(i = 0; i < ARRSIZEGUERREIRO; i++)//Imprimir os guerreiros e seus codigos
					{
						printf("%d - %s\n", i, nomeGuerreiro[i]);
					}
					printf("Digite o codigo do guerreiro que quer excluir: ");
					scanf("%d", &guerreiroExcluido);
					
					if (guerreiroExcluido >= 0 && guerreiroExcluido < ARRSIZEGUERREIRO)
					{
						if (checarSeGuerreiroJaTemDragao[guerreiroExcluido] == 1)
						{
							printf("Este guerreiro ja tem um dragao locado, para ser excluido ele deve devolver o dragao.\n");
							break;
						}
					    else if (nomeGuerreiro[guerreiroExcluido][0] == '\0')
	                    {
	                        printf("Nenhum guerreiro cadastrado nesse codigo.\n");
	                        break;
	                    }
	                    else
	                    {
	                        for (i = 0; i <= 20; i++)
	                        {
	                            nomeGuerreiro[guerreiroExcluido][i] = '\0';
	                        }
		                    printf("Guerreiro excluido com sucesso\n");
		                    checarCadastroGuerreiro[guerreiroExcluido] = 0;
							break;
	                    }
					}
				}
			}
			tentarNovamente = 0;
			contar = 0;
		}

		if (opcao == 5)//listar dragoes
		{
		     for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (nomeDrake[i][0] != '\0')
					{
						contar++;
					}
				}
			
        	if (contar == 0)
				{
					printf("Nenhum dragao cadastrado ate o momento\n\n");
				}
            else
            {
                for(i = 0; i < ARRSIZEDRAKE; i++)
                {
                    printf("%d - %s\n", i, nomeDrake[i]);
                }
            }
			contar = 0;
		}

		if (opcao == 6)//cadastrar dragao
        {
            while(tentarNovamente == 0)
            {
	            printf("Digite o codigo do dragao que nao esteja sendo usado(um numero de 0 ate %d): ", ARRSIZEDRAKE-1);
	            scanf("%d", &codigoDrake);
	            if (codigoDrake >= 0 && codigoDrake < ARRSIZEDRAKE)
            	{
	            	if (checarCadastroDrake[codigoDrake] == 1)
	            	{
	            		printf("Um dragao ja esta cadastrado com esse codigo, digite 0 para tentar novamente ou qualquer outro numero para voltar ao menu principal: ");
	            		scanf("%d", &tentarNovamente);
					}
					else
					{
						fflush(stdin);
						printf("Digite o nome do dragao: ");
                        scanf("%[^\n]s", nomeDrake[codigoDrake]);
						fflush(stdin);
                        printf("Digite a idade do dragao: ");
                        scanf("%d", &idadeDrake[codigoDrake]);
						
                        while (tentarNovamente == 0)
                        {
                            printf("Digite o numero do elemento do dragao\n1 - terra\n2 - fogo\n3 - agua\n4 -  gelo\n5 - vento: ");
                            scanf("%d", &elementoDrake[codigoDrake]);
                            if (elementoDrake[codigoDrake] >= 0 && elementoDrake[codigoDrake] <= 5)
                            {
                                printf("Dragao cadastrado com sucesso\n\n");
                                checarCadastroDrake[codigoDrake] = 1;
                                switch (elementoDrake[codigoDrake])
                                {
                                case 1:
                                    strcpy(elementoDrakeString[codigoDrake], terra[0]);
                                    break;
                                case 2:
                                    strcpy(elementoDrakeString[codigoDrake], terra[1]);
                                    break;
                                case 3:
                                    strcpy(elementoDrakeString[codigoDrake], terra[2]);
                                    break;
                                case 4:
                                    strcpy(elementoDrakeString[codigoDrake], terra[3]);
                                    break;
                                default:
                                    strcpy(elementoDrakeString[codigoDrake], terra[4]);
                                    break;
                                }
                                break;
                            }
                            else
                            {
                                printf("Numero do elemento invalido, digite 0 para digitar o numero do elemento novamente ou qualquer outro numero para voltar ao menu principal: ");
                                scanf("%d", &tentarNovamente);
                            }
                        }
                        break;
					}
            	}
	            else
	            {
	                printf("Codigo invalido, digite 0 para tentar novamente ou qualquer outro numero para voltar ao menu principal: ");
	                scanf("%d", &tentarNovamente);
	            }
            }
            tentarNovamente = 0;
        }

        if (opcao == 7)//pesquisar dragao por nome
        {
            while (tentarNovamente == 0)
			{
				fflush(stdin);
				printf("Digite o nome do dragao: ");
				scanf("%[^\n]s", drakeProcurado[0]);

				for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (strcmpi(drakeProcurado[0], nomeDrake[i]) == 0)
					{
						printf("Dragao encontrado na posicao %d\n", i);
						printf("Sua idade eh: %d anos\n", idadeDrake[i]);
						printf("Seu elemento eh: %s\n", elementoDrakeString[i]);
						tentarNovamente = 1;
						i = ARRSIZEDRAKE+1;
						break;
					}
				}
				if (i!=ARRSIZEDRAKE+1)
				{
						
					printf("Dragao nao encontrado, digite 0 para pesquisar novamente ou qualquer outro numero para voltar ao menu principal: ");
					scanf("%d", &tentarNovamente);		
				}
       		}
       		tentarNovamente = 0;
       }

        if (opcao == 8)//excluir dragao por codigo
        {
        	for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (nomeDrake[i][0] != '\0')
					{
						contar++;
					}
				}
			
        	if (contar == 0)
				{
					printf("Nenhum dragao cadastrado ate o momento\n\n");
				}
			else
			{
				while (tentarNovamente == 0)
				{
					for(i = 0; i < ARRSIZEDRAKE; i++)
					{
						printf("%d - %s\n", i, nomeDrake[i]);
					}
					printf("Digite o codigo do dragao: ");
					scanf("%d", &drakeExcluido);
					
					if (checarSeDragaoJaEstaLocado[drakeExcluido] == 1)
					{
						printf("Esse dragao esta locado, para ser excluido ele ser devolvido.\n");
						break;
					}
	
					if (drakeExcluido >= 0 && drakeExcluido < ARRSIZEDRAKE)
					{
					    if (nomeDrake[drakeExcluido][0] == '\0')
	                    {
	                        printf("Nenhum dragao cadastrado nesse codigo.\n");
	                        break;
	                    }
	                    else
	                    {
	                        for (i = 0; i <= 1; i++)
	                        {
	                            nomeDrake[drakeExcluido][i] = '\0';
	                            elementoDrakeString[drakeExcluido][i] = '\0';
	                            idadeDrake[i] = 0;
	                        }
	                    printf("Dragao %s excluido com sucesso\n", nomeDrake[drakeExcluido]);
	                    checarCadastroDrake[drakeExcluido] = 0;
						break;
	                    }
					}
				}
			}
			contar = 0;
        }

        if (opcao == 9)//listar dragoes locados
        {
            for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (drakeLocado[i][0] != '\0')
					{
						contar++;
					}
				}
			
        	if (contar == 0)
				{
					printf("Nenhum dragao locado ate o momento\n\n");
				}
			else
            {
                for(i = 0; i < ARRSIZE; i++)
                {
                    printf("Dragao: %s, guerreiro que alugou: %s, data para devolucao: ", drakeLocado[i], alugadores[i]);
                    for (e = 0; e < 3; e++)
                    {
                    	printf("%d/", data[i][e]);
					}
					printf("\n");
                }
			}
			contar = 0;
        }

        if (opcao == 10)//locar dragao
        {	
			for (i = 0; i < ARRSIZEGUERREIRO; i++)
				{
					if (nomeGuerreiro[i][0] != '\0')
					{
						contar++;
					}
				}
			for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (nomeDrake[i][0] != '\0')
					{
						contarDrake++;
					}
				}
			
        	if (contar == 0 || contarDrake == 0)
				{
					printf("Nenhum guerreiro e(ou) dragao cadastrado\n");
				}
			
			
			else
			{
				while (tentarNovamente == 0)
				{
					printf("Digite o codigo do guerreiro: ");
					scanf("%d", &codigoGuerreiro);
					if (!(codigoGuerreiro >=0 && codigoGuerreiro < ARRSIZEGUERREIRO))
					{
						printf("Codigo invalido, digite 0 para tentar novamente ou qualquer outro numero para voltar para o menu principal: ");
						scanf("%d", &tentarNovamente);
					}
					else if (nomeGuerreiro[codigoGuerreiro][0] == '\0')
					{
						printf("Nenhum guerreiro esta com esse codigo, digite 0 para tentar novamente ou qualquer outro numero para voltar para o menu principal: ");
						scanf("%d", &tentarNovamente);
					}
					else if (checarSeGuerreiroJaTemDragao[codigoGuerreiro] == 1)
					{
						printf("Esse guerreiro ja tem um dragao locado, digite 0 para digitar outro codigo ou qualquer outro numero para voltar para o menu principal: ");
						scanf("%d", &tentarNovamente);
					}
					else
					{
						printf("Digite o codigo do dragao: ");
						scanf("%d", &codigoDrake);
						if (nomeDrake[codigoDrake][0] == '\0')
						{
							printf("Nenhum dragao esta com esse codigo, digite 0 para tentar novamente ou qualquer outro numero para voltar para o menu principal: ");
							scanf("%d", &tentarNovamente);
						}
						else if (!(codigoDrake >=0 && codigoDrake < ARRSIZEDRAKE))
						{
							printf("Codigo invalido, digite 0 para tentar novamente ou qualquer outro numero para voltar para o menu principal: ");
							scanf("%d", &tentarNovamente);
						}
						else if (checarSeDragaoJaEstaLocado[codigoDrake] == 1)
						{
							printf("Esse dragao ja esta locado, digite 0 para digitar outro codigo ou qualquer outro numero para voltar para o menu principal: ");
							scanf("%d", &tentarNovamente);
						}
						else 
						{
							strcpy(drakeLocado[codigoGuerreiro], nomeDrake[codigoDrake]);
							strcpy(alugadores[codigoGuerreiro], nomeGuerreiro[codigoGuerreiro]);
							checarSeDragaoJaEstaLocado[codigoDrake] = 1;
							checarSeGuerreiroJaTemDragao[codigoGuerreiro] = 1;
							data[codigoGuerreiro][0] = tempo->tm_mday;
							data[codigoGuerreiro][1] = tempo->tm_mon+1;
							data[codigoGuerreiro][2] = tempo->tm_year+1901;
							
							d--;
							strcpy(historicoGuerreiro[d], alugadores[codigoGuerreiro]);
							strcpy(historicoDrake[d], drakeLocado[codigoGuerreiro]);
							
							printf("Dragao locado com sucesso\n\n");
							break;
						}
					}
            	}
			}
            tentarNovamente = 0;
			contar = 0;
        }
        
        if (opcao == 11)//devolver dragao locado
        {
			for (i = 0; i < ARRSIZEGUERREIRO; i++)
				{
					if (nomeGuerreiro[i][0] != '\0')
					{
						contar++;
					}
				}
			for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (nomeDrake[i][0] != '\0')
					{
						contarDrake++;
					}
				}
			
        	if (contar == 0 || contarDrake == 0)
				{
					printf("Nenhum guerreiro e(ou) dragao cadastrado\n");
				}
			
			else
			{
				while (tentarNovamente == 0)
				{
				
					printf("Digite o codigo do guerreiro: ");
					scanf("%d", &codigoGuerreiro);
					if (!(codigoGuerreiro >=0 && codigoGuerreiro < ARRSIZEGUERREIRO))
						{
							printf("Codigo invalido, digite 0 para tentar novamente ou qualquer outro numero para voltar para o menu principal: ");
							scanf("%d", &tentarNovamente);
						}
						
					else if (nomeGuerreiro[codigoGuerreiro][0] == '\0')
						{
							printf("Nenhum guerreiro esta com esse codigo, digite 0 para tentar novamente ou qualquer outro numero para voltar para o menu principal: ");
							scanf("%d", &tentarNovamente);
						}
		
					else if (checarSeGuerreiroJaTemDragao[codigoGuerreiro] == 0)
					{
						printf("Esse guerreiro nao tem nenhum dragao locado, digite 0 para digitar outro codigo ou qualquer outro numero para voltar para o menu principal: ");
						scanf("%d", &tentarNovamente);
					}
						else
						{
							drakeLocado[codigoGuerreiro][0] = '\0';
							alugadores[codigoGuerreiro][0] = '\0';
							checarSeDragaoJaEstaLocado[codigoDrake] = 0;
							checarSeGuerreiroJaTemDragao[codigoGuerreiro] = 0;
							data[codigoGuerreiro][0] = '\0';
							data[codigoGuerreiro][1] = '\0';
							data[codigoGuerreiro][2] = '\0';
							printf("Dragao devolvido com sucesso\n\n");
							break;
						}
				}
			}	
	        tentarNovamente = 0;
	    }
	    
	    if (opcao == 12)
	    {
	    	for (i = 0; i < TAMANHOHISTORICO; i++)
				{
					if (historicoGuerreiro[i][0] != '\0')
					{
						contar++;
					}
				}
			if (contar == 0)
				{
					printf("Nenhuma transacao feita\n");
				}
			else
			{
		    	for (i = TAMANHOHISTORICO-1; i >= 0; i--)
		    	{
		    		printf("%s foi locado por %s\n ", historicoDrake[i], historicoGuerreiro[i]);
				}
			}
		}
		tentarNovamente = 0;
		contarDrake = 0;
		contar = 0;
    }
    while(opcao != 0);
    return 0;
}
