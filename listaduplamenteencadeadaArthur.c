#include<stdio.h>
#include<stdlib.h>

typedef struct {
    // DADOS
    int dados;

    // PONTEIROS
    struct No* anterior;
    struct No* prox;
} No;

typedef struct {
    // DADOS
    int comprimento;

    // PONTEIROS
    No* head;
} ListaEncadeada ;

No* inicializar_no() {
    No* no = malloc(sizeof(No));
    no->anterior = NULL;
    no->prox = NULL;
    no->dados = 0;

    return no;
}

ListaEncadeada* inicializar_lista_encadeada() {
    ListaEncadeada* lista_encadeada = malloc(sizeof(ListaEncadeada));
    return lista_encadeada;
}

void inserir(int valor, ListaEncadeada* le) {
    No* novo_no = inicializar_no();

    // O NÓ QUE ESTÁ NA CABEÇA DA LISTA, APONTARÁ
    // PARA O NOVO NÓ
    if(le->head) {
        le->head->anterior = novo_no;
    }
    
    // NOVO NO APONTA PARA CABEÇA DA LISTA
    novo_no->prox = le->head;    

    // NOVO NO SE TORNA A CABEÇA DA LISTA
    le->head = novo_no;

    novo_no->dados = valor;
    le->comprimento++;
}

void deletar(int indice, ListaEncadeada* le) {
    printf("DELETANDO %d\n", indice);

    No* cabeca = le->head;

    if(indice == 1) {
        le->head = le->head->prox;
        free(cabeca);
        return;
    }

    if(indice > le->comprimento) {
        return;
    }

    // PERCORRA A LISTA INTEIRA
    for(int i = 1; i < le->comprimento; i++) {
        // ATÉ ENCONTRAR O ÍNDICE ANTERIOR
        if (i == indice-1) break;
        cabeca = cabeca->prox;
    }

    No* a_ser_deletado = cabeca->prox;
    cabeca->prox = a_ser_deletado->prox;
    free(a_ser_deletado);
}

No* buscar(ListaEncadeada* le, int indice) {
    No* cabeca = le->head;

    // CASO DE ERRO
    if (cabeca == NULL) {
        printf("[]\n");
        return;
    }

    for(int i=0; i<indice; i++) {
        //printf("%i, ", cabeca->dados);
        cabeca = cabeca->prox;
    }

    return (struct No*)(cabeca);
}

void print(ListaEncadeada* le) {
    No* cabeca = le->head;

    // CASO DE ERRO
    if (cabeca == NULL) {
        printf("[]\n");
        return;
    }

    printf("[");
    while(cabeca) {
        printf("%i, ", cabeca->dados);
        cabeca = cabeca->prox;
    }
    printf("\b\b]\n");
}

int main(void) {
    // TESTE DE INSERCAO
    ListaEncadeada* lista_encadeada = inicializar_lista_encadeada();
    inserir(1, lista_encadeada);
    inserir(2, lista_encadeada);
    inserir(3, lista_encadeada);
    print(lista_encadeada);
    // printf("ID: %d\n", (lista_encadeada->head->prox)->dados);
    printf("ID: %d, ANTERIOR: %d, POSTERIOR: %d\n", 
        buscar(lista_encadeada, 1)->dados, 
        ((No*)(buscar(lista_encadeada, 1)->anterior))->dados,
        ((No*)(buscar(lista_encadeada, 1)->prox))->dados);

    // inserir(4, lista_encadeada);
    // print(lista_encadeada);
    // inserir(5, lista_encadeada);
    // print(lista_encadeada);

    // ListaEncadeada* lista_encadeada_vazia = inicializar_lista_encadeada();
    // print(lista_encadeada_vazia);


    // // DELETAR ELEMENTO DA LISTA (POR INDICE)
    // deletar(6, lista_encadeada);
    // print(lista_encadeada);
    // deletar(5, lista_encadeada);
    // print(lista_encadeada);
    // deletar(3, lista_encadeada);
    // print(lista_encadeada);
    // deletar(1, lista_encadeada);
    // print(lista_encadeada);

    return 0;
}
