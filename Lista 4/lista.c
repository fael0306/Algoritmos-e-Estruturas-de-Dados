#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Lista {
  int n;
  struct Lista * prox;
}
Lista;

Lista * inicio;

int somachaves() {
  if (inicio != NULL) {
    Lista * lista;
    lista = malloc(sizeof(Lista));
    lista = inicio;
    int soma = 0;
    while (lista != NULL) {
      soma = soma + (lista -> n);
      lista = lista -> prox;
    }
    return soma;
  }
}

int nos() {
  if (inicio != NULL) {
    Lista * lista;
    lista = malloc(sizeof(Lista));
    lista = inicio;
    int somanos = 0;
    while (lista != NULL) {
      somanos++;
      lista = lista -> prox;
    }
    return somanos;
  }
}

int maior(int n) {
  Lista * lista;
  lista = malloc(sizeof(Lista));
  lista = inicio;
  int soma = 0;
  while (lista != NULL) {
    if ((lista -> n) > n) {
      soma++;
    }
    lista = lista -> prox;
  }
  return soma;
}

void inserir(int num) {
  Lista * nova;
  nova = malloc(sizeof(Lista));
  if (nova != NULL) {
    nova -> n = num;
    nova -> prox = inicio;
    inicio = nova;
  }
}

void exibir() {
  Lista * aux;
  aux = inicio;
  while (aux != NULL) {
    printf("%d ", aux -> n);
    aux = aux -> prox;
  }
}

int ult() {
  if (inicio != NULL) {
    Lista * lista;
    lista = malloc(sizeof(Lista));
    lista = inicio;
    while (lista -> prox != NULL) {
      lista = lista -> prox;
    }
    return (lista -> n);
  }
}

void remover(int num) {
  Lista * ant = NULL;
  Lista * aux = inicio;
  if (inicio != NULL) {
    while (aux != NULL && aux -> n != num) {
      ant = aux;
      aux = aux -> prox;
    }
    if (aux == NULL) {
      printf("\nElemento não encontrado.");
    } else {
      if (ant == NULL) {
        inicio = aux -> prox;
      } else {
        ant -> prox = aux -> prox;
        free(aux);
      }
    }
  } else {
    printf("\nLista vazia!");
  }
}

int main() {

  setlocale(LC_ALL, "portuguese");

  int n;

  inserir(1);
  inserir(35);
  inserir(86);
  inserir(31);
  inserir(53);
  inserir(89);
  inserir(36);
  inserir(33);
  inserir(34);
  inserir(2);

  printf("Digite um número: ");
  scanf("%d", & n);

  printf("\nA soma das chaves é: %d", somachaves());

  printf("\nA quantidade de nós é: %d", nos());

  printf("\nA quantidade de números maior do que %d é %d", n, maior(n));

  printf("\nO último elemento da lista é: %d", ult());

  printf("\nSegue a lista: ");
  exibir();

  printf("\n\nDigite um número para remover: ");
  scanf("%d", & n);
  remover(n);

  printf("Segue a lista sem o número: ");
  exibir();

  getch();
  return 0;
}
