#include "index.h"

void InseriFilial()
{
    int cont = 1;
    string filial[cont++];
    cin >> filial[cont--];
    int i=0;
    cout << filial[i] <<endl;
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
        InseriFilial();
        break;
    
    default:
        break;
    }
}