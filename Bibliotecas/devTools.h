/*Biblioteca feita por Dyego dos Anjos Cordeiro*/
/*versão 3.0 ajustes em nomes*/


void linha(int tamanho, int quantidade){
	while(quantidade>0){
		printf("\n");
		for(int i=0;i<tamanho;i++)
			printf("-");
		
		quantidade--;
	}
}

int pesquisaStr(int tamanho, char *indice, char *valor){
	for(int i=0;i<=tamanho;i++){
		if(strcmp(indice, valor)==0)
			return i;
	}
	
	return -1;
}

int pesquisaInt(int tamanho, int indice, int valor){
	for(int i=0;i<=tamanho;i++){
		if(valor == indice)
			return i;
	}
	
	return -1;
}

int pesquisaFloat(int tamanho, float indice, float valor){
	for(int i=0;i<=tamanho;i++){
		if(valor == indice)
			return i;
	}
	
	return -1;
}
