#ifndef FILA_DINAMICA_H
#define FILA_DINAMICA_H

/*
** Função: Interface do TAD Fila Dinâmica (para Enfermagem)
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Define operações para uma fila ilimitada para agendamento de enfermagem.
*/

typedef struct PacienteEnfermagem {
    char nome_paciente[50];
    // Outros dados do paciente podem ser adicionados aqui
    struct PacienteEnfermagem *prox;
} PacienteEnfermagem;

typedef struct {
    PacienteEnfermagem *frente;
    PacienteEnfermagem *re_final;
    int tamanho;
} FilaDinamica;

// Protótipos
FilaDinamica* criar_fila_dinamica();
void destruir_fila_dinamica(FilaDinamica *f);
int enfileirar_dinamica(FilaDinamica *f, char *nome); // Retorna 1 se sucesso, 0 se falha
PacienteEnfermagem* desenfileirar_dinamica(FilaDinamica *f); // Retorna o ponteiro para o paciente, ou NULL
int fila_dinamica_vazia(FilaDinamica *f);
void imprimir_fila_dinamica(FilaDinamica *f);

#endif