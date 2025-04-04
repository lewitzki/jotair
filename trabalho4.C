#include <stdio.h>

typedef struct {
    char nome[100];
    char area_atuacao[100];
    double valor_atual;
    double valor_anterior;
    double variacao;
} Acao;

void calcularVariacao(Acao *acao) {
    if (acao->valor_anterior > 0) {
        acao->variacao = ((acao->valor_atual - acao->valor_anterior) / acao->valor_anterior) * 100;
    } else {
        acao->variacao = 0;
    }
}

void exibirAcao(Acao acao) {
    printf("Nome da Companhia: %s\n", acao.nome);
    printf("Área de Atuação: %s\n", acao.area_atuacao);
    printf("Valor Atual: R$ %.2f\n", acao.valor_atual);
    printf("Valor Anterior: R$ %.2f\n", acao.valor_anterior);
    printf("Variação: %.2f%%\n", acao.variacao);
}

int main() {
    Acao acao = {"TechCorp", "Tecnologia", 120.50, 115.00, 0};
    
    calcularVariacao(&acao);
    exibirAcao(acao);
    
    return 0;
}

#include <stdio.h>


typedef struct {
    char nome[100];
    char area_atuacao[100];
    double valor_atual;
    double valor_anterior;
    double variacao;
} Acao;


void calcularVariacao(Acao *acao) {
    if (acao->valor_anterior > 0) {
        acao->variacao = ((acao->valor_atual - acao->valor_anterior) / acao->valor_anterior) * 100;
    } else {
        acao->variacao = 0;
    }
}


void exibirAcao(Acao acao) {
    printf("Nome da Companhia: %s\n", acao.nome);
    printf("Área de Atuação: %s\n", acao.area_atuacao);
    printf("Valor Atual: R$ %.2f\n", acao.valor_atual);
    printf("Valor Anterior: R$ %.2f\n", acao.valor_anterior);
    printf("Variação: %.2f%%\n", acao.variacao);
    printf("-----------------------------\n");
}

int main() {
    Acao acoes[3];
    
    for (int i = 0; i < 3; i++) {
        printf("Digite o nome da companhia: ");
        scanf(" %99[^"]", acoes[i].nome);
        printf("Digite a área de atuação: ");
        scanf(" %99[^"]", acoes[i].area_atuacao);
        printf("Digite o valor atual da ação: ");
        scanf("%lf", &acoes[i].valor_atual);
        printf("Digite o valor anterior da ação: ");
        scanf("%lf", &acoes[i].valor_anterior);
        
        calcularVariacao(&acoes[i]);
    }
    
    printf("\nDados das Ações:\n");
    for (int i = 0; i < 3; i++) {
        exibirAcao(acoes[i]);
    }
    
    return 0;
}

