#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int lista_simb(char buffer[])
{
	char keywords[11][10] = {"for", "step", "sqrt", "if", "else", "return", "print", "read", "to", "num", "string"};
	int i, flag = 0;
	for (i = 0; i < 11; ++i)
	{
		if (strcmp(keywords[i], buffer) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int lista_aux(char buffer[], char aux[])
{
	int i, flag = 0;
	for (i = 0; i < 3; ++i)
	{
		if (strcmp(aux, buffer) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

int automatos(int &partida)
{
	switch (partida)
	{
	case 0:
		return 3;
	case 3:
		return 6;
	case 6:
		return 8;
	case 8:
		return 11;
	case 11:
		return 13;
	case 13:
		return 15;
	case 15:
		return 17;
	case 17:
		return 19;
	case 19:
		return 20;
	default:
		return 91;
	}
}

int primAspa = 0;
int primChave = 0;
int primParentese = 0;
int contaAspas = 0;
int contaChaves = 0;
int contaParentese = 0;

token ProximoToken()
{
	token t;
	int p;
	int estado = 0;
	int partida = 0;
	int pos = 0;
	char aux[3], buffer[10], outros[] = ",;(){}[]'':%+-*/=><";
	int j = 0;
	int i;

	for (p = 0; p < 100; p++)
	{
		t.valor[p] = NULL;
	}
	while (1)
	{
		switch (estado)
		{

		// numero
		case 0:
			c = ProximoCaracter();
			if (isdigit(c))
				estado = 1;
			else
			{
				fimLexema = iniLexema;
				estado = partida = automatos(partida);
			}
			break;
		case 1:
			c = ProximoCaracter();
			if (isdigit(c))
				estado = 1;
			else
			{
				if (c == '\n')
					linha--;
				estado = 2;
				fimLexema--;
			}
			break;
		case 2:
			t.classe = 1;
			for (p = iniLexema; p < fimLexema; p++)
            {
                t.valor[pos] = vetor[p];
                pos++;
            }
			t.pLinha = linha;
			iniLexema = fimLexema;
			return t;
		// identificadores
		case 3:
			c = ProximoCaracter();
			if (isalnum(c))
				estado = 4;
			else
			{
				fimLexema = iniLexema;
				estado = partida = automatos(partida);
			}
			break;
		case 4:
			c = ProximoCaracter();
			if (isalnum(c))
				estado = 4;
			else
			{
				if (c == '\n' || c == ' ' || c == ':')
					linha--;
				estado = 5;
				fimLexema--;
			}
			break;
		case 5:
			for (p = iniLexema; p < fimLexema; p++)
			{
				buffer[pos] = vetor[p];
				pos++;
			}
			if (lista_simb(buffer) == 1)
			{
				t.classe = 2;
				t.pLinha = linha;
				iniLexema = fimLexema;
				return t;
			}
			else if (linha == 1)
			{
				pos = 0;
				do
				{
					j++;
					aux[j] = buffer[pos];
					pos++;
				} while (buffer[pos] != '\0');
				aux[j] = ' ';
			}
			else if (lista_aux(buffer, aux) == 1)
			{
				t.classe = 2;
				t.pLinha = linha;
				iniLexema = fimLexema;
				return t;
			}
			else
			{
				estado = 91;
			}
		// final
		case 6:
			c = ProximoCaracter();
			if (c == '\0')
				estado = 7;
			else
			{
				fimLexema = iniLexema;
				estado = partida = automatos(partida);
			}
			break;
		case 7:
			t.classe = 3;
			strcpy(t.valor, "FIM");
			t.pLinha = linha;
			iniLexema = fimLexema;
			return t;
		// entre aspas
		case 8:
			c = ProximoCaracter();
			if (c == '"')
			{
				contA++;
				if (t.primAspas == 0)
				{
					t.primAspas = linha;
				}
				estado = 9;
			}
			else
			{
				fimLexema = iniLexema;
				estado = partida = automatos(partida);
			}
			break;
		case 9:
			c = ProximoCaracter();
			if (c == '"' && vetor[iniLexema] == '"')
			{
				contA++;
				estado = 10;
			}
			else
			{
				estado = 10;
			}
			break;
		case 10:
			t.classe = 4;
			strcpy(t.valor, "ASPAS");
			t.contaAspas = contA;
			t.pLinha = linha;
			iniLexema = fimLexema;
			return t;
		// chaves
		case 11:
			c = ProximoCaracter();
			if (c == '{')
			{
				contC++;
				if (t.primChaves == 0)
				{
					t.primChaves = linha;
				}
				estado = 12;
			}
			else
			{
				fimLexema = iniLexema;
				estado = partida = automatos(partida);
			}
			break;
		case 12:
			t.classe = 5;
			strcpy(t.valor, "{");
			t.contaChaves = contC;
			t.pLinha = linha;
			iniLexema = fimLexema;
			return t;
		case 13:
			c = ProximoCaracter();
			if (c == '}')
			{
				contC++;
				estado = 14;
			}
			else
			{
				fimLexema = iniLexema;
				estado = partida = automatos(partida);
			}
			break;
		case 14:
			t.classe = 6;
			strcpy(t.valor, "}");
			t.contaChaves = contC;
			t.pLinha = linha;
			iniLexema = fimLexema;
			return t;
		//parenteses
		case 15:
			c = ProximoCaracter();
			if (c == '(')
			{
				contP++;
				if (t.primParenteses == 0)
				{
					t.primParenteses = linha;
				}
				estado = 16;
			}
			else
			{
				fimLexema = iniLexema;
				estado = partida = automatos(partida);
			}
			break;
		case 16:
			t.classe = 7;
			strcpy(t.valor, "(");
			t.contaParentese = contP;
			t.pLinha = linha;
			iniLexema = fimLexema;
			return t;
		case 17:
			c = ProximoCaracter();
			if (c == ')')
			{
				contP++;
				estado = 18;
			}
			else
			{
				fimLexema = iniLexema;
				estado = partida = automatos(partida);
			}
			break;
		case 18:
			t.classe = 8;
			strcpy(t.valor, ")");
			t.contaParentese = contP;
			t.pLinha = linha;
			iniLexema = fimLexema;
			return t;
		//caracteres no vetor outros
		case 19:
			c = ProximoCaracter();
			if (c == outros[i])
			{
				estado = 20;
			}
			else
			{
				estado = 91;
			}
			break;
		case 20:
			t.classe = 9;
			t.pLinha = linha;
			iniLexema = fimLexema;
			return t;
		// erro
		case 91:
			fimLexema++;

			t.classe = 10;
			for (p = iniLexema; p < fimLexema; p++)
			{
				t.valor[pos] = vetor[p];
				pos++;
			}
			t.pLinha = linha;
			iniLexema = fimLexema;
			return t;
		}
	}
}