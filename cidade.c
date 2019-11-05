#include <stdlib.h>
#include "cidade.h"

struct cidade {
    char* nome;
    char* descricao;
    Cidade* ant;
    Cidade* prox;
};

Cidade* criaCidade(char* nome, char* descricao) {
    Cidade* cidade ;
    if (cidade = (Cidade*) malloc(sizeof(Cidade))) {
        cidade->nome = nome;
        cidade->descricao = descricao;
        cidade->ant = NULL;
        cidade->prox = NULL;
        return cidade;
    }
    return NULL;
}

