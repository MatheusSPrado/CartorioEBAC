#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca de string

int registrar(){ //função responsavel por cadastrar os usuários
	
	setlocale(LC_ALL, "Portuguese");
	
	//inicio da criaçâo das variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); //%s = refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria um novo arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //o "a" atualiza o arquivo existente
	fprintf(file, ","); //a "," coloca uma virgula dentro do arquivo existente
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	printf("\nUsuário cadastrado com sucesso!\n\n");
	
	system("pause");
}

int consultar(){ //função responsavel por consultar os usuários
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da criaçâo das variaveis/string
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //o "r" significa lê o arquivo
	
	if(file == NULL){
		printf("\nNão foi possível localizar o CPF digitado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){ //função responsavel por deletar os usuários
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF que deseja excluir do sistema: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("\nO usuário não existe!\n\n");
		system("pause");
	}
	
	else{
		fclose(file);
		remove(cpf);
		printf("\nUsuário removido com sucesso!\n\n");
		system("pause");
	}
}




int main(){ //função principal, responsavel pelas telas 

	int opcao=0; //Definindo variaveis
	int x=1;
	char senhadigitada[] = "a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0){
	
		for(x=1;x=1;){ //Inicio do laço de repetição
			
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
			printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: ");
			
			scanf("%d", &opcao); //Fim do menu
			
			system("cls"); //Troca de tela
			
			switch(opcao){ //Inicio da seleção
				case 1:
				registrar();
				break;
				
				case 2:
				consultar();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por usar o sistema!");
				return 0;
				break;
				
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;	
			} //Fim da seleção
			
		} //Fim do laço de repetição
	}
		else
		printf("Senha errada!");
}
