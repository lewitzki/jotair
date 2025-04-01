#include <stdio.h>

void verificar_paridade(int numero) {
    if (numero % 2 == 0) {
        printf("O número %d é par.\n", numero);
    } else {
        printf("O número %d é ímpar.\n", numero);
    }
}

void verificar_sinal(int numero) {
    if (numero > 0) {
        printf("O número %d é positivo.\n", numero);
    } else if (numero < 0) {
        printf("O número %d é negativo.\n", numero);
    } else {
        printf("O número é zero.\n");
    }
}

void verificar_letra(char letra) {
    char vogais[] = "aeiouAEIOU";
    int eh_vogal = 0;
    
    for (int i = 0; i < 10; i++) {
        if (letra == vogais[i]) {
            eh_vogal = 1;
            break;
        }
    }
    
    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
        if (eh_vogal) {
            printf("A letra '%c' é uma vogal.\n", letra);
        } else {
            printf("A letra '%c' é uma consoante.\n", letra);
        }
    } else {
        printf("Por favor, informe apenas uma letra válida.\n");
    }
}

void calcular_total(int compra, int regiao) {
    float preco = 5.00;
    float frete;
    char *nome_regiao;
    
    switch (regiao) {
        case 1: nome_regiao = "Norte"; frete = 0.10; break;
        case 2: nome_regiao = "Nordeste"; frete = 0.08; break;
        case 3: nome_regiao = "Centro-Oeste"; frete = 0.12; break;
        case 4: nome_regiao = "Sudeste"; frete = 0.15; break;
        case 5: nome_regiao = "Sul"; frete = 0.11; break;
        default: printf("Código de região inválido.\n"); return;
    }
    
    float total_sem_frete = compra * preco;
    float valor_frete = total_sem_frete * frete;
    float total_com_frete = total_sem_frete + valor_frete;
    
    printf("Total da compra sem frete: R$ %.2f\n", total_sem_frete);
    printf("Frete (%s): R$ %.2f\n", nome_regiao, valor_frete);
    printf("Total a pagar com frete: R$ %.2f\n", total_com_frete);
}

int main() {
    int numero;
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);
    verificar_paridade(numero);
    verificar_sinal(numero);
    
    char letra;
    printf("Digite uma letra: ");
    scanf(" %c", &letra);
    verificar_letra(letra);
    
    int quantidade, regiao;
    printf("Digite a quantidade de itens (máximo 100): ");
    scanf("%d", &quantidade);
    
    if (quantidade >= 1 && quantidade <= 100) {
        printf("Informe o código da região (1-5): ");
        scanf("%d", &regiao);
        calcular_total(quantidade, regiao);
    } else {
        printf("Quantidade inválida.\n");
    }
    
    return 0;
}

#include <stdio.h>

void verificar_paridade(int numero) {
    if (numero % 2 == 0) {
        printf("O número %d é par.\n", numero);
    } else {
        printf("O número %d é ímpar.\n", numero);
    }
}

void verificar_sinal(int numero) {
    if (numero > 0) {
        printf("O número %d é positivo.\n", numero);
    } else if (numero < 0) {
        printf("O número %d é negativo.\n", numero);
    } else {
        printf("O número é zero.\n");
    }
}

void verificar_letra(char letra) {
    char vogais[] = "aeiouAEIOU";
    int eh_vogal = 0;
    
    for (int i = 0; i < 10; i++) {
        if (letra == vogais[i]) {
            eh_vogal = 1;
            break;
        }
    }
    
    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
        if (eh_vogal) {
            printf("A letra '%c' é uma vogal.\n", letra);
        } else {
            printf("A letra '%c' é uma consoante.\n", letra);
        }
    } else {
        printf("Por favor, informe apenas uma letra válida.\n");
    }
}

void calcular_total(int compra, int regiao) {
    float preco = 5.00;
    float frete;
    char *nome_regiao;
    
    switch (regiao) {
        case 1: nome_regiao = "Norte"; frete = 0.10; break;
        case 2: nome_regiao = "Nordeste"; frete = 0.08; break;
        case 3: nome_regiao = "Centro-Oeste"; frete = 0.12; break;
        case 4: nome_regiao = "Sudeste"; frete = 0.15; break;
        case 5: nome_regiao = "Sul"; frete = 0.11; break;
        default: printf("Código de região inválido.\n"); return;
    }
    
    float total_sem_frete = compra * preco;
    float valor_frete = total_sem_frete * frete;
    float total_com_frete = total_sem_frete + valor_frete;
    
    printf("Total da compra sem frete: R$ %.2f\n", total_sem_frete);
    printf("Frete (%s): R$ %.2f\n", nome_regiao, valor_frete);
    printf("Total a pagar com frete: R$ %.2f\n", total_com_frete);
}

