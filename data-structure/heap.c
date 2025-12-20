#include <stdio.h>
#include <stdlib.h> //memory management

struct MaxHeap { 
    int *value; //data 
    int size; // elementos atuais
    int capacity; // elementos que cabem
};

struct MaxHeap* createHeap(int capacity) { 
    struct MaxHeap* newHeap = malloc(sizeof(struct MaxHeap)); //Alocar memória para a própria struct
    /* 
        - Alocar memória para cada valor (capacidade * dado) 
        - int -> aramazenar só o valor de mémoria pra um inteiro
    */
    newHeap->value = malloc(capacity * (sizeof(int))); 
    //Você esqueceu de guardar o número capacity dentro da struct para usarmos depois.    

    if(capacity != 0){
        /*0 para números 
         NULL para ponteiros.*/
        newHeap -> size = 0;
        newHeap->capacity = capacity;
    }
    
    return newHeap;
}

void swap(int *x, int *y){ //os ponteiros vão guardar as mudanças 
    int temp = *x;
    *x = *y;
    *y = temp;
} 

void insert(struct MaxHeap* heap, int item){ 
    //tá cheio?
    if(heap->size == heap->capacity) return;

    else{
        heap->value[heap->size] = item; //o valor correspondente ao item atual 
        heap->size++; //aumenta em 1

        //O elemento novo está no índice anterior ao size atual
        int i = heap->size - 1;

        //Heapify-Up
        //Se eu estou no índice i, meu pai está em (i - 1) / 2.
        while(i > 0 ){
            //o pai tem que estar dentro para ser recalculado a cada nova volta
            int parentIndex = (i-1)/2;  
            if(heap->value[i] > heap->value[parentIndex]) {
                //faz o swap
                swap(&heap->value[i], &heap->value[parentIndex]);
                i = parentIndex;   
            }
            else{
                break;
            }
        }
    }
}

int extMax(struct MaxHeap* heap) { 
    if(heap->size == 0){
        return -1; //retornar erro
    }

    int root = heap->value[0]; //salvando a raiz
    heap->value[0] = (heap->value[heap->size - 1]); //o último elemento vira o primeiro 
    heap->size --; // diminui o tamanho 

    
    //Heapfy-Down
    int i = 0;
    while (1){
        int largest = i; //o maior 
        int left = 2* i + 1;
        int right = 2* i + 2;

        // Verificar se 'left' está dentro do array (left < heap->size) 
        // E se value[left] > value[largest]. Se sim, há um novo número maior.
        if(left < heap->size && heap->value[left] > heap->value[largest]){
            largest = left; //a esquerda vira o novo maior
        }
        //  Verifique se 'right' está dentro do array 
        //   E se value[right] > value[largest]. Se sim, há um novo número maior.
        if(right < heap->size && heap->value[right] > heap->value[largest]){
            largest = right;
        }
        
        if (largest != i) { 
            swap(&heap->value[i], &heap->value[largest]);
            i = largest; // O elevador desce
        } else {
            break; // Está no lugar certo
        }
    }

    return root;
}

void printHead(struct MaxHeap* heap, int index){ //ponteiro pra estrutura e o indice
    
    for(index; index < heap->size; index++){
        printf("%d\n", heap->value[index]);
    }
    
}

int main (){
    struct MaxHeap *heap;

    heap = createHeap(10);
    insert(heap, 10);
    insert(heap, 50);
    insert(heap, 30);
    insert(heap, 5);
    insert(heap, 60);

    printf("Heap:\n");
    printHead(heap, 0);

    extMax(heap);
    extMax(heap);
    printf("New heap: \n");
    printHead(heap, 0);

}