#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> //gerencia as strings

void limpa_buffer() //Fun��o utilizada no c�digo para limpar caracteres indesejados salvos na memoria
{
	while(getchar() != '\n')
	{
	}
}

int registrar()
{
	setlocale(LC_ALL, "Portuguese");
	char arquivo[40];
	char nome[40];
	char sobrenome[40];
	char cpf[40];
	char cargo[40];
	char confirmacao[5]; //string que verificar� a confirma��o dos dados digitados pelo usu�rio
		
		
	do
	{
		printf("Digite o CPF: ");
		scanf("%s", cpf);
		printf("Digite o Nome: ");
		scanf("%s", nome);
		printf("Digite o Sobrenome: ");
		scanf("%s", sobrenome);
		printf("Digite o Cargo: ");
		scanf("%s", cargo);
					
		do //Solicita a verifica��o, aceitando como resposta 'S', 's', 'n', 'N' ou strings come�adas por estas. 
		{
			limpa_buffer();
			printf("\nConfirmar os Dados Inseridos? (s/n) ");	
			scanf("%c", &confirmacao);
			
		}while(confirmacao[0] != 's' && confirmacao[0] != 'S' && confirmacao[0] != 'n' && confirmacao[0] != 'N');
			
		if(confirmacao[0] == 's' || confirmacao[0] == 'S') //Verifica se o usu�rio confirmou as informa��es (ou n�o)
		{
			break;
		}
		limpa_buffer();
		system("cls");
	}while(1); //Permaneceremos no loop at� que o comando break seja acionado, isto �, at� que o usu�rio esteja satisfeito com os dados
				
		strcpy(arquivo, cpf); //copia strings
		FILE *file; //para criar um arquivo txt
		file = fopen(arquivo, "w"); // Foi feita a op��o por escrever apenas uma vez no arquivo em vez de abri-lo e fecha-lo 
		fprintf(file, strcat(cpf, ",")); //Concatena��o da v�rgula ap�s "cpf", "nome" e "sobrenome"
		fprintf(file, strcat(nome, ","));
		fprintf(file, strcat(sobrenome, ","));
		fprintf(file, cargo);
		fclose(file); // fechando o arquivo
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	int c; 
	int pos = 1;
	char dado[4][12] = {"CPF: ", "Nome: ", "Sobrenome: ", "Cargo: "};
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF n�o localizado\n");
		return;
	}
	
	system("cls");
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("---Dados do Registro---\n");
	}
	
	printf("%s", dado[0]);
	for(c=0; c<200;c++)
	{
		if(conteudo[c] == '\0')
		{
			break;
		}
		if(conteudo[c] == ',')
		{
			printf("\n%s", dado[pos]);
			pos++;
			continue;
		}
		printf("%c", conteudo[c]);
	}
	fclose(file);
	printf("\n\n");
}

int deletar()
{
	
	char cpf[40];
	char arq[40];
	
	printf("Digite o CPF do registro a ser deletado: ");
	scanf("%s", cpf);
			
	FILE *file;
	file = fopen(cpf, "r");
	if(file == NULL)
	{
		printf("CPF n�o cadastrado!\n\n");
	}
	fclose(file);
	
	if(remove(cpf)==0)
	{
		printf("Registro removido com sucesso!\n\n");
	}
	else
	{
		printf("Erro! N�o foi possivel remover o registro.\n\n");
	}
			
}

int main(){ 
	setlocale(LC_ALL, "Portuguese"); //Setando a localidade do texto para Portugues, permitindo acentos, "�" ...
	char opcao;
	int laco;
	char senha[20];
	int a;
	
	while(a!=0){
		printf("--------Registro de Alunos--------\n");
		printf("Administrador\n");
		printf("Digite sua senha: ");
		scanf("%s20", senha);
		a=strcmp(senha, "AdminPass");
		limpa_buffer();
		system("cls");
	}
	
	laco = 1;
	while(laco==1)
	{
	
		printf("--------Registro de Alunos--------\n\n");
		printf("Selecione a Op��o Desejada:\n\n");
		printf("\t1. Inserir Novo Aluno\n");
		printf("\t2. Consultar Aluno\n");
		printf("\t3. Deletar um Registro\n");
		printf("\t4. Sair\n\n");
		
		printf("Op��o: ");
		scanf("%c", &opcao); //Sele��o no menu por char em vez de int
		
		
		
		switch(opcao){
			case '1':
			system("cls");
			registrar();
			break;
			
			case '2':
			system("cls");
			consulta();
			break;
			
			case '3':
			system("cls");
			deletar();
			break;
			
			case '4':
			laco = 0; // Atribuimos valor 0 para que o laco seja interrompido
			break;
			
			default:
			printf("Op��o Inv�lida\n\n");
		}
		
		if(laco==1)	// O sistema s� ser� pausado e limpo se o usu�rio n�o optar por sair do programa
		{
			system("pause");
			system("cls");
			limpa_buffer();
		}
	}
}
