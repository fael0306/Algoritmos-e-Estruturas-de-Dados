#include <stdio.h>

int fat(n){
  if (n==0){
    return 1;
  }
  else{
    return(n*fat(n-1));
  }
}

int main() {

  int n,r;
  
  printf("Digite um n: ");
  scanf("%d",&n);

  r = fat(n);

  printf("");
  
  printf("%d\n",r);
  
   return 0;
}
