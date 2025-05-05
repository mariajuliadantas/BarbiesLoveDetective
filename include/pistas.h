#ifndef PISTAS_H
#define PISTAS_H

typedef struct Pista {
    char descricao[256];
    int relevancia;
    struct Pista* prox;
} Pista;

void adicionarPista(Pista** lista, const char* descricao, int relevancia);
void mostrarPistas(Pista* lista);
void ordenarPistas(Pista** lista);

#endif

