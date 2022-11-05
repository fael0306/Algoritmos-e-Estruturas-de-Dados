#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int n;
  struct No * prox;
} No;

typedef struct Lista {
  No *inicio, *fim;
  int tam;
} Lista;

void insere(No *p, int x){
  No *novo;
  novo = malloc(sizeof(No));
  novo->n = x;
  novo->prox = p->prox;
  p->prox = novo;
  }
  
void insereprimeiro(No *p, int x){
  p = malloc(sizeof(No));
  p->n=x;
  p->prox = NULL;
  }

int main() {

  struct Lista lista1;

  No *l;
  
  // Colocando o primeiro elemento da lista (cabeça)
  insereprimeiro(l,5);
  
  // Inserindo após o primeiro elemento estar na lista
  insere(l,2);

  return 0;
}
