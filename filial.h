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
    int andaFiliais = 0;
    char filiais[MAX_LOCATIONS][MAX_LOCATIONS];
    int andaCustos = 0;
    int custo[MAX_LOCATIONS];//matrizAdjacencia
    int grafo[MAX_LOCATIONS];
    int andaGrafo = 0;
};

bool localExiste(const struct Filial* filial, const char* nomeLocal) {
    for (int i = 0; i < filial->andaFiliais; ++i) {
        if (strcmp(filial->filiais[i], nomeLocal) == 0) {
            return true;
        }
    }
    return false;
}

void insereFilial(struct Filial* filial, const char* cidade)
{
    // Numero de filiais atingidos?
    if (filial->andaFiliais >= MAX_LOCATIONS) { 
        cout << "Limite de filiais atingido!!!" << endl;
        return;
    }

    // Local existe?
    if (localExiste(filial, cidade)) {
        cout << "Local '" << cidade << "' já existe no filial. Insira um nome único." << endl;
        return;
    }

    // Copia o nome do novo local para a matriz de filiais no filial
    strcpy(filial->filiais[filial->andaFiliais], cidade);
    cout << "Filial '" << filial->filiais[filial->andaFiliais] << "' inserido com sucesso." << endl;
    filial->andaFiliais++;
}

void insereMovimentacao(struct Filial* filial, const char* filial_um, const char* filial_dois)
{
    int i1 = -1, i2 = -1;
    for (int i = 0; i < filial->andaFiliais; i++)
    {
        if (strcmp(filial->filiais[i], filial_um))
        {
            i1 = i;
            filial->grafo[filial->andaGrafo] = i;
            filial->andaGrafo++;
        }
            
        if (strcmp(filial->filiais[i], filial_dois))
        {
            i2 = i;
            filial->grafo[filial->andaGrafo] = i;
            filial->andaGrafo++;
        }
    }
    if (i1 == -1 || i2 == -1)
    {
        cout << "Filial(is) não encontrada(s)" <<endl;
        return;
    }
    cout << "Custo da viagem entre filiais: ";
        cin >> filial->custo[filial->andaCustos];
        filial->andaCustos++;
}

void listaFiliaisProximas(struct Filial* filial, const char* pFilial)
{
    if (!localExiste(filial, pFilial))
    {
        cout << "Filial nao cadastrada!"<<endl;
        return;
    }
    
    for (int i = 0; i < filial->andaGrafo; i = i+2)
    {
        if (strcmp(filial->filiais[i], pFilial) == 0 || strcmp(filial->filiais[i+1], pFilial) == 0)
            cout << "As filias, "<< filial->filiais[i] << " e " << filial->filiais[i+1] << " estao proximas"<<endl;
    }
}

void atualizaMovimentacao(struct Filial* filial, const char* filial_um, const char* filial_dois)
{
    int i1 = -1, i2 = -1;
    for (int i = 0; i < filial->andaFiliais; i++)
    {
        if (strcmp(filial->filiais[i], filial_um))
        {
            i1 = i;
        }
            
        if (strcmp(filial->filiais[i], filial_dois))
        {
            i2 = i;
        }
    }
    if (i1 == -1 || i2 == -1)
    {
        cout << "Filial(is) não encontrada(s)" <<endl;
        return;
    }
    for (int i = 0; i < filial->andaGrafo; i = i+2)
    {
        if (strcmp(filial->filiais[i], filial_um) == 0 || strcmp(filial->filiais[i+1], filial_um) == 0)
        {
        }
        if (strcmp(filial->filiais[i], filial_dois) == 0 || strcmp(filial->filiais[i+1], filial_dois) == 0)
        {
        }
    }
    
}

void removeFilial(struct Filial* filial, const char* eFilial)
{
    int i1 = -1, i2 = -1;
    for (int i = 0; i < filial->andaFiliais; i++)
    {
        if (strcmp(filial->filiais[i], eFilial))
        {
            i1 = i;
        }
    }

}

void executarMenuFilial(struct Filial* filial)
{
    vector<string> cdd;
    int op;
        do
        {
        cout << "\t\tMENU LOGISTICA\n"<<endl;
        cout << "1. Insere filial"<<endl;
        cout << "2. Insere movimentacao"<<endl;
        cout << "3. Lista filiais proximas"<<endl;
        cout << "4. Atualiza movimentacao"<<endl;
        cout << "5. Remover filial"<<endl;
        cout << "6. Voltar para o menu principal"<<endl;
        cout << "0. Sair do programa"<<endl;
        cout << "Insira sua escolha: ";
            cin >> op;

        switch (op)
        {
        case 1:
            char nFilial[100];
            while (true) {
                cout << "\nDigite o nome do novo local ou 'sair' para sair: ";
                cin >> nFilial;
                if (strcmp(nFilial, "sair") == 0){
                    break;  
                }


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
            char pFilial[100];
            cout << "Digite a cidade da filial: ";
                cin >> pFilial;
            listaFiliaisProximas(filial, pFilial);
            break;
        case 4:

            break;
        case 5:
            char eFilial[100];
            cout <<"Digite a cidades das duas filiais:"<<endl;
                cin >> cfilial1;
                cin >> cfilail2;
            removeFilial(filial, eFilial);
            break;
        default:
            break;
        }
    } while (op != 0);
    
    
}