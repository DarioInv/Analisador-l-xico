#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <bits/stdc++.h>

using namespace std;
typedef struct token
{
	int classe;
	char valor[100];
	int pLinha;
	int resultC;
	int resultA;
	int resultP;

} token;

char c;
int linha = 1;
int iniLexema = 0;
int fimLexema = 0;
char *vetor;

char arquivo(char *nArquivo)
{
	FILE *arquivo;
	char letra;
	int colum = 0;
	int aux = 0;

	if ((arquivo = fopen(nArquivo, "r")) == NULL)
	{
		cout << "Erro... Reveja o path" << endl;
	}

	//ler caracter do arquivo pra alocação dinamica do vetor segundo pesquisas
	while ((letra = getc(arquivo)) != EOF)
	{
		colum++;
	}

	vetor = new char[colum];

	for (int i = 0; i < colum; i++)
		vetor[i] = NULL;

	rewind(arquivo);

	while ((letra = getc(arquivo)) != EOF)
	{
		vetor[aux] = letra;
		aux++;
	}
	vetor[colum] = '\0';

	fclose(arquivo);
}
char ProximoCaracter()
{
	c = vetor[fimLexema++];
	if (c == '\n')
		linha++;

	return c;
}