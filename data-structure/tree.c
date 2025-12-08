#include <stdio.h>
#include <stdlib.h>

//Eu crio uma estrutura básica
typedef struct treeNode { 
    int value; 
    struct treeNode* left; 
    struct treeNode* right;
} tree_t; // pq especificamente o "_t" gera isso? É type

tree_t *createnode(int value){
    tree_t* result = malloc(sizeof(tree_t)); //alocando memoria dinaicamente e tals, mas 
    
    if(result != NULL) { 
        result->left = NULL; 
        result->right = NULL;
        result->value = value;
    }
    
    return result;
}

void printree(tree_t *root, int level){ //quem guia agora 
    

    for(int i=0; i < level; i++) { //
        printf("--------------");
    }

    printf("value = %d\n", root->value);
    
    //for subtrees use recursion
    if(root->left != NULL){
        printf("left\n");
        printree(root->left, level + 1); 
    }   
    if(root->right != NULL){
        printf("right\n");
        printree(root->right, level + 1);
        printf("\n");
    }
}

// ...

int main(){

    int level = 0;
    //criamos nós como normalmente
    tree_t *n1 = createnode(10);
    tree_t *n2 = createnode(11);
    tree_t *n3 = createnode(12);
    tree_t *n4 = createnode(13);
    tree_t *n5 = createnode(14);
    tree_t *n6 = createnode(15);
    tree_t *n7 = createnode(16);

    
    //indicamos os lados
    //n1 is my root
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n5->left = n6;
    n5->right = n7;

    printree(n1, 0);
}