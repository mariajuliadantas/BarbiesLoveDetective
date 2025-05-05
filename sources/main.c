#include "raylib.h"
#include "../include/pistas.h"
#include <stddef.h>


#define SCREEN_WIDTH (1800)
#define SCREEN_HEIGHT (950)

#define WINDOW_TITLE "Window title"

typedef enum { TELA_INICIAL, NARRATIVA, ESCOLHA } EstadoDoJogo;

int main(void) {
    InitAudioDevice();  // Inicializa o áudio
    InitWindow(800, 450, "Quem é o Crush Secreto da Barbie?");
    SetTargetFPS(60);

    // Carrega a música
    Music musica = LoadMusicStream("../assets/Barbie Girl.mp3");
    PlayMusicStream(musica);

    EstadoDoJogo estado = TELA_INICIAL;

    Rectangle botaoComecar = { 300, 200, 200, 50 };
    int passoTexto = 0;
    const char *textos[] = {
        "Era uma vez uma Barbie em duvida...",
        "Bilhetes misteriosos começaram a aparecer.",
        "Alguém está apaixonado por ela!",
        "Mas quem será o admirador secreto?"
    };
    int totalTextos = sizeof(textos) / sizeof(textos[0]);

    // Lista de pistas (estrutura de dados)
    Pista* listaPistas = NULL;
    int pistaAdicionada = 0; // garante que só adiciona uma vez por escolha


    while (!WindowShouldClose()) {
        UpdateMusicStream(musica);  // Atualiza a música

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (estado) {
            case TELA_INICIAL:
                DrawText("Quem é o Crush Secreto da Barbie? ", 100, 100, 30, PINK);
                DrawRectangleRec(botaoComecar, LIGHTGRAY);
                DrawText("COMEÇAR", botaoComecar.x + 50, botaoComecar.y + 15, 20, BLACK);

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
                    CheckCollisionPointRec(GetMousePosition(), botaoComecar)) {
                    estado = NARRATIVA;
                }
                break;

            case NARRATIVA:
                DrawText(textos[passoTexto], 80, 180, 22, BLACK);
                DrawText("Pressione ESPAÇO para continuar...", 80, 360, 16, GRAY);

                if (IsKeyPressed(KEY_SPACE)) {
                    passoTexto++;
                    if (passoTexto >= totalTextos) {
                        estado = ESCOLHA;
                    }
                }
                break;

                case ESCOLHA:
                DrawText("Barbie tem dois suspeitos:", 80, 100, 22, DARKBLUE);
                DrawText("1 - Ken: sempre elegante e carinhoso", 100, 160, 20, BLACK);
                DrawText("2 - Ryan: divertido, misterioso e ousado", 100, 200, 20, BLACK);
                DrawText("Pressione 1 ou 2 para escolher", 100, 300, 18, GRAY);
            
                // Adiciona a pista com base na escolha do jogador (somente 1 vez)
                if (IsKeyPressed(KEY_ONE)) {
                    if (!pistaAdicionada) {
                        adicionarPista(&listaPistas, "Ken foi visto deixando flores na porta da Barbie!", 3);
                        pistaAdicionada = 1;
                    }
                }
            
                if (IsKeyPressed(KEY_TWO)) {
                    if (!pistaAdicionada) {
                        adicionarPista(&listaPistas, "Ryan escreveu um bilhete misterioso.", 2);
                        pistaAdicionada = 1;
                    }
                }
            
                //Exibe todas as pistas já adicionadas
                int y = 350;
                Pista* atual = listaPistas;
                while (atual != NULL) {
                    DrawText(atual->descricao, 100, y, 18, DARKGRAY);
                    y += 30;
                    atual = atual->prox;
                }
                break;
            
        }

        EndDrawing();
    }

    // Encerra a música e áudio
    UnloadMusicStream(musica);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
