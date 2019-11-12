#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <curses.h>
#include "cidade.h"
#include "rota.h"



void nav(Rota* rota) {
    int a;
    char c;
    Cidade* aux = obtemComeco(rota);
    printf("%s\n\n%s", obtemNome(aux), obtemDesc(aux));
    printf("\n\nDigite 'A' para navegar à esquerda e 'D', à direita, e qualquer outra para sair.\n\n");
    while (1) {
        scanf(" %c", &c);
        if (c == 'D') {
            if (obtemProx(aux) != NULL) {
                aux = obtemProx(aux);
                printf("%s\n\n%s\n", obtemNome(aux), obtemDesc(aux));
            } else {
                continue;
            }
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
/* Retorna a rota com o horário mais próximo, recebendo o vetor contendo todas as rotas, o destino, o horário fornecido pelo 
usuário, e o número total de rotas. Levando em consideração que o número máximo de rotas para um destino seja 5 */

Rota* buscaRota(Rota** vetRotas, Cidade* cidade, int h, int m, int num) {
    //Aqui armazenamos as rotas com o destino desejado.
    Rota* rotasDestino[5];
    int j = 0;
    for (int i=0; i < num; i++) {
        if (obtemNome(obtemDestino(vetRotas[i])) == obtemNome(cidade)) {
            rotasDestino[j] = vetRotas[i];
            j++;
        } else {
            continue;
        }
    }
    //Aqui encontramos o horário mais próximo
    int tempMin[6];
    int tempProx;
    int k;
    tempMin[0] = h*60 + m;
    for (int i=0; i < j; i++) {
        tempMin[i+1] = obtemHoraEmMin(rotasDestino[i]);
    }
    for (int i=1; i < j; i++) {        
        if (abs(tempMin[0] - tempMin[i]) > abs(tempMin[0] - tempMin[i + 1])) {
            k = i;
        }
    }
    return rotasDestino[k];
}

void main() {
    Cidade* fortaleza = criaCidade("Fortaleza", "Fortaleza é a capital do estado do Ceará, no Nordeste brasileiro. A cidade é conhecida por suas praias, com falésias vermelhas, palmeiras, dunas e lagoas. As tradições folclóricas da cidade podem ser vistas em apresentações de dança no Theatro José de Alencar, construção em estilo art nouveau inaugurada em 1910. Outro destaque arquitetônico é a Catedral Metropolitana, em estilo neogótico.");    
    Cidade* umirim = criaCidade("Umirim", "Umirim é um município brasileiro do estado do Ceará, de clima tropical semiárido brando.");
    Cidade* aquiraz = criaCidade("Aquiraz", "Aquiraz é um município brasileiro no litoral do estado do Ceará, Região Nordeste do país. Pertence à Mesorregião Metropolitana, à Microrregião de Fortaleza e à Região Metropolitana de Fortaleza e sua população estimada em 2015 era de 77 717 habitantes.");
    Cidade* maracanau = criaCidade("Maracanaú", "É o maior centro industrial do estado. É também a terra adotiva do escritor Rodolfo Teófilo e conhecida como a maior cidade-dormitório do Ceará.");
    Cidade* cascavel = criaCidade("Cascavel", "Cascavel é um município brasileiro, localizado na região Oeste do estado do Paraná, do qual é o quinto mais populoso, com 328 454 habitantes, conforme estimativa do IBGE publicada em agosto de 2019.");    
    Cidade* pacajus = criaCidade("Pacajus", "Pacajus é um município brasileiro do estado do Ceará. A distância para Fortaleza é de 51,1 km. A via de acesso para a capital é a BR-116. Localiza-se na Região Metropolitana de Fortaleza.");
    Cidade* quixada = criaCidade("Quixadá", "Quixadá é um município brasileiro do estado do Ceará, pertence à mesorregião dos Sertões Cearenses e à microrregião do Sertão de Quixeramobim. É a maior cidade do sertão central, com uma população de 85.371 habitantes. Possui uma área de 2.019,833 km² e uma densidade demográfica de 39,91 hab/km².");
    Cidade* aracati = criaCidade("Aracati", "Aracati, Terra dos Bons Ventos, é um município do estado do Ceará, no Brasil, a 150 km da capital cearense Fortaleza, fundada em 11 de abril de 1747, teve o núcleo urbano sede do município tombado em 2000 pelo Instituto do Patrimônio Histórico e Artístico Nacional como patrimônio nacional.");
    Cidade* miraima = criaCidade("Miraima", "Miraíma é um município brasileiro do estado do Ceará localizado na Mesorregião do Noroeste Cearense.");
    Cidade* pentecoste = criaCidade("Pentecoste", "Pentecoste é um município brasileiro do estado do Ceará. Sua população estimada em 2010 é de 35.412 habitantes.");
    Cidade* itapipoca = criaCidade("Itapipoca", "Itapipoca é um município brasileiro do estado do Ceará. É conhecida como cidade dos três climas, por haver em seu território praias, serras e o sertão. Seu desenvolvimento confere a cidade a 12ª colocação entre os municípios mais ricos do estado e a 7ª colocação entre os municípios mais populosos do estado. ");
    Cidade* itapage = criaCidade("Itapagé", "Segundo o mesmo censo, a cidade está entre as melhores do Estado no que diz respeito à geração de empregos, alcance de rede de energia elétrica, pavimentação dos logradouros e coleta de lixo.");
    Cidade* sobral = criaCidade("Sobral", "Sobral é um município brasileiro no interior do estado do Ceará. Com uma população de 208.935 habitantes, conforme estimativa do IBGE de 2019, é o quinto município mais povoado do estado e o segundo maior do interior. Com uma taxa de urbanização de 88,35%.");
    Cidade* iraucuba = criaCidade("Irauçuba", "Irauçuba é conhecida como a capital cearense da rede de descanso.");
    Cidade* forquilha = criaCidade("Forquilha", "Situada na região Nordeste, Forquilha era distrito de Sobral, até que no ano 1985 declara emancipação através da Lei Estadual n0 11.012.");
    Cidade* jacauna = criaCidade("Jacaúna", "Jacaúna é um distrito do município brasileiro de Aquiraz, no litoral leste da Região Metropolitana de Fortaleza, no estado do Ceará. ");
    Cidade* horizonte = criaCidade("Horizonte", "Segundo o IBGE, Horizonte foi a cidade no Estado do Ceará que mais cresceu em população entre 2000 e 2010 - 65 por cento.");
    Cidade* beberibe = criaCidade("Beberibe", "Beberibe é um município brasileiro do estado do Ceará, localizando-se na microrregião de Cascavel, mesorregião do Norte Cearense. Sua população estimada em 2004 era de 45 186 habitantes.");
    Cidade* redencao = criaCidade("Redenção", "O município recebe esse nome por ter sido a primeira cidade brasileira a libertar todos os seus escravos.");
    Cidade* aracoiaba = criaCidade("Aracoiaba", "Aracoiaba é um município brasileiro do estado do Ceará, localizado na Microrregião de Baturité, mesorregião do Norte Cearense. Sua população estimada em 2004 era de 24.862 habitantes.Faz parte do Polo Serra do Baturité.");
    Cidade* choro = criaCidade("Choró", "Choró é um município brasileiro localizado no estado do Ceará, na microrregião do Sertão de Quixeramobim, mesorregião dos Sertões Cearenses.");
    Cidade* ocara = criaCidade("Ocara", "É um dos municípios mais novos do Ceará, tendo se emancipado politicamente em 1987.");
    Cidade* caninde = criaCidade("Canindé", "A religiosidade e o cotidiano da população estão intimamente ligados, quanto mais nos meses de alto fluxo turístico alimentado por romeiros vindos dos mais diversos lugares do Brasil que vêm a Canindé depositar sua fé e devoção nos vários locais de peregrinação considerados sagrados pelos visitantes");
    Cidade* guaramiranga = criaCidade("Guaramiranga", "O município se destaca como destino turístico pelo clima ao longo do ano, rica fauna, movimentada cena artística e importantes construções históricas.");
    Cidade* parajuru = criaCidade("Parajuru", "Parajuru é uma vila de pescadores que está localizada ao leste do litoral cearense a 120 km da cidade de Fortaleza e a 42 km de sua sede Beberibe. A população de Parajuru está estimada em aproximadamente seis mil habitantes. Conhecida pela pesca da lagosta, praias bonitas, tranqüilas, lugar turístico e agradável.");
    Cidade* russas = criaCidade("Russas", "É conhecida como a 'Terra da Laranja', 'Terra de Dom Lino' e 'Capital do Vale'.");

    /* Teremos um total de 15 rotas, para 6 destinos diferentes, representadas por R<cidade>_<horario> */
    Rota* vetRotas[15];
    
    /* Para Sobral */   
    Rota* Rsobral_1 = criarRota(copCidade(fortaleza), copCidade(sobral), 8, 0);
    vetRotas[0] = Rsobral_1;
    Cidade* camSobral1[3];
    camSobral1[0] = copCidade(umirim);
    camSobral1[1] = copCidade(itapipoca);
    camSobral1[2] = copCidade(miraima);
    preencheRota(Rsobral_1, camSobral1, 3);

    Rota* Rsobral_2 = criarRota(copCidade(fortaleza), copCidade(sobral), 12, 0);
    vetRotas[1] = Rsobral_2;
    Cidade* camSobral2[5];
    camSobral2[0] = copCidade(pentecoste);
    camSobral2[1] = copCidade(umirim);
    camSobral2[2] = copCidade(itapage);
    camSobral2[3] = copCidade(iraucuba);
    camSobral2[4] = copCidade(forquilha);
    preencheRota(Rsobral_2, camSobral2, 5);

    Rota* Rsobral_3 = criarRota(copCidade(fortaleza), copCidade(sobral), 20, 30);
    vetRotas[2] = Rsobral_3;
    Cidade* camSobral3[2];
    camSobral3[0] = copCidade(maracanau);
    camSobral3[1] = copCidade(forquilha);
    preencheRota(Rsobral_3, camSobral3, 2);
    
    /* Para Beberibe */
    Rota* Rbeberibe_1 = criarRota(copCidade(fortaleza), copCidade(beberibe), 12, 30);
    vetRotas[3] = Rbeberibe_1;
    Cidade* camBeberibe1[3];
    camBeberibe1[0] = copCidade(aquiraz);
    camBeberibe1[1] = copCidade(jacauna);
    camBeberibe1[2] = copCidade(cascavel);
    preencheRota(Rbeberibe_1, camBeberibe1, 3);

    Rota* Rbeberibe_2 = criarRota(copCidade(fortaleza), copCidade(beberibe), 22, 0);
    vetRotas[4] = Rbeberibe_2;
    Cidade* camBeberibe2[3];
    camBeberibe2[0] = copCidade(maracanau);
    camBeberibe2[1] = copCidade(horizonte);
    camBeberibe2[2] = copCidade(cascavel);
    preencheRota(Rbeberibe_2, camBeberibe2, 3);

    /* Quixadá */
    Rota* Rquixada_1 = criarRota(copCidade(fortaleza), copCidade(quixada), 6, 0);
    vetRotas[5] = Rquixada_1;
    Cidade* camQuixada1[4];
    camQuixada1[0] = copCidade(maracanau);
    camQuixada1[1] = copCidade(redencao);
    camQuixada1[2] = copCidade(aracoiaba);
    camQuixada1[3] = copCidade(choro);
    preencheRota(Rquixada_1, camQuixada1, 4);

    Rota* Rquixada_2 = criarRota(copCidade(fortaleza), copCidade(quixada), 12, 30);
    vetRotas[6] = Rquixada_2;
    Cidade* camQuixada2[3];
    camQuixada2[0] = copCidade(aquiraz);
    camQuixada2[1] = copCidade(horizonte);
    camQuixada2[2] = copCidade(ocara);
    preencheRota(Rquixada_2, camQuixada2, 3);

    Rota* Rquixada_3 = criarRota(copCidade(fortaleza), copCidade(quixada), 20, 20);
    vetRotas[7] = Rquixada_3;
    Cidade* camQuixada3[3];
    camQuixada3[0] = copCidade(maracanau);
    camQuixada3[1] = copCidade(caninde);
    camQuixada3[3] = copCidade(choro);
    preencheRota(Rquixada_3, camQuixada3, 3);

    /* Para Guaramiranga */
    Rota* Rguaramiranga_1 = criarRota(copCidade(fortaleza), copCidade(guaramiranga), 8, 20);
    vetRotas[8] = Rguaramiranga_1;
    Cidade* camGuaramiranga1[3];
    camGuaramiranga1[0] = copCidade(maracanau);
    camGuaramiranga1[1] = copCidade(redencao);
    camGuaramiranga1[2] = copCidade(guaramiranga);
    preencheRota(Rguaramiranga_1, camGuaramiranga1, 3);
    
    Rota* Rguaramiranga_2 = criarRota(copCidade(fortaleza), copCidade(guaramiranga), 16, 0);
    vetRotas[9] = Rguaramiranga_2;
    Cidade* camGuaramiranga2[3];
    camGuaramiranga2[0] = copCidade(maracanau);
    camGuaramiranga2[1] = copCidade(redencao);
    camGuaramiranga2[2] = copCidade(guaramiranga);
    preencheRota(Rguaramiranga_2, camGuaramiranga2, 3);

    Rota* Rguaramiranga_3 = criarRota(copCidade(fortaleza), copCidade(guaramiranga), 21, 40);
    vetRotas[10] = Rguaramiranga_3;
    Cidade* camGuaramiranga3[3];
    camGuaramiranga3[0] = copCidade(maracanau);
    camGuaramiranga3[1] = copCidade(redencao);
    camGuaramiranga3[2] = copCidade(guaramiranga);
    preencheRota(Rguaramiranga_3, camGuaramiranga3, 3);

    /* Aracati */
    Rota* Raracati_1 = criarRota(copCidade(fortaleza), copCidade(aracati), 10, 0);
    vetRotas[11] = Raracati_1;
    Cidade* camAracati1[4];
    camAracati1[0] = copCidade(aquiraz);
    camAracati1[1] = copCidade(cascavel);
    camAracati1[2] = copCidade(beberibe);
    camAracati1[3] = copCidade(parajuru);
    preencheRota(Raracati_1, camAracati1, 4);

    Rota* Raracati_2 = criarRota(copCidade(fortaleza), copCidade(aracati), 15, 45);
    vetRotas[12] = Raracati_2;
    Cidade* camAracati2[3];
    camAracati2[0] = copCidade(maracanau);
    camAracati2[1] = copCidade(horizonte);
    camAracati2[2] = copCidade(pacajus);
    preencheRota(Raracati_2, camAracati2, 3);

    /* Para Russas */
    Rota* Rrussas_1 = criarRota(copCidade(fortaleza), copCidade(russas), 7, 0);
    vetRotas[13] = Rrussas_1;
    Cidade* camRussas1[2];
    camRussas1[0] = copCidade(maracanau);
    camRussas1[1] = copCidade(horizonte);
    preencheRota(Rrussas_1, camRussas1, 2);

    Rota* Rrussas_2 = criarRota(copCidade(fortaleza), copCidade(russas), 23, 0);
    vetRotas[14] = Rrussas_2;
    Cidade* camRussas2[3];
    camRussas2[0] = copCidade(aquiraz);
    camRussas2[1] = copCidade(cascavel);
    preencheRota(Rrussas_2, camRussas2, 2);


    /* Interface */
    char dest[10];
    int h, m;
    int qtdRotas = 15;

    printf("Olá, seja bem vindo à rodoviária Afonceu Pirulin.\nEscolha o sua rota!\n");
    printf("Diga aí o destino(Ex.: Quixadá, Sobral): ");
    scanf("%s", dest);
    printf("Diga aí o horário(hh:mm): ");
    scanf("%d:%d", &h, &m);
    if (strcmp(dest, "Sobral") == 0) {
        Rota* rotaEscolhida = buscaRota(vetRotas, sobral, h, m, qtdRotas);
        nav(rotaEscolhida);
    }
    else if (strcmp(dest, "Beberibe")) {
        Rota* rotaEscolhida = buscaRota(vetRotas, beberibe, h, m, qtdRotas);
        nav(rotaEscolhida);
    }
    else if (strcmp(dest, "Quixadá")) {
        Rota* rotaEscolhida = buscaRota(vetRotas, quixada, h, m, qtdRotas);
        nav(rotaEscolhida);
    }
    else if (strcmp(dest, "Guaramiranga")) {
        Rota* rotaEscolhida = buscaRota(vetRotas, guaramiranga, h, m, qtdRotas);
        nav(rotaEscolhida);
    }
    else if (strcmp(dest, "Aracati")) {
        Rota* rotaEscolhida = buscaRota(vetRotas, aracati, h, m, qtdRotas);
        nav(rotaEscolhida);
    }
    else if (strcmp(dest, "Russas")) {
        Rota* rotaEscolhida = buscaRota(vetRotas, russas, h, m, qtdRotas);
        nav(rotaEscolhida);
    }
}

