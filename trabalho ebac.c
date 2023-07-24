#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>// Bioblioteca de aloca��o  de espa�o na mem�ria
#include <locale.h>// Biblioteca de texto por regi�o
#include <string.h>// Biblioteca por cuidar da regi�o

int registro()// Fun��o responsavel por registrar usu�rio no sistema
{
	// In�cio da cria��o das variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da cria��o de variaveis
	
	printf("Digite o seu cpf para cadastro:");// coletando informa��o do usu�rio
	scanf("%s", cpf);// %s responsavel por armazernar a string
	
	strcpy(arquivo, cpf);// Copiar os valores das strings

	FILE*file;// criar arquivos
	file = fopen(arquivo, "w");// criar arquivos e "w" significa escrever
	fprintf(file,"CPF:");
	fprintf(file,cpf);// Salva os valores da variavel
	fclose(file);// Fechar cria��o de arquivos

	file = fopen(arquivo, "a");// Atualiza o arquivo e "A" significa atualizar
	fprintf(file,"\nNome:");// Separa as inform��es por v�rgula
	fclose(file);// Fecha os arquivos 
	
	printf("Digite o nome pra cadastrar:");// coletando informa��o do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);// Atualiza o arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome:");
	fclose(file);
	
	printf("Digite o sobrenome pra cadastrar:");// coletando informa��o do usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo:");
	fclose(file);
	
	printf("Digite o cargo pra cadastrar:");// coletando informa��o do usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);
	
	system("pause");//Pausar o sistema pro usu�rio pensar em que fazer
	
	
	
}

int consulta()// Fun��o responsavel por consultar inform��es do usu�rio
{
	setlocale(LC_ALL, "portuguese");// Responsavel pelo texto de cada regi�o
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf que deseja consultar: \n");// coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	FILE*file;
	file = fopen(cpf,"r");// responsavel por ler arquivo e "R" significa ler
	
	if(file == NULL)// reponsavel por informar o usu�rio
	{
		printf("nao foi possivel acessar, n�o localizado!\n");
	}
	
	printf("Essa s�o as inform��es do usu�rio:\n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	system("pause");// Pausa o sistema
	
}

int deletar()// Responsavel por deletar o usu�rio
{
	char cpf[40];
	
	printf("Digite o cpf do us�rio deseja deletar:\n");// coletando informa��o do usu�rio
	scanf("%s",cpf);

		
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)// Difere caso n�o ache o usu�rio
	{
		fclose(file);
		printf("O usu�rio n�o encontrado\n");//  Informa o usu�rio
		system("pause");// Pausa o sistema
	}
	
	if(file != NULL)// Informa a exclusas�o
	{
		fclose(file);
		remove(cpf);// remove a informa��o
		printf("O usu�rio foi deletado com sucesso.\n");
		system("pause ");
	}
	
}
int main()
{
	int escolha=0;// Define as variaveis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		system("cls");// Limpa a tela
		
		setlocale(LC_ALL, "portuguese");// Define a liguagem
	
		printf("CARTORIO DA EBAC \n\n");// In�cio do menu
		printf("Escolha uma das op��o:\n\n");
		printf("\t1 - inserir nomes \n");
		printf("\t2 - consultar nomes \n");
		printf("\t3 - deletar nomes \n");
		printf("\t4 - sair do menu\n\n ");
		printf("op��es:");// Fim do menu
	
		scanf("%d", &escolha);// Armazena a escolha do usu�rio
	
		system("cls");
		
	    switch(escolha)// Inicio da sele��o do Menu
		{
		    case 1:
			registro();
			break;
		
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("obrigado por utilizar o sistema!\n");
			return 0;
			break;
		
			default:
			printf("Essa op��o n�o est� disponivel \n");
			system("pause");
			break;
			
		}// fim da sele��o
	}
}// fim do c�digo
