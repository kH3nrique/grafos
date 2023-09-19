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
    int nFiliais;
    char locais[MAX_LOCATIONS][MAX_LOCATIONS];
    int tempo[MAX_LOCATIONS][MAX_LOCATIONS];//matrizAdjacencia
};

bool localExiste(const struct Filial* filial, const char* nomeLocal) {
    for (int i = 0; i < filial->nFiliais; ++i) {
        if (strcmp(filial->locais[i], nomeLocal) == 0) {
            return true;
        }
    }
    return false;
}

void insereFilial(struct Filial* filial, const char* nomeLocal)
{
    // Numero de locais atingidos?
    if (filial->nFiliais >= MAX_LOCATIONS) { 
        cout << "Limite de locais atingido. Não é possível adicionar mais locais." << endl;
        return;
    }

    // Local existe?
    if (localExiste(filial, nomeLocal)) {
        cout << "Local '" << nomeLocal << "' já existe no filial. Insira um nome único." << endl;
        return;
    }

    // Copia o nome do novo local para a matriz de locais no filial
    strcpy(filial->locais[filial->nFiliais], nomeLocal);
    
    int novoIndice = filial->nFiliais++;

    cout << "Local '" << nomeLocal << "' inserido com sucesso." << endl;
}

void insereMovimentacao(struct Filial* filial, const char* filial_um, const char* filial_dois)
{
    int i1 = -1, i2 = -1;
    for (int i = 0; i < filial->nFiliais; i++)
    {
        if (strcmp(filial->locais[i], filial_um))
            i1 = i;
        if (strcmp(filial->locais[i], filial_dois))
            i2 = i;
    }
    if (i1 == -1 || i2 == -1)
    {
        cout << "Filial(is) não encontrada(s)" <<endl;
        return;
    }
    cout << "Tempo de viagem entre as filiais: ";
        cin >> filial->tempo[i1][i2];
    filial->tempo[i2][i1] = filial->tempo[i1][i2];
}

void listaFiliaisProximas()
{
    
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
            if (strcmp(nFilial, "sair") == 0)
            break; 

            insereFilial(filial, nFilial);
            cdd.push_back(nFilial); // Adiciona o nome da cidade ao vetor
        }
        break;
    case 2: 
        char cfilial1[100], cfilail2[100];
        cout <<"Digite a cidades das duas filiais:"<<endl;
            cin >> cfilial1;
            cin >> cfilail2;
            insereMovimentacao(filial, cfilial1, cfilail2);
        break;
    case 3:

        break;
    default:
        break;
    }
}
=======
}

#endif
>>>>>>> Stashed changes
