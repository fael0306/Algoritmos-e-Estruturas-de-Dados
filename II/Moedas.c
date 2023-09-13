#include <stdio.h>

int Moedas(int n, int V[], int lenV) {
    int T[lenV + 1][n + 1];

    for (int j = 0; j <= n; j++) {
        T[0][j] = 0;
    }

    for (int i = 0; i <= lenV; i++) {
        T[i][0] = 1;
    }

    for (int i = 1; i <= lenV; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= V[i - 1]) {
                T[i][j] = T[i][j - V[i - 1]] + T[i - 1][j];
            } else {
                T[i][j] = T[i - 1][j];
            }
        }
    }

    return T[lenV][n];
}

int main() {
    int V[] = {1, 5, 10, 25, 50, 100};
    int resultado = Moedas(50, V, sizeof(V) / sizeof(V[0]));
    printf("Número de maneiras de fazer 50 usando as moedas: %d\n", resultado);
    return 0;
}
