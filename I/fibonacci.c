#include <stdio.h>

int fib(n){
  if(n==2 || n==3){
    return 1;
  }
  else{
    return(fib(n-1)+fib(n-2));
  }
}

int main(int argc, char *argv[]) {
    
    printf("%d\n",fib(10));
    
    getch();
    return 0;
}
