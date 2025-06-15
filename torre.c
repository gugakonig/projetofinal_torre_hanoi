#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "torre.h"
#include "historico.h"

void carregarTorre(TORRE *torre)
{
    (*torre).topo = -1;
}

int organizarTorre(TORRE *torre, int disco)
{
    if ((*torre).topo >= MAXIMODEDISCOS - 1)
        return 0;
    (*torre).discos[++(*torre).topo] = disco;
    return 1;
}
int desmontarTorre(TORRE *torre)
{
    if ((*torre).topo < 0)
        return -1;
    return (*torre).discos[(*torre).topo--];
}
int topo(TORRE *torre)
{
    if ((*torre).topo < 0)
        return -1;
    return (*torre).discos[(*torre).topo];
}
void mostrarDisco(int tamanho, int larguraMax)
{
    int larguraDisco = tamanho == 0 ? 1 : 2 * tamanho - 1;
    int espacos = (larguraMax - larguraDisco) / 2;

    for (int i = 0; i < espacos; i++)
        printf(" ");
    if (tamanho == 0)
        printf("|");
    else
        for (int i = 0; i < larguraDisco; i++)
            printf("*");
    for (int i = 0; i < espacos; i++)
        printf(" ");
}
void exibirTorres(TORRE torres[], int numeroDiscos)
{
    clear();
    printf("\nTorre de Hanoi - %d discos\n\n", numeroDiscos);

    for (int nivel = numeroDiscos - 1; nivel >= 0; nivel--)
    {
        for (int i = 0; i < NUMERODETORRES; i++)
        {
            int disco = nivel <= torres[i].topo ? torres[i].discos[nivel] : 0;
            mostrarDisco(disco, 2 * numeroDiscos - 1);
            printf("   ");
        }
        printf("\n");
    }

    const char nomes[] = {'A', 'B', 'C'};
    for (int i = 0; i < NUMERODETORRES; i++)
    {
        int largura = 2 * numeroDiscos - 1;
        for (int j = 0; j < largura / 2; j++)
            printf(" ");
        printf("%c", nomes[i]);
        for (int j = 0; j < largura / 2; j++)
            printf(" ");
        printf("   ");
    }
    printf("\n");
}

int indiceTorre(char letra)
{
    letra = toupper(letra);
    if (letra == 'A')
        return 0;
    if (letra == 'B')
        return 1;
    if (letra == 'C')
        return 2;
    return -1;
}

int jogoConcluido(TORRE *torreFinal, int numeroDiscos)
{
    if ((*torreFinal).topo + 1 != numeroDiscos)
        return 0;
    for (int i = 0; i < numeroDiscos; i++)
    {
        if ((*torreFinal).discos[i] != numeroDiscos - i)
            return 0;
    }
    return 1;
}
void jogar(int numeroDiscos, const char *nome, const char *data, Historico **listahistorico)
{
    TORRE torres[NUMERODETORRES];
    for (int i = 0; i < NUMERODETORRES; i++)
        carregarTorre(&torres[i]);

    for (int i = numeroDiscos; i >= 1; i--)
        organizarTorre(&torres[0], i);

    char origem, destino;
    int movimentos = 0;

    while (1)
    {
        exibirTorres(torres, numeroDiscos);
        printf("\n\nQuantidade de movimentos: %d\n", movimentos);

        if (jogoConcluido(&torres[2], numeroDiscos))
        {
            printf("\nParanéns, %s! Jogo concluído com sucesso!\n", nome);

            salvarHistoricoArquivo(nome, data, numeroDiscos, movimentos);
            adicionarHistoricoLista(listahistorico, nome, data, numeroDiscos, movimentos);

            printf("O histórico da partida foi salvo com êxito!\n\n");
            printf("Pressione a tecla 'Enter' para retornar ao menu!");
            getchar();
            getchar();
            break;
        }

        printf("\nDigite movimento (Ex.: AB): ");
        scanf(" %c", &origem);

        if (toupper(origem) == 'Q')
            break;
        if (toupper(origem) == 'R')
        {
            jogar(numeroDiscos, nome, data, listahistorico);
            return;
        }

        scanf("%c", &destino);

        int idxOrigem = indiceTorre(origem);
        int idxDestino = indiceTorre(destino);

        if (idxOrigem == -1 || idxDestino == -1)
        {
            printf("Torres inválidas! Pressione a tecla 'Enter' para tentar novamente!");
            getchar();
            getchar();
            continue;
        }

        int disco = topo(&torres[idxOrigem]);
        if (disco == -1 || (topo(&torres[idxDestino]) != -1 && topo(&torres[idxDestino]) < disco))
        {
            printf("Movimento inválido! Pressione a tecla 'Enter' para tentar novamente!");
            getchar();
            getchar();
            continue;
        }

        desmontarTorre(&torres[idxOrigem]);
        organizarTorre(&torres[idxDestino], disco);
        movimentos++;
    }
}
