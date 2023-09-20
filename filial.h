#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <vector> 

#define MAX_LOCATIONS 100

using namespace std;

struct Filial
{
    char filiais[MAX_LOCATIONS][MAX_LOCATIONS];//matrizAdjacencia
        int andaFiliais = 0;
    float custo[MAX_LOCATIONS];
        int andaCustos = 0;
    int grafo[MAX_LOCATIONS];
       int andaGrafo = 0;
};

bool localExiste(const struct Filial* filial, const char* nomeLocal) {
    for (int i = 0; i < filial->andaFiliais; ++i) {
        if (strcmp(filial->filiais[i], nomeLocal) == 0) {
            return true;
        }
    }
    return false;
}

/*
reserva uma linha e uma coluna na matriz de adjacência, referente ao módulo de logística, para
representar uma eventual informação sobre os custos de movimentação de carga com as demais filiais;
◦ A filial deverá ser inserida pelo nome;
◦ O programa deverá verificar se a filial já está inserida e, caso positivo, retornar uma mensagem de erro.
*/
void insereFilial(struct Filial* filial, const char* cidade)
{
    // Numero de filiais atingidos?
    if (filial->andaFiliais >= MAX_LOCATIONS) { 
        cout << "Limite de filiais atingido!!!" << endl;
        return;
    }
    // Local existe?
    if (localExiste(filial, cidade)) {
        cout << "Local '" << cidade << "' já existe no filial. Insira um nome único." << endl;
        return;
    }
    // Copia o nome do novo local para a matriz de filiais no filial
    strcpy(filial->filiais[filial->andaFiliais], cidade);
    cout << "Filial '" << filial->filiais[filial->andaFiliais] << "' inserido com sucesso." << endl;
    filial->andaFiliais++;
}

/*
insere um custo (em reais) relacionado à movimentação de produtos entre duas filiais i e j;
◦ As filiais deverão estar previamente inseridas no grafo. Caso contrário, retornar uma mensagem de erro para
o usuário.
◦ Importante: deverão ser listados os nomes das filiais para que o usuário se guie na escolha;
◦ Caso uma eventual movimentação de produtos já esteja inserida, deve-se oferecer a opção de atualizar o custo
entre as filiais selecionadas.
*/
void insereMovimentacao(struct Filial* filial, const char* filial_um, const char* filial_dois)
{
    int i1 = -1, i2 = -1;
    for (int i = 0; i < filial->andaFiliais; i++)
    {
        if (strcmp(filial->filiais[i], filial_um) == 0)
        {
            i1 = i;
            filial->grafo[filial->andaGrafo] = i;
            filial->andaGrafo++;
        }
            
        if (strcmp(filial->filiais[i], filial_dois) == 0)
        {
            i2 = i;
            filial->grafo[filial->andaGrafo] = i;
            filial->andaGrafo++;
        }
    }
    if (i1 == -1 || i2 == -1)
    {
        cout << "Filial(is) não encontrada(s)" <<endl;
        return;
    }
    cout << "Custo da viagem entre filiais: ";
        cin >> filial->custo[filial->andaCustos];
        filial->andaCustos++;
}

/*
após o usuário escolher uma filial hipotética i, o programa deverá listar todas as filiais j
para as quais exista alguma movimentação (i,j) de mercadoria cadastrada, inclusive com os custos de
movimentação para cada uma delas;
*/
void listaFiliaisProximas(struct Filial* filial, const char* pFilial)
{
    if (!localExiste(filial, pFilial))
    {
        cout << "Filial nao cadastrada!"<<endl;
        return;
    }
    
    for (int i = 0; i < filial->andaGrafo; i = i+2)
    {
        if (strcmp(filial->filiais[i], pFilial) == 0 || strcmp(filial->filiais[i+1], pFilial) == 0)
            cout << "As filias, "<< filial->filiais[i] << " e " << filial->filiais[i+1] << " estao proximas"<<endl;
    }
}

/*
ocorre similarmente à inserção de eventuais movimentações de carga no módulo da
logística, porém, nesse caso, a movimentação deverá estar previamente inserida na matriz de pesos que representa
esse módulo;
◦ Caso a movimentação entre duas filiais i e j não esteja inserida, deve-se oferecer essa opção ao usuário;
◦ Na eventualidade de alguma das cidades envolvidas na operação, ou ainda as duas, não esteja(m) inseridas,
deverá ser oferecida essa opção ao usuário.
*/
void atualizaMovimentacao(struct Filial* filial, const char* filial_um, const char* filial_dois)
{
    int i1 = -1, i2 = -1;
    for (int i = 0; i < filial->andaFiliais; i++)
    {
        if (strcmp(filial->filiais[i], filial_um))
        {
            i1 = i;
        }
            
        if (strcmp(filial->filiais[i], filial_dois))
        {
            i2 = i;
        }
    }
    if (i1 == -1 || i2 == -1)
    {
        cout << "Filial(is) não encontrada(s)" <<endl;
        return;
    }
    for (int i = 0; i < filial->andaGrafo; i = i+2)
    {
        if (strcmp(filial->filiais[i], filial_um) == 0 || strcmp(filial->filiais[i+1], filial_um) == 0)
        {
        }
        if (strcmp(filial->filiais[i], filial_dois) == 0 || strcmp(filial->filiais[i+1], filial_dois) == 0)
        {
        }
    }
    
}

/*
com base na informação de um nome de filial, essa função realiza a deleção dos dados de tal
filial, inclusive de todas as eventuais movimentações de carga vinculadas à essa filial;
◦ Caso a filial não exista, o programa deve emitir uma mensagem de erro;
◦ No que diz respeito à matriz de pesos, não é necessário realizar a realocação de linhas e colunas. Para indicar
a não existência de dados em alguma linha/coluna, pode-se apenas marcá-la como inutilizada (com -1, por
exemplo).
*/
void removeFilial(struct Filial* filial, const char* eFilial)
{
    int i1 = -1;
    for (int i = 0; i < filial->andaFiliais; i++)
    {
        if (strcmp(filial->filiais[i], eFilial))
        {
            i1 = i;
        }
    }
    if (i1 == -1)
    {
        cout << "Filial nao encontrada!" <<endl;
        return;
    }
    int exclui = 0;
    for (int i = 0; i < filial->andaGrafo; i = i+2)
    {
        if (strcmp(filial->filiais[i], eFilial) == 0 || strcmp(filial->filiais[i+1], eFilial) == 0)
        {
            exclui = filial->grafo[i];
            filial->grafo[i] = filial->grafo[i+2];
            filial->grafo[i+1] = filial->grafo[i+3];
        }
    }
    for (int i = exclui; i < filial->andaFiliais-1; i++)
    {
        strcpy(filial->filiais[i], filial->filiais[i+1]);
    }
    filial->andaFiliais--;

    cout << "Filiais ainda cadastradas: "<<endl;
    for (int i = 0; i < filial->andaFiliais; i++)
    {
        cout<< filial->filiais[i]<<endl;
    }
    
}

/*
retorna o somatório de todas os custos de movimentação de carga entre todas as filiais
cadastradas no programa;
*/
float calculaCustosFiliais(struct Filial* filial)
{
    float cTotal=0;
    for (int i = 0; i < filial->andaCustos; i++)
    {
        cTotal += filial->custo[i];
    }
    return cTotal;
}

void executarMenuFilial(struct Filial* filial)
{
    vector<string> cdd;
    int op;
    do
    {
        cout << "\t\tMENU LOGISTICA\n"<<endl;
        cout << "1. Insere filial"<<endl;
        cout << "2. Insere movimentacao"<<endl;
        cout << "3. Lista filiais proximas"<<endl;
        cout << "4. Atualiza movimentacao"<<endl;
        cout << "5. Remover filial"<<endl;
        cout << "6. Calcular custos totais"<<endl;
        cout << "7. Voltar para o menu principal"<<endl;
        cout << "0. Sair do programa"<<endl;
        cout << "\nInsira a opcao: ";
            cin >> op;

        switch (op)
        {
        case 1:
            char nFilial[100];
            while (true) {
                cout << "\nDigite o nome do novo local ou 'sair' para sair: ";
                cin >> nFilial;
                if (strcmp(nFilial, "sair") == 0){
                    break;  
                }


                insereFilial(filial, nFilial);
                cdd.push_back(nFilial); // Adiciona o nome da cidade ao vetor
            }
            break;
        case 2: 
            char cfilial1[100], cfilail2[100];
            cout <<"Digite a cidades das duas filiais:"<<endl;
                cin >> cfilial1;
                cin >> cfilail2;
                insereMovimentacao(filial, cfilial1, cfilail2);
            break;
        case 3:
            char pFilial[100];
            cout << "Digite a cidade da filial: ";
                cin >> pFilial;
            listaFiliaisProximas(filial, pFilial);
            break;
        case 4:

            break;
        case 5:
            char eFilial[100];
            cout <<"Digite a cidades das duas filiais:"<<endl;
                cin >> eFilial;
            removeFilial(filial, eFilial);
            break;

        case 6:
            cout << "Custos totais: " << calculaCustosFiliais(filial)<<endl;
            break;
        case 7:
        {
            return;
        }
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
    } while (op != 0);
    
    
}