#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void printlista(int n) {
  if (n == 0) {
    printf("%d ", n);
  } else {
    printlista(n - 1);
    printf("%d ", n);
  }
}

int main(int argc, char * argv[]) {

  setlocale(LC_ALL, "portuguese");

  int n;

  printf("Digite um número: ");
  scanf("%d", & n);
  printf("\nNúmeros de 0 até %d em ordem crescente: ", n);
  printlista(n);

  getch();
  return 0;
}
