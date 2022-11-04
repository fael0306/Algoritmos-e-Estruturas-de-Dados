#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int pot(int x, int n) {
  if (n >= 0) {
    if (n == 0) {
      return 1;
    }
    return (x * pot(x, n - 1));
  }
  return -1;
}

int main(int argc, char * argv[]) {

  setlocale(LC_ALL, "portuguese");

  int x, n;

  printf("Digite o número: ");
  scanf("%d", & x);

  printf("Digite a potência: ");
  scanf("%d", & n);

  printf("O resultado é: %d", pot(x, n));

  getch();
  return 0;
}
