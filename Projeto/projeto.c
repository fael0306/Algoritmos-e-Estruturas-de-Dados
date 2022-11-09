#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void preencher(int vetor[]) {
  int k;
  for (k = 0; k < 10; k++) {
    printf("Digite o número: ");
    scanf("%d", & vetor[k]);
  }
}

int buscabinaria(int n, int vetor[], int e, int d) {

  int meio = (e + d) / 2;

  if (vetor[meio] == n) {
    return meio;
  }
  if (e >= d) {
    return -1;
  } else {
    if (vetor[meio] < n) {
      return buscabinaria(n, vetor, meio + 1, d);
    } else {
      return buscabinaria(n, vetor, e, meio - 1);
    }
  }
}

int buscasequencial(int n, int vetor[]) {
  for (k = 0; k < 10; k++) {
    if (vetor[k] == n) {
      return k;
    }
  }
  return -1;
}

void quicksort(int values[], int began, int end) {
  int i, j, pivo, aux;
  i = began;
  j = end - 1;
  pivo = values[(began + end) / 2];
  while (i <= j) {
    while (values[i] < pivo && i < end) {
      i++;
    }
    while (values[j] > pivo && j > began) {
      j--;
    }
    if (i <= j) {
      aux = values[i];
      values[i] = values[j];
      values[j] = aux;
      i++;
      j--;
    }
  }
  if (j > began)
    quicksort(values, began, j + 1);
  if (i < end)
    quicksort(values, i, end);
}

void bubblesort(int vetor[]) {
  int k, i, aux;
  for (k = 0; k < 10; k++) {
    for (i = 0; i < 10; i++) {
      if (vetor[k] < vetor[i]) {
        aux = vetor[k];
        vetor[k] = vetor[i];
        vetor[i] = aux;
      }
    }
  }
}

void print(int v[]) {
  printf("");
  for (k = 0; k < 10; k++) {
    printf("%d ", v[k]);
  }
}

int main(int argc, char * argv[]) {

  setlocale(LC_ALL, "portuguese");

  getch();
  return 0;
}
