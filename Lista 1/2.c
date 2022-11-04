#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int maiorvalor(int vetor[10]) {

  int maior, k, i, j;
  printf("");

  for (k = 0; k < 10; k++) {
    printf("%d ", vetor[k]);
  }

  maior = vetor[0];
  for (k = 1; k < 10; k++) {
    if (vetor[k] > maior) {
      maior = vetor[k];
    }
  }

  printf("\nO maior valor é: %d", maior);

}

int main(int argc, char ** argv) {

  setlocale(LC_ALL, "portuguese");

  int vetor[10], k;

  for (k = 0; k < 10; k++) {
    printf("Digite um valor: ");
    scanf("%d", &vetor[k]);
  }

  maiorvalor(vetor);

  getch();
  return 0;
}
