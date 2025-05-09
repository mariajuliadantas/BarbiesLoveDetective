//#include <stdio.h>
//#include "jogo.h"
//#include "personagens.h"
//#include "pistas.h"

//void iniciarJogo() {
    // Loop principal do jogo
//}

#include <stdlib.h>
#include <string.h>
#include "../include/pistas.h"

// Função para adicionar uma nova pista à lista encadeada
void adicionarPista(Pista** lista, const char* descricao, int relevancia) {
    Pista* nova = (Pista*)malloc(sizeof(Pista));
    if (nova == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    // Copia a descrição da pista para o nó
    strncpy(nova->descricao, descricao, sizeof(nova->descricao) - 1);
    nova->descricao[sizeof(nova->descricao) - 1] = '\0';  // Garante que a string esteja terminada corretamente
    nova->relevancia = relevancia;  // Define a relevância
    nova->prox = *lista;  // Adiciona no início da lista

    *lista = nova;  // Atualiza o ponteiro para a lista
}

// Função para mostrar todas as pistas
void mostrarPistas(Pista* lista) {
    Pista* temp = lista;
    while (temp != NULL) {
        printf("Pista: %s (Relevância: %d)\n", temp->descricao, temp->relevancia);
        temp = temp->prox;
    }
}

// Função para ordenar as pistas por relevância ou nome, conforme necessário
void ordenarPistas(Pista** lista) {
    // Aqui, você pode implementar a lógica de ordenação, caso queira
}

