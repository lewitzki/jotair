#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct disciplina {
    char nome[50];
    struct disciplina *prox;
} Disciplina;

typedef struct aluno {
    char nome[100];
    int matricula;
    struct disciplina_do_aluno {
        Disciplina *disciplina;
        char turma;
        struct disciplina_do_aluno *prox;
    } *disciplinas;
    struct aluno *prox;
} Aluno;

Disciplina *disciplinas = NULL;
Aluno *alunos = NULL;

Disciplina *buscarDisciplina(char *nome) {
    for (Disciplina *d = disciplinas; d; d = d->prox)
        if (!strcmp(d->nome, nome)) return d;
    return NULL;
}

void cadastrarDisciplina() {
    Disciplina *nova = malloc(sizeof(Disciplina));
    printf("Nome da disciplina: ");
    scanf("%s", nova->nome);
    nova->prox = disciplinas;
    disciplinas = nova;
}

void cadastrarAluno() {
    Aluno *novo = malloc(sizeof(Aluno));
    printf("Primeiro nome do aluno: ");
    scanf("%s", novo->nome);
    printf("Matricula: ");
    scanf("%d", &novo->matricula);
    novo->disciplinas = NULL;
    novo->prox = alunos;
    alunos = novo;

    int n;
    printf("Quantas disciplinas? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char nome_disc[50];
        printf("Disciplina #%d: ", i + 1);
        scanf("%s", nome_disc);
        Disciplina *d = buscarDisciplina(nome_disc);
        if (!d) { printf("Nao encontrada.\n"); i--; continue; }
        struct disciplina_do_aluno *da = malloc(sizeof(*da));
        da->disciplina = d;
        printf("Turma: ");
        scanf(" %c", &da->turma);
        da->prox = novo->disciplinas;
        novo->disciplinas = da;
    }
}

void imprimirTodosAlunos() {
    for (Aluno *a = alunos; a; a = a->prox) {
        printf("%s | %d\n", a->nome, a->matricula);
        for (struct disciplina_do_aluno *d = a->disciplinas; d; d = d->prox)
            printf("  - %s (%c)\n", d->disciplina->nome, d->turma);
    }
}

void imprimirPorDisciplina(char *nome_disc) {
    for (Aluno *a = alunos; a; a = a->prox)
        for (struct disciplina_do_aluno *d = a->disciplinas; d; d = d->prox)
            if (!strcmp(d->disciplina->nome, nome_disc))
                printf("%s (%d) - %c\n", a->nome, a->matricula, d->turma);
}

void imprimirAluno() {
    char busca[100];
    printf("Nome ou matricula: ");
    scanf("%s", busca);
    for (Aluno *a = alunos; a; a = a->prox)
        if (!strcmp(a->nome, busca) || atoi(busca) == a->matricula) {
            printf("%s | %d\n", a->nome, a->matricula);
            for (struct disciplina_do_aluno *d = a->disciplinas; d; d = d->prox)
                printf("  - %s (%c)\n", d->disciplina->nome, d->turma);
            return;
        }
    printf("Nao encontrado.\n");
}

int main() {
    int op;
    while (1) {
        printf("\n1 - Cadastrar disciplina\n2 - Cadastrar aluno\n3 - Imprimir alunos\n4 - Buscar por disciplina\n5 - Buscar aluno\n0 - Sair\nOpcao: ");
        scanf("%d", &op);
        if (op == 0) break;
        if (op == 1) cadastrarDisciplina();
        else if (op == 2) cadastrarAluno();
        else if (op == 3) imprimirTodosAlunos();
        else if (op == 4) {
            char nome[50];
            printf("Disciplina: ");
            scanf("%s", nome);
            imprimirPorDisciplina(nome);
        } else if (op == 5) imprimirAluno();
    }
    return 0;
}