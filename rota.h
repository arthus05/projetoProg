#include "cidade.h"

/* TAD rota */
typedef struct rota Rota;

/* Cria uma rota com destino 'destino' e horário 'hor' */
Rota* criarRota(Cidade* comeco, Cidade* destino, char* hor);

/* Preenche a rota */
void preencheRota(Cidade* destino);
