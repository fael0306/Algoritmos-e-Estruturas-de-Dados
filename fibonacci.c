#include <stdio.h>

int fib(n){
  if(n==2 || n==3){
    return 1;
  }
  else{
    return(fib(n-1)+fib(n-2));
  }
}

int main() {
    
    printf("%d\n",fib(10));
  
    return 0;
}
