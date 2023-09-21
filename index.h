#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <cstring>
#include <vector>
#include "jogo.h"
#include "filial.h"

#define MaxTam 100

using namespace std;

int menuPrincipal(){
    system("cls");
    int op;
    cout << "\t\tMENU DE OPCOES"<<endl;;
    cout << "\n1. Modulo da logistica (grafo nao direcionado)"<<endl;;
    cout << "2. Modulo do jogo (grafo direcionado)"<<endl;;
    cout << "0. Sair do programa\n"<<endl;;
    cout << "Escolha uma opcao: "<<endl;;
        cin >> op;
    system("cls");
    return op;
}

void executarMenu(struct Jogo* jogo);
void executarMenuFilial(struct Filial* filial);

void switchMenu(){
    struct Jogo jogo;
    struct Filial filial;

    bool lmao = true;
    while(lmao){
        switch (menuPrincipal()) {
            case 1:
                executarMenuFilial(&filial);
                break;
            case 2:
                executarMenu(&jogo);
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                return;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }
    
    
}

#endif