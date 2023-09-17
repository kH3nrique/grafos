#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include "filial.h"
#include "jogo.h"

#define MaxTam 100

using namespace std;

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
    cout << "6. Sair do programa: "<<endl;;
        cin >> op;
    return op;
}

int opcoes_menulogistica();
int opcoes_menujogo(struct Jogo* jogo);

int chamaMenu() {
    struct Jogo jogo;

    switch (menuPrincipal()) {
    case 1:
        menu_logistica();
        opcoes_menulogistica();
        break;
    case 2:
        executarMenu(&jogo);
        break;
    default:
        break;
    }
}


int opcoes_menulogistica(){
    int op;
    switch (op) {
    case 1:
        break;
    case 5:
        chamaMenu();
        break;
    case 6:
        break;
    default:
        break;
    }
}


void IniciarGrafo(float mat[MaxTam][MaxTam]) {
    for (int i = 0; i < MaxTam; i++)
    {
        for (int j = 0; j < MaxTam; j++)
        {
            mat[i][j] = 0;
        }
    }
}