void situacao_civil() {
    int opcao;
    printf("Informe sua situação civil:\n1 - Solteiro(a)\n2 - Casado(a)\n3 - Divorciado(a)\n4 - Viúvo(a)\n");
    scanf("%d", &opcao);
    
    switch (opcao) {
        case 1: {
            int idade;
            printf("Informe sua idade: ");
            scanf("%d", &idade);
            printf("Situação: Solteiro(a), Idade: %d\n", idade);
            break;
        }
        case 2: {
            char sexo, conjuge[50];
            printf("Informe seu sexo (M/F): ");
            scanf(" %c", &sexo);
            printf("Informe o nome do cônjuge: ");
            scanf(" %s", conjuge);
            printf("Situação: Casado(a), Sexo: %c, Cônjuge: %s\n", sexo, conjuge);
            break;
        }
        case 3: {
            int filhos, idade_mais_velho;
            printf("Informe a quantidade de filhos: ");
            scanf("%d", &filhos);
            if (filhos > 0) {
                printf("Informe a idade do mais velho: ");
                scanf("%d", &idade_mais_velho);
            } else {
                idade_mais_velho = 0;
            }
            printf("Situação: Divorciado(a), Filhos: %d, Idade do mais velho: %d\n", filhos, idade_mais_velho);
            break;
        }
        case 4: {
            char cidade[50];
            float salario;
            printf("Informe a cidade onde vive: ");
            scanf(" %s", cidade);
            printf("Informe seu salário atual: ");
            scanf("%f", &salario);
            printf("Situação: Viúvo(a), Cidade: %s, Salário: R$ %.2f\n", cidade, salario);
            break;
        }
        default:
            printf("Opção inválida!\n");
    }
}

void multiplos_de_5() {
    printf("Múltiplos de 5 de 1 até 500:\n");
    for (int i = 5; i <= 500; i += 5) {
        printf("%d ", i);
    }
    printf("\n");
}

void metade_e_media() {
    float numeros[10], soma = 0;
    printf("Digite 10 números:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%f", &numeros[i]);
        soma += numeros[i];
    }
    printf("Metades dos números:\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", numeros[i] / 2);
    }
    printf("\nMédia dos números: %.2f\n", soma / 10);
}

void tabela_polegadas_cm() {
    int inicio, fim;
    printf("Informe o intervalo de polegadas (inicio e fim): ");
    scanf("%d %d", &inicio, &fim);
    printf("Polegadas para Centímetros:\n");
    for (int i = inicio; i <= fim; i++) {
        printf("%d pol = %.2f cm\n", i, i * 2.54);
    }
}

int main() {
    situacao_civil();
    multiplos_de_5();
    metade_e_media();
    tabela_polegadas_cm();
    return 0;
}
#include <stdio.h>

void verificar_paridade(int numero) {
    if (numero % 2 == 0) {
        printf("O número %d é par.\n", numero);
    } else {
        printf("O número %d é ímpar.\n", numero);
    }
}

void verificar_sinal(int numero) {
    if (numero > 0) {
        printf("O número %d é positivo.\n", numero);
    } else if (numero < 0) {
        printf("O número %d é negativo.\n", numero);
    } else {
        printf("O número é zero.\n");
    }
}

void verificar_letra(char letra) {
    char vogais[] = "aeiouAEIOU";
    int eh_vogal = 0;
    
    for (int i = 0; i < 10; i++) {
        if (letra == vogais[i]) {
            eh_vogal = 1;
            break;
        }
    }
    
    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
        if (eh_vogal) {
            printf("A letra '%c' é uma vogal.\n", letra);
        } else {
            printf("A letra '%c' é uma consoante.\n", letra);
        }
    } else {
        printf("Por favor, informe apenas uma letra válida.\n");
    }
}

void calcular_total(int compra, int regiao) {
    float preco = 5.00;
    float frete;
    char *nome_regiao;
    
    switch (regiao) {
        case 1: nome_regiao = "Norte"; frete = 0.10; break;
        case 2: nome_regiao = "Nordeste"; frete = 0.08; break;
        case 3: nome_regiao = "Centro-Oeste"; frete = 0.12; break;
        case 4: nome_regiao = "Sudeste"; frete = 0.15; break;
        case 5: nome_regiao = "Sul"; frete = 0.11; break;
        default: printf("Código de região inválido.\n"); return;
    }
    
    float total_sem_frete = compra * preco;
    float valor_frete = total_sem_frete * frete;
    float total_com_frete = total_sem_frete + valor_frete;
    
    printf("Total da compra sem frete: R$ %.2f\n", total_sem_frete);
    printf("Frete (%s): R$ %.2f\n", nome_regiao, valor_frete);
    printf("Total a pagar com frete: R$ %.2f\n", total_com_frete);
}

void pessoas_masculinas() {
    char nome[50], sexo;
    int idade;
    for (int i = 0; i < 20; i++) {
        printf("Informe o nome: ");
        scanf(" %s", nome);
        printf("Informe a idade: ");
        scanf("%d", &idade);
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &sexo);
        
        if (sexo == 'M' || sexo == 'm') {
            if (idade > 21) {
                printf("Nome: %s\n", nome);
            }
        }
    }
}

