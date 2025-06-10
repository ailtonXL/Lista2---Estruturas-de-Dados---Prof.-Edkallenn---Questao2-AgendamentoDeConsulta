#include <stdio.h>
#include <string.h>
#include "fila_estatica.h"
#include "fila_dinamica.h"

/*
** Função: Sistema de Agendamento de Consultas
** Autor: [Seu Nome], [Sua Turma]
** Data: [Data de Hoje]
** Observações: Simula um sistema de agendamento usando fila estática para médicos e dinâmica para enfermagem.
*/

void menu() {
    printf("\n--- Sistema de Agendamento de Consultas ---\n");
    printf("1. Agendar consulta com Medico\n");
    printf("2. Agendar consulta com Enfermagem\n");
    printf("3. Atender proximo paciente (Medico)\n");
    printf("4. Atender proximo paciente (Enfermagem)\n");
    printf("5. Mostrar filas de agendamento\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    FilaEstatica *fila_medico = criar_fila_estatica();
    FilaDinamica *fila_enfermagem = criar_fila_dinamica();
    int opcao;
    char nome[50];
    PacienteMedico p_medico;
    PacienteEnfermagem *p_enfermagem;

    if (fila_medico == NULL || fila_enfermagem == NULL) {
        return 1; // Erro na criação das filas
    }

    do {
        menu();
        scanf("%d", &opcao);
        getchar(); // Consome o '\n' restante

        switch (opcao) {
            case 1: // Agendar medico
                printf("Nome do paciente para medico: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove o '\n'
                strcpy(p_medico.nome_paciente, nome);
                enfileirar_estatica(fila_medico, p_medico);
                break;
            case 2: // Agendar enfermagem
                printf("Nome do paciente para enfermagem: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove o '\n'
                enfileirar_dinamica(fila_enfermagem, nome);
                break;
            case 3: // Atender medico
                p_medico = desenfileirar_estatica(fila_medico);
                if (strcmp(p_medico.nome_paciente, "") != 0) {
                    printf("Paciente %s atendido por medico.\n", p_medico.nome_paciente);
                }
                break;
            case 4: // Atender enfermagem
                p_enfermagem = desenfileirar_dinamica(fila_enfermagem);
                if (p_enfermagem != NULL) {
                    printf("Paciente %s atendido por enfermagem.\n", p_enfermagem->nome_paciente);
                    free(p_enfermagem); // Libera a memória do nó do paciente
                }
                break;
            case 5: // Mostrar filas
                imprimir_fila_estatica(fila_medico);
                imprimir_fila_dinamica(fila_enfermagem);
                break;
            case 0:
                printf("Saindo do sistema.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    destruir_fila_estatica(fila_medico);
    destruir_fila_dinamica(fila_enfermagem);

    return 0;
}