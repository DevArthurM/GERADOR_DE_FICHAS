#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
//Raças
#define ANAO 1
#define ELFOS 2
#define HUMANO 3
#define ORC 4
#define GIGANTE 5
#define DARKELF 6
// Constantes
#define NUMERO_DE_ATRIBUTOS 6
#define CARACTER_CLASSE 4
// Rodar dados
#define RODAR_D3 rand() % 3 + 1
#define RODAR_D6 rand() % 6 + 1
#define RODAR_D8 rand() % 8 + 1
#define RODAR_D10 rand() % 10 + 1
#define RODAR_D20 rand() % 20 + 1
// Buffs
#define FORCA_BUFF 0
#define DESTREZA_BUFF 1
#define CONSTUICAO_BUFF 2
#define INTELIGENCIA_BUFF 3
#define SABEDORIA_BUFF 4
#define CARISMA_BUFF 5
//Variáveis Globais.
//Atributos Globais
int forca, destreza, constuicao, inteligencia, sabedoria, carisma;
char raca[8];
//Buffs
int anao_buff[NUMERO_DE_ATRIBUTOS] = {0};
int elfos_buff[NUMERO_DE_ATRIBUTOS] = {0};
int humano_buff[NUMERO_DE_ATRIBUTOS] = {0};
int ogro_buff[NUMERO_DE_ATRIBUTOS] = {0};
int gigante_buff[NUMERO_DE_ATRIBUTOS] = {0};
int darkelf_buff[NUMERO_DE_ATRIBUTOS] = {0};
// Gerador de Raças & Buffs
int raca_rand;
int atributo;
//Funcão principal.
int main()
{
    //Declarando funções.
    void rodardados();
    void print_atributo(int atributo_escolhido);
    void caracteristicas_personagens();
    //Variáveis
    srand(time(NULL));
    FILE *txt_ficha;
    int d20, quantidade_de_dados;
    int escolha;
    bool programa = true, rodar_dados_novamente, rodando_d20 = false, gerar_raca = true, raca_aleatoria = true, setar_buff = true, escolher_raca = true;
    //Programa
    while (programa)
    {
        system("cls");
        printf("|\tM E N U\n");
        printf("| 01. Gerar uma ficha.\n");
        printf("| 02. Rodar dados\n");
        printf("| 03. Setar Buffs\n");
        printf("| 04. Fechar programa.\n");
        printf("|>   ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1: //Gerar uma ficha
            system("cls");
            do
            {
                printf("| Deseja travar a raça?\n");
                printf("| 1- Escolher raca\n");
                printf("| 2- Gerar raca aleatoria.\n");
                printf("|>   ");
                scanf("%d", &escolha);
                switch (escolha)
                {
                case 1: // Escolher raca
                    do
                    {
                        system("cls");
                        printf("| Qual raca deseja travar?\n");
                        printf("| 1 - Anao\n");
                        printf("| 2 - Elfos\n");
                        printf("| 3 - Humano\n");
                        printf("| 4 - Orc\n");
                        printf("| 5 - Gigante\n");
                        printf("| 6 - DarkElf\n");
                        printf("| > ");
                        scanf("%d", &raca_rand);
                        if (raca_rand > 6 || raca_rand < 1)
                        {
                            system("cls");
                            printf("| ERRO DIGITE UMA OPCAO VALIDA\n");
                            system("PAUSE");
                            escolher_raca = true;
                        }
                        else
                        {
                            gerar_raca = false;
                            raca_aleatoria = false;
                            escolher_raca = false;
                        }
                    } while (escolher_raca);
                    break;
                case 2: // Gerar raça aleatoria
                    raca_aleatoria = true;
                    gerar_raca = false;
                    break;
                default:
                    system("cls");
                    printf("| ERRO DIGITE UMA OPCAO VALIDA\n");
                    system("PAUSE");
                    gerar_raca = true;
                    break;
                }
            } while (gerar_raca);
            do //Gerar uma ficha.
            {
                if (raca_aleatoria)
                {
                    raca_rand = rand() % 6 + 1;
                }
                system("cls");
                rodardados();
                printf("| Raca:\t\t%s\n", raca);
                printf("| Forca:\t%d\n", forca);
                printf("| Destreza:\t%d\n", destreza);
                printf("| Constitucao:\t%d\n", constuicao);
                printf("| Inteligencia:\t%d\n", inteligencia);
                printf("| Sabedoria:\t%d\n", sabedoria);
                printf("| Carisma:\t%d\n", carisma);
                printf("|\n");
                caracteristicas_personagens();
                printf("|\n");
                printar_classes();
                printf("|\n");
                printf("| 1- Gerar outra ficha.\n");
                printf("| 2- Salvar ficha\n");
                printf("| 3- Voltar do menu\n");
                printf("|>   ");
                scanf("%d", &escolha);
                switch (escolha)
                {
                case 1: // Gerar outra ficha
                    rodar_dados_novamente = true;
                    break;
                case 2: // Salvar ficha
                    txt_ficha = fopen("ficha.txt", "w");
                    fprintf(txt_ficha, "Teste");
                    break;
                case 3: // Voltar no menu
                    rodar_dados_novamente = false;
                    break;
                default:
                    system("cls");
                    printf("| ERRO DIGITE UMA OPCAO VALIDA\n");
                    system("PAUSE");
                    break;
                }
            } while (rodar_dados_novamente);
            break;
        case 2:
            do //Rodar d20
            {
                system("cls");
                printf("| Quantos d20 deseja rodar?\n");
                printf("|> ");
                scanf("%d", &quantidade_de_dados);
                system("cls");
                printf("|NUMERO DO DADO\t\t\tNUMERO\n");
                for (int cont = 0; cont <= quantidade_de_dados - 1; cont++)
                {
                    d20 = RODAR_D20;
                    printf("|> %d\t\t\t\t%d\n", cont + 1, d20);
                }
                printf("| Deseja rodar mais dados?\n");
                printf("|> 1 - Sim 2 - Nao\n");
                printf("| ");
                scanf("%d", &escolha);
                switch (escolha)
                {
                case 1:
                    rodando_d20 = true;
                    break;
                case 2:
                    rodando_d20 = false;
                    break;
                default:
                    system("cls");
                    printf("| ERRO DIGITE UMA OPCAO VALIDA\n");
                    system("PAUSE");
                    break;
                }
            } while (rodando_d20);
            break;
        case 3: // Setar buffs
            do
            {
                system("cls");
                printf("| Escolha qual classe deseja mudar o buff\n");
                printf("| 1 - Anao\n");
                printf("| 2 - Elfos\n");
                printf("| 3 - Humano\n");
                printf("| 4 - Orc\n");
                printf("| 5 - Gigante\n");
                printf("| 6 - DarkElf\n");
                printf("| 7 - VOLTAR AO MENU\n");
                printf("| > ");
                scanf("%d", &escolha);
                switch (escolha)
                {
                case ANAO:
                    system("cls");
                    printf("|> ATRIBUTOS ANAO\n");
                    for (atributo = 0; atributo < NUMERO_DE_ATRIBUTOS; atributo++)
                    {
                        print_atributo(atributo);
                        scanf("%d", &anao_buff[atributo]);
                        setar_buff = false;
                    }
                    break;
                case 2:
                    system("cls");
                    printf("|> ATRIBUTOS ELFO\n");
                    for (atributo = 0; atributo < NUMERO_DE_ATRIBUTOS; atributo++)
                    {
                        print_atributo(atributo);
                        scanf("%d", &elfos_buff[atributo]);
                        setar_buff = false;
                    }
                    break;
                case 3:
                    system("cls");
                    printf("|> ATRIBUTOS HUMANO\n");
                    for (atributo = 0; atributo < NUMERO_DE_ATRIBUTOS; atributo++)
                    {
                        print_atributo(atributo);
                        scanf("%d", &humano_buff[atributo]);
                    }
                    setar_buff = false;
                    break;
                case 4:
                    system("cls");
                    printf("|> ATRIBUTOS OGRO\n");
                    for (atributo = 0; atributo < NUMERO_DE_ATRIBUTOS; atributo++)
                    {
                        print_atributo(atributo);
                        scanf("%d", &ogro_buff[atributo]);
                        setar_buff = false;
                    }
                    break;
                case 5:
                    system("cls");
                    printf("|> ATRIBUTOS GIGANTE\n");
                    for (atributo = 0; atributo < NUMERO_DE_ATRIBUTOS; atributo++)
                    {
                        print_atributo(atributo);
                        scanf("%d", &gigante_buff[atributo]);
                        setar_buff = false;
                    }
                    break;
                case 6:
                    system("cls");
                    printf("|> ATRIBUTOS DARK ELF\n");
                    for (atributo = 0; atributo < NUMERO_DE_ATRIBUTOS; atributo++)
                    {
                        print_atributo(atributo);
                        scanf("%d", &darkelf_buff[atributo]);
                        setar_buff = false;
                    }
                    break;
                case 7:
                    setar_buff = false;
                    break;
                default:
                    system("cls");
                    printf("| ERRO DIGITE UMA OPCAO VALIDA\n");
                    system("PAUSE");
                    setar_buff = true;
                    break;
                }
            } while (setar_buff);
            break;
        case 4:
            system("cls");
            printf("| PROGRAMA ENCERRADO.\n\n");
            programa = false;
            break;
        default:
            system("cls");
            printf("| ERRO! DIGITE UMA OPCAO VALIDA.\n\n");
            system("PAUSE");
            break;
        }
    }
}

