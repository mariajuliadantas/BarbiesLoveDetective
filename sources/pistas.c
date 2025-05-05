#include <stdlib.h>
#include <string.h>
#include "../include/pistas.h"

void adicionarPista(Pista** lista, const char* descricao, int relevancia) {
    Pista* nova = (Pista*)malloc(sizeof(Pista));
    strcpy(nova->descricao, descricao);
    nova->relevancia = relevancia;
    nova->prox = *lista;
    *lista = nova;
}

