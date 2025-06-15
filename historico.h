#ifndef HISTORICO_H
#define HISTORICO_H

typedef struct Historico
{
    char nomedoJogador[30];
    char data[11];
    int modoJogo;
    int movimentos;
    struct Historico *proximo;
} Historico;

void adicionarHistoricoLista(Historico **lista, const char *nome, const char *data, int quantDiscos, int movimentos);
void salvarHistoricoArquivo(const char *nome, const char *data, int quantDiscos, int movimentos);
void loadHistorico(Historico **lista);
void exibirHistorico(Historico *lista);
void liberarHistorico(Historico *lista);

#endif