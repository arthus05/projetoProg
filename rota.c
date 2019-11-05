#include <stdlib.h>
#include "rota.h"
#include "cidade.h"

struct rota {
    Cidade* comeco;
    Cidade* destino;
    char hor[5];
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