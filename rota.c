#include <stdlib.h>
#include "rota.h"
#include "cidade.h"

struct rota {
    Cidade* comeco;
    Cidade* destino;
    int hora;
    int min;
};

Rota* criarRota(Cidade* comeco, Cidade* destino, int hora, int min) {
    Rota* rota;
    if (rota = (Rota*) malloc(sizeof(Rota))){
        rota->comeco = comeco;
        rota->destino = destino;
        rota->hora = hora;
        rota->min = min;
        atribuiProx(comeco, destino);
        return rota;
    }
    return NULL;
}

void preencheRota(Rota* rota, Cidade** preenchimento, int tam) {
    atribuiProx(rota->comeco, preenchimento[0]);
    for (int i = 0; i < tam-1; i++) {
        atribuiProx(preenchimento[i], preenchimento[i + 1]);
    }
    atribuiProx(preenchimento[tam-1], rota->destino);
}

Cidade* obtemComeco(Rota* rota) {
    return rota->comeco;
}