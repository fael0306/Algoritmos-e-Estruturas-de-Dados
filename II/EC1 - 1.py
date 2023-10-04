ncasos = int(input())

def verificapadrao(i, string, padrao):
    cont = 0
    index = 0
    while index < len(string):
        index = string.find(padrao,index)
        if index == -1:
            break
        cont = cont+1
        index = index+1
    return cont==i    

for k in range(ncasos):
    i = int(input())
    while i<1 or i>1000:
        print("\nO número deve estar entre 1 e 1000.\n")
        i = int(input())
    string = input()
    while len(string)>1000:
        print("\nA string deve conter no máximo 1000 caracteres.\n")
        string = input()
    padrao = input()
    while len(padrao)>100:
        print("\nA string deve conter no máximo 100 caracteres.\n")
        padrao = input()
    cont = 0
    index = 0
    while index < len(string):
        index = string.find(padrao,index)
        if index == -1:
            break
        cont = cont+1
        index = index+1

    if verificapadrao(i,string,padrao):
        print("Y")
    else:
        print("N")