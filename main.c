#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Estrutura para representar um cliente
typedef struct {
    int numero;
    char nome[50];
    int tempo_atendimento; // em minutos
} Cliente;

// Estrutura da fila
typedef struct {
    Cliente dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->tamanho == MAX;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

// Adiciona cliente na fila
void adicionarCliente(Fila *f, Cliente c) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível adicionar mais clientes.\n");
        return;
    }
    f->dados[f->fim] = c;
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
    printf("Cliente %s adicionado à fila.\n", c.nome);
}

// Atende próximo cliente da fila
Cliente atenderCliente(Fila *f) {
    Cliente c;
    if (filaVazia(f)) {
        printf("Fila vazia! Nenhum clie
