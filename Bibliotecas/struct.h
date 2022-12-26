/*Biblioteca feita por Dyego dos Anjos Cordeiro*/
/*versão 2.0 ajustes em nomes*/
//A bilioteca "struct.h" usa struct como parâmetros, será necessário adiconar a struct usada e mudar o tipo da struct nas funções

typedef struct tContato{
		char nome[50];
		char numero[50];
}tcontato;

int deletarstc(tcontato *Struct, int tamanho, int deletar){
	for(int i=deletar;i<=tamanho;i++){
		Struct[i]=Struct[i+1];
	}
	tamanho--;
	return tamanho;
}
