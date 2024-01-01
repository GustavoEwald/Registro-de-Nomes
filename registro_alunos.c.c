#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> //gerencia as strings

void limpa_buffer() //Função utilizada no código para limpar caracteres indesejados salvos na memoria
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
	char confirmacao[5]; //string que verificará a confirmação dos dados digitados pelo usuário
		
		
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
					
		do //Solicita a verificação, aceitando como resposta 'S', 's', 'n', 'N' ou strings começadas por estas. 
		{
			limpa_buffer();
			printf("\nConfirmar os Dados Inseridos? (s/n) ");	
			scanf("%c", &confirmacao);
			
		}while(confirmacao[0] != 's' && confirmacao[0] != 'S' && confirmacao[0] != 'n' && confirmacao[0] != 'N');
			
		if(confirmacao[0] == 's' || confirmacao[0] == 'S') //Verifica se o usuário confirmou as informações (ou não)
		{
			break;
		}
		limpa_buffer();
		system("cls");
	}while(1); //Permaneceremos no loop até que o comando break seja acionado, isto é, até que o usuário esteja satisfeito com os dados
				
		strcpy(arquivo, cpf); //copia strings
		FILE *file; //para criar um arquivo txt
		file = fopen(arquivo, "w"); // Foi feita a opção por escrever apenas uma vez no arquivo em vez de abri-lo e fecha-lo 
		fprintf(file, strcat(cpf, ",")); //Concatenação da vírgula após "cpf", "nome" e "sobrenome"
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
		printf("CPF não localizado\n");
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
		printf("CPF não cadastrado!\n\n");
	}
	fclose(file);
	
	if(remove(cpf)==0)
	{
		printf("Registro removido com sucesso!\n\n");
	}
	else
	{
		printf("Erro! Não foi possivel remover o registro.\n\n");
	}
			
}

int main(){ 
	setlocale(LC_ALL, "Portuguese"); //Setando a localidade do texto para Portugues, permitindo acentos, "ç" ...
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
		printf("Selecione a Opção Desejada:\n\n");
		printf("\t1. Inserir Novo Aluno\n");
		printf("\t2. Consultar Aluno\n");
		printf("\t3. Deletar um Registro\n");
		printf("\t4. Sair\n\n");
		
		printf("Opção: ");
		scanf("%c", &opcao); //Seleção no menu por char em vez de int
		
		
		
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
			printf("Opção Inválida\n\n");
		}
		
		if(laco==1)	// O sistema só será pausado e limpo se o usuário não optar por sair do programa
		{
			system("pause");
			system("cls");
			limpa_buffer();
		}
	}
}
