#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int k;
void leituradevetor(int v[10]) {

  for (k = 0; k < 10; k++) {
    printf("Digite o número: ");
    scanf("%d", & v[k]);
  }
}

void print(int v[10]) {
  printf("");
  for (k = 0; k < 10; k++) {
    printf("%d ", v[k]);
  }
}

void somar(int v[10]) {
  int soma = 0;
  for (k = 0; k < 10; k++) {
    soma = soma + v[k];
  }
  printf("%d", soma);
}

int main(int argc, char * argv[]) {

  setlocale(LC_ALL, "portuguese");

  int v[10];

  leituradevetor(v);
  printf("\n");
  printf("Números do vetor: ");
  print(v);
  printf("\n");
  printf("Soma dos números do vetor: ");
  somar(v);

  getch();
  return 0;
}
