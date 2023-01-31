/* Nome: Rafael Manteiga Balbino
  Matrícula: 201920649111 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct livro {
  char titulo[51];
  char autor[51];
  int ano;
}
livro;

typedef struct noLivro {
  livro campos;
  struct noLivro * prox;
}
noLivro;

noLivro * inicioL;

int listaVazia(int lista) {
  if (lista == 1)
    return (inicioL == NULL);
  return 0;
}

void insereLivro(livro dado, int lista) {
  noLivro * aux;
  aux = (noLivro * )(malloc(sizeof(noLivro)));
  if (aux != NULL) {
    aux -> campos = dado;
    if (lista == 1) {
      aux -> prox = inicioL;
      inicioL = aux;
    }
  } else {
    printf("\nErro! Não foi possível inserir!");
  }
}

//funções e/ou procedimentos complementares
void imprimir() {
  noLivro * aux = inicioL;
  if (aux != NULL) {
    while (aux != NULL) {
      printf("\n\nTítulo: %s", aux -> campos.titulo);
      printf("\nAutor: %s", aux -> campos.autor);
      printf("\nAno: %d", aux -> campos.ano);
      aux = aux -> prox;
    }
  } else {
    printf("\nA lista de livros está vazia!");
  }
}

void filtro() {
  noLivro * aux = inicioL;
  while (aux != NULL) {
    if (aux -> campos.ano < 2010) {
      printf("\n\nTítulo: %s", aux -> campos.titulo);
      printf("\nAutor: %s", aux -> campos.autor);
      printf("\nAno: %d", aux -> campos.ano);
    } else {
      printf("\n\nTítulo: %s", aux -> campos.titulo);
      printf("\nAutor: %s", aux -> campos.autor);
      printf("\nAno: %d", aux -> campos.ano);
    }
    aux = aux -> prox;
    printf("");
  }

}

int main() {
  inicioL = NULL;
  int resp = 1;
  char lixo[10];
  livro dado;
  do {
    printf("\nTítulo do livro: ");
    scanf("%s", dado.titulo);
    printf("\nAutor do livro: ");
    scanf("%s", dado.autor);
    printf("\nAno de publicação: ");
    scanf("%d", & dado.ano);
    insereLivro(dado, 1);
    printf("\n\nDeseja cadastrar um novo livro (1- sim ou 2- não)? ");
    scanf("%d", & resp);
  } while (resp == 1);

  //chamada das funções criadas e impressão
  filtro();
  printf("\n");
  printf("\n");
  imprimir();

  return 0;
}
