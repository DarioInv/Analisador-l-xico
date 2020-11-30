#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "lexico.h"
#include "token.h"

using namespace std;
void imprimir(int tipoErro, char vetorErro[100], int linhaErro);
void arqSaida(){
	FILE *arq;
	arq = fopen("ArqResult2.txt", "w");
	fclose(arq);
}
int main(){
	arquivo("Arquivo de entrada 2.txt");

	arqSaida();
	R_Token();
	
	return 0;
}