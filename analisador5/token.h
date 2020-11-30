#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <conio.h>

using namespace std;
int erro = 0;
void arqsaida();
void imprimir(int tipoErro, char vetorErro[100], int linhaErro){
	FILE *arq;
	arq = fopen("ArqResult2.txt", "a");
	if(arq == NULL){
		printf("Problema na criação de Arquivo\n");
		return;
	}
	
	switch (tipoErro)
	{
		case 0:
			fprintf(arq,"Arquivo OK");
			break;
		case 1:
			fprintf(arq,"Erro 'Parentese' linha = %d \n",linhaErro);
			break;
		case 2:
			fprintf(arq,"Erro 'Chaves' linha = %d \n",linhaErro);
			break;
		case 3:
			fprintf(arq,"Erro 'Aspas' linha = %d \n",linhaErro);
			break;
		case 4:
			fprintf(arq,"Erro Palavra '%s' Não esta definido. esta na linha = %d \n",vetorErro,linhaErro);
			break;
	}

	fclose(arq);
}

void R_Token()
{
	
	token t;
	int contC = 0;
	int contA = 0; 
	int contP = 0;
	int primC = 0; 
	int primA = 0;
	int primP = 0;
	int j = 0;
	
	do
	{
		t = ProximoToken();
		switch (t.classe)
		{
			case 0:	//cout << "Classe = "	 << "to" << endl; 
				break;
			case 1://	cout << "Classe = "  << "if" << endl;	
				break;
			case 2:	//cout << "Classe = "	 << "step" << endl;	
				break;
			case 3:	//cout << "Classe = "	 << "else" << endl;	
				break;
			case 4:	//cout << "Classe = "	 << "num" << endl;	
				break;
			case 5:	//cout << "Classe = "	 << "string" << endl;	
				break;
			case 6:	//cout << "Classe = "	 << "print" << endl;	
				break;
			case 7:	//cout << "Classe = "	 << "read" << endl;	
				break;
			case 8:	//cout << "Classe = "	 << "return" << endl;	
				break;
			case 9:	//cout << "Classe = "	 << "for" << endl;	
				break;
			case 10: //cout << "Classe = "	<< "sqrt" << endl;
				break;
			case 11: //cout << "Classe = "<< "+" << endl;	
				break;
			case 12: //cout << "Classe = "<< "-" << endl;	
				break;
			case 13: //cout << "Classe = "<< "*" << endl;	
				break;
			case 14: //cout << "Classe = "<< "/" << endl;	
				break;
			case 15: //cout << "Classe = "<< "=" << endl;	
				break;
			case 16: //cout << "Classe = " << "<" << endl;	
				break;
			case 17: //cout << "Classe = " << ">" << endl;	
				break;
			case 18:
				contP++;
				//cout << "Classe = " << "(" << endl;
				break;
			case 19:
				contP++;
				//cout << "Classe = " << ")" << endl;
				break;
			case 20: //cout << "Classe = "<< ":" << endl;	
				break;
			case 21: //cout << "Classe = "<< "%" << endl;	
				break;
			case 22: //cout << "Classe = "<< "," << endl;	
				break;
			case 23:
				contC++;
				//cout << "Classe = "	 << "{" << endl;
				break;
			case 24:
				contC++;
				//cout << "Classe = "	 << "}" << endl;
				break;
			case 25: //cout << "Classe = "<< "Numeros" << endl;	
				break;
			case 26: 
				//cout << "Classe = "<< "Identificadores"<< endl;
				break;
			case 27:
				contA = contA + 2;	
				//cout << "Classe = "	 << "ASPAS" << endl;
				break;
			case 28: 
				contA++;
				//cout << "Classe = "<< "ASPAS" << endl;	
				break;
			case 29: //cout << "Classe = "<< "Break" << endl;	
				break;
			case 30: //cout << "Classe = "<< "Final" << endl;	
				break;
			case 31: 
				cout << "Erro"	<< "" << endl;	
				break;
		}
		// coletar o primeiro de cada um, chaves, parenteses, aspas
		if(t.classe == 18){
			if (primP == 0)
			{
				primP = t.pLinha;
			}
		}
		if(t.classe == 23){
			if (primC == 0)
			{
				primC = t.pLinha;
			}
		}
		if(t.classe == 27){
			if (primA == 0)
			{
				primA = t.pLinha;
			}
		}else if(t.classe == 28){
			if (primA == 0)
			{
				primA = t.pLinha;
				primA--;
			}
		}	 
		// cout << "Lexema = " << t.valor << endl;
		// cout << "Linha = " << t.pLinha << endl;
		cout << endl;
	} while (t.classe != 30);

	if (contP % 2 == 1)
	{
		cout << "error linha = " << primP << endl;
		cout << "Parentese" << endl;
		erro = 1;
		imprimir(erro,0,primP);
		
	}
	if (contC % 2 == 1)
	{
		cout << "error linha = " << primC << endl;
		cout << "Chaves" << endl;
		erro = 2;
		imprimir(erro,0,primC);
		
	}
	if (contA % 2 == 1)
	{
		cout << "error linha = " << primA << endl;
		cout << "Aspas" << endl;
		erro = 3;
		imprimir(erro,0,primA);
	 }
	else {
		cout << "Arquivo ok "<< endl;
		erro = 0;
		imprimir(erro,0,0);
	}
	// cout << aux[0] << endl;
	// cout << aux[1] << endl;
	// cout << aux[2] << endl;
	
	delete[] vetor;
}