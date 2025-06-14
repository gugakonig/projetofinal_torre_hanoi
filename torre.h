#ifndef TORRE_H
#define TORRE_H

#define MAXIMODEDISCOS 5
#define MINIMODEDISCOS 3
#define NUMERODETORRES 3

typedef struct {
    int discos [MAXIMODEDISCOS];
    int topo;

} TORRE;

void clear();
void instrucoes();
void carregarTorre(TORRE *torre);
int organizarTorre(TORRE *torre, int disco);
int desmontarTorre(TORRE *torre);
int topo (TORRE *torre);
void mostrarDisco(int tamanho, int larguraMax);
void exibirTorres(TORRE torres[], int numeroDiscos);
int indiceTorre(char letra);
int jogoConcluido(TORRE *torreFinal, int numeroDiscos);
void jogar(int numeroDiscos);

#endif