void rodardados()
{
    forca = RODAR_D20;
    destreza = RODAR_D20;
    constuicao = RODAR_D20;
    inteligencia = RODAR_D20;
    sabedoria = RODAR_D20;
    carisma = RODAR_D20;
    // Buffs
    switch (raca_rand)
    {
    case ANAO: // Anão
        sprintf(raca, "Anao");
        forca += anao_buff[FORCA_BUFF];
        destreza += anao_buff[DESTREZA_BUFF];
        constuicao += anao_buff[CONSTUICAO_BUFF];
        inteligencia += anao_buff[INTELIGENCIA_BUFF];
        sabedoria += anao_buff[SABEDORIA_BUFF];
        carisma += anao_buff[CARISMA_BUFF];
        break;
    case ELFOS: // Elfos
        sprintf(raca, "Elfos");
        forca += elfos_buff[FORCA_BUFF];
        destreza += elfos_buff[DESTREZA_BUFF];
        constuicao += elfos_buff[CONSTUICAO_BUFF];
        inteligencia += elfos_buff[INTELIGENCIA_BUFF];
        sabedoria += elfos_buff[SABEDORIA_BUFF];
        carisma += elfos_buff[CARISMA_BUFF];
        break;
    case HUMANO: // Humano
        sprintf(raca, "Humano");
        forca += humano_buff[FORCA_BUFF];
        destreza += humano_buff[DESTREZA_BUFF];
        constuicao += humano_buff[CONSTUICAO_BUFF];
        inteligencia += humano_buff[INTELIGENCIA_BUFF];
        sabedoria += humano_buff[SABEDORIA_BUFF];
        carisma += humano_buff[CARISMA_BUFF];
        break;
    case ORC: // Orc
        sprintf(raca, "Ogro");
        forca += ogro_buff[FORCA_BUFF];
        destreza += ogro_buff[DESTREZA_BUFF];
        constuicao += ogro_buff[CONSTUICAO_BUFF];
        inteligencia += ogro_buff[INTELIGENCIA_BUFF];
        sabedoria += ogro_buff[SABEDORIA_BUFF];
        carisma += ogro_buff[CARISMA_BUFF];
        break;
    case GIGANTE: // Gigante
        sprintf(raca, "Gigante");
        forca += gigante_buff[FORCA_BUFF];
        destreza += gigante_buff[DESTREZA_BUFF];
        constuicao += gigante_buff[CONSTUICAO_BUFF];
        inteligencia += gigante_buff[INTELIGENCIA_BUFF];
        sabedoria += gigante_buff[SABEDORIA_BUFF];
        carisma += gigante_buff[CARISMA_BUFF];
        break;
    case DARKELF: // DarkElf
        sprintf(raca, "DarkElf");
        forca += darkelf_buff[FORCA_BUFF];
        destreza += darkelf_buff[DESTREZA_BUFF];
        constuicao += darkelf_buff[CONSTUICAO_BUFF];
        inteligencia += darkelf_buff[INTELIGENCIA_BUFF];
        sabedoria += darkelf_buff[SABEDORIA_BUFF];
        carisma += darkelf_buff[CARISMA_BUFF];
        break;
    }
}

