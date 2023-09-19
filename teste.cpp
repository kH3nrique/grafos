#include <iostream>
#include <string>
#include <cstring>
#include <vector> 

#define MAX_LOCATIONS 100

using namespace std;

struct Jogo {
    int numLocais;
    char locais[MAX_LOCATIONS][100];
    int matrizAdjacencia[MAX_LOCATIONS][MAX_LOCATIONS];
};

// Verificar se local existe
bool localExiste(const struct Jogo* jogo, const char* nomeLocal) {
    for (int i = 0; i < jogo->numLocais; ++i) {
        if (strcmp(jogo->locais[i], nomeLocal) == 0) {
            return true;
        }
    }
    return false;
}

void insereLocalJogo(struct Jogo* jogo, const char* nomeLocal) {
    // Numero de locais atingidos?
    if (jogo->numLocais >= MAX_LOCATIONS) { 
        cout << "Limite de locais atingido. Não é possível adicionar mais locais." << endl;
        return;
    }

    // Local existe?
    if (localExiste(jogo, nomeLocal)) {
        cout << "Local '" << nomeLocal << "' já existe no jogo. Insira um nome único." << endl;
        return;
    }

    // Copia o nome do novo local para a matriz de locais no jogo
    strcpy(jogo->locais[jogo->numLocais], nomeLocal);
    
    int novoIndice = jogo->numLocais++;

    cout << "Local '" << nomeLocal << "' inserido com sucesso." << endl;
}

void insereTempoDeslocamento(struct Jogo* jogo, const char* localA, const char* localB) {
    int indiceA = -1;
    int indiceB = -1;

    // Procura os índices dos locais
    for (int i = 0; i < jogo->numLocais; ++i) {
        if (strcmp(jogo->locais[i], localA) == 0) {
            indiceA = i;
        }
        if (strcmp(jogo->locais[i], localB) == 0) {
            indiceB = i;
        }
    }

    if (indiceA == -1 || indiceB == -1) {
        cout << "Um ou ambos os locais nao foram encontrados." << endl;
        return;
    }

    int tempo;
    cout << "Insira o tempo de deslocamento entre " << localA << " e " << localB << " (em segundos): ";
    cin >> tempo;

    jogo->matrizAdjacencia[indiceA][indiceB] = jogo->matrizAdjacencia[indiceB][indiceA] = tempo;
}

void listaLocaisDestino(const struct Jogo* jogo, const char* localPartida) {
    int indicePartida = -1;

    // Procurar o índice do local de partida na lista de locais
    for (int i = 0; i < jogo->numLocais; ++i) {
        if (strcmp(jogo->locais[i], localPartida) == 0) {
            indicePartida = i; //armazena seu índice
            break; 
        }
    }

    // Verifica se o local de partida não foi encontrado
    if (indicePartida == -1) {
        cout << "O local de partida '" << localPartida << "' nao foi encontrado." << endl;
        return;
    }

    cout << "Locais de destino a partir de '" << localPartida << "':" << endl;

    // Percorre todos os locais do jogo
    for (int i = 0; i < jogo->numLocais; ++i) {
        // Local diferente? e tempo valido?
        if (i != indicePartida && jogo->matrizAdjacencia[indicePartida][i] > 0) {
            cout << "Local: " << jogo->locais[i] << ", Tempo de deslocamento: " << jogo->matrizAdjacencia[indicePartida][i] << " segundos" << endl;
        }
    }
}

void listaLocaisOrigem(const struct Jogo* jogo, const char* localDestino) {
    int indiceDestino = -1;

    // Procura o índice do local de destino na lista de locais
    for (int i = 0; i < jogo->numLocais; ++i) {
        if (strcmp(jogo->locais[i], localDestino) == 0) {
            indiceDestino = i; // armazena seu índice
            break;
        }
    }

    // Verifica se o local de destino não foi encontrado
    if (indiceDestino == -1) {
        cout << "O local de destino '" << localDestino << "' não foi encontrado." << endl;
        return;
    }

    cout << "Locais de origem para '" << localDestino << "':" << endl;

    // Percorre todos os locais do jogo
    for (int i = 0; i < jogo->numLocais; ++i) {
        // Local atual = destino? e tempo valido?
        if (i != indiceDestino && jogo->matrizAdjacencia[i][indiceDestino] > 0) {
            cout << "Local: " << jogo->locais[i] << ", Tempo de deslocamento: " << jogo->matrizAdjacencia[i][indiceDestino] << " segundos" << endl;
        }
    }
}

void removeTempo(struct Jogo* jogo, const char* localA, const char* localB) {
    int indiceA = -1;
    int indiceB = -1;

    // Procura os índices dos locais
    for (int i = 0; i < jogo->numLocais; ++i) {
        if (strcmp(jogo->locais[i], localA) == 0) {
            indiceA = i; // Armazena o índice de 'localA' 
        }
        if (strcmp(jogo->locais[i], localB) == 0) {
            indiceB = i; // Armazena o índice de 'localB' 
        }
    }

    // Verifica se ambos os locais foram encontrados
    if (indiceA == -1 || indiceB == -1) {
        cout << "Um ou ambos os locais não foram encontrados." << endl;
        return;
    }

    // Verifica se a movimentação existe na matriz de pesos
    if (jogo->matrizAdjacencia[indiceA][indiceB] == 0) {
        cout << "Nao ha tempo de deslocamento entre " << localA << " e " << localB << "." << endl;
    } else {
        // Remove o tempo de deslocamento, faz ele virar zero
        jogo->matrizAdjacencia[indiceA][indiceB] = jogo->matrizAdjacencia[indiceB][indiceA] = 0;
        cout << "Tempo de deslocamento entre " << localA << " e " << localB << " removido com sucesso." << endl;
    }
}

