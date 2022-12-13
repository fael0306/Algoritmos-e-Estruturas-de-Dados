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

void inserirnofinal(listaSeq * L, int num) {
  if (L -> n < 10) {
    L -> valores[L -> n] = num;
    (L -> n) ++;
  } else {
    printf("\nLista cheia");
  }
}

void inserirnoinicio(listaSeq * L, int num) {
  int aux=L -> n;
  if (L -> n == 10) {
    printf("\nLista cheia");
  } else {
    while (L -> n >= 0) {
      L -> valores[L -> n + 1] = L -> valores[L -> n];
      L -> n--;
    }
  }
  L->n=aux;
  L -> valores[0] = num;
}

// Pensar numa forma de fazer o remover
void remover(listaSeq L, int valor){
  
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
 // remover(lista,6);
  return 0;
}
