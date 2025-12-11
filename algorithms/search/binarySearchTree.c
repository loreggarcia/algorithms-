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
        Search(curr->left, needle);
    }

    else if(needle > curr->value){
        Search(curr->right, needle);
    }
}

int Height (struct TreeNode *curr){
    int x,y;
    if(curr == NULL) return 0;
    x = Height(curr->left);
    y = Height(curr->right);
    return x>y?x+1:y+1;
}

//Predecessor: o maior valor da esquerda 
struct TreeNode *InPre(struct TreeNode *curr){
    while(curr && curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}

//Sucessor: maior valor da direita
struct TreeNode *InSucc(struct TreeNode *curr){
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

struct TreeNode *Delete(struct TreeNode *curr, int key){

    struct TreeNode *root = NULL;

    //proucura
    if( curr == NULL){ 
        return NULL;
    }

    if(key < curr->value){
        curr->left = Delete(curr->left, key);
    }

    else if(key > curr->value){
        curr->right = Delete(curr->right, key);
    }

    //encontrou
    else{
        
        if(curr->left == NULL && curr->right == NULL){
            free(curr);
            curr = NULL;
        }

        //1 raiz
        else if(curr->left == NULL){
            struct TreeNode* temp = curr; 
            curr = curr->right;
            free(temp);
        }
        else if(curr->right == NULL){
            struct TreeNode* temp = curr; 
            curr = curr->left;
            free(temp);
        }

        //2 raízes: verificar qual lado tem o menor tamanho
        else if(Height(curr->left) > Height(curr->right)){
            root = InPre(curr->left); 
            curr->value = root->value;
            curr->left = Delete(curr->left, curr->value);
        }
        else{
            root = InSucc(curr->right);
            curr->value = root->value;
            curr->right = Delete(curr->right, curr->value);
        }
    }
    return curr;
}

int main(){
    struct TreeNode *root = NULL;

    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 10);
    root = Insert(root, 25);
    root = Insert(root, 35);
    root = Insert(root, 45);
    root = Insert(root, 42);
    root = Insert(root, 43);
    
    

    Inorder(root);

}