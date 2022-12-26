#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "Bibliotecas\\devTools.h"
#include "Bibliotecas\\struct.h"

int validador(char *tamanho){
	int retorno;
	
	retorno = strlen(tamanho);
	return retorno;
}

int main(){
	tcontato contato[50];
	
	int tamanho=-1, escolha, retorno;
	char soun, indice[50];
	
	setlocale(LC_ALL, "Portuguese");
	
	do{
		system("cls");
		printf ("::::::::::Menu::::::::::");
		printf("\n1-Cadastra contato\n2-lista de contatos\n3-Pesquisar contato\n4-Deletar\n0-Sair");
		scanf("%d", &escolha);
		switch (escolha){
			case 1:{
				while(1){
					tamanho++;
					system("cls");
					printf("::::::::::Cadastra Contato::::::::::");
					printf("\nDigite o Nome do contato:");
					do{
						scanf("%s", &indice);
					}while(validador(indice) == 0);
					
					indice[0]=toupper(indice[0]);
					retorno=pesquisaStr(tamanho,indice,contato[tamanho].nome);
					
					if(retorno != -1){
						printf("\nContato já cadastrado");
						printf("\nNome:%s", contato[retorno].nome);
						printf("\nNúmero:%s\n", contato[retorno].numero);
						system("pause");
					}
					
					else strcpy(contato[tamanho].nome, indice);
					
					
					printf("\nDigite o Número do contato:");
					do{
						scanf("%s", &indice);
					}while(validador(indice) == 0);
					
					retorno=pesquisaStr(tamanho,indice,contato[tamanho].numero);
					
					if(retorno != -1){
						printf("\nContato já cadastrado");
						printf("\nNome:%s", contato[retorno].nome);
						printf("\nNúmero:%s\n", contato[retorno].numero);
						system("pause");
					}
					
					else strcpy(contato[tamanho].numero, indice);
						
					printf("\nDeseja continuar? S/N");
					soun=toupper(getche());
					if (soun == 'N') break;
				}
			break;}
		
			case 2:{
				system("cls");
				printf("::::::::::Lista de Contatos::::::::::");
				for(int i=0;i<=tamanho;i++){
					printf("\nNome:%s", contato[i].nome);
					printf("\nNúmero:%s", contato[i].numero);
					linha(30,1);
				}
				getch();
			break;}
			
			case 3:{
				system("cls");
				printf("::::::::::Pesquisar Contato::::::::::");
				if(tamanho <0){
					printf("\nNenhum contato cadastrado");
					getch();
					break;
				}
				
				else{
					printf("\nPesquisar Por");
					printf("\n1-Nome\n2-Número");
					scanf("%d", &escolha);
					if(escolha==1){
						printf("\nDigite o nome:");
						scanf("%s", &indice);
						indice[0]=toupper(indice[0]);
						for(int i=0;i<tamanho;i++)
							retorno=pesquisaStr(tamanho, indice, contato[i].nome);
					}
					
					else if(escolha==2){
						printf("\nDigite o número:");
						scanf("%s", &indice);
						for(int i=0;i<tamanho;i++)
							retorno=pesquisaStr(tamanho, indice, contato[i].numero);
							
					}
					
					if(retorno != -1){
						printf("\nNome:%s", contato[retorno].nome);
						printf("\nNúmero:%s", contato[retorno].numero);
						system("pause");
						getch();
					}
					
					else{
						printf("\nContato não encontrado");
						getch();
					}
				}
				
			break;}
		
			case 4:{
				system("cls");
				printf("::::::::::Deletar contato::::::::::");
				printf("\nRemover por");
				printf("\n1-Nome\n2-Número");
				scanf("%d", &escolha);
				if(escolha == 1){
					printf("\nDigite o nome:");
					do{
						fflush(stdin);
						gets(indice);
						validador(indice);
					}while(validador(indice) == 0);
					
					indice[0]=toupper(indice[0]);
					
					for(int i=0;i<=tamanho;i++){
						pesquisaStr(tamanho, indice, contato[i].nome);
						tamanho=deletarstc(contato,tamanho,i);
					}
				}
				
				else if(escolha == 2){
					printf("\nDigite o número:");
					do{
						fflush(stdin);
						gets(indice);
						validador(indice);
					}while(validador(indice) == 0);
					
					indice[0]=toupper(indice[0]);
					
					for(int i=0;i<=tamanho;i++){
						pesquisaStr(tamanho, indice, contato[i].numero);
						tamanho=deletarstc(contato,tamanho,i);
					}
				}
			break;}
		}
		
	}while(escolha != 0);	
}
