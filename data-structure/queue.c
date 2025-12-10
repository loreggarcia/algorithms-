#include <stdio.h>
#include <stdlib.h> //memory management
#include <limits.h>

struct QueueNode { 
    int value; 
    struct QueueNode* prev; 
    struct QueueNode* next; 
};

void enqueue (struct QueueNode **rear, struct QueueNode **front, int value){ 
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->value = value;
    newNode->next = NULL; //garantir que sempre o próximo seja nulo
    
    if((*rear) != NULL){
        newNode->prev = (*rear); //Olha pra trás e vê o antigo último
        (*rear)->next = newNode;
    }

    else{
        newNode->prev = NULL; //se não tiver ninguém na fila, o anterior é nulo
        *front = newNode; //só se a fileira estiver vazia
    }

    *rear = newNode;
}

void printlist(struct QueueNode *front){

    struct QueueNode *temporary = front;  

    while (temporary != NULL) { 
        printf("%d - ", temporary->value); 
        temporary = temporary->next; 
    }
    printf("\n");

}

void dequeue(struct QueueNode **rear, struct QueueNode **front){

    if(*front == NULL) return; //se não tiver nada na frente, não existe

    else {
        struct QueueNode* temp = *front; 
        *front = (*front)->next; 
            if (*front == NULL) {
            // A fila ficou vazia: atualiza só o rear
            *rear = NULL;
            } else {
                // Ainda existe alguém na frente: o prev do novo front vira NULL
                (*front)->prev = NULL;
            }
            free(temp);
    }    
}

int main(){
    int value;
    struct QueueNode *rear;
    struct QueueNode *front;

    rear = NULL;
    front = NULL;

    enqueue(&rear, &front, 10);
    enqueue(&rear, &front, 30);

    printf("The queue is: ");
    value = front->value; 

    printlist(front);

    enqueue(&rear, &front, 40);
    enqueue(&rear, &front, 50);
    enqueue(&rear, &front, 60); 
    enqueue(&rear, &front, 20);

    value = front->value ; 

    printf("The new queue is: ");
    printlist(front);

    dequeue(&rear, &front);  
    value = front->value ;
    printf("%d got out of queue\n", value); 

    dequeue(&rear, &front);
    value = front->value ;
    printf("%d got out of queue\n", value); 
    
    dequeue(&rear, &front); 
    value = front->value ;
    printf("%d got out of queue\n", value); 
    
    printf("After delate, the first element is %d\n\n", front->value);

    printf("The new queue is: ");
    printlist(front);

    return 0;
}