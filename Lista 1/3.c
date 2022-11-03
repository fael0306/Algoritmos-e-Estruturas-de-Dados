#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Animal{
	char nome[30];
	char raca[30];
	char datadenascimento[11];
	char sexo[30];
};

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"portuguese");
	
	int k,n=0,cont=0;
    struct Animal animais[50];
    
    printf("Caso queira parar, digite o nome 'stop'");
    
    for(k=0;k<50;k++){
    	printf("\nDigite o nome: ");
    	gets(animais[k].nome);
    	if(strcmp(animais[k].nome,"stop")==0){
    		memset(animais[k].nome, 0, sizeof(animais[k].nome));
    		break;
		}
    	printf("\nDigite a raça: ");
    	gets(animais[k].raca);
    	printf("\nDigite a data de nascimento (dd/mm/aaaa): ");
    	gets(animais[k].datadenascimento);
    	printf("\nDigite o sexo: ");
    	gets(animais[k].sexo);
    	cont++;
}

for(k=0;k<cont;k++){
    printf("\n%s\n",animais[k].nome);
    printf("%s\n",animais[k].raca);
    printf("%s\n",animais[k].datadenascimento);
    printf("%s\n",animais[k].sexo);
}

	getch();
	return 0;
}