void maior_numero() {
    int n, numero, maior;
    printf("Quantos números deseja fornecer? ");
    scanf("%d", &n);
    
    if (n > 0) {
        printf("Digite um número: ");
        scanf("%d", &maior);
        
        for (int i = 1; i < n; i++) {
            printf("Digite um número: ");
            scanf("%d", &numero);
            if (numero > maior) {
                maior = numero;
            }
        }
        printf("O maior número é: %d\n", maior);
    } else {
        printf("Quantidade inválida!\n");
    }
}

void crescimento_populacional() {
    int anos = 0;
    double popA = 90000, popB = 50000;
    
    while (popB <= popA) {
        popA *= 1.009;
        popB *= 1.015;
        anos++;
    }
    
    printf("Serão necessários %d anos para a cidade B ter mais habitantes que a cidade A.\n", anos);
}

int main() {
    pessoas_masculinas();
    maior_numero();
    crescimento_populacional();
    return 0;
}

#include <stdio.h>

void verificar_paridade(int numero) {
    if (numero % 2 == 0) {
        printf("O número %d é par.\n", numero);
    } else {
        printf("O número %d é ímpar.\n", numero);
    }
}

void verificar_sinal(int numero) {
    if (numero > 0) {
        printf("O número %d é positivo.\n", numero);
    } else if (numero < 0) {
        printf("O número %d é negativo.\n", numero);
    } else {
        printf("O número é zero.\n");
    }
}

void verificar_letra(char letra) {
    char vogais[] = "aeiouAEIOU";
    int eh_vogal = 0;
    
    for (int i = 0; i < 10; i++) {
        if (letra == vogais[i]) {
            eh_vogal = 1;
            break;
        }
    }
    
    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
        if (eh_vogal) {
            printf("A letra '%c' é uma vogal.\n", letra);
        } else {
            printf("A letra '%c' é uma consoante.\n", letra);
        }
    } else {
        printf("Por favor, informe apenas uma letra válida.\n");
    }
}

void calcular_total(int compra, int regiao) {
    float preco = 5.00;
    float frete;
    char *nome_regiao;
    
    switch (regiao) {
        case 1: nome_regiao = "Norte"; frete = 0.10; break;
        case 2: nome_regiao = "Nordeste"; frete = 0.08; break;
        case 3: nome_regiao = "Centro-Oeste"; frete = 0.12; break;
        case 4: nome_regiao = "Sudeste"; frete = 0.15; break;
        case 5: nome_regiao = "Sul"; frete = 0.11; break;
        default: printf("Código de região inválido.\n"); return;
    }
    
    float total_sem_frete = compra * preco;
    float valor_frete = total_sem_frete * frete;
    float total_com_frete = total_sem_frete + valor_frete;
    
    printf("Total da compra sem frete: R$ %.2f\n", total_sem_frete);
    printf("Frete (%s): R$ %.2f\n", nome_regiao, valor_frete);
    printf("Total a pagar com frete: R$ %.2f\n", total_com_frete);
}

void registro_compras() {
    float preco, total_compra = 0, total_vendas = 0;
    int quantidade_itens = 0, total_itens_vendidos = 0, opcao_pagamento;
    
    do {
        printf("Informe o valor do produto (ou um valor menor ou igual a zero para finalizar): ");
        scanf("%f", &preco);
        
        if (preco > 0) {
            total_compra += preco;
            quantidade_itens++;
        }
    } while (preco > 0);
    
    if (total_compra > 0) {
        total_vendas += total_compra;
        total_itens_vendidos += quantidade_itens;
        printf("Quantidade de itens comprados: %d\n", quantidade_itens);
        printf("Total da compra: R$ %.2f\n", total_compra);
        
        printf("Escolha a forma de pagamento:\n1 - Dinheiro\n2 - Cartão Débito\n3 - Cartão Crédito\n");
        scanf("%d", &opcao_pagamento);
        
        switch (opcao_pagamento) {
            case 1:
                printf("Opção escolhida: Dinheiro\n");
                printf("Desconto: 10%%\n");
                printf("Valor do desconto: R$ %.2f\n", total_compra * 0.10);
                printf("Total a pagar: R$ %.2f\n", total_compra * 0.90);
                break;
            case 2:
                printf("Opção escolhida: Cartão Débito\n");
                printf("Desconto: 5%%\n");
                printf("Valor do desconto: R$ %.2f\n", total_compra * 0.05);
                printf("Total a pagar: R$ %.2f\n", total_compra * 0.95);
                break;
            case 3:
                printf("Opção escolhida: Cartão Crédito\n");
                printf("Total a pagar: R$ %.2f\n", total_compra);
                break;
            default:
                printf("Opção inválida!\n");
        }
    }
    
    printf("Total de itens vendidos no dia: %d\n", total_itens_vendidos);
    printf("Total de vendas no dia (sem descontos): R$ %.2f\n", total_vendas);
}

int main() {
    registro_compras();
    return 0;
}


    
    
    
