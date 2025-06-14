#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "torre.h"

void clear() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[H");
    fflush(stdout);
#endif
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    int funcao;

    do {
        clear();
        printf("            TORRE DE HANÓI              \n");
        printf("======================================\n\n");
        printf("Escolha uma opção:\n");
        printf("  1. Como Jogar\n");
        printf("  2. Jogar\n");
        printf("  3. Ver Histórico de partidas\n");
        printf("  0. Sair do Jogo\n\n");
        printf("Digite sua opção: ");
        scanf("%d", &funcao);

        if (funcao == 1) {
            instrucoes();
        }
        else if (funcao == 2) {
            int numerodediscos;
            do {
                printf("Escolha o número de discos (entrte %d e %d)", MINIMODEDISCOS, MAXIMODEDISCOS);
                scanf("%d", &numerodediscos);
                if (numerodediscos < MINIMODEDISCOS || numerodediscos > MAXIMODEDISCOS) {
                    printf ("Número inválido! Pressione a tecla 'ENTER' para tentar novamente.\n");
                    getchar(); getchar();
                    clear();
                }
                 
            } while (numerodediscos < MINIMODEDISCOS || numerodediscos > MAXIMODEDISCOS);
            
            jogar(numerodediscos);

        }
        else if (funcao == 0) {
            clear();
            printf("Obrigado por jogar!\n\n");
        }
        else {
            printf("\nOpção Inválida! Pressione a tecla 'Enter' para tentar novamente!");
            getchar(); getchar();
        }

    } while (funcao != 0);

    return 0;
}

void instrucoes() {
    clear();
    printf("           COMO JOGAR           \n");
    printf("================================\n\n");
    printf("Objetivo:\n");
    printf(" Mover todos os discos da haste inicial (A) para a haste de destino (C).\n\n");

    printf("Como Jogar:\n");
    printf("  1. É possível mexer somente um disco por vez.\n");
    printf("  2. Só é possível colocar um disco sobre outro quando a base for maior.\n");
    printf("  3. Para sair do jogo, utilize a tecla 'Q' (quit)!\n");
    printf("  4. Para reiniciar o jogo, utilize a tecla 'R' (reset)!\n");
    printf("Pressione a tecla 'Enter' para retornar ao menu principal!\n");

    getchar(); 
    getchar();
}
