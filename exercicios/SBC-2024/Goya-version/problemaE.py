n = int(input())
k = []

for i in range (n):
    s = input().split()
    k.append([int(x) for(x) in s])

    c = ((0,0), (0,1), (-1,-1), (-1,1), (-1,0)) ##tupla de tuplas 

    r = 0

    ##for i, x in enumerate(c)
    ##   if k[x[0] x[1]] < k[c]