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
  } else {
    printf("\nLista vazia!");
    return -1;
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
  } else {
    printf("\nLista vazia!");
    return -1;
  }
}

int maior(int n) {
  if (inicio != NULL) {
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
  } else {
    printf("\nLista vazia!");
    return -1;
  }
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
  } else {
    printf("\nLista vazia!");
    return -1;
  }
}

void remover(int num) {
  Lista * atual = inicio;
  Lista * anterior = NULL;

  while (atual != NULL) {
    if (atual -> n == num) {
      if (anterior == NULL) {
        inicio = atual -> prox;
      } else {
        anterior -> prox = atual -> prox;
      }
    } else {
      anterior = atual;
    }
    atual = atual -> prox;
  }
}

void inserirposicao(int num, int posicao) {
  Lista * nova;
  nova = malloc(sizeof(Lista));
  if (nova != NULL) {
    nova -> n = num;
    Lista * aux = inicio;
    int i;
    for (i = 1; i < posicao - 1 && aux != NULL; i++) {
      aux = aux -> prox;
    }
    if (aux != NULL) {
      nova -> prox = aux -> prox;
      aux -> prox = nova;
    } else {
      printf("Posição inválida!");
    }
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
  inserir(35);
  inserirposicao(28, 2);

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

  printf("\nSegue a lista sem o número: ");
  exibir();

  getch();
  return 0;
}
