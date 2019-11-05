#include <stdlib.h>
#include "rota.h"
#include "cidade.h"

struct rota {
    Cidade* comeco;
    Cidade* destino;
    char h[5];
};

Rota* criarRota(Cidade* comeco, Cidade* destino, char* h) {
    Rota* rota;
    if (rota = (Rota*) malloc(sizeof(Rota))){
        rota->comeco = comeco;
        rota->destino = destino;
        return rota;
    }
    return NULL;
}

void preencheRota(Rota* rota, Cidade** preenchimento, int tam) {
    atribuiProx(rota->comeco, preenchimento[0]);
    for (int i = 0; i < tam-1; i++) {
        atribuiProx(preenchimento[1], preenchimento[i + 1]);
    }
    atribuiProx(preenchimento[tam-1], rota->destino);
}