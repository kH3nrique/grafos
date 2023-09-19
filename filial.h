#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <vector> 

#define MAX_LOCATIONS 100

using namespace std;

struct Filial
{
    int numLocais;
    char locais[MAX_LOCATIONS][100];
    int mat[MAX_LOCATIONS][MAX_LOCATIONS];//matrizAdjacencia
};

void IniciarGrafo(float mat[MAX_LOCATIONS][MAX_LOCATIONS]) {
    for (int i = 0; i < MAX_LOCATIONS; i++)
    {
        for (int j = 0; j < MAX_LOCATIONS; j++)
        {
            mat[i][j] = 0;
        }
    }
}

void insereFilial(struct Filial* filial, const char* nomeLocal)
{

}

void excutarMenuFilial(struct Filial* filial)
{
    vector<vector>
    system("cls");
    int op;
    cout << "\t\tMENU LOGISTICA\n"<<endl;
    cout << "1. Insere filial: "<<endl;
    cout << "2. Insere movimentacao: "<<endl;
    cout << "3. Lista filiais proximas:"<<endl;
    cout << "4. Atualiza movimentacao: "<<endl;
    cout << "5. Voltar para o menu principal: "<<endl;
    cout << "0. Sair do programa: "<<endl;
        cin >> op;

    switch (op)
    {
    case 1:
        insereFilial(&filial, cdd);
        break;
    
    default:
        break;
    }
}