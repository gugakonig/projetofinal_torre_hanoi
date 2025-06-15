#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "torre.h"
#include "historico.h"


void adicionarHistoricoLista(Historico **lista, const char *nome, const char *data, int quantDiscos, int movimentos)
{
    Historico *registro = (Historico *)malloc(sizeof(Historico));
    if (!registro)
    {

        perror("Falha ao tentar alocar memória para o histórico!");
        return;
    }
    strncpy(registro->nomedoJogador, nome, 29);
    registro->nomedoJogador[29] = '\0';

    strncpy(registro->data, data, 10);
    registro->data[10] = '\0';
    registro->modoJogo = quantDiscos;
    registro->movimentos = movimentos;
    registro->proximo = *lista;
    *lista = registro;
}

void salvarHistoricoArquivo(const char *nome, const char *data, int quantDiscos, int movimentos)
{
    FILE *arquivo = fopen("HistoricoDePartidas.txt", "a");
    if (arquivo == NULL)
    {
        perror("Não foi possível abrir o arquivo de histórico de partidas!");
        return;
    }
    fprintf(arquivo, "%s / %s / %d / %d\n", nome, data, quantDiscos, movimentos);
    fclose(arquivo);
}

void loadHistorico(Historico **lista)
{
    FILE *arquivo = fopen("HistoricoDePartidas.txt", "r");
    if (arquivo == NULL)
    {
        return;
    }
    char linha[200];
    char nomedoJogador[30], data[11];
    int modoJogo, movimentos;

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%49[^;]/ %10[^;]/ %d/ %d", nomedoJogador, data, &modoJogo, &movimentos) == 4)
        {
            adicionarHistoricoLista(lista, nomedoJogador, data, modoJogo, movimentos);
        }
    }
    fclose(arquivo);
}

void liberarHistorico(Historico *lista)
{
    Historico *atual = lista;
    Historico *proximo;
    while (atual != NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}
