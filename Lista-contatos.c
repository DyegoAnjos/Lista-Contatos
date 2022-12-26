#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "Bibliotecas\\devTools.h"

/*Lista de contatos*/

struct cadastroContato{
	char nome[50];
	char numero[50];
};

struct cadastroContato contato[50];

char continuar, nome[50], numero[50];
int escolha=0, cont=-1;

int tamanho(char *tamanho){
	int retorno;
	
	retorno = strlen(tamanho);
	return retorno;
}

//int igualNome(char *nome){
//	int i=cont, retorno;
//	for(i=cont;i>=0;i--)
//			retorno = strcmp(nome, contato[i].nome);
//	return retorno;
//}

//int igualNumero(char *numero){
//	int i=cont, retorno;
//	for(i=cont;i>=0;i--)
//			retorno = strcmp(nome, contato[i].numero);
//	return retorno;
//}

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

//int linha(){
//	printf("\n------------------------------------\n");
//}

int main(){
	int i=cont, retorno;
	int contLista=cont;
	setlocale(LC_ALL, "Portuguese");
	do{
		system("cls");
		printf ("::::::::::Menu::::::::::");
		printf ("\nlista de contatos (1)\nPesquisar contato (2)\nCadastra contato (3)\nDeletar (4)\nSair (0)\n");
		scanf("%d", &escolha);
		
		switch(escolha){
			
			
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


