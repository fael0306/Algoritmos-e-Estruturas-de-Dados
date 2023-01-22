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
#include <string.h>

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

void cadastrar(Produtos * p, int codigo, char name[50], float precos) {
  Produto * novo;
  novo = malloc(sizeof(Produto));
  novo -> cod = codigo;
  strcpy(novo -> nome, name);
  novo -> preco = precos;

  novo -> prox = p -> inicio;
  p -> inicio = novo;
}

int main() {
  struct Produtos listadeprodutos;

  Produtos * p = malloc(sizeof(Produtos));

  cadastrar(p, 123, "Cerveja", 10);
  cadastrar(p, 321, "Refrigerante", 9);

  return 0;
}
