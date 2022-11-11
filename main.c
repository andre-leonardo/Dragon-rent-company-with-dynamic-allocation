#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dragoes.h"
#include "guerreiros.h"
#include "elementos.h"
#include "locacoes.h"




//GUERREIROS

void listarGuerreiros()
{
    int i;

    for (i = 0; i < QuantidadeGuerreiros(); i++)
    {
		Guerreiro* warrior = obterGuerreiroPeloIndice(i);
        if (warrior != NULL)		
            printf("\n%d - %s, titulo: %s, reino: %s\n\n",
            warrior->codigo, warrior->nome,
            warrior->titulo, warrior->reino);
            free(warrior);
    }
    if (QuantidadeGuerreiros() == 0)
    {
        printf("NENHUM GUERREIRO CADASTRADO\n");
    }
    
}

void funcaoCadastroGuerreiro()
{
    Guerreiro warrior;

	warrior.codigo = QuantidadeGuerreiros() + 1;

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

    if (salvarGuerreiro(warrior) == 1)
        printf("Guerreiro cadastrado com sucesso!\n");
    else
        printf("Falha ao cadastrar guerreiros!\n");
}

void funcaoPesquisarGuerreiro()
{
    char procurado[30];
    int i;

    fflush(stdin);
    printf("Digite o nome do guerreiro: ");
	scanf("%[^\n]s", procurado);
	Guerreiro* warrior = obterGuerreiroPeloNome(procurado);
	
	if (warrior == NULL)
		printf("Nenhum guerreiro encontrado");
	else{
		printf("O codigo do guerreiro eh: %d\n", warrior->codigo);
        printf("Seu reino eh: %s\n", warrior->reino);
        printf("Seu titulo eh: %s\n", warrior->titulo);
        free(warrior);
	}
}

void funcaoExcluirGuerreiro()
{
    listarGuerreiros();
    int codigo;
    printf("Digite o codigo do guerreiro que deseja APAGAR: ");
	scanf("%d", &codigo);
	if (ApagarGuerreiroPeloCodigo(codigo)==1)
		printf("Guerreiro APAGADO com sucesso!\n");
	else
		printf("Falha ao apagar o guerreiro!\n");
}

void alterarGuerreiros()
{
	int i, opcao, r;
	char mudanca[30];
	listarGuerreiros();
	int codigo;
	printf("Digite o codigo do guerreiro que deseja alterar: ");
	scanf("%d", &codigo);
	

	
	do
	{
	printf("\n0 - Finalizar\n1 - Alterar nome\n2 - Alterar titulo\n3 - Alterar reino\n");
	printf("Digite a numero do que deseja alterar: ");
	scanf("%d", &opcao);
	
	if (opcao == 0)
	{
		printf("Finalizado!\n");
		break;
	}
	else if (opcao == 1)
	{
		printf("Digite o novo nome: ");
		fflush(stdin);
		scanf("%[^\n]s", mudanca);
		r = atualizarGuerreiro(mudanca, 30, 1, codigo);
	}
	else if (opcao == 2)
	{
		printf("Digite o novo titulo: ");
		fflush(stdin);
		scanf("%[^\n]s", mudanca);
		r = atualizarGuerreiro(mudanca, 30, 2, codigo);
	}
	else if (opcao == 3)
	{
		printf("Digite o novo reino: ");
		fflush(stdin);
		scanf("%[^\n]s", mudanca);
		r = atualizarGuerreiro(mudanca, 30, 3, codigo);
	}
	else printf("Numero invalido!n");
	
			
	} while (opcao != 0);
		
}


//DRAGOES
void listarElementos()
{
	int i;

    
    for (i = 0; i < QuantidadeElementos(); i++)
    {
        Elemento element = obterElementoPeloIndice(i);
        if (element.codigo > 0)		
            printf("\n%d - %s, vulnerabilidade: %s\n\n",
            element.codigo, element.nome, element.vulnerabilidade);
    }
    if (QuantidadeElementos() == 0)
    {
        printf("NENHUM ELEMENTO CADASTRADO\n");
    }
}

void listarDragoes()
{
	int i;

    
    for (i = 0; i < QuantidadeDragoes(); i++)
    {
        Dragao* dragon = obterDragaoPeloIndice(i);
        if (dragon != NULL)		
            printf("\n%d - %s, idade: %d, elemento: %s, valor: %.2f, quantidade: %d\n\n",
            dragon->codigo, dragon->nome,
            dragon->idade, dragon->elemento, dragon->valor, dragon->unidade);
    }
    if (QuantidadeDragoes() == 0)
    {
        printf("NENHUM DRAGAO CADASTRADO\n");
    }
}

