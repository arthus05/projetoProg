#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <curses.h>
#include "cidade.h"
#include "rota.h"

void nav(Rota* rota) {
    int a;
    char c;
    Cidade* aux = obtemComeco(rota);
    printf("%s\n\n%s", obtemNome(aux), obtemDesc(aux));
    printf("\n\nDigite 'A' para navegar à esquerda e 'D', à direita.\n\n");
    while (1) {
        scanf(" %c", &c);
        if (c == 'D') {
            aux = obtemProx(aux);
            printf("%s\n\n%s\n", obtemNome(aux), obtemDesc(aux));
        }
        else if (c == 'A') {
            aux = obtemAnt(aux);
            printf("%s\n\n%s\n", obtemNome(aux), obtemDesc(aux));
        } else {
            break;
        }
    }
    /*if (getch() == '\033') {// if the first value is esc
    getch();// skip the [
    if (getch()) {
        case 'C':
            // código para a seta direita
            break;
        case 'D':
            // código para a seta esquerda
            break;
        }   
    }*/
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

    Rota* vetRotas[2];
    
    Rota* Rsobral_1 = criarRota(copCidade(fortaleza), copCidade(sobral), 2, 17);
    vetRotas[0] = Rsobral_1;

    Cidade* preenchimento1[4];
    preenchimento1[0] = caucaia;
    preenchimento1[1] = aquiraz;
    preenchimento1[2] = maranguape;
    preenchimento1[3] = cascavel;

    preencheRota(Rsobral_1, preenchimento1, 4);

    Rota* Rsobral_2 = criarRota(copCidade(fortaleza), copCidade(sobral), 10, 23);
    vetRotas[1] = Rsobral_2;

    Cidade* preenchimento2[6];
    preenchimento2[0] = pacajus;
    preenchimento2[1] = quixada;
    preenchimento2[2] = aracati;
    preenchimento2[3] = quixeramobim;
    preenchimento2[4] = moradanova;
    preenchimento2[5] = itapipoca;

    preencheRota(Rsobral_2, preenchimento2, 6);

    
    /* Interface */
    char dest[10];
    int h, m;
/*
    printf("Olá, seja bem vindo à rodoviária Afonceu Pirulin.\nEscolha o sua rota!\n");
    printf("Diga aí o destino: ");
    scanf("%s", dest);
    printf("Diga aí o horário(hh:mm): ");
    scanf("%d:%d", &h, &m);
*/
    int numRota;


    scanf("%d", &numRota);
    if (numRota == 1) {
        nav(Rsobral_1);
    }
    else if (numRota == 2) {
        nav(Rsobral_2);
    }
    return 0;
}

