#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lista{
	int chave;
	struct lista *prox;
};

typedef struct lista Lista;

Lista * criaNo(int chave){
	Lista *aux;
	aux = (Lista*) malloc(sizeof(Lista));
	aux->chave = chave;
	aux->prox = NULL;

	return aux;
}

Lista * lerArquivo(char nomeDoArquivo[]){
	FILE *fp;
	int num_int;//número de inteiros que possue o arquivo
	int chave;
	int i;
	Lista *inteiros,*aux;

	fp = fopen(nomeDoArquivo,"r");
	fscanf(fp,"%d\n",&num_int); //le o primeiro inteiro do arquivo que é o número de chaves no arquivo

	if(num_int > 1){
		fscanf(fp,"%d\n",&chave);
		inteiros = criaNo(chave);
		aux = inteiros;
		for(i=1; i<num_int ; i++){
			fscanf(fp,"%d\n",&chave);
			aux->prox = criaNo(chave);
			aux = aux->prox;
		}
	}

	fclose(fp);
	return inteiros;
	
}

void imprimeLista(Lista *lista){
	Lista *aux;
	aux = lista;

	while(aux != NULL){
		printf("%d\n",aux->chave);
		aux = aux->prox;
	}
}

int main(int argc,char *arqv[]){//arqv[1] = nome do arquivo passado na execução do programa no terminal do linux	
	Lista *inteiros;
	inteiros = lerArquivo(arqv[1]);
	imprimeLista(inteiros);
	return 0;
}
