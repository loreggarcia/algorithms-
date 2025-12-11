#include <stdio.h>
#include <stdlib.h> 

struct TreeNode { 
    int value; 
    struct TreeNode* left; 
    struct TreeNode* right; 
};

struct TreeNode* Insert(struct TreeNode *root, int key){ 
    struct TreeNode *curr;

    if(root == NULL){
        struct TreeNode *curr = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
        curr->value = key;
        curr->left=curr->right=NULL;
        return curr;
    }

    if(key < root->value){
        root->left = Insert(root->left, key);
    }

    if(key > root->value){
        root->right = Insert(root->right, key);
    }

    return root;
}

void Inorder(struct TreeNode *curr){
    if(curr){
        Inorder(curr->left);
        printf("%d \n", curr->value);
        Inorder(curr->right);
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
        curr->left = Search(curr->left, needle);
    }

    else if(needle > curr->value){
        curr->right = Search(curr->right, needle);
    }
}

int main(){
    struct TreeNode *root = NULL;

    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 30);
    
    Inorder(root);

    Search(root, 12);
    Search(root, 8);
}