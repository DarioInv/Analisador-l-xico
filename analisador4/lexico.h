#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int lista_aux(char aux[], char buffer[])
{
    int i, flag = 0;
    for (i = 0; i < 30; ++i)
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
        return 11;
    case 11:
        return 16;
    case 16:
        return 20;
    case 20:
        return 27;
    case 27:
        return 33;
    case 33:
        return 38;
    case 38:
        return 45;
    case 45:
        return 49;
    case 49:
        return 54;
    case 54:
        return 56;
    case 56:
        return 58;
    case 58:
        return 60;
    case 60:
        return 62;
    case 62:
        return 64;
    case 64:
        return 66;
    case 66:
        return 68;
    case 68:
        return 70;
    case 70:
        return 72;
    case 72:
        return 74;
    case 74:
        return 76;
    case 76:
        return 78;
    case 78:
        return 80;
    case 80:
        return 82;
    case 82:
        return 85;
    case 85:
        return 88;
    case 88:
        return 92;
    case 92:
        return 95;
    case 95:
        return 96;
    default:
        return 97;
    }
}

int primAspa;
int primChave;
int primParentese;
int contaAspas;
int contaChaves;
int contaParentese;

token ProximoToken()
{
    token t;
    int p;
    int estado = 0;
    int partida = 0;
    int pos = 0;
    char aux[30], buffer[10];
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
        // to
        case 0:
            c = ProximoCaracter();
            if (c == 't')
                estado = 1;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 1:
            c = ProximoCaracter();
            if ((c == 'o') && (!islower(vetor[fimLexema])) && (!isupper(vetor[fimLexema])))
                estado = 2;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 2:
            t.classe = 0;
            strcpy(t.valor, "to");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // if
        case 3:
            c = ProximoCaracter();
            if (c == 'i')
                estado = 4;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 4:
            c = ProximoCaracter();
            if ((c == 'f') && (!islower(vetor[fimLexema])) && (isupper(vetor[fimLexema])))
                estado = 5;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 5:
            t.classe = 1;
            strcpy(t.valor, "if");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // step
        case 6:
            c = ProximoCaracter();
            if (c == 's')
                estado = 7;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 7:
            c = ProximoCaracter();
            if (c == 't')
                estado = 8;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 8:
            c = ProximoCaracter();
            if (c == 'e')
                estado = 9;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 9:
            c = ProximoCaracter();
            if ((c == 'p') && (!islower(vetor[fimLexema])) && (!isupper(vetor[fimLexema])))
                estado = 10;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 10:
            t.classe = 2;
            strcpy(t.valor, "step");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // else
        case 11:
            c = ProximoCaracter();
            if (c == 'e')
                estado = 12;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 12:
            c = ProximoCaracter();
            if (c == 'l')
                estado = 13;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 13:
            c = ProximoCaracter();
            if (c == 's')
                estado = 14;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 14:
            c = ProximoCaracter();
            if ((c == 'e') && (!islower(vetor[fimLexema])) && (!isupper(vetor[fimLexema])))
                estado = 15;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 15:
            t.classe = 3;
            strcpy(t.valor, "else");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // num
        case 16:
            c = ProximoCaracter();
            if (c == 'n')
                estado = 17;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 17:
            c = ProximoCaracter();
            if (c == 'u')
                estado = 18;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 18:
            c = ProximoCaracter();
            if ((c == 'm') && (!islower(vetor[fimLexema])) && (!isupper(vetor[fimLexema])))
                estado = 88;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 19:
            t.classe = 4;
            strcpy(t.valor, "num");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // string
        case 20:
            c = ProximoCaracter();
            if (c == 's')
                estado = 21;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 21:
            c = ProximoCaracter();
            if (c == 't')
                estado = 22;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 22:
            c = ProximoCaracter();
            if (c == 'r')
                estado = 23;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 23:
            c = ProximoCaracter();
            if (c == 'i')
                estado = 24;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 24:
            c = ProximoCaracter();
            if (c == 'n')
                estado = 25;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 25:
            c = ProximoCaracter();
            if ((c == 'g') && (!islower(vetor[fimLexema])) && (!isupper(vetor[fimLexema])))
                estado = 26;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 26:
            t.classe = 5;
            strcpy(t.valor, "string");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // print
        case 27:
            c = ProximoCaracter();
            if (c == 'p')
                estado = 28;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 28:
            c = ProximoCaracter();
            if (c == 'r')
                estado = 29;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 29:
            c = ProximoCaracter();
            if (c == 'i')
                estado = 30;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 30:
            c = ProximoCaracter();
            if (c == 'n')
                estado = 31;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 31:
            c = ProximoCaracter();
            if ((c == 't') && (!islower(vetor[fimLexema])) && (!isupper(vetor[fimLexema])))
                estado = 32;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 32:
            t.classe = 6;
            strcpy(t.valor, "print");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // read
        case 33:
            c = ProximoCaracter();
            if (c == 'r')
                estado = 34;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 34:
            c = ProximoCaracter();
            if (c == 'e')
                estado = 35;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 35:
            c = ProximoCaracter();
            if (c == 'a')
                estado = 36;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 36:
            c = ProximoCaracter();
            if ((c == 'd') && (!islower(vetor[fimLexema])) && (!isupper(vetor[fimLexema])))
                estado = 37;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 37:
            t.classe = 7;
            strcpy(t.valor, "read");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // return
        case 38:
            c = ProximoCaracter();
            if (c == 'r')
                estado = 39;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 39:
            c = ProximoCaracter();
            if (c == 'e')
                estado = 40;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 40:
            c = ProximoCaracter();
            if (c == 't')
                estado = 41;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 41:
            c = ProximoCaracter();
            if (c == 'u')
                estado = 42;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 42:
            c = ProximoCaracter();
            if (c == 'r')
                estado = 43;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 43:
            c = ProximoCaracter();
            if ((c == 'n') && (!islower(vetor[fimLexema])) && (!isupper(vetor[fimLexema])))
                estado = 44;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 44:
            t.classe = 8;
            strcpy(t.valor, "return");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        //for
        case 45:
            c = ProximoCaracter();
            if (c == 'f')
                estado = 46;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 46:
            c = ProximoCaracter();
            if (c == 'o')
                estado = 47;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 47:
            c = ProximoCaracter();
            if ((c == 'r') && (!islower(vetor[fimLexema])) && (!isupper(vetor[fimLexema])))
                estado = 48;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 48:
            t.classe = 9;
            strcpy(t.valor, "for");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // sqrt
        case 49:
            c = ProximoCaracter();
            if (c == 's')
                estado = 50;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 50:
            c = ProximoCaracter();
            if (c == 'q')
                estado = 51;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 51:
            c = ProximoCaracter();
            if (c == 'r')
                estado = 52;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 52:
            c = ProximoCaracter();
            if ((c == 't') && (!islower(vetor[fimLexema])) && (!isupper(vetor[fimLexema])))
                estado = 53;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 53:
            t.classe = 10;
            strcpy(t.valor, "sqrt");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // +
        case 54:
            c = ProximoCaracter();
            if (c == '+')
                estado = 55;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 55:
            t.classe = 11;
            strcpy(t.valor, "+");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // -
        case 56:
            c = ProximoCaracter();
            if (c == '-')
                estado = 57;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 57:
            t.classe = 12;
            strcpy(t.valor, "-");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // *
        case 58:
            c = ProximoCaracter();
            if (c == '*')
                estado = 59;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 59:
            t.classe = 13;
            strcpy(t.valor, "*");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // /
        case 60:
            c = ProximoCaracter();
            if (c == '/')
                estado = 61;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 61:
            t.classe = 14;
            strcpy(t.valor, "/");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // =
        case 62:
            c = ProximoCaracter();
            if (c == '=')
                estado = 63;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 63:
            t.classe = 15;
            strcpy(t.valor, "=");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // <
        case 64:
            c = ProximoCaracter();
            if (c == '<')
                estado = 65;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 65:
            t.classe = 16;
            strcpy(t.valor, "<");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // >
        case 66:
            c = ProximoCaracter();
            if (c == '>')
                estado = 67;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 67:
            t.classe = 17;
            strcpy(t.valor, ">");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // (
        case 68:
            c = ProximoCaracter();
            if (c == '(')
            {
                contaParentese++;
                if (primParentese == 0)
                {
                    primParentese = linha;
                }
                estado = 69;
            }
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 69:
            t.classe = 18;
            strcpy(t.valor, "(");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // )
        case 70:
            c = ProximoCaracter();
            if (c == ')')
            {
                contaParentese++;
                estado = 71;
            }
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 71:
            t.classe = 19;
            strcpy(t.valor, ")");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // :
        case 72:
            c = ProximoCaracter();
            if (c == ':')
                estado = 73;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 73:
            t.classe = 20;
            strcpy(t.valor, ":");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // %
        case 74:
            c = ProximoCaracter();
            if (c == '%')
                estado = 75;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 75:
            t.classe = 21;
            strcpy(t.valor, "%");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // ,
        case 76:
            c = ProximoCaracter();
            if (c == ',')
                estado = 77;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 77:
            estado = 0;
            iniLexema = fimLexema;
            break;
        // {
        case 78:
            c = ProximoCaracter();
            if (c == '{')
            {
                if (primChave == 0)
                {
                    primChave = linha;
                }
                contaChaves++;
                estado = 79;
            }
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 79:
            t.classe = 23;
            strcpy(t.valor, "{");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // }
        case 80:
            c = ProximoCaracter();
            if (c == '}')
            {
                contaChaves++;
                estado = 81;
            }
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 81:
            t.classe = 24;
            strcpy(t.valor, "}");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // numero
        case 82:
            c = ProximoCaracter();
            if (isdigit(c))
                estado = 83;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 83:
            c = ProximoCaracter();
            if (isdigit(c))
                estado = 83;
            else
            {
                if (c == '\n')
                    linha--;
                estado = 84;
                fimLexema--;
            }
            break;
        case 84:
            t.classe = 25;
            for (p = iniLexema; p < fimLexema; p++)
            {
                t.valor[pos] = vetor[p];
                pos++;
            }
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // identificadores
        case 85:
            c = ProximoCaracter();
            if (islower(c) || isupper(c))
                estado = 86;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 86:
            c = ProximoCaracter();
            if (islower(c) || isupper(c))
                estado = 86;
            else
            {
                if (c == '\n')
                    linha--;
                estado = 87;
                fimLexema--;
            }
            break;
        case 87:
            t.classe = 26;
            for (p = iniLexema; p < fimLexema; p++)
            {
                buffer[pos] = vetor[p];
                pos++;
            }
            if (lista_aux(aux, buffer) == 1)
            {
                t.pLinha = linha;
                iniLexema = fimLexema;
                return t;
            }
            else
            {
                estado = 94;
            }
        // guardar no vetor auxiliar
        case 88:
            c = ProximoCaracter();
            if (c == ':')
            {
                estado = 89;
            }
            else
            {
                estado = 19;
            }
        case 89:
            c = ProximoCaracter();
            if (c == ' ')
            {
                estado = 89;
            }
            if (islower(c) || isupper(c))
                estado = 90;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 90:
            c = ProximoCaracter();
            if (islower(c) || isupper(c))
                estado = 90;
            else
            {
                if (c == ',')
                {
                    estado = 91;
                }
                else if (c == '\n')
                {
                    estado = 19;
                }
            }
            break;
        case 91:
            for (p = iniLexema; p < fimLexema; p++)
            {
                aux[pos] = vetor[p];
                pos++;
            }
            aux[pos] = ',';
            estado = 89;
        // aspas
        case 92:
            c = ProximoCaracter();
            if (c == '"')
            {
                if (primAspa == 0)
                {
                    primAspa = linha;
                }
                contaAspas++;
                estado = 93;
            }
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 93:
            c = ProximoCaracter();
            if (c == '"' && vetor[iniLexema] == '"')
            {
                contaAspas++;
                estado = 94;
            }
            else
            {
                estado = 94;
            }
        case 94:
            t.classe = 27;
            strcpy(t.valor, "ASPAS");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // final
        case 95:
            c = ProximoCaracter();
            if (c == '\0')
                estado = 96;
            else
            {
                fimLexema = iniLexema;
                estado = partida = automatos(partida);
            }
            break;
        case 96:
            t.classe = 28;
            strcpy(t.valor, "FIM");
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        // erro
        case 97:
            fimLexema++;

            t.classe = 29;
            for (p = iniLexema; p < fimLexema; p++)
            {
                t.valor[pos] = vetor[p];
                pos++;
            }
            t.pLinha = linha;
            iniLexema = fimLexema;
            return t;
        }
        if (contaAspas % 2 == 0){
            t.resultA = 1;
        }else{
            t.resultA = 0;
        }
        if (contaChaves % 2 == 0){
            t.resultC = 1;
        }else{
            t.resultC = 0;
        }
        if (contaParentese % 2 == 0){
            t.resultP = 1;
        }else{
            t.resultP = 0;
        }
    }
}
