#include <stdlib.h>
#include <stdio.h>

struct node { 
    int value; 
    struct node* next; 
    struct node* prev;
};

typedef struct node node_t; 

void printlist(node_t * head){

    node_t *temporary = head; 

    while (temporary != NULL) { 
        printf("%d -", temporary->value); 
        temporary = temporary->next; 
    }

    printf("\n");

}

node_t *create_new_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value; 
    result->next = NULL; 
    result->prev = NULL;
    return result;
}

node_t *insert_at_head(node_t *head, node_t *node_to_insert){
    node_to_insert->next = head; 
    if(head != NULL){
        head->prev = node_to_insert; 
    } 
    return node_to_insert;
}

void insert_after_node(node_t *node_to_after, node_t *newnode){
    newnode->next = node_to_after->next; 
    if(newnode->next != NULL){
        newnode->next->prev = node_to_after;
    }

    node_to_after->next = newnode;
}

void remove_node(node_t **head, node_t *node_to_remove){ //** = ponteiro duplo/
    if (node_to_remove == NULL) return;

    if(*head == node_to_remove) {
        *head = node_to_remove->next;
        if(*head != NULL){
            (*head)->prev = NULL;
        }
    } else{
        node_to_remove-> prev-> next = node_to_remove->next;
            if(node_to_remove->next != NULL){ //faz o caminho de volta
                node_to_remove-> next-> prev = node_to_remove->prev;
            }
        }

        free(node_to_remove); //oposto de malloc 
    }


int main(){
    node_t *head;
    node_t *tmp;

    head = NULL;

    for (int i=0; i < 25; i++){
        tmp = create_new_node(i);
        head = insert_at_head(head, tmp);
    }

    insert_after_node(tmp, create_new_node(75));

    remove_node(&head, tmp);
    remove_node(&head, head);

    printlist(head);

    return 0;
}