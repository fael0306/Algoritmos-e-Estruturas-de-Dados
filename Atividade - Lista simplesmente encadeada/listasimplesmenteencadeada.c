/*
Faça um sistema para gerenciar os produtos (código, nome e preço) de um supermercado utilizando uma lista simplesmente encadeada, apresentando ao usuário as seguintes opções:

  1- Cadastrar produto

  2- Exibir a lista de produtos

  3- Buscar um produto

  4- Remover um produto

  5- Sair

Você deve implementar procedimentos e/ou funções para as funcionalidades de uma lista encadeada.
*/

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
int main() {
  struct Lista lista1;

  Lista * l = malloc(sizeof(Lista));

  insere(l, 2);
  insere(l, 10);
  
  return 0;
}
