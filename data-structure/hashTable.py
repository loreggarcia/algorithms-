'''
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.

void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
'''

class ListNode:
    def __init__(self, key = -1, value = -1, next = None): 
        #key e value são iguais a -1, porque inicialmente não guardam dados reais  
        # next é NONE porque começa vazio  
        self.key = key #chave
        self.value = value #valor
        self.next = next #próximo elemento

class MyHashMap:

    def __init__(self):
        # List comprehension offers a shorter syntax when you want to create a new list based on the values of an existing list.
        # Sua sintaxe básica é: [expr for item in lista]

        self.map = [ListNode() for i in range (1000)] 

    #função de implementação da equação matemática do hash
    def hash(self, key): 
        return key % len(self.map) #chave/numero de gavetas(1000)

    def put(self, key: int, value: int) -> None: #inserir um par (chave, valor)
        #Calcular o índice usando a nossa função hash.
        i = self.hash(key)
        #Começar a busca pelo nó sentinela que está naquela posição: cur = self.map[index].
        cur = self.map[i]
        # Percorrer a lista ligada enquanto cur.next existir
        while cur.next:
            #Se encontrarmos um nó onde cur.next.key == key, atualizamos o valor.
            if cur.next.key == key:
                cur.next.value = value
                return cur.next
            else:
                cur = cur.next
        #Se chegarmos ao fim da lista sem encontrar a chave, criamos um novo nó
        cur.next = ListNode(key, value)

    def get(self, key: int) -> int:
        #Você calcula o index.
        i = self.hash(key)
        #Começa pelo primeiro nó real (que é o self.map[index].next).
        cur = self.map[i].next
        #Percorre enquanto o nó existir.
        while cur:
            #Comparação: Como comparamos a key do nó cur com a key que recebemos como argumento?
            if(cur.key == key):
                return cur.value
            #Movimentação: Se não forem iguais, como fazemos o cur apontar para o próximo nó para continuar a busca?
            else:
                cur = cur.next
        return -1

    def remove(self, key: int) -> None:
        #Calculamos o índice usando o hash.
        i = self.hash(key)
        #Começamos no nó sentinela: cur = self.map[i].
        cur = self.map[i]
        #Enquanto o próximo nó existir (while cur.next:):
        while cur.next:
        #Se o próximo nó for quem buscamos (if cur.next.key == key):
            if(cur.next.key == key):
        #Fazemos o "pulo": o next do nó atual deve passar a apontar para o "neto" (o nó depois do que estamos apagando).
                cur.next = cur.next.next 
        #Terminamos a função com um return.
                return 
        #Caso contrário, avançamos o cur
            else:
                cur = cur.next
        

# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)