void print_atributo(int atributo_escolhido)
{
    switch (atributo_escolhido)
    {
    case 0:
        printf("|> Escolha a forca: ");
        break;
    case 1:
        printf("|> Escolha a destreza: ");
        break;
    case 2:
        printf("|> Escolha a constituicao: ");
        break;
    case 3:
        printf("|> Escolha a inteligencia: ");
        break;
    case 4:
        printf("|> Escolha a sabedoria: ");
        break;
    case 5:
        printf("|> Escolha a carisma: ");
        break;
    }
}

void caracteristicas_personagens()
{
    // forca
    if (forca >= 20)
    {
        printf("| [Extremamente forte fisicamente]\n");
    }
    else if (forca >= 16)
    {
        printf("| [Muito forte fisicamente]\n");
    }
    else if (forca >= 10)
    {
        printf("| [Forca normal]\n");
    }
    else if (forca >= 5)
    {
        printf("| [Fraco fisicamente]\n");
    }
    else
    {
        printf("| [Sem forca fisica alguma]\n");
    }
    // destreza
    if (destreza >= 20)
    {
        printf("| [Super rapido]\n");
    }
    else if (destreza >= 16)
    {
        printf("| [Movimentcao rapida]\n");
    }
    else if (destreza >= 10)
    {
        printf("| [Movimentacao normal]\n");
    }
    else if (destreza >= 5)
    {
        printf("| [Movimentacao debilitada]\n");
    }
    else
    {
        printf("| [Mal consegue se mover]\n");
    }
    // constituição
    if (constuicao >= 20)
    {
        printf("| [Corpo extremamente resistente]\n");
    }
    else if (constuicao >= 16)
    {
        printf("| [Corpo muito resistente]\n");
    }
    else if (constuicao >= 10)
    {
        printf("| [Corpo normal]\n");
    }
    else if (constuicao >= 5)
    {
        printf("| [Corpo fragil]\n");
    }
    else
    {
        printf("| [Nao tem corpo fisico]\n");
    }
    // inteligencia
    if (inteligencia >= 20)
    {
        printf("| [Extremamente inteligencia]\n");
    }
    else if (inteligencia >= 16)
    {
        printf("| [Muito inteligente]\n");
    }
    else if (inteligencia >= 10)
    {
        printf("| [Tem um bom raciocinio]\n");
    }
    else if (inteligencia >= 5)
    {
        printf("| [Desprovido de inteligencia]\n");
    }
    else
    {
        printf("| [Sem capacidade cognitiva]\n");
    }
    // sabedoria
    if (sabedoria >= 20)
    {
        printf("| [Consegue compreender todas nuancias de cada evento]\n");
    }
    else if (sabedoria >= 16)
    {
        printf("| [Tem uma boa nocao da situacao em que esta inserido]\n");
    }
    else if (sabedoria >= 10)
    {
        printf("| [Consegue perseber o mundo ao seu redor]\n");
    }
    else if (sabedoria >= 5)
    {
        printf("| [Pouca percepcao do mundo]\n");
    }
    else
    {
        printf("| [Sem tato para perceber o mundo ao seu redor]\n");
    }
    // carisma
    if (carisma >= 20)
    {
        printf("| [Muito atraente e confiante]\n");
    }
    else if (carisma >= 16)
    {
        printf("| [Transparece confiança]\n");
    }
    else if (carisma >= 10)
    {
        printf("| [Aparencia normal]\n");
    }
    else if (carisma >= 5)
    {
        printf("| [Pouco carismatico]\n");
    }
    else
    {
        printf("| [Assustador]\n");
    }
}

