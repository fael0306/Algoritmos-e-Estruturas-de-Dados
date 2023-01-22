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
#include <locale.h>
#include <stdbool.h>

typedef struct Produto {
  int cod;
  char nome[50];
  float preco;
  struct Produto * prox;
}
Produto;

typedef struct Produtos {
  struct Produto * inicio;
  int tam;
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

  setlocale(LC_ALL,"Portuguese");

  Produtos * p = malloc(sizeof(Produtos));

  int o, codigo;
  float preco;
  char nome[50];

  printf("1 - Cadastrar produto\n2 - Exibir a lista de produtos\n3 - Buscar um produto\n4 - Remover um produto\n5 - Sair\n");
  scanf("%d", & o);

  while (o != 5) {

    switch (o) {
    case 1:
      printf("\nDigite o código: ");
      scanf("%d", & codigo);
      printf("\nDigite o nome: ");
      scanf("%s", & nome);
      printf("\nDigite o preço: ");
      scanf("%f", & preco);
      break;
    case 2:
      // exibir(p);
      break;
    case 3:
      break;
    case 4:
      break;
    }
    printf("\n1 - Cadastrar produto\n2 - Exibir a lista de produtos\n3 - Buscar um produto\n4 - Remover um produto\n5 - Sair\n");
    scanf("%d", & o);
  }
  printf("\nEncerrando...");

  getch();
  return 0;
}
