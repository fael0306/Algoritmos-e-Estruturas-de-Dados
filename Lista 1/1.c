#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float qvetor(float vetor[10]){

	float resultado[10];
	int k;
	
	for(k=0;k<10;k++){
		printf("%.2f ",vetor[k]);
		resultado[k] = vetor[k]*vetor[k];
	}
  printf("\n");
	for(k=0;k<10;k++){
		printf("%.2f ",resultado[k]);
	}
}

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"portuguese");
	
	float vetor[10],n;
	int k;
	
	for(k=0;k<10;k++){
	printf("Digite um número: ");
	scanf("%f",&vetor[k]);
	}
	printf("\n");
	
	qvetor(vetor);


	return 0;
}
