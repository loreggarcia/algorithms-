def selection_sort(list_a):
    indexing_length = range(0, len(list_a)-1) #0 até o penultimo, pois se ordenar todos, o último estará obrigatoriamente na ordem certa

    for i in indexing_length: #ele percorre a 
        min_value = i #assumimos que i é o menor elemento a cada rodada

        for j in range(i+1, len(list_a)): # olha o que vem depois na lista e vai até o final
            if list_a[j] < list_a[min_value]: #se o numero atual é menor que o último registro
                min_value = j #o novo valor é o último número
        
        if min_value != i: # se o menor valor é diferente de i
            list_a[min_value], list_a[i] = list_a[i], list_a[min_value] #faça o swap
    
    return list_a #retorna a lista pronta

print(selection_sort([7,8,9,8,7,6]))