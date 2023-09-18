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

int chamaMenu() {
    struct Jogo jogo;
    struct Filial filial;
    
    switch (menuPrincipal()) {
    case 1:
        excutarMenuFilial(&filial);
        break;
    case 2:
        executarMenuJogo(&jogo);
        break;
    default:
        break;
    }
}