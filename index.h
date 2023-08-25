#include<stdio.h>
#include<string>
#include<iostream>

#define MaxTam 100

using namespace std;

int menuPrincipal(){
    cout << "\t\tMENU DE OPCOES\n"<<endl;;
    cout << "\n1. Modulo da logistica (grafo nao direcionado)"<<endl;;
    cout << "\n2. Modulo do jogo (grafo direcionado)"<<endl;;
    cout << "\n3. Sair do programa\n\n"<<endl;;
    cout << "Escolha uma opcao: "<<endl;;
}

int menu_logistica(){
    cout << "\t\tMENU LOGISTICA\n"<<endl;;
    cout << "1. Insere filial: \n"<<endl;;
    cout << "2. Insere movimentacao: \n"<<endl;;
    cout << "3. Lista filiais proximas: \n"<<endl;;
    cout << "4. Atualiza movimentacao: \n"<<endl;;
}

int menu_jogo(){
    cout << "\t\tMENU LOGISTICA\n"<<endl;;
    cout << "1. Insere local do jogo: \n"<<endl;;
    cout << "2. Insere Tempo: \n"<<endl;;
    cout << "3. Lista locais destino: \n"<<endl;;
    cout << "4. Lista locais origem: \n"<<endl;;
    cout << "5. Atualiza tempo: \n"<<endl;;
    cout << "6. Remove Tempo: \n"<<endl;;
    cout << "7. Calcula tempo de locais: \n"<<endl;;
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