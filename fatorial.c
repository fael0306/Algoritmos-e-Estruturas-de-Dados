#include <stdio.h>

int fat(n){
  if (n>1){
    return(n*fat(n-1));
  }
  else{
    return n;
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
