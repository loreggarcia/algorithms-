#include <stdio.h>
#include <stdlib.h> //memory management
#include <limits.h>

//criei a estrutura de árvore
typedef struct TreeNode { 
    int value; 
    struct TreeNode* left; 
    struct TreeNode* right; 
} tree_t;

//crio uma estrutura de fila para armazenar os valores da árvore
struct QueueNode {
    struct TreeNode *node;  // ao invés de armazenar o valor inteiro, armazena o endereço do nó 
    struct QueueNode* prev;
    struct QueueNode* next;
};

/*1. Receber o endereço de "rear" -> para atualizar o final
  2. A fila está vazia? Não -> Atualiza o front*/

void enqueue (struct QueueNode **rear, struct QueueNode **front, struct TreeNode *node){  
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node; 
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


void bfs(struct TreeNode *root){ //a função inicial que deve ser chamada é root 

    struct QueueNode *front = NULL;
    struct QueueNode *rear = NULL;
    struct TreeNode *curr;

    if(root != NULL){ 
        enqueue(&rear, &front, root); //proucuro o endereço 
    }

    while(front != NULL){

        curr = front->node; // só pra apontar pro nó

        /*
        1. Pegar o front.
        2. Acessar o node dentro dele.
        3. Acessar o value dentro desse nó da árvore
        */
        printf("%d\n", front->node->value); // mostra o valor
        dequeue(&rear, &front); //desenfileira o pai
        
        //enfileira os filhos
        if(curr->left != NULL){
            enqueue(&rear, &front, curr->left); 
        }  

        if(curr->right != NULL){
            enqueue(&rear, &front, curr->right); 
        } 
    }
}

struct TreeNode* Search(struct TreeNode *curr, int needle){
    if(curr == NULL){ //aponta pra um lugar que não tem nada 
        printf("Esse valor não está na lista.\n");
    }
    else if(needle == curr->value){
        printf("Achei! O seu número é: %d \n", curr->value);
    }

    else if(needle < curr->value){
        Search(curr->left, needle);
    }

    else if(needle > curr->value){
        Search(curr->right, needle);
    }
}

int main(){
    struct QueueNode *rear;
    struct QueueNode *front;
    
    struct TreeNode *root;
    struct TreeNode *curr;

    //para criar um nó é necessário reservar um espaço para ele
    struct TreeNode *n1 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n2 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n3 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n4 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n5 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n6 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n7 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 

    //indico o valor e faço com que as referencias comecem nulas
    n1 -> value = 10;
    n1->left = NULL;
    n1->right = NULL;

    n2 -> value = 11;
    n2->left = NULL;
    n2->right = NULL;

    n3 -> value = 12;
    n3->left = NULL;
    n3->right = NULL;

    n4 -> value = 13;
    n4->left = NULL;
    n4->right = NULL;

    n5 -> value = 14;
    n5->left = NULL;
    n5->right = NULL;

    n6 -> value = 15;
    n6->left = NULL;
    n6->right = NULL;

    n7 -> value = 16;
    n7->left = NULL;
    n7->right = NULL;

    rear = NULL;
    front = NULL;

    /*
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node; 
    newNode->next = NULL; //garantir que sempre o próximo seja nulo
    */

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n5->left = n6;
    n5->right = n7;

    bfs(n1);
    Search(n1, 14);
}