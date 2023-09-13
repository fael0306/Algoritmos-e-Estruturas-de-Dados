def Moedas(n, V):
    T = [[0] * (n + 1) for _ in range(len(V) + 1)]

    for j in range(n + 1):
        T[0][j] = 0

    for i in range(len(V) + 1):
        T[i][0] = 1

    for i in range(1, len(V) + 1):
        for j in range(1, n + 1):
            if j >= V[i - 1]:
                T[i][j] = T[i][j - V[i - 1]] + T[i - 1][j]
            else:
                T[i][j] = T[i - 1][j]

    return T[len(V)][n]

# Exemplo de uso:
V = [1, 5, 10, 25, 50, 100]
resultado = Moedas(165, V)
print("Número de maneiras de fazer 50 usando as moedas:", resultado)
