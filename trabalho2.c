#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
	int chave;
	struct Lista *prox;
}lista;

void lerArquivo(char nomeDoArquivo[]){
	FILE *fp;
	int num_int;//número de inteiros que possue o arquivo

	fp = fopen(nomeDoArquivo,"r");
	fscanf(fp,"%d\n",&num_int);
	printf("%d",num_int);
	fclose(fp);
	
}

int main(int argc,char *arqv[]){
	lerArquivo(arqv[1]);
	return 0;
}
