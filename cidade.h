
/* TAD cidade */
typedef struct cidade Cidade;

/* Cria uma cidade */
Cidade* criaCidade(char* nome, char* descricao);

/* Retorna o tamanho da cidade */
int tamCidade();

/* Obtém cópia de uma cidade */
Cidade copCidade(Cidade* cidade);

/* Retorna o próximo de uma cidade */
Cidade* obtemProx(Cidade* cidade);

/* Retorna o anterior de uma cidade */
Cidade* obtemAnt(Cidade* cidade);

/* Atribui próximo a uma cidade */
Cidade* atribuiProx(Cidade* cidade, Cidade* prox);

/* Atribui anterior a uma cidade */
Cidade* atribuiAnt(Cidade* cidade, Cidade* ant);

/* Retorna o nome da cidade */
char* obtemNome(Cidade* cidade);

/* Retorna a descrição da cidade */
char* obtemDesc(Cidade* cidade);
