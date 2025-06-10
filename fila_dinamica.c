#include "fila_dinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Função: Implementação do TAD Fila Dinâmica
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Contém a lógica das operações da fila dinâmica para agendamentos de enfermagem.
*/

FilaDinamica* criar_fila_dinamica() {
    FilaDinamica *f = (FilaDinamica*) malloc(sizeof(FilaDinamica));
    if (f == NULL) {
        printf("Erro ao alocar memoria para a fila dinamica!\n");
        return NULL;
    }
    f->frente = NULL;
    f->re_final = NULL;
    f->tamanho = 0;
    return f;
}

void destruir_fila_dinamica(FilaDinamica *f) {
    if (f != NULL) {
        PacienteEnfermagem *atual = f->frente;
        while (atual != NULL) {
            PacienteEnfermagem *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(f);
        printf("Fila dinamica destruida.\n");
    }
}

int fila_dinamica_vazia(FilaDinamica *f) {
    return f->frente == NULL; // Ou f->tamanho == 0
}

int enfileirar_dinamica(FilaDinamica *f, char *nome) {
    if (f == NULL) {
        printf("Fila dinamica nao inicializada.\n");
        return 0;
    }
    PacienteEnfermagem *novo_paciente = (PacienteEnfermagem*) malloc(sizeof(PacienteEnfermagem));
    if (novo_paciente == NULL) {
        printf("Erro ao alocar memoria para novo paciente.\n");
        return 0;
    }
    strcpy(novo_paciente->nome_paciente, nome);
    novo_paciente->prox = NULL;

    if (fila_dinamica_vazia(f)) {
        f->frente = novo_paciente;
        f->re_final = novo_paciente;
    } else {
        f->re_final->prox = novo_paciente;
        f->re_final = novo_paciente;
    }
    f->tamanho++;
    printf("Paciente %s enfileirado para enfermagem.\n", nome);
    return 1;
}

PacienteEnfermagem* desenfileirar_dinamica(FilaDinamica *f) {
    if (f == NULL || fila_dinamica_vazia(f)) {
        printf("Erro: Fila dinamica vazia ou nao inicializada.\n");
        return NULL;
    }
    PacienteEnfermagem *paciente_removido = f->frente;
    f->frente = f->frente->prox;
    if (f->frente == NULL) { // Se a fila ficou vazia após a remoção
        f->re_final = NULL;
    }
    f->tamanho--;
    printf("Paciente %s desenfileirado de enfermagem.\n", paciente_removido->nome_paciente);
    return paciente_removido; // O chamador deve liberar este nó!
}

void imprimir_fila_dinamica(FilaDinamica *f) {
    if (f == NULL || fila_dinamica_vazia(f)) {
        printf("Fila de enfermagem vazia.\n");
        return;
    }
    printf("Fila de enfermagem (tamanho: %d): [", f->tamanho);
    PacienteEnfermagem *atual = f->frente;
    while (atual != NULL) {
        printf("%s", atual->nome_paciente);
        atual = atual->prox;
        if (atual != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}