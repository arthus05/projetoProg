#include <stdlib.h>
#include "cidade.h"

struct cidade {
    char* nome;
    char* descricao;
    Cidade* ant;
    Cidade* prox;
};

Cidade* criaCidade(char* nome, char* descricao) {
    Cidade* cidade;
    if (cidade = (Cidade*) malloc(sizeof(Cidade))) {
        cidade->nome = nome;
        cidade->descricao = descricao;
        cidade->ant = NULL;
        cidade->prox = NULL;
        return cidade;
    }
    return NULL;
}

int tamCidade() {
    return sizeof(Cidade);
}

Cidade copCidade(Cidade* cidade) {
    return *cidade;
}

Cidade* obtemProx(Cidade* cidade) {
    return cidade->prox;
}

Cidade* obtemAnt(Cidade* cidade) {
    return cidade->ant;
}

Cidade* atribuiProx(Cidade* cidade, Cidade* prox) {
    cidade->prox = prox;
    prox->ant = cidade;
}

Cidade* atribuiAnt(Cidade* cidade, Cidade* ant){
    cidade->ant = ant;
    ant->prox = cidade;
}

