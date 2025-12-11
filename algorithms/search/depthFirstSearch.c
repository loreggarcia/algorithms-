#include <stdio.h> 
#include <stdlib.h> //memory management
#include <limits.h> 

struct TreeNode { 
    int value; 
    struct TreeNode* left; 
    struct TreeNode* right; 
};

struct StackNode { 
    struct TreeNode *node;
    struct StackNode* next; 
    struct StackNode* prev; 
};

void push (struct StackNode **head, struct TreeNode *node){ 
    struct StackNode *newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->node = node; 
    newNode->next = (*head);

    *head = newNode;
}

void pop(struct StackNode **head){ 
    if(head == NULL) return; 

    else {
        struct StackNode* temp = *head;
        *head = (*head)->next; 
        if(*head != NULL){
            (*head)->prev = NULL;
        }
        free(temp);
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
        return Search(curr->left, needle);
    }

    else{
        return Search(curr->right, needle);
    }

}

void dfs (struct TreeNode *root){
    struct StackNode *head = NULL;
    struct TreeNode *curr;

    if(head == NULL){ 
        push(&head, root); //proucuro o endereço 
    }

    while(head != NULL){ //Enquanto a pilha existe
        curr = head->node;  
        
        printf("%d\n", head->node->value); 
        pop(&head);

        if(curr->right != NULL){
            push(&head, curr->right);
        } 
        if(curr->left != NULL){
            push (&head, curr->left); 
        }
    }
}


int main(){
    struct StackNode *head;
    struct StackNode *root;

    //para criar um nó é necessário reservar um espaço para ele
    struct TreeNode *n1 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n2 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n3 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n4 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n5 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n6 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    struct TreeNode *n7 = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 

    //indico o valor e faço com que as referencias comecem nulas
    n1 -> value = 13;
    n1->left = NULL;
    n1->right = NULL;

    n2 -> value = 12;
    n2->left = NULL;
    n2->right = NULL;

    n3 -> value = 17;
    n3->left = NULL;
    n3->right = NULL;

    n4 -> value = 11;
    n4->left = NULL;
    n4->right = NULL;

    n5 -> value = 10;
    n5->left = NULL;
    n5->right = NULL;

    n6 -> value = 15;
    n6->left = NULL;
    n6->right = NULL;

    n7 -> value = 16;
    n7->left = NULL;
    n7->right = NULL;

    head = NULL;

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    dfs(n1);

    Search(n1, 15);
}