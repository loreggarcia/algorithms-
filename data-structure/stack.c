#include <stdio.h>
#include <stdlib.h> //memory management
#include <limits.h>

struct StackNode { 
    int value; 
    struct StackNode* next; 
    struct StackNode* prev; 
};

void push (struct StackNode **head, int value){ //add a item to top
    struct StackNode *newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->value = value; 
    newNode->next = (*head);

    *head = newNode;
}

void printlist(struct StackNode *head){

    struct StackNode *temporary = head; 

    while (temporary != NULL) { 
        printf("%d - ", temporary->value); 
        temporary = temporary->next; 
    }
    printf("\n");

}

void pop(struct StackNode **head){ //** = um endereço de um endereço
    /*
    1) head (sem asterisco) = O Cofre (endereço da variável na main).

    2) *head (um asterisco) = O Mapa (o endereço do primeiro nó).

    3) (*head)->next = A informação dentro do Nó.
    */


    if(head == NULL) return; 

    else {
        struct StackNode* temp = *head;
        *head = (*head)->next; //quem tem acesso ao endereço é o nó
        if(*head != NULL){
            (*head)->prev = NULL;
        }
        free(temp);
    }
    
}

int main(){
    int value;
    struct StackNode *head;
    
    head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);

    value = head->value ; 

    printf("\nTop element is %d\n", head->value);

    push(&head, 40);
    push(&head, 50);
    push(&head, 60); 

    value = head->value ; 

    printf("The new stack is:");
    printlist(head);

    pop(&head); // This will cause a stack underflow

    printf("%d popped from stack\n", value); 

    printf("After popping, top element is %d\n\n",head->value);

    printlist(head);

    return 0;
}