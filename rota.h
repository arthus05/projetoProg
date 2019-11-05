#include "cidade.h"

/* TAD rota */
typedef struct rota Rota;

/* Cria uma rota com destino 'destino' e horário 'h' */
Rota* criarRota(Cidade* comeco, Cidade* destino, char* h);

/* Preenche a rota, recebendo, a rota, um vetor cujos elementos são as cidades da rota, em ordem, e o
tamanho do vetor */
void preencheRota(Rota* rota, Cidade** preenchimento, int tam);
