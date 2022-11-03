#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int multrec(int a, int b){
	if(b==0){
		return b;
	}
	return a+multrec(a,b-1);
}

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"portuguese");
	
	int a,b,r;
	
	printf("Digite o primeiro número: ");
	scanf("%d",&a);
	printf("\nDigite o segundo número: ");
	scanf("%d",&b);
	
	r = multrec(a,b);
	
	printf("\n\nO resultado é: %d",r);
	
	getch();
	return 0;
}
