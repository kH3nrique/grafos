#ifndef FILIAL_H
#define FILIAL_H

#include <cstdio>
#include <cstdlib>
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

bool localExiste(const struct Filial* filial, const char* nomeLocal) {
    for (int i = 0; i < filial->numLocais; ++i) {
        if (strcmp(filial->locais[i], nomeLocal) == 0) {
            return true;
        }
    }
    return false;
}

void insereFilial(struct Filial* filial, const char* nomeLocal)
{
    // Numero de locais atingidos?
    if (filial->numLocais >= MAX_LOCATIONS) { 
        cout << "Limite de locais atingido. Não é possível adicionar mais locais." << endl;
        return;
    }

    // Local existe?
    if (localExiste(filial, nomeLocal)) {
        cout << "Local '" << nomeLocal << "' já existe no filial. Insira um nome único." << endl;
        return;
    }

    // Copia o nome do novo local para a matriz de locais no filial
    strcpy(filial->locais[filial->numLocais], nomeLocal);
    
    int novoIndice = filial->numLocais++;

    cout << "Local '" << nomeLocal << "' inserido com sucesso." << endl;
}

void excutarMenuFilial(struct Filial* filial)
{
    vector<string> cdd;
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

<<<<<<< Updated upstream
    switch (op)
    {
    case 1:
        char nFilial[100];
        while (true) {
                    cout << "\nDigite o nome do novo local ou 'sair' para sair: ";
                    cin >> nFilial;

                    if (strcmp(nFilial, "sair") == 0) {
                        break; 
                    }
                    insereFilial(filial, nFilial);
                    cdd.push_back(nFilial); // Adiciona o nome da cidade ao vetor
                }
        break;
    
    default:
        break;
    }
}
=======
}

#endif
>>>>>>> Stashed changes
