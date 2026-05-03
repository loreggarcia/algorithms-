def counting_sort(arr):

    # Base case
    if not arr: 
        return arr

    # Find the max and min value    
    max_val = max(arr)
    min_val = min(arr)    
    #diferença entre os números
    range_of_element = max_val - min_val + 1 

    # Create count array and initialaize to 0 
    count = [0] * range_of_element #aumentando o array com base na diferença entre os números 

    # Count the occurences 
    for num in arr: # o loop percorre todo o array 
        count[num - min_val] += 1 # o outro array que tinha sido criado agora verifica quantas vezes dentro do array o número apareveu

    # Modify the count array
    for i in range(1, len(count)): # uma forma de fazer a iteração entre 1 e o índice final 
        count[i] += count[i - 1] #cada vez que aparece, soma 

    # Build the output array
    output = [0] * len(arr)
    for num in reversed(arr):
        output[count[num - min_val] - 1] = num 
        count[num - min_val] -= 1

    return output

arr = [4, 2, 2, 8, 3, 3, 1]
sorted_arr = counting_sort(arr)
print(sorted_arr)
