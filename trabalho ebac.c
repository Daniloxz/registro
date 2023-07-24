#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h>// Bioblioteca de alocação  de espaço na memória
#include <locale.h>// Biblioteca de texto por região
#include <string.h>// Biblioteca por cuidar da região

int registro()// Função responsavel por registrar usuário no sistema
{
	// Início da criação das variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da criação de variaveis
	
	printf("Digite o seu cpf para cadastro:");// coletando informação do usuário
	scanf("%s", cpf);// %s responsavel por armazernar a string
	
	strcpy(arquivo, cpf);// Copiar os valores das strings

	FILE*file;// criar arquivos
	file = fopen(arquivo, "w");// criar arquivos e "w" significa escrever
	fprintf(file,"CPF:");
	fprintf(file,cpf);// Salva os valores da variavel
	fclose(file);// Fechar criação de arquivos

	file = fopen(arquivo, "a");// Atualiza o arquivo e "A" significa atualizar
	fprintf(file,"\nNome:");// Separa as informções por vírgula
	fclose(file);// Fecha os arquivos 
	
	printf("Digite o nome pra cadastrar:");// coletando informação do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);// Atualiza o arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome:");
	fclose(file);
	
	printf("Digite o sobrenome pra cadastrar:");// coletando informação do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo:");
	fclose(file);
	
	printf("Digite o cargo pra cadastrar:");// coletando informação do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);
	
	system("pause");//Pausar o sistema pro usuário pensar em que fazer
	
	
	
}

int consulta()// Função responsavel por consultar informções do usuário
{
	setlocale(LC_ALL, "portuguese");// Responsavel pelo texto de cada região
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf que deseja consultar: \n");// coletando informação do usuário
	scanf("%s",cpf);
	
	FILE*file;
	file = fopen(cpf,"r");// responsavel por ler arquivo e "R" significa ler
	
	if(file == NULL)// reponsavel por informar o usuário
	{
		printf("nao foi possivel acessar, não localizado!\n");
	}
	
	printf("Essa são as informções do usuário:\n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	system("pause");// Pausa o sistema
	
}

int deletar()// Responsavel por deletar o usuário
{
	char cpf[40];
	
	printf("Digite o cpf do usário deseja deletar:\n");// coletando informação do usuário
	scanf("%s",cpf);

		
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)// Difere caso não ache o usuário
	{
		fclose(file);
		printf("O usuário não encontrado\n");//  Informa o usuário
		system("pause");// Pausa o sistema
	}
	
	if(file != NULL)// Informa a exclusasão
	{
		fclose(file);
		remove(cpf);// remove a informação
		printf("O usuário foi deletado com sucesso.\n");
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
	
		printf("CARTORIO DA EBAC \n\n");// Início do menu
		printf("Escolha uma das opção:\n\n");
		printf("\t1 - inserir nomes \n");
		printf("\t2 - consultar nomes \n");
		printf("\t3 - deletar nomes \n");
		printf("\t4 - sair do menu\n\n ");
		printf("opções:");// Fim do menu
	
		scanf("%d", &escolha);// Armazena a escolha do usuário
	
		system("cls");
		
	    switch(escolha)// Inicio da seleção do Menu
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
			printf("Essa opção não está disponivel \n");
			system("pause");
			break;
			
		}// fim da seleção
	}
}// fim do código