void funcaoCadastroDragao()
{
    Dragao dragon;
	int check = 0;
	int b, i;
    
    for (i = 0; i < retornaTamanhoElementos(); i++)
    {
    	Elemento element = obterElementoPeloIndice(i);
    	if (element.codigo > 0)
		{
			dragon.codigo = QuantidadeDragoes() + 1;
		
			fflush(stdin);
			printf("Digite o nome do dragao: ");
		    scanf("%[^\n]s", dragon.nome);
		
		    printf("Digite a idade do dragao: ");
		    scanf("%d", &dragon.idade);
		    
		    listarElementos();
		    printf("Digite o codigo do elemento do dragao: ");
		    scanf("%d", &dragon.codigoElemento);
		    for (b = 0; b < retornaTamanhoElementos(); b++)
			{
				Elemento element = obterElementoPeloIndice(b);
				printf("%s", element.nome);
				if (dragon.codigoElemento == element.codigo)
				strcpy(dragon.elemento, element.nome);
			}
		    printf("Digite o valor do dragao: ");
		    scanf("%f", &dragon.valor);
		    
		    printf("Digite a quantidade em estoque do dragao: ");
		    scanf("%d", &dragon.unidade);
		
		    if (salvarDragao(dragon) == 1)
		        printf("Dragao cadastrado com sucesso!\n");
		    else
		        printf("Falha ao cadastrar dragao!\n");
		        
		    check++;
		        
		    break;
		}			
	}
	if (check == 0) printf("CADASTRE PELO MENOS UM ELEMENTO ANTES DE CADASTRAR UM DRAGAO\n");
    


}

void funcaoPesquisarDragao()
{
    char procurado[30];
    int i;

    fflush(stdin);
    printf("Digite o nome do dragao: ");
	scanf("%[^\n]s", procurado);
	Dragao* dragon = obterDragaoPeloNome(procurado);
	
	if (dragon == NULL)
		printf("Nenhum dragao encontrado");
	else{
		printf("O codigo do dragao eh: %d\n", dragon->codigo);
        printf("Sua idade eh: %d\n", dragon->idade);
        printf("Seu elemento eh: %s\n", dragon->elemento);
        printf("Seu valor eh: %f\n", dragon->valor);
        printf("Seu estoque eh: %d\n", dragon->unidade);
        free(dragon);
	}
}

void funcaoExcluirDragao()
{
    listarDragoes();
    int codigo;
    printf("Digite o codigo do dragao que deseja APAGAR: ");
	scanf("%d", &codigo);
	if (ApagarDragaoPeloCodigo(codigo)==1)
		printf("Dragao APAGADO com sucesso!\n");
	else
		printf("Falha ao apagar o dragao!\n");
}

void alterarDragoes()
{
	int i, opcao, r, mudancaInt;
	char mudanca[30];
	listarDragoes();
	int codigo;
	printf("Digite o codigo do guerreiro que deseja alterar: ");
	scanf("%d", &codigo);
	

	
	do
	{
	printf("\n0 - Finalizar\n1 - Alterar nome\n2 - Alterar idade\n3 - Alterar elemento\n4 - Alterar valor\n5 - Alterar Unidades\n");
	printf("Digite a numero do que deseja alterar: ");
	scanf("%d", &opcao);
	
	if (opcao == 0)
	{
		printf("Finalizado!\n");
		break;
	}
	else if (opcao == 1)
	{
		printf("Digite o novo nome: ");
		fflush(stdin);
		scanf("%[^\n]s", mudanca);
		r = atualizarDragao(0, mudanca, 30, 1, codigo);
	}
	else if (opcao == 2)
	{
		printf("Digite a nova idade: ");
		scanf("%d", mudancaInt);
		r = atualizarDragao(mudancaInt, mudanca, 30, 2, codigo);
	}
	else if (opcao == 3)
	{
		listarElementos();
		printf("Digite o codigo do novo elemento: ");
		scanf("%d", mudancaInt);
		r = atualizarDragao(mudancaInt, mudanca, 30, 3, codigo);
	}
	else if (opcao == 4)
	{
		printf("Digite o novo valor: ");
		scanf("%d", mudancaInt);
		r = atualizarDragao(mudancaInt, mudanca, 30, 3, codigo);
	}
	else if (opcao == 5)
	{
		printf("Digite o novo estoque: ");
		scanf("%d", mudancaInt);
		r = atualizarDragao(mudancaInt, mudanca, 30, 3, codigo);
	}
	else printf("Numero invalido!n");
	
			
	} while (opcao != 0);
		
}

