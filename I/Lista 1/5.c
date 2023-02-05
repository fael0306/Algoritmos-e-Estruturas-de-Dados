#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

bool primo(int n) {

  int k;

  for (k = 2; k <= n / 2; k++) {
    if (n % k == 0) {
      return false;
    }
  }
  return true;
}

int main(int argc, char * argv[]) {

  setlocale(LC_ALL, "portuguese");

  int n, k;

  printf("Digite um número: ");
  scanf("%d", & n);

  printf("\nNúmeros primos até %d: ", n);

  for (k = 2; k <= n; k++) {
    if (primo(k)) {
      printf("%d ", k);
    }
  }

  getch();
  return 0;
}
