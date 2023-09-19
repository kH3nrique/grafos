
#include"jogo.h"

#define MaxTam 100

using namespace std;

int main() {
    struct Jogo jogo;
    jogo.numLocais = 0;

    executarMenu(&jogo);

    return 0;
}