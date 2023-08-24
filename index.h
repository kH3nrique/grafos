#include <iostream>
#include <string>
#define MaxTam 100

using namespace std;

int menuPrincipal()
{
    int op;
    cout << "\t\tMENU DE OPCOES\n" <<endl;
    cout << "1. Modulo da logistica (grafo nao direcionado)\n2. Modulo do jogo (grafo direcionado)\n3. Sair do programa\n"<<endl;
    cout << "Escolha a opcao desejada: ";
        cin >> op;
        
    return op; 
}

void inicializaGrafo(float mat[MaxTam][MaxTam])
{
    for (int i = 0; i < MaxTam; i++)
    {
        for (int j = 0; j < MaxTam; j++)
        {
            mat[i][j] = 0;
        }
    }
}