//ELEMENTOS



void funcaoCadastroElemento()
{
    Elemento element;
    

	element.codigo = QuantidadeElementos() + 1;

	fflush(stdin);
	printf("Digite o nome do elemento: ");
    scanf("%[^\n]s", element.nome);

	fflush(stdin);
    printf("Digite a vulnerabilidade do elemento: ");
    scanf("%[^\n]s", element.vulnerabilidade);

    if (salvarElemento(element) == 1)
        printf("Elemento cadastrado com sucesso!\n");
    else
        printf("Falha ao cadastrar elemento!\n");
}

void funcaoPesquisarElemento()
{
    char procurado[30];
    int i;

    fflush(stdin);
    printf("Digite o nome do elemento : ");
	scanf("%[^\n]s", procurado);
    for (i = 0; i < QuantidadeElementos(); i++)
    {
        Elemento element = obterElementoPeloIndice(i);
        if (strcmpi(procurado, element.nome));
        {
            printf("Elemento encontrado na posicao %d\n", i);
            printf("Sua vulnerabilidade eh: %s\n", element.vulnerabilidade);
            printf("Seu codigo eh: %d\n", element.codigo);
            break;
        }
    }
}

void funcaoExcluirElemento()
{
    listarElementos();
    int codigo;
    printf("Digite o codigo do elemento  que deseja APAGAR: ");
	scanf("%d", &codigo);
	if (ApagarElementoPeloCodigo(codigo)==1)
		printf("Elemento APAGADO com sucesso!\n");
	else
		printf("Falha ao apagar o elemento !\n");
}


//LOCACOES

void listarLocacoes()
{
	int i;

    
    for (i = 0; i < QuantidadeLocacoes(); i++)
    {
        Locacao location = obterLocacaoPeloIndice(i);
        if (location.codigoLocacao > 0)		
            printf("\n%d - %s, locado por: %s\n\n",
            location.codigoLocacao, location.nomeDragaoLocado, location.nomeGuerreiroLocador);
    }
    if (QuantidadeLocacoes() == 0)
    {
        printf("NENHUMA LOCACAO REALIZADA\n");
    }
}

void funcaoRealizarLocacao()
{
	int opcao, i;
    Locacao location;
    int quantidade;
    Guerreiro warrior;
    Dragao dragon;
	
	location.codigoLocacao = QuantidadeLocacoes() + 1;
	
	listarGuerreiros();
	printf("Digite o codigo do guerreiro: ");
    scanf("%d", &location.codigoGuerreiroLocador);

    for (i = 0; i < retornaTamanhoLocacoes(); i++)
    {
        Guerreiro* warrior = obterGuerreiroPeloIndice(i);
        if (location.codigoGuerreiroLocador == warrior->codigo)
        {
            strcpy(location.nomeGuerreiroLocador, warrior->nome);
            break;
        }
    }
	listarDragoes();
    printf("Digite o codigo do dragao: ");
    scanf("%d", &location.codigoDragaoLocado);
    for (i = 0; i < retornaTamanhoLocacoes(); i++)
    {
        Dragao* dragon = obterDragaoPeloIndice(i);
        if (location.codigoDragaoLocado == dragon->codigo && dragon->checarLocacao == 0)
        {
            strcpy(location.nomeDragaoLocado, dragon->nome);
            dragon->checarLocacao = 1;
            while (opcao != 0)
		    {
		    	int r = 0;
			    printf("Digite quantos dragoes quer locar: ");
			    scanf("%d", &quantidade);
			    if (quantidade > 0)
			    for (i = 0; i < 8; i++)
			    	{
			    		if (dragon->unidadeAnterior[i] == 0)
			    		dragon->unidadeAnterior[i] = dragon->unidade;
					}
			    	r = diminuirEstoque(quantidade);
			    	
				
			    if (r == 1)
			    {
			    	break;
				}
		    	else printf("Quantidade maior do que o que esta disponivel ou igual a/menor do que zero\n");
			}
            break;
        }
    }
    

    if (salvarLocacao(location) == 1)
        printf("Locacao realizada com sucesso!\n");
    else
        printf("Falha ao realizar locacao!\n");
}

