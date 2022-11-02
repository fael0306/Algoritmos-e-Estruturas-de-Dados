#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int maiorvalor(int vetor[10]){

int aux;
printf("");
for(int k=0;k<10;k++){
printf("%d ",vetor[k]);
}

for(int i=0;i<10;i++){
for(int j=0;j<10;j++){
	if(vetor[i]>vetor[j]){
		aux = vetor[i];
		vetor[i]=vetor[j];
		vetor[j]=aux;
	}
}	
}
printf("\nO maior valor é: %d",vetor[0]);
}

int main(int argc, char** argv) {
	
	setlocale(LC_ALL,"portuguese");
	
	int vetor[10];
	
	for(int k=0;k<10;k++){
printf("Digite um valor: ");
scanf("%d",&vetor[k]);
}

maiorvalor(vetor);
	
    getch();
	return 0;
}
