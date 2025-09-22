#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

struct Turma{
	string nome;
	vector<string> alunos;
};

int main () {
    int qtdTurmas;
    printf("Quantas turmas? ");
    scanf("%d", &qtdTurmas);

    float ***notas = (float ***) malloc(qtdTurmas * sizeof(float **));

    int qtdAlunos[qtdTurmas], qtdNotas[qtdTurmas]; // guardar quantidades

    for (int i = 0; i < qtdTurmas; i++) {
        printf("\nTurma %d:\n", i + 1);

        printf("Quantos alunos na turma %d? ", i + 1);
        scanf("%d", &qtdAlunos[i]);

        printf("Quantas notas por aluno? ");
        scanf("%d", &qtdNotas[i]);

        // alocar alunos
        notas[i] = (float **) malloc(qtdAlunos[i] * sizeof(float *));

        for (int j = 0; j < qtdAlunos[i]; j++) {
            // alocar notas
            notas[i][j] = (float *) malloc(qtdNotas[i] * sizeof(float));

            printf("\nAluno %d:\n", j + 1);
            for (int k = 0; k < qtdNotas[i]; k++) {
                printf("Nota %d: ", k + 1);
                scanf("%f", &notas[i][j][k]);
            }
        }
    }

    // Impressão
    for (int i = 0; i < qtdTurmas; i++) {
        printf("\nTurma %d:\n", i + 1);

        for (int j = 0; j < qtdAlunos[i]; j++) {
            printf("Aluno %d:\n", j + 1);

            for (int k = 0; k < qtdNotas[i]; k++) {
                printf(" Nota %d: %.2f\n", k + 1, notas[i][j][k]);
            }
        }
    }

    return 0;
}
