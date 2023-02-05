#include <stdio.h>

// Complexidade: quantos passos são executados

// Melhor caso: o número procurado está no meio -> O(1) no máximo 1
// Pior caso: o número de entrada -> O(n-1) no máximo n-1
// Caso médio: O(n/2)

int fat(n){
  if (n==0){
    return 1;
  }
  else{
    return(n*fat(n-1));
  }
}

int main(int argc, char *argv[]) {

  int n,r;
  
  printf("Digite um n: ");
  scanf("%d",&n);

  r = fat(n);

  printf("");
  
  printf("%d\n",r);
  
  getch();
   return 0;
}
