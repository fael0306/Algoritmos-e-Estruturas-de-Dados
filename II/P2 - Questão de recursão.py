def encontrar_maior_numero_divisao_conquista(lista_circular, inicio, fim):
    # Caso base: se há apenas um elemento, retorna esse elemento
    if inicio == fim:
        return lista_circular[inicio]

    # Caso base: se há apenas dois elementos, retorna o maior
    if inicio + 1 == fim:
        return max(lista_circular[inicio], lista_circular[fim])

    # Calcula o índice do meio
    meio = (inicio + fim) // 2

    # Encontra o máximo em cada metade
    max_esquerda = encontrar_maior_numero_divisao_conquista(lista_circular, inicio, meio)
    max_direita = encontrar_maior_numero_divisao_conquista(lista_circular, meio + 1, fim)

    # Retorna o máximo entre os máximos encontrados
    return max(max_esquerda, max_direita)

# Exemplo de uso
lista_circular = [8, 12, 13, 5, 6, 7]
maior_numero = encontrar_maior_numero_divisao_conquista(lista_circular, 0, len(lista_circular) - 1)
print(f"O maior número na lista circular é: {maior_numero}")