void atualizaTempo(struct Jogo* jogo, const char* localA, const char* localB) {
    int indiceA = -1;
    int indiceB = -1;

    // Procura os índices dos locais no jogo
    for (int i = 0; i < jogo->numLocais; ++i) {
        //nome do local na posição 'i' é igual ao nome de 'localA'
        if (strcmp(jogo->locais[i], localA) == 0) {
            indiceA = i;  // Armazena o índice de 'localA' 
        }
        // nome do local na posição 'i' é igual ao nome de 'localB'
        if (strcmp(jogo->locais[i], localB) == 0) {
            indiceB = i;  // Armazena o índice de 'localB'
        }
    }

    // Verifica se ambos os locais foram encontrados
    if (indiceA == -1 || indiceB == -1) {
        cout << "Um ou ambos os locais nao foram encontrados." << endl;
        return; 
    }

    // Verifica se a movimentação já existe na matriz de pesos
    if (jogo->matrizAdjacencia[indiceA][indiceB] == 0) {
        cout << "Tempo entre os locais nao existe" << endl;
    } else {
        removeTempo(jogo, localA, localB);
        int tempo;
        cout << "Insira o tempo de deslocamento entre " << localA << " e " << localB << " (em segundos): ";
        cin >> tempo;

    jogo->matrizAdjacencia[indiceA][indiceB] = jogo->matrizAdjacencia[indiceB][indiceA] = tempo;
    }
}

int calculaTemposLocais(const struct Jogo* jogo) {
    int somaTempos = 0;

    // Percorre a matriz e soma tudo
    for (int i = 0; i < jogo->numLocais; ++i) {
        for (int j = i + 1; j < jogo->numLocais; ++j) {
            if (jogo->matrizAdjacencia[i][j] > 0) {
                somaTempos += jogo->matrizAdjacencia[i][j];
            }
        }
    }

    return somaTempos;
}

void executarMenu(struct Jogo* jogo) {
    int opcao;
    char nomeLocalA[100], nomeLocalB[100];
    vector<string> cidades; // armazenar as cidades inseridas
    
    do {
        cout << "MENU:" << endl;
        cout << "1. Inserir local" << endl;
        cout << "2. Inserir tempo de deslocamento" << endl;
        cout << "3. Listar locais de destino" << endl;
        cout << "4. Listar locais de origem" << endl;
        cout << "5. Atualizar tempo de deslocamento" << endl;
        cout << "6. Remover tempo de deslocamento" << endl;
        cout << "7. Calcular somatorio dos tempos de deslocamento" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                char nomeLocal[100];
                cout << "\n";

                while (true) {
                    cout << "Digite o nome do novo local ou 'sair' para sair: ";
                    cin >> nomeLocal;

                    if (strcmp(nomeLocal, "sair") == 0) {
                        break; 
                    }

                    insereLocalJogo(jogo, nomeLocal);
                    cidades.push_back(nomeLocal); // Adiciona o nome da cidade ao vetor
                }
                cout << "\n";
            break;
            }
            case 2: {
                cout << "\n";
                cout << "Digite o nome do primeiro local: ";
                cin >> nomeLocalA;
                cout << "Digite o nome do segundo local: ";
                cin >> nomeLocalB;
                insereTempoDeslocamento(jogo, nomeLocalA, nomeLocalB);
                cout << "\n";
                break;
            }
            case 3: {
                char localPartida[100];
                cout << "\n";
                cout << "Digite o nome do local de partida: ";
                cin >> localPartida;

                if (strcmp(localPartida, nomeLocalA) == 0) {
                    listaLocaisDestino(jogo, localPartida);
                } else {
                    cout << "O local nao possui destino!!" << endl;
                }
                
                cout << "\n";
                break;
            }
            case 4: {
                char localDestino[100];
                cout << "\n";
                cout << "Digite o nome do local de destino: ";
                cin >> localDestino;

                if (strcmp(localDestino, nomeLocalA) == 0) {
                    cout << "O local nao possui origem!!" << endl;
                }
                else {
                    listaLocaisOrigem(jogo, localDestino);
                }
                cout << "\n";
                break;
            }
            case 5: {
                char localA[100], localB[100];
                cout << "\n";
                cout << "Digite o nome do primeiro local: ";
                cin >> localA;
                cout << "Digite o nome do segundo local: ";
                cin >> localB;
                atualizaTempo(jogo, localA, localB);
                cout << "\n";
                break;
            }
            case 6: {
                char localX[100], localY[100];
                cout << "\n";
                cout << "Digite o nome do primeiro local: ";
                cin >> localX;
                cout << "Digite o nome do segundo local: ";
                cin >> localY;
                removeTempo(jogo, localX, localY);
                cout << "\n";
                break;
            }
            case 7: {
                int somaTempos = calculaTemposLocais(jogo);
                cout << "\n";
                cout << "Somatorio dos tempos de deslocamento: " << somaTempos << " segundos" << endl;
                cout << "\n";
                break;
            }
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 0);
    
    cout << "Cidades inseridas pelo usuário:" << endl;
    for (const string& cidade : cidades) {
        cout << cidade << endl;
    }
}

int main() {
    struct Jogo jogo;
    jogo.numLocais = 0;

    executarMenu(&jogo);

    return 0;
}
