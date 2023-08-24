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

int menu_logistica(){
    printf("\t\tMENU LOGISTICA\n");
    printf("1. Insere filial: \n");
    printf("2. Insere movimentacao: \n");
    printf("3. Lista filiais proximas: \n");
    printf("4. Atualiza movimentacao: \n");
}

int menu_jogo(){
    printf("\t\tMENU LOGISTICA\n");
    printf("1. Insere local do jogo: \n");
    printf("2. Insere Tempo: \n");
    printf("3. Lista locais destino: \n");
    printf("4. Lista locais origem: \n");
    printf("5. Atualiza tempo: \n");
    printf("6. Remove Tempo: \n");
    printf("7. Calcula tempo de locais: \n");
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