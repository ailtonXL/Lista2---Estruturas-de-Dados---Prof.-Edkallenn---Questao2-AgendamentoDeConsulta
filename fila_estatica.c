#include "fila_estatica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcpy

/*
** Função: Implementação do TAD Fila Estática
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Contém a lógica das operações da fila estática para agendamentos médicos.
*/

FilaEstatica* criar_fila_estatica() {
    FilaEstatica *f = (FilaEstatica*) malloc(sizeof(FilaEstatica));
    if (f == NULL) {
        printf("Erro ao alocar memoria para a fila estatica!\n");
        return NULL;
    }
    f->frente = 0;
    f->re_final = -1; // Indica fila vazia
    f->tamanho = 0;
    return f;
}

void destruir_fila_estatica(FilaEstatica *f) {
    if (f != NULL) {
        free(f);
        printf("Fila estatica destruida.\n");
    }
}

int fila_estatica_vazia(FilaEstatica *f) {
    return f->tamanho == 0;
}

int fila_estatica_cheia(FilaEstatica *f) {
    return f->tamanho == MAX_MEDICOS;
}

int enfileirar_estatica(FilaEstatica *f, PacienteMedico p) {
    if (f == NULL || fila_estatica_cheia(f)) {
        printf("Erro: Fila estatica cheia ou nao inicializada.\n");
        return 0; // Falha
    }
    f->re_final = (f->re_final + 1) % MAX_MEDICOS;
    f->pacientes[f->re_final] = p;
    f->tamanho++;
    printf("Paciente %s enfileirado para medico.\n", p.nome_paciente);
    return 1; // Sucesso
}

PacienteMedico desenfileirar_estatica(FilaEstatica *f) {
    PacienteMedico paciente_nulo = {""}; // Paciente "nulo" para indicar erro
    if (f == NULL || fila_estatica_vazia(f)) {
        printf("Erro: Fila estatica vazia ou nao inicializada.\n");
        return paciente_nulo;
    }
    PacienteMedico p = f->pacientes[f->frente];
    f->frente = (f->frente + 1) % MAX_MEDICOS;
    f->tamanho--;
    printf("Paciente %s desenfileirado de medico.\n", p.nome_paciente);
    return p;
}

void imprimir_fila_estatica(FilaEstatica *f) {
    if (f == NULL || fila_estatica_vazia(f)) {
        printf("Fila de medicos vazia.\n");
        return;
    }
    printf("Fila de medicos (tamanho: %d/%d): [", f->tamanho, MAX_MEDICOS);
    int i = f->frente;
    int count = 0;
    while (count < f->tamanho) {
        printf("%s", f->pacientes[i].nome_paciente);
        count++;
        if (count < f->tamanho) {
            printf(", ");
        }
        i = (i + 1) % MAX_MEDICOS;
    }
    printf("]\n");
}