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

void filtro(livro * vetor, int n, livro * antes, livro * depois) {
  int contadorAntes = 0, contadorDepois = 0;
  for (int i = 0; i < n; i++) {
    if (vetor[i].ano < 2010) {
      antes[contadorAntes++] = vetor[i];
      insereLivro(vetor[i], 1);
    } else {
      depois[contadorDepois++] = vetor[i];
      insereLivro(vetor[i], 1);
    }
  }
  printf("\n\nLivros lançados antes de 2010:\n");
  for (int i = 0; i < contadorAntes; i++) {
    printf("%s - %d\n", antes[i].titulo, antes[i].ano);
  }
  printf("\nLivros lançados depois de 2010:\n");
  for (int i = 0; i < contadorDepois; i++) {
    printf("%s - %d\n", depois[i].titulo, depois[i].ano);
  }
}

int main() {
  inicioL = NULL;
  int resp = 1;
  char lixo[10];
  livro vetor[50];
  livro antes[50];
  livro depois[50];
  int n = 0;

  do {
    livro dado;
    printf("\nDigite o título do livro: ");
    scanf("%s", dado.titulo);
    printf("Digite o autor do livro: ");
    scanf("%s", dado.autor);
    printf("Digite o ano de lançamento do livro: ");
    scanf("%d", & dado.ano);
    vetor[n++] = dado;
    printf("Deseja inserir outro livro? (1 - sim / 0 - não): ");
    scanf("%d", & resp);
  } while (resp);

  filtro(vetor, n, antes, depois);

  printf("\n\nTodos os livros: ");
  imprimir();

  return 0;
}
