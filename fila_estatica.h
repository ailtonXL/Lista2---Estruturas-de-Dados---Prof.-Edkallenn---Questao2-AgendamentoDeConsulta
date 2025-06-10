#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

/*
** Função: Interface do TAD Fila Estática (para Médicos)
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Define operações para uma fila de tamanho fixo para agendamento médico.
*/

#define MAX_MEDICOS 5 // Limite de 5 pacientes por médico 

typedef struct {
    char nome_paciente[50];
    // Outros dados do paciente podem ser adicionados aqui
} PacienteMedico;

typedef struct {
    PacienteMedico pacientes[MAX_MEDICOS];
    int frente;
    int re_final;
    int tamanho;
} FilaEstatica;

// Protótipos
FilaEstatica* criar_fila_estatica();
void destruir_fila_estatica(FilaEstatica *f);
int enfileirar_estatica(FilaEstatica *f, PacienteMedico p); // Retorna 1 se sucesso, 0 se falha
PacienteMedico desenfileirar_estatica(FilaEstatica *f); // Retorna o paciente, ou um paciente "nulo"
int fila_estatica_vazia(FilaEstatica *f);
int fila_estatica_cheia(FilaEstatica *f);
void imprimir_fila_estatica(FilaEstatica *f);

#endif