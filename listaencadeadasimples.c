#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int n;
  struct No * prox;
}
No;

typedef struct Lista {
  No * inicio;
  int tam;
}
Lista;

void insere(Lista * p, int x) {
  No * novo;
  novo = malloc(sizeof(No));
  novo -> n = x;

  novo -> prox = p -> inicio;
  p -> inicio = novo;
}

int main() {

  struct Lista lista1;

  Lista * l = malloc(sizeof(Lista));

  insere(l, 2);
  insere(l,10);
  
  getch();
  return 0;
}
