#include<stdio.h>
#include<string>
#include<iostream>

#define MaxTam 100

using namespace std;

int menuPrincipal(){
    int op;
    cout << "\t\tMENU DE OPCOES"<<endl;;
    cout << "\n1. Modulo da logistica (grafo nao direcionado)"<<endl;;
    cout << "2. Modulo do jogo (grafo direcionado)"<<endl;;
    cout << "3. Sair do programa\n\n"<<endl;;
    cout << "Escolha uma opcao: "<<endl;;
        cin >> op;
    return op;
}

int menu_logistica(){
    int op;
    cout << "\t\tMENU LOGISTICA\n"<<endl;;
    cout << "1. Insere filial: \n"<<endl;;
    cout << "2. Insere movimentacao: \n"<<endl;;
    cout << "3. Lista filiais proximas: \n"<<endl;;
    cout << "4. Atualiza movimentacao: \n"<<endl;;
        cin >> op;
    return op;
}

int menu_jogo(){
    int op;
    cout << "\t\tMENU LOGISTICA\n"<<endl;;
    cout << "1. Insere local do jogo: \n"<<endl;;
    cout << "2. Insere Tempo: \n"<<endl;;
    cout << "3. Lista locais destino: \n"<<endl;;
    cout << "4. Lista locais origem: \n"<<endl;;
    cout << "5. Atualiza tempo: \n"<<endl;;
    cout << "6. Remove Tempo: \n"<<endl;;
    cout << "7. Calcula tempo de locais: \n"<<endl;;
        cin >> op;
    return op;
}

void chamaMenu()
{
    switch (menuPrincipal())
    {
    case 1:
        menu_logistica();
        break;
    case 2:
        menu_jogo();
        break;
    default:
        break;
    }
}

void IniciarGrafo(float mat[MaxTam][MaxTam])
{
    for (int i = 0; i < MaxTam; i++)
    {
        for (int j = 0; j < MaxTam; j++)
        {
            mat[i][j] = 0;
        }
    }
}