void printar_classes()
{
    //Caçador
    if (forca >= 10 && destreza >= 15 && raca_rand != GIGANTE && raca_rand != ANAO && raca_rand != ORC)
    {
        printf("| [%c] Cacador experiente\n", CARACTER_CLASSE);
    }
    else if (forca >= 5 && destreza >= 9 && raca_rand != GIGANTE && raca_rand != ANAO && raca_rand != ORC)
    {
        printf("| [%c] Cacador\n", CARACTER_CLASSE);
    }
    //Mago
    if (inteligencia >= 15 && sabedoria >= 11 && raca_rand != GIGANTE && raca_rand != ANAO && raca_rand != ORC)
    {
        if (raca_rand == ELFOS)
        {
            printf("| [%c] Mago da luz experiente\n", CARACTER_CLASSE);
        }
        else if (raca_rand == DARKELF)
        {
            printf("| [%c] Mago das trevas experiente\n", CARACTER_CLASSE);
        }
        else
        {
            printf("| [%c] Mago experiente\n", CARACTER_CLASSE);
        }
    }
    else if (inteligencia >= 9 && sabedoria >= 5 && raca_rand != GIGANTE && raca_rand != ANAO && raca_rand != ORC)
    {
        if (raca_rand == ELFOS)
        {
            printf("| [%c] Mago branco\n", CARACTER_CLASSE);
        }
        else if (raca_rand == DARKELF)
        {
            printf("| [%c] Mago das trevas\n", CARACTER_CLASSE);
        }
        else
        {
            printf("| [%c] Mago\n", CARACTER_CLASSE);
        }
    }
    //Guerreiro tank
    if (forca >= 15 && constuicao >= 10 && raca_rand != ELFOS && raca_rand != DARKELF)
    {
        if (raca_rand == ORC && inteligencia > 10)
        {
            printf("| [%c] Guerreiro chama experiente\n");
        }
        else
        {
            printf("| [%c] Guerreiro experiente\n", CARACTER_CLASSE);
        }
    }
    else if (forca >= 10 && constuicao >= 7 && raca_rand != ELFOS && raca_rand != DARKELF)
    {
        if (raca_rand == ORC && inteligencia > 10)
        {
            printf("| [%c] Guerreiro chama\n");
        }
        else
        {
            printf("| [%c] Guerreiro\n", CARACTER_CLASSE);
        }
    }
    //Assasino
    if (inteligencia >= 13 && destreza >= 15 && raca_rand != GIGANTE && raca_rand != ANAO && raca_rand != ORC)
    {
        if (raca_rand == ELFOS)
        {
            printf("| [%c] Assasino da floresta experiente\n");
        }
        else if (raca_rand == DARKELF)
        {
            printf("| [%c] Assasino das sombras experiente\n", CARACTER_CLASSE);
        }
        else
        {
            printf("| [%c] Assasino experiente\n", CARACTER_CLASSE);
        }
    }
    else if (inteligencia >= 9 && destreza >= 10 && raca_rand != GIGANTE && raca_rand != ANAO && raca_rand != ORC)
    {
        if (raca_rand == ELFOS)
        {
            printf("| [%c] Assasino da floresta\n");
        }
        else if (raca_rand == DARKELF)
        {
            printf("| [%c] Assasino das sombras\n", CARACTER_CLASSE);
        }
        else
        {
            printf("| [%c] Assasino\n", CARACTER_CLASSE);
        }
    }
}
