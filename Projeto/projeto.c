#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

void preencher(int vetor[]) {
  int k;
  for (k = 0; k < 10; k++) {
    printf("\nDigite o número: ");
    scanf("%d", & vetor[k]);
  }
  printf("\n");
}

int buscabinaria(int n, int vetor[], int e, int d) {
  int meio = (e + d) / 2;
  if (vetor[meio] == n) {
    return meio;
  }
  if (e >= d) {
    return -1;
  } else if (vetor[meio] < n) {
    return buscabinaria(n, vetor, meio + 1, d);
  } else {
    return buscabinaria(n, vetor, e, meio - 1);
  }
}

int buscasequencial(int n, int vetor[]) {
  int k;
  for (k = 0; k < 10; k++) {
    if (vetor[k] == n) {
      return k;
    }
  }
  return -1;
}

/*void quicksort(int * a, int left, int right) {
  int i, j, x, y;

  i = left;
  j = right;
  x = a[(left + right) / 2];

  while (i <= j) {
    while (a[i] < x && i < right) {
      i++;
    }
    while (a[j] > x && j > left) {
      j--;
    }
    if (i <= j) {
      y = a[i];
      a[i] = a[j];
      a[j] = y;
      i++;
      j--;
    }
  }

  if (j > left) {
    quicksort(a, left, j);
  }
  if (i < right) {
    quicksort(a, i, right);
  }
}*/

void insertionsort(int * a) {
  int i, j, tmp;
  for (i = 1; i < 10; i++) {
    tmp = a[i];
    for (j = i - 1; j >= 0 && tmp < a[j]; j--) {
      a[j + 1] = a[j];
    }
    a[j + 1] = tmp;
  }
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
  int k;
  printf("");
  for (k = 0; k < 10; k++) {
    printf("%d ", v[k]);
  }
}

int main(int argc, char * argv[]) {

  setlocale(LC_ALL, "portuguese");
  
  int opAux = 0;
  int op, v[10], r, n;
  char opbusca[2], opord[2];

  printf("\n1 - Preencher o vetor\n2 - Buscar por um valor\n3 - Ordenar o vetor\n4 - Sair\n\n");
  scanf("%d", & op);

  while (op != 4) {

    switch (op) {

    case 1:
      preencher(v);
      opAux++;
      break;

    case 2:
      if (opAux == 0) {
        printf("\nO vetor não foi inicializado.");
      } else {
        printf("\nDigite o número que deseja buscar: ");
        scanf("%d", & n);
        printf("\nQual a operação de busca gostaria de utilizar?\na) Busca Binária\nb) Busca Sequencial\n");
        scanf("%s", & opbusca);
        if (strcmp(opbusca, "a") == 0) {
          r = buscabinaria(n, v, 0, 10);
          printf("\nO número está na posição: %d\n", r);
        } else if (strcmp(opbusca, "b") == 0) {
          r = buscasequencial(n, v);
          printf("\nO número está na posição: %d\n", r);
        } else {
          printf("\nOpção inválida.\n\n");
        }
      }
      break;

    case 3:
      if (opAux == 0) {
        printf("\nO vetor não foi inicializado.");
      } else {
        printf("\nQual método de ordenação gostaria de utilizar?\na) Insertion Sort\nb) Bubble Sort\n");
        scanf("%s", & opord);
        if (strcmp(opord, "a") == 0) {
          insertionsort(v);
          print(v);
          printf("");
        } else if (strcmp(opord, "b") == 0) {
          bubblesort(v);
          print(v);
          printf("");
        } else {
          printf("\nOpção inválida.");
        }
      }
      break;
    }
    printf("\n1 - Preencher o vetor\n2 - Buscar por um valor\n3 - Ordenar o vetor\n4 - Sair\n\n");
    scanf("%d", & op);
  }

  getch();
  return 0;
}
