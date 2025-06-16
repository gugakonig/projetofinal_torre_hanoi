#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "torre.h"
#include "historico.h"

void exibirColaboradores();

void clear()
{
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[H");
    fflush(stdout);
#endif
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    int funcao;
    Historico *listaHistorico = NULL;

    loadHistorico(&listaHistorico);

    do
    {
        clear();
        printf("            TORRE DE HANÓI              \n");
        printf("======================================\n\n");
        printf("Escolha uma opção:\n");
        printf("  1. Como Jogar\n");
        printf("  2. Jogar\n");
        printf("  3. Ver Histórico de partidas\n");
        printf("  4. Ver Colaboradores\n");
        printf("  0. Sair do Jogo\n\n");
        printf("Digite sua opção: ");
        scanf("%d", &funcao);

        if (funcao == 1)
        {
            instrucoes();
        }
        else if (funcao == 2)
        {
            int numerodediscos;
            char nomedoJogador[30];
            char data[11];

            clear();
            printf("Insira seu nome: ");
            scanf(" %49[^\n]", nomedoJogador);
            printf("Digite a data (DD/MM/AAAA): ");
            scanf(" %10s", data);

            do
            {
                printf("Escolha o número de discos (entre %d e %d): ", MINIMODEDISCOS, MAXIMODEDISCOS);
                scanf("%d", &numerodediscos);
            } while (numerodediscos < MINIMODEDISCOS || numerodediscos > MAXIMODEDISCOS);

            jogar(numerodediscos, nomedoJogador, data, &listaHistorico);
        }

        else if (funcao == 3)
        {
            exibirHistorico(listaHistorico);
        }

        else if (funcao == 4)
        {
            exibirColaboradores();
        }

        else if (funcao == 0)
        {
            clear();
            printf("Obrigado por jogar! Até a próxima!\n\n");
        }

        else
        {
            printf("\nNúmero Inválido! Pressione a tecla 'Enter' para tentar novamente!");
            getchar();
            getchar();
        }
    } while (funcao != 0);

    liberarHistorico(listaHistorico);
    return 0;
}

void instrucoes()
{
    clear();
    printf("           COMO JOGAR           \n");
    printf("================================\n\n");
    printf("Objetivo Geral:\n");
    printf(" Mover todos os discos da haste inicial (A) para a haste de destino (C) com o m?nimo de movimentos.\n\n");

    printf("Como Jogar:\n");
    printf("  1. É possível mexer somente um disco por vez.\n");
    printf("  2. Somente é possível colocar um disco sobre outro quando a base for maior.\n");
    printf("  3. Para fazer o movimento dos discos entre as torres, devem ser utilizados as teclas A, B, C.\n");
    printf("  4. Em primeiro caso, selecione a torre de origem (A) e depois a torre de destino (C). (Ex.: AC).\n");
    printf("  5. Utilize a tecla 'Q' (Quit) para sair do jogo!\n");
    printf("  6. Utilize a tecla 'R' (Reset) para reiniciar o jogo!\n\n");
    printf("Pressione a tecla 'Enter' para retornar ao menu principal!\n");

    getchar();
    getchar();
}

void exibirHistorico(Historico *lista)
{
    clear();
    printf("       HISTÓRICO DE PARTIDAS    \n");
    printf("================================\n\n");
    if (lista == NULL)
    {
        printf("Nenhuma partida foi registrada até o momento!\n");
    }
    else
    {
        printf("%-20s / %-12s / %-7s / %s\n", "Jogador", "Data", "Discos", "Movimentos");
        Historico *atual = lista;
        while (atual != NULL)
        {
            printf("%-20s / %-12s / %-7d / %d\n",
                   atual->nomedoJogador, atual->data, atual->modoJogo, atual->movimentos);
            atual = atual->proximo;
        }
    }
    printf("\n\nPressione a tecla 'Enter' para retornar ao menu principal!\n");
    getchar();
    getchar();
}

void exibirColaboradores()
{

    clear();
    printf("        COLABORADORES           \n");
    printf("================================\n\n");
    printf("Gustavo Domingues de Sousa\n");
    printf("Henrique Vinhal Rocha\n\n");

    printf("\nPressione a tecla 'Enter' para retornar ao menu principal!\n");
    getchar();
    getchar();
}
