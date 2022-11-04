#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int buscabinaria(int n, int vetor[], int e, int d){
	
	int meio = (e+d)/2;
	
	if(vetor[meio]==n){
		return meio;
	}
	if(e>=d){
		return -1;
	}
	else{
		if(vetor[meio]<n){
			return buscabinaria(n,vetor,meio+1,d);
		}
		else{
			return buscabinaria(n,vetor,e,meio-1);
		}
	}
}

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"portuguese");
	
	int n,vetor[10]={1,3,5,7,9},r;
	
	printf("Digite um número: ");
	scanf("%d",&n);
	
	r = buscabinaria(n,vetor,vetor[0],vetor[sizeof(vetor)/sizeof(int)]);
	
	printf("\nA posição do número no vetor é: %d", r);
	
	getch();
	return 0;
}
