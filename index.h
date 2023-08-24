#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<iostream>

#define MaxTam 100

using namespace std;

int menu_inicial(){
    printf("\t\tMENU DE OPCOES\n");
    printf("\n1. Modulo da logistica (grafo nao direcionado)");
    printf("\n2. Modulo do jogo (grafo direcionado)");
    printf("\n3. Sair do programa\n\n");
    printf("Escolha uma opcao: ");
}

void startGraf(float mat[MaxTam][MaxTam])
{
    for (int i = 0; i < MaxTam; i++)
    {
        for (int j = 0; j < MaxTam; j++)
        {
            mat[i][j] = 0;
        }
    }
}