void funcaoDevolverDragao()
{
    listarLocacoes();
    int codigo, r;
    printf("Digite o codigo da locacao que quer devolver: ");
	scanf("%d", &codigo);
	if (ApagarLocacaoPeloCodigo(codigo) == 1)
		printf("Locacao devolvida com sucesso!\n");
	else
		printf("Falha ao devolver a locacao !\n");
}


//MENUS	
	
void menuPrincipal()
{
	printf("0 - Sair\n1 - Guerreiros\n2 - Dragoes\n3 - Elementos de dragoes\n4 - Locacoes\n\n");
}
void subMenuGuerreiro()
{
	printf("0 - Sair\n1 - Cadastrar\n2 - Pesquisar\n3 - Excluir\n4 - Listar Guerreiros\n5 - Alterar guerreiro\n\n");
}

void subMenuDragao()
{
	printf("0 - Sair\n1 - Cadastrar\n2 - Pesquisar\n3 - Excluir\n4 - Listar Dragoes\n5 - Alterar dragao\n\n");
}

void subMenuElemento()
{
	printf("0 - Sair\n1 - Cadastrar\n2 - Pesquisar\n3 - Excluir\n4 - Listar Elementos\n5 - Alterar elemento\n\n");	
}

void subMenuLocacao()
{
	printf("0 - Sair\n1 - Locar Dragao\n2 - Listar Locacoes\n3 - Devolver\n5 - Alterar locacao\n\n");	
}

int main(int argc, char *argv[]){
	int opcao;
	//horario do sistema
	struct tm *tempo;
	time_t segundos;
	time(&segundos); 
	tempo = localtime(&segundos);  
	printf("%d/%d/%d\n", tempo->tm_mday, tempo->tm_mon+1, tempo->tm_year+1900);

	inicializarGuerreiros();
	inicializarDragoes();
	inicializarElementos();
	inicializarLocacoes();
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
        	while (opcao != 0)
        	{
	        		
				subMenuGuerreiro();
				scanf("%d", &opcao);
				
	            if (opcao == 0){}
	
				else if (opcao == 1)
					funcaoCadastroGuerreiro();
				else if (opcao == 2)
	            {
					funcaoPesquisarGuerreiro();
	            }
				else if (opcao == 3)
	            {
					funcaoExcluirGuerreiro();
	            }
	            else if (opcao == 4)
	            {
	                listarGuerreiros();
	            }
	            else if (opcao == 5)
	            {
	            	alterarGuerreiros();
				}
				else
					printf("Opcao invalida");
			}
			opcao = 1;
			
        }
        
        if (opcao == 2)// Dragoes
        {
        	while (opcao != 0)
        	{
	        	subMenuDragao();
				scanf("%d", &opcao);
				
	            if (opcao == 0){}
	
				else if (opcao == 1)
					funcaoCadastroDragao();
				else if (opcao == 2)
	            {
					funcaoPesquisarDragao();
	            }
				else if (opcao == 3)
	            {
					funcaoExcluirDragao();
	            }
	            else if (opcao == 4)
	            {
	                listarDragoes();
	            }
				else if (opcao == 5)
				{
					alterarDragoes();
				}
				else
					printf("Opcao invalida");
			}
			opcao = 1;
		}

        if (opcao == 3)// Elementos
        {
        	while (opcao != 0)
        	{
	        	subMenuElemento();
				scanf("%d", &opcao);
				
	            if (opcao == 0){}
	
				else if (opcao == 1)
					funcaoCadastroElemento();
				else if (opcao == 2)
	            {
					listarLocacoes();
	            }
				else if (opcao == 3)
	            {
					funcaoExcluirElemento();
	            }
	            else if (opcao == 4)
	            {
	                listarElementos();
	            }
				else
					printf("Opcao invalida");
			}
			opcao = 1;
		}
		
        if (opcao == 4)// Locacoes
        {
        	while (opcao != 0)
        	{
	        	subMenuLocacao();
				scanf("%d", &opcao);
				
	            if (opcao == 0){}
	
				else if (opcao == 1)
					funcaoRealizarLocacao();
				else if (opcao == 2)
	            {
					listarLocacoes();
	            }
				else if (opcao == 3)
	            {
					funcaoDevolverDragao();
	            }
				else
					printf("Opcao invalida");
			}
		}
		
		opcao = 1;
    } while(opcao != 0);

}
