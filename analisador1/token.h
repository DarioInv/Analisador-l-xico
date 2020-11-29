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
	t = ProximoToken();
	if (t.contaAspas % 2 == 0)
	{
		cout << "Arquivo OK" << endl;
	}
	else
	{
		cout << "erro linha= " << t.primAspas;
	}
	if (t.contaChaves % 2 == 0)
	{
		cout << "Arquivo OK" << endl;
	}
	else
	{
		cout << "erro linha= " << t.primChaves;
	}
	if (t.contaParentese % 2 == 0)
	{
		cout << "Arquivo OK" << endl;
	}
	else
	{
		cout << "erro linha = " << t.primParenteses;
	}
	cout << endl;
	delete[] vetor;
}