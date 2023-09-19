#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <cstring>
#include <vector>
#include "jogo.h"

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
    return op;
}

struct Jogo{
    int numLocais;
    char locais[MaxTam][100];
    int matrizAdjacencia[MaxTam][MaxTam];
};

void executarMenu(struct Jogo* jogo);

void switchMenu(){
    struct Jogo jogo;

    bool lmao = true;
    while(lmao){
        switch (menuPrincipal()) {
            case 1:
                //Coloca aqui henrique
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