#include "index.h"

int q_filial;

void InseriFilial()
{
    string filial;
}

void menuLogistica()
{
    int n;
    cout << "1. Inserir filial" <<endl;
    cout << "2. Remover filial" <<endl;
        cin >> n;
    switch (n)
    {
    case 1:
        break;
    
    default:
        break;
    }
}

int pesquisaFilial(string filiais[50], string filial)
{
    int i;
    for (int i = 0; i < q_filial; i++)
    {
        if(filiais[i] == filial)
            break;
    }
    if (i == q_filial)
        return -1;
    else
        return i;
    
}