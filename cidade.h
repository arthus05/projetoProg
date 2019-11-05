
/* TAD cidade */
typedef struct cidade Cidade;

/* Cria uma cidade */
Cidade* criaCidade(char* nome, char* descricao);

/* Retorna o próximo de uma cidade */
Cidade* obtemProx(Cidade* cidade);

/* Retorna o anterior de uma cidade */
Cidade* obtemAnt(Cidade* cidade);

/* Atribui próximo a uma cidade */
Cidade* atribuiProx(Cidade* cidade, Cidade* prox);

/* Atribui anterior a uma cidade */
Cidade* atribuiAnt(Cidade* cidade, Cidade* ant);

