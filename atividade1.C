#include <stdio.h>

#define MAX 100


int buscarSequencial(int vetor[], int tamanho, int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == elemento) {
            return 1; 
        }
    }
    return 0; 
}


void inserirSemRepetir(int vetor[], int elemento, int *quantidade, int maximo) {
    if (*quantidade >= maximo) {
        printf("Erro: Capacidade máxima atingida.\n");
        return;
    }
    if (!buscarSequencial(vetor, *quantidade, elemento)) {
        vetor[*quantidade] = elemento;
        (*quantidade)++;
        printf("Elemento %d inserido com sucesso.\n", elemento);
    } else {
        printf("Elemento %d já existe na lista.\n", elemento);
    }
}

void percorrer(int vetor[], int quantidade) {
    printf("Lista de elementos: ");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int lista[MAX];
    int quantidade = 0;
    int elemento;
    char opcao;
    
    do {
        printf("Digite um número para inserir na lista: ");
        scanf("%d", &elemento);
        inserirSemRepetir(lista, elemento, &quantidade, MAX);
        
        printf("Deseja inserir outro número? (s/n): ");
        scanf(" %c", &opcao);
    } while (opcao == 's' || opcao == 'S');
    
    percorrer(lista, quantidade);
    
    return 0;
}
///////
#include <stdio.h>

#define TAM 10

int buscaBinaria(int lista[], int tamanho, int elemento) {
    int inicio = 0, fim = tamanho - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (lista[meio] == elemento) {
            return meio;
        } else if (lista[meio] < elemento) {
            fim = meio - 1; 
        } else {
            inicio = meio + 1; 
        }
    }
    return -1;
}

void inserirOrdenado(int lista[], int *quantidade, int elemento) {
    if (*quantidade >= TAM) {
        printf("Lista cheia!\n");
        return;
    }
    
    int i = *quantidade - 1;
    while (i >= 0 && lista[i] < elemento) {
        lista[i + 1] = lista[i];
        i--;
    }
    lista[i + 1] = elemento;
    (*quantidade)++;
    printf("Elemento %d inserido com sucesso.\n", elemento);
}

void removerElemento(int lista[], int *quantidade, int elemento) {
    int indice = buscaBinaria(lista, *quantidade, elemento);
    if (indice == -1) {
        printf("Elemento %d não encontrado na lista.\n", elemento);
        return;
    }
    for (int i = indice; i < *quantidade - 1; i++) {
        lista[i] = lista[i + 1];
    }
    (*quantidade)--;
    printf("Elemento %d removido com sucesso.\n", elemento);
}

void percorrerLista(int lista[], int quantidade) {
    printf("Lista: ");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int lista[TAM];
    int quantidade = 0;
    int opcao, elemento;
    
    do {
        printf("\nMenu:\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Buscar elemento\n");
        printf("4 - Percorrer lista\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                inserirOrdenado(lista, &quantidade, elemento);
                break;
            case 2:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &elemento);
                removerElemento(lista, &quantidade, elemento);
                break;
            case 3:
                printf("Digite o elemento a ser buscado: ");
                scanf("%d", &elemento);
                int posicao = buscaBinaria(lista, quantidade, elemento);
                if (posicao != -1) {
                    printf("Elemento %d encontrado na posição %d.\n", elemento, posicao);
                } else {
                    printf("Elemento %d não encontrado.\n", elemento);
                }
                break;
            case 4:
                percorrerLista(lista, quantidade);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);
    
    return 0;
}



