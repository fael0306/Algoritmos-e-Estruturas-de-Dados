import random
import timeit

def mergesort(alist):
    if len(alist)>1:
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]

        mergesort(lefthalf)
        mergesort(righthalf)

        i=0
        j=0
        k=0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k]=lefthalf[i]
                i=i+1
            else:
                alist[k]=righthalf[j]
                j=j+1
            k=k+1

        while i < len(lefthalf):
            alist[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j < len(righthalf):
            alist[k]=righthalf[j]
            j=j+1
            k=k+1
    return alist

def quicksort(vetor,inicio,fim):
    if inicio > fim:
        return
    ant = inicio
    post = fim
    pivo = vetor[inicio]

    while ant<post:
        while ant<post and vetor[post]>pivo:
            post = post-1
        if ant<post:
            vetor[ant]=vetor[post]
            ant = ant+1
        while ant<post and vetor[ant]<=pivo:
            ant = ant+1
        if ant<post:
            vetor[post]=vetor[ant]
            post = post-1
        vetor[ant]=pivo
    quicksort(vetor,inicio,ant-1)
    quicksort(vetor,ant+1,fim)
    return vetor

vetor = []
for k in range(0,5000):
    random.seed()
    n = random.randint(0,10000000)
    vetor.append(n)

inicio = timeit.default_timer()
quicksort(vetor,0,len(vetor)-1)
fim = timeit.default_timer()
print("Tempo de execução do Quicksort em segundos: ",fim-inicio)

quickvel = fim-inicio

inicio = timeit.default_timer()
mergesort(vetor)
fim = timeit.default_timer()
print("Tempo de execução do Mergesort em segundos: ",fim-inicio)

mergevel = fim-inicio

difperc = (mergevel/quickvel-1)*100

difperc = round(difperc,2)

print("\nO Mergesort foi {}% mais lento que o Quicksort.".format(difperc))
