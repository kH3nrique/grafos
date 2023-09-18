#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <vector> 

#define MaxTam 100

using namespace std;

struct Filial
{
    /* data */
};

void IniciarGrafo(float mat[MaxTam][MaxTam]) {
    for (int i = 0; i < MaxTam; i++)
    {
        for (int j = 0; j < MaxTam; j++)
        {
            mat[i][j] = 0;
        }
    }
}

int menu_logistica(){
    system("cls");
    int op;
    cout << "\t\tMENU LOGISTICA\n"<<endl;;
    cout << "1. Insere filial: "<<endl;;
    cout << "2. Insere movimentacao: "<<endl;;
    cout << "3. Lista filiais proximas:"<<endl;;
    cout << "4. Atualiza movimentacao: "<<endl;;
    cout << "\n5. Voltar para o menu principal: "<<endl;;
    cout << "6. Sair do programa: "<<endl;;
        cin >> op;
    return op;
}

int excutarMenuFilial(struct Filial* filial)
{

}