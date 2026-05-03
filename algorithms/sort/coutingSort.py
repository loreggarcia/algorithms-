def couting_sort(x, max_val):
    #Cria vetor de contagem
    count = [0] * (max_val + 1)

    #Contar as ocorrências 
    for num in x:
        count[num] += 1 

    #Construir saída ordenada
    i = 0
    for num in count:
        for j in range(num):
            x[i] = num
            i += 1
    return x

print(couting_sort([7,8,9,8,7,6], 9))