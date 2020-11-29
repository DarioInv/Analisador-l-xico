#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <bits/stdc++.h>

using namespace std;

void R_Token()
{
	token t;
	do
		{
		 t = ProximoToken();
		//   switch (t.classe)
		// {
		// 	case 0: cout << "Classe = " << "to" << endl; break;
		// 	case 1: cout << "Classe = " << "if" << endl; break;
		// 	case 2: cout << "Classe = " << "step" << endl; break;
		// 	case 3: cout << "Classe = " << "else" << endl; break;
		// 	case 4: cout << "Classe = " << "num" << endl; break;
		// 	case 5: cout << "Classe = " << "string" << endl; break;
		// 	case 6: cout << "Classe = " << "print" << endl; break;
		// 	case 7: cout << "Classe = " << "read" << endl; break;
		// 	case 8: cout << "Classe = " << "return" << endl; break;
		// 	case 9: cout << "Classe = " << "for" << endl; break;
		// 	case 10: cout << "Classe = " << "sqrt" << endl; break;
		// 	case 11: cout << "Classe = " << "+" << endl; break;
		// 	case 12: cout << "Classe = " << "-" << endl; break;
		// 	case 13: cout << "Classe = " << "*" << endl; break;
		// 	case 14: cout << "Classe = " << "/" << endl; break;
		// 	case 15: cout << "Classe = " << "=" << endl; break;
		// 	case 16: cout << "Classe = " << "<" << endl; break;
		// 	case 17: cout << "Classe = " << ">" << endl; break;
		// 	case 18: cout << "Classe = " << "(" << endl; break;
		// 	case 19: cout << "Classe = " << ")" << endl; break;
		// 	case 20: cout << "Classe = " << ":" << endl; break;
		// 	case 21: cout << "Classe = " << "%" << endl; break;
		// 	case 22: cout << "Classe = " << "," << endl; break;
		// 	case 23: cout << "Classe = " << "{" << endl; break;
		// 	case 24: cout << "Classe = " << "}" << endl; break;
		// 	case 25: cout << "Classe = " << "Numeros" << endl; break;
		// 	case 26: cout << "Classe = " << "Identificadores" << endl; break;
		// 	case 27: cout << "Classe = " << "Final" << endl; break;
		// 	case 28: cout << "Classe = " << "ASPAS" << endl; break;
		// 	case 29: cout << "Erro" << "" << endl; break;
		// }
		if(t.classe == 29){
		cout << "erro"<<endl;
        cout << "Lexema = " << t.valor << endl;
		cout << "Linha = " << t.pLinha << endl;
		cout << endl;
		} else if(t.classe == 28){
			cout<<"Final"<<endl;
			cout<<"arquivo ok"<<endl;
		}
		// cout << "Lexema = " << t.valor << endl;
		// cout << "Linha = " << t.pLinha << endl;
		// cout << endl;
		
	} while (t.classe != 28);
	// if(t.resultA = 1 && t.resultC = 1 && t.resultP = 1){
	// 	cout << " Arquivo OK " << endl;
	// }
	if(t.resultA=0){
		cout<<"erro linha " << primAspa<<endl;
	} 
	if(t.resultC=0){
		cout<<"erro linha " << primChave<<endl;
	} 
	if(t.resultP=0){
		cout<<"erro linha " << primParentese<<endl;
	}
	
	cout << endl;
	delete[] vetor;
}