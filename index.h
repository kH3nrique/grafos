#include<stdio.h>
#include<string>
#include<iostream>
#include<stdlib.h>

#define MaxTam 100

using namespace std;

//
int menuPrincipal(){
    system("cls");
    int op;
    cout << "\t\tMENU DE OPCOES"<<endl;;
    cout << "\n1. Modulo da logistica (grafo nao direcionado)"<<endl;;
    cout << "2. Modulo do jogo (grafo direcionado)"<<endl;;
    cout << "3. Sair do programa\n"<<endl;;
    cout << "Escolha uma opcao: "<<endl;;
        cin >> op;
    return op;
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
        cin >> op;
    return op;
}

int menu_jogo(){
    system("cls");
    int op;
    cout << "\t\tMENU LOGISTICA\n"<<endl;;
    cout << "1. Insere local do jogo: "<<endl;;
    cout << "2. Insere Tempo: "<<endl;;
    cout << "3. Lista locais destino: "<<endl;;
    cout << "4. Lista locais origem: "<<endl;;
    cout << "5. Atualiza tempo: "<<endl;;
    cout << "6. Remove Tempo: "<<endl;;
    cout << "7. Calcula tempo de locais: "<<endl;;
    cout << "\n8. Voltar para o menu principal: "<<endl;;
        cin >> op;
    return op;
}

int opcoes_menulogistica();
int opcoes_menujogo();

int chamaMenu()
{
    switch (menuPrincipal())
    {
    case 1:
        menu_logistica();
        opcoes_menulogistica();
        break;
    case 2:
        menu_jogo();
        opcoes_menujogo();
        break;
    default:
        break;
    }
}

int opcoes_menulogistica(){
    int op;
    switch (op) {
    case 5:
        chamaMenu();
        break;
    default:
        break;
    }
}

int opcoes_menujogo(){
    int op;
    switch (op) {
    case 8:
        chamaMenu();
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