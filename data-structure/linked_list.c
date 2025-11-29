#include <stdlib.h>
#include <stdio.h>

struct node { //maneira de armazenar valores do mesma tipo
    int value; 
    struct node* next; // * => guarda o endereço de memória onde o próximo elemento está
};

typedef struct node node_t; // só uma associação

void printlist(node_t * head){
    /*Função pra verificar o topo da lista, tipo o peek 
    Printa os valores enquanto a pilha existir*/
    //na real, só printa mesmo
    node_t *temporary = head; //ponteiro temporário, isso porque o head vai mudar e eu vouprecisar de uma indicação de memória pras diferentes vezes que e for fazer isso

    while (temporary != NULL) { 
        printf("%d -", temporary->value); // eu mostro o valor atual
        temporary = temporary->next; //imediatamente após eu passo pro próximo
    }

    printf("\n");

}

node_t *create_new_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value; 
    result->next = NULL; 
    return result;
}

int main(){
    node_t *head;
    node_t *tmp;

    tmp = create_new_node(32); //adiciono o valor
    head = tmp; //igualo ele a função
    tmp = create_new_node(8); //adiono o valor
    tmp->next = head; //esse novo valor adicionado sinaliza que o head atual vai ser o próximo valor, ou seja, ele vira o head atual
    // ...
    head = tmp;
    tmp = create_new_node(34);
    tmp->next = head;
    head = tmp;

    printlist(head);
    return 0;
}