#include "ia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"

// Função para consultar a IA (usando Gemini) com um prompt
void consultarIA(const char* prompt, char* resposta) {
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;
    char url[] = "https://api.gemini.com/v1/query"; // Coloque a URL da Gemini

    // Configurar o prompt e enviar para a IA
    cJSON *json = cJSON_CreateObject();
    cJSON_AddStringToObject(json, "query", prompt);
    char *data = cJSON_Print(json);
    cJSON_Delete(json);

    // Configuração da requisição HTTP
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Curl request failed: %s\n", curl_easy_strerror(res));
        } else {
            // Aqui você irá processar a resposta da IA
            strcpy(resposta, "Resposta da IA aqui");
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

// Função para modificar as pistas com base na resposta da IA
void modificarPistas(Pista** listaPistas, const char* resposta) {
    // Adicionar lógica para manipular pistas baseadas na resposta da IA
    if (strstr(resposta, "Ken") != NULL) {
        adicionarPista(listaPistas, "Ken foi visto deixando flores na porta da Barbie!", 3);
    } else if (strstr(resposta, "Ryan") != NULL) {
        adicionarPista(listaPistas, "Ryan escreveu um bilhete misterioso.", 2);
    }
}
