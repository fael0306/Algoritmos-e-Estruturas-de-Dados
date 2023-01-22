#include <stdio.h>
#include <stdlib.h>

typedef struct Produto {
  int cod;
  char nome[50];
  float preco;
  struct Produto * prox;
}
Produto;

typedef struct Produtos {
  Produto * inicio;
}
Produtos;

void insere(Produtos * p, int codigo) {
  Produto * novo;
  novo = malloc(sizeof(Produto));
  novo -> cod = codigo;

  novo -> prox = p -> inicio;
  p -> inicio = novo;
}

int main() {
  struct Produtos listadeprodutos;

  Produtos * p = malloc(sizeof(Produtos));

  insere(p, 2);
  insere(p, 10);

  return 0;
}
