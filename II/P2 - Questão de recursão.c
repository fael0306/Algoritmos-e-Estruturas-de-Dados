#include <stdio.h>

// Função para encontrar o maior número em uma lista circular usando divisão e conquista
int encontrar_maior_numero_divisao_conquista(int lista_circular[], int inicio, int fim) {
    // Caso base: se há apenas um elemento, retorna esse elemento
    if (inicio == fim) {
        return lista_circular[inicio];
    }

    // Caso base: se há apenas dois elementos, retorna o maior
    if (inicio + 1 == fim) {
        return (lista_circular[inicio] > lista_circular[fim]) ? lista_circular[inicio] : lista_circular[fim];
    }

    // Calcula o índice do meio
    int meio = (inicio + fim) / 2;

    // Encontra o máximo em cada metade
    int max_esquerda = encontrar_maior_numero_divisao_conquista(lista_circular, inicio, meio);
    int max_direita = encontrar_maior_numero_divisao_conquista(lista_circular, meio + 1, fim);

    // Retorna o máximo entre os máximos encontrados
    return (max_esquerda > max_direita) ? max_esquerda : max_direita;
}

int main() {
    // Exemplo de uso
    int lista_circular[] = {8, 12, 13, 5, 6, 7};
    int tamanho_lista = sizeof(lista_circular) / sizeof(lista_circular[0]);
    
    int maior_numero = encontrar_maior_numero_divisao_conquista(lista_circular, 0, tamanho_lista - 1);
    
    printf("O maior número na lista circular é: %d\n", maior_numero);

    return 0;
}
