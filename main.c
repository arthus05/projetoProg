#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "cidade.h"
#include "rota.h"

void nav(Rota* rota) {
    if (getch() == '\033') {// if the first value is esc
    getch();// skip the [
    if (getch()) {
        case 'C':
            // código para a seta direita
            break;
        case 'D':
            // código para a seta esquerda
            break;
        }   
    }
}

int main() {
    Cidade* fortaleza = criaCidade("Fortaleza", "Fortaleza é a capital do estado do Ceará, no Nordeste brasileiro. A cidade é conhecida por suas praias, com falésias vermelhas, palmeiras, dunas e lagoas. As tradições folclóricas da cidade podem ser vistas em apresentações de dança no Theatro José de Alencar, construção em estilo art nouveau inaugurada em 1910. Outro destaque arquitetônico é a Catedral Metropolitana, em estilo neogótico.");
    Cidade* caucaia = criaCidade("Caucaia", "Caucaia é um município brasileiro do estado do Ceará que integra a Região Metropolitana de Fortaleza com cerca de 1.227,9 km², equivalente a 0,83% da superfície estadual. Em 2019, possui um contingente populacional estimado de 361 400 habitantes e, em 2010, sua densidade demográfica era de 264,91 hab./km².");
    Cidade* aquiraz = criaCidade("Aquiraz", "Aquiraz é um município brasileiro no litoral do estado do Ceará, Região Nordeste do país. Pertence à Mesorregião Metropolitana, à Microrregião de Fortaleza e à Região Metropolitana de Fortaleza e sua população estimada em 2015 era de 77 717 habitantes.");
    Cidade* maranguape = criaCidade("Maranguape", "Maranguape é um município brasileiro do Estado do Ceará. Localizado na Região Metropolitana de Fortaleza, a 27 km da capital.");
    Cidade* cascavel = criaCidade("Cascavel", "Cascavel é um município brasileiro, localizado na região Oeste do estado do Paraná, do qual é o quinto mais populoso, com 328 454 habitantes, conforme estimativa do IBGE publicada em agosto de 2019.");
    Cidade* pacajus = criaCidade("Pacajus", "Pacajus é um município brasileiro do estado do Ceará. A distância para Fortaleza é de 51,1 km. A via de acesso para a capital é a BR-116. Localiza-se na Região Metropolitana de Fortaleza.");
    Cidade* quixada = criaCidade("Quixadá", "Quixadá é um município brasileiro do estado do Ceará, pertence à mesorregião dos Sertões Cearenses e à microrregião do Sertão de Quixeramobim. É a maior cidade do sertão central, com uma população de 85.371 habitantes. Possui uma área de 2.019,833 km² e uma densidade demográfica de 39,91 hab/km².");
    Cidade* aracati = criaCidade("Aracati", "Aracati, Terra dos Bons Ventos, é um município do estado do Ceará, no Brasil, a 150 km da capital cearense Fortaleza, fundada em 11 de abril de 1747, teve o núcleo urbano sede do município tombado em 2000 pelo Instituto do Patrimônio Histórico e Artístico Nacional como patrimônio nacional.");
    Cidade* quixeramobim = criaCidade("Quixeramobim", "Quixeramobim é um município brasileiro do estado do Ceará, localizado na Mesorregião dos Sertões Cearenses. É a segunda maior cidade do sertão central, com uma população de 75 565 habitantes.");
    Cidade* moradanova = criaCidade("Morada Nova", "Morada Nova é um município no interior do estado brasileiro do Ceará. Localizado na Mesorregião do Jaguaribe, na Microrregião do Baixo Jaguaribe, no Vale do Jaguaribe.");
    Cidade* itapipoca = criaCidade("Itapipoca", "Itapipoca é um município brasileiro do estado do Ceará. É conhecida como cidade dos três climas, por haver em seu território praias, serras e o sertão. Seu desenvolvimento confere a cidade a 12ª colocação entre os municípios mais ricos do estado e a 7ª colocação entre os municípios mais populosos do estado. ");
    Cidade* sobral = criaCidade("Sobral", "Sobral é um município brasileiro no interior do estado do Ceará. Com uma população de 208.935 habitantes, conforme estimativa do IBGE de 2019, é o quinto município mais povoado do estado e o segundo maior do interior. Com uma taxa de urbanização de 88,35%.");
    
    /* Cada rota ocorrerá às 08:00, 13:00 e 20:00, sendo representada por R<cidade>_<horario> */

    /* Rotas Caucáia :: 1 */
    Rota* Rcaucaia_8 = criarRota(copCidade(fortaleza), copCidade(caucaia), "08:00");
    Rota* Rcaucaia_13 = criarRota(copCidade(fortaleza), copCidade(caucaia), "13:00");
    Rota* Rcaucaia_20 = criarRota(copCidade(fortaleza), copCidade(caucaia), "20:00");
    
    /* Interface */
    int numRota;

    printf("Olá, seja bem vindo à rodoviária Afonceu Pirulin.\nEscolha o sua rota!\n");
    printf("[1] Caucaia - 08:00\n");
    printf("[2] Caucaia - 13:00\n");
    printf("[3] Caucaia - 20:00\n");

    scanf("%d", &numRota);
    switch (numRota) {
        case 1:

        break;
    }
    return 0;
}