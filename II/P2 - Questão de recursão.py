def encontra_maior(lista, primeiro, ultimo):
    # Verifica se há apenas um elemento na lista
    if primeiro == ultimo:
        return lista[primeiro]

    meio = (primeiro + ultimo) // 2

    # Compara o elemento no meio com o elemento anterior
    if lista[meio] > lista[meio - 1]:
        # Se o elemento no meio é maior que o anterior, verifica a segunda metade
        return encontra_maior(lista, meio + 1, ultimo)
    else:
        # Se o elemento no meio não é maior que o anterior, verifica a primeira metade
        return encontra_maior(lista, primeiro, meio - 1)

# Exemplo de uso
lista_circular = [6, 7, 8, 1, 2, 4, 5]
maior_elemento = encontra_maior(lista_circular, 0, len(lista_circular) - 1)
print("Maior elemento na lista circular:", maior_elemento)
