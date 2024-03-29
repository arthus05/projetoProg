#include "cidade.h"

/* TAD rota */
typedef struct rota Rota;

/* Cria uma rota com destino 'destino' e horário 'h' */
Rota* criarRota(Cidade* comeco, Cidade* destino, int hora, int min);

/* Preenche a rota, recebendo, a rota, um vetor cujos elementos são as cidades da rota, em ordem, e o
tamanho do vetor */
void preencheRota(Rota* rota, Cidade** preenchimento, int tam);

/* Retorna o ponteiro para a cidade inicial da rota */
Cidade* obtemComeco(Rota* rota);

/* Retorna o ponteiro para o destino da rota */
Cidade* obtemDestino(Rota* rota);

/* Retorna o horário da rota, em minutos. */
int obtemHoraEmMin(Rota* rota);