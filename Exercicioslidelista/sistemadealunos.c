#include <stdio.h>
#include <string.h>
#define max 30

typedef struct Alunos{
    char matricula[20];
    char nome[20];
    char cpf[12];
    char telefone[12];
    int tam=0;
} Alunos;

void exibirLista(Alunos aluno){
    int i;
    if(aluno.tam>0){
       for(i=0;i<aluno.tam;i++){
        printf("%s\n",aluno.matricula[i]);
        printf("%s\n",aluno.nome[i]);
        printf("%s\n",aluno.cpf[i]);
        printf("%s\n",aluno.telefone[i]);
       } 
      printf("");
    }
    else{
        printf("\nLista vazia!");
    }
    
}

Alunos buscarAluno(Alunos aluno, char matricula){
    int i;
    for(i=0;i<aluno.tam;i++){
        if(strcmp(L.matricula[i],valor)==0){
            return aluno;
        }
    }
    return -1;
}

// Continuar daqui
void inserir(Alunos *L, char matricula){
    if(L->n < max){
        if(buscarAluno(*L,matricula)==-1){
            L->valores[L->n] = valor;
            (L->n)++;
        }
        else{
            printf("\nElemento já está cadastrado!");
        }
        
    }
    else{
        printf("\nLista cheia!!!");
    }
}

void remover(listaSeq *L, int valor){
    if(L->n>0){
        int pos = buscarValor(*L,valor);
        if(pos!=-1){
            L->valores[pos] = L->valores[(L->n)-1];
            (L->n)--;
        }
        else{
            printf("\nValor não está na lista!");
        }
    }
    else{
        printf("\nLista vazia!");
    }
}

int main()
{
    listaSeq lista;
    inicializar(&lista);
    inserir(&lista,5);
    inserir(&lista,2);
    inserir(&lista,4);
    inserir(&lista,8);
    exibirLista(lista);
    return 0;
}
