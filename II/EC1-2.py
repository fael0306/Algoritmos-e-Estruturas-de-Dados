def encontrar_posicao_media(array, inicio, fim):
	if inicio == fim:
		return inicio
	else:
		meio = (inicio + fim) // 2
		posicao_esquerda = encontrar_posicao_media(array, inicio, meio)
		posicao_direita = encontrar_posicao_media(array, meio + 1, fim)
		
		soma_esquerda = sum(array[inicio:meio + 1])
		soma_direita = sum(array[meio + 1:fim + 1])
		
		if soma_esquerda > soma_direita:
			return posicao_esquerda
		else:
			return posicao_direita
