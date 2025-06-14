#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


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
        printf("            TORRE DE HAN�I              \n");
        printf("======================================\n\n");
        printf("Escolha uma op��o:\n");
        printf("  1. Como Jogar\n");
        printf("  2. Jogar\n");
        printf("  3. Ver Hist�rico de partidas\n");
        printf("  0. Sair do Jogo\n\n");
        printf("Digite sua op��o: ");
        scanf("%d", &funcao);

        if (funcao == 1) {
            instrucoes();
        }
        else if (funcao == 2) {
            clear();
            printf("implenta��o - torres\n");
            printf("Pressione a tecla 'Enter' para retornar ao menu principal.\n");
            getchar();
            getchar();
        }
        
        else if (funcao == 0) {
            clear();
            printf("Obrigado por jogar!\n\n");
        }
        else {
            printf("\nOp��o Inv�lida! Pressione a tecla 'Enter' para tentar novamente!");

            getchar();
            getchar();
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
    printf("  1. � poss�vel mexer somente um disco por vez.\n");
    printf("  2. S� e poss�vel colocar um disco sobre outro quando a base for maior.\n");
    printf("Pressione a tecla 'Enter' para retornar ao menu principal!\n");

    getchar(); 
    getchar();
}
