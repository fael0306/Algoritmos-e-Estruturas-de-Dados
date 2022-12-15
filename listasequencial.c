#include <stdio.h>

typedef struct listaSeq {

  int n;
  int valores[10];

}
listaSeq;

int buscarvalor(listaSeq L, int num) {
  int k;
  for (k = 0; k < L.n; k++) {
    if (L.valores[k] == num) {
      return k;
    }
  }
  return -1;
}

void modificar(listaSeq * L, int pos, int valornovo) {
  if (L -> n >= pos) {
    L -> valores[pos] = valornovo;
  } else {
    printf("\nEsta posição não existe!");
  }
}

void inserirnofinal(listaSeq * L, int num) {
  if (L -> n < 10) {
    L -> valores[L -> n] = num;
    (L -> n) ++;
  } else {
    printf("\nLista cheia");
  }
}

void inserirnoinicio(listaSeq * L, int num) {
  int aux = L -> n;
  if (L -> n == 10) {
    printf("\nLista cheia");
  } else {
    while (L -> n >= 0) {
      L -> valores[L -> n + 1] = L -> valores[L -> n];
      L -> n--;
    }
  }
  L -> n = aux;
  L -> valores[0] = num;
}

// Verificar se está correto
void remover(listaSeq * L, int valor) {
  int v = buscarvalor( * L, valor);
  if (v == -1) {
    printf("\nO valor informado não está na lista");
  } else {
    while (v <= L -> n - 1) {
      L -> valores[v] = L -> valores[v + 1];
      v++;
    }
    (L -> n) --;
  }
}

void inicializar(listaSeq * L) {
  L -> n = 0;
}

int main() {

  listaSeq lista;

  inicializar( & lista);
  inserirnofinal( & lista, 4);
  inserirnofinal( & lista, 7);
  inserirnofinal( & lista, 1);
  inserirnofinal( & lista, 2);
  inserirnofinal( & lista, 4);
  inserirnoinicio( & lista, 6);
  int busca = buscarvalor(lista, 7);
  int busca2 = buscarvalor(lista, 0);
  modificar( & lista, 3, 10);
  remover( & lista, 6);
  return 0;
}
