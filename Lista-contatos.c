#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

/*Lista de contatos*/

struct cadastroContato{
	char nome[50];
	char numero[50];
};

struct cadastroContato contato[50];

char continuar, nome[50], numero[50];
int escolha=0, cont=-1;
FILE *pont_teste;


int main(){
	int i=cont, retorno;
	int contLista=cont;
	char testestring[50];
	setlocale(LC_ALL, "Portuguese");
	do{
		system("cls");
		printf ("::::::::::Menu::::::::::");
		printf ("\nlista de contatos (1)\nPesquisar contato (2)\nCadastra contato (3)\nDeletar (4)\nSair (0)\n");
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:{
				system("cls");
					printf("\n::::::::::Contatos::::::::::\n");
					pont_teste = fopen("Agenda.txt", "r");
					if (pont_teste != NULL){
						while(fgets(testestring, 50, pont_teste) != NULL)
							printf("%s", testestring);	
					}
					
					else{
						printf("\nNenhum contato cadastrado\n");
					}
				fclose(pont_teste);
				system("pause");
			break;}
			
			case 2:{
				if (cont < 0){
					printf("::::::::::Pesquisar Contato::::::::::\n");
					printf("Nenhum Contato Cadastrado\n");
					system("pause");
				}
				
				else{
					system("cls");
					printf("::::::::::Pesquisar Contato::::::::::\n");
					printf("\nDigite o nome ou o número:");
					fflush(stdin);
					gets(nome);
					for(i=cont;i>=0;i--){
							retorno = strcmp(nome, contato[i].nome);
						if(retorno == 0){
							printf("\nNome:%s", contato[i].nome);
							printf("\nTelefone:%s\n", contato[i].numero);
						}
					}
					
					for(i=cont;i>=0;i--){
							retorno = strcmp(nome, contato[i].numero);
						if(retorno == 0){
							printf("\nNome:%s", contato[i].nome);
							printf("\nTelefone:%s\n", contato[i].numero);
						}
					}
						
					
					
					
		
				}
				system("pause");
			break;}
			
			case 3:{
				system("cls");
				do{
					cont++;
					printf("::::::::::Cadastra Contato::::::::::");
					printf("\nNome do contato:");
					do{
						pont_teste = fopen ("Agenda.txt", "a");
						fflush(stdin);
						gets(nome);
					}while(tamanho(nome) == 0);
		
					for(i=cont;i >= 0;i--){
						retorno = strcmp(nome, contato[i].nome);
							if (retorno == 0){
								printf("\nContato existente");
								printf("\nNome:%s",contato[i].nome);
								printf("\nNúmero:%s\n",contato[i].numero);
								cont--;
								system("pause");
								break;
							}
					}		
		
					if (retorno != 0){
						strcpy (contato[cont].nome, nome);
						fprintf(pont_teste, "Nome: %s", contato[cont].nome);
					}
		
					if (retorno != 0){
						printf("Numero:");
						do{
							fflush(stdin);
							gets(numero);
						}while(tamanho(numero) == 0);
					
					for(i=cont;i >= 0;i--){
						retorno = strcmp(numero, contato[i].numero);
						if (retorno == 0){
							printf("\nContato existente");
							printf("\nNome:%s",contato[i].nome);
							printf("\nNúmero:%s\n",contato[i].numero);
							cont--;
							system("pause");
							break;
						}
					}		
		
					if (retorno != 0){
						strcpy (contato[cont].numero, numero);
						fprintf(pont_teste,"\nNúmero: %s", contato[cont].numero);
						fprintf(pont_teste,"\n------------------------------------\n");
					}
					}
					
					
					printf("\nDeseja continuar? s/n");
					continuar=toupper(getche());
						if (continuar == 'N'){
							fclose(pont_teste);
							break;
						} 
		system("cls");
	}while(1);
			break;}
			
			case 4:{
				system("cls");
				printf("\nQual contato deseja remover?");
				do{
						fflush(stdin);
						gets(nome);
						tamanho(nome);
				}while(tamanho(nome) == 0);
				//Por que eu tive que trocar os printfs de posição?
				if (deletar2(nome, &contato) == 0)
					printf("Contato não encontrado!\n");
				else
					printf("Contato removido!\n");
				system("pause");
			break;}
		}
	}while(escolha != 0);
	return(0);
}

int tamanho(char *tamanho){
	int retorno;
	
	retorno = strlen(tamanho);
	return retorno;
}

int igualNome(char *nome){
	int i=cont, retorno;
	for(i=cont;i>=0;i--)
			retorno = strcmp(nome, contato[i].nome);
	return retorno;
}

int igualNumero(char *numero){
	int i=cont, retorno;
	for(i=cont;i>=0;i--)
			retorno = strcmp(nome, contato[i].numero);
	return retorno;
}

int deletar(char *nome){
	int i, j, achou=0;
	
	for(i=0;i<=cont;i++){
		if(strcmp(contato[i].nome,nome)==0){
			achou=1;
			for(j=i;j<cont;j++)
				contato[i]=contato[i+1];
		}
	}
	cont--;
	return achou;
}

int deletar2(char *nome, struct cadastroContato *vet){
	int i, j, achou=0;
	
	for(i=0;i<=cont;i++){
		if(strcmp(vet[i].nome,nome)==0){
			achou=1;
			for(j=i;j<cont;j++)
				vet[i]=vet[i+1];
		}
	}
	cont--;
	return achou;
}

int linha(){
	printf("\n------------------------------------\n");
}
