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
    printf("Lista cheia");
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
  int busca = buscarvalor(lista, 7);
  int busca2 = buscarvalor(lista, 0);

  return 0;
}
