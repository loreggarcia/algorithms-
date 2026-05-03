//Hash Table is an array with a hash function to compute the index of the array where the value will be stored.

#include <stdio.h> 
#include <stdlib.h> // for malloc and free
#include <string.h> // manipulação de strings
#include <stdint.h> // declara conjuntos de tipos inteiros que possuem larguras especificadas
#include <stdbool.h> // for bool type

#define MAX_NAME 256
#define TABLE_SIZE 7

typedef struct {
    char name[MAX_NAME];
    int age;  
} person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME); //1. Mede o tamanho do nome
    unsigned int hash_value = 0; // 2.Começa com o valor zero
    for(int i=0; i<length; i++){ // 3. Para cada letra do nome 
        hash_value += name[i]; // 4. Soma o valor numérico da letra 
        hash_value = (hash_value * name[i]) % TABLE_SIZE; //5. Faz um calculo e usa o resto da divisão
    }
    return hash_value;
}

void init_hash_table(){
    for(int i = 0; i<TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    //table is empty
}


bool hash_table_insert(person *p){
    if(p == NULL) return false;
    int index = hash(p->name);
    if(hash_table[index] != NULL){
        return false;
    }
    hash_table[index] = p;
    return true;
}

person*hash_table_lookup(char *name){
    int index = hash(name);
    if(hash_table[index] != NULL && 
        strncmp(hash_table[index]->name, name, TABLE_SIZE)==0){
            return hash_table[index];
    } else{
        return NULL;
    } 
}

person*hash_table_delete(char *name){
    int index = hash(name);
    if(hash_table[index] != NULL && 
        strncmp(hash_table[index]->name, name, TABLE_SIZE)==0){
            person *tmp = hash_table[index];
            hash_table[index] = NULL;
            return tmp;
    } else{
        return NULL;
    } 
}

void print_table(){
    /*
    %i -> espera um inteiro 
    %s -> espera uma string
    */
    printf("Start\n");
    for(int i=0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n", i); // when the element dont have a key
        }else{
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

int main(){
    init_hash_table();

    person Maria = {.name="Maria", .age=256};
    person Marcos = {.name="Marcos", .age=27};
    person Davi = {.name="Davi", .age=14};
    person Luiz = {.name="Luiz", .age=14};

    hash_table_insert(&Maria);
    hash_table_insert(&Marcos);
    hash_table_insert(&Luiz);

    print_table();
    
    person *tmp = hash_table_lookup("Vasco");
    if(tmp == NULL){
    printf("NOT FOUND\n");
    } else{ printf("FOUND: %s\n", tmp->name);
    }
    
    tmp = hash_table_lookup("Luiz");
    if(tmp == NULL){
    printf("NOT FOUND");
    } else{ printf("FOUND: %s\n", tmp->name);
    }
    

    /*
    printf("Maria => %u\n", hash("Maria"));
    printf("Luiz => %u\n", hash("Luiz"));
    printf("Marcos => %u\n", hash("Marcos"));
    printf("Davi => %u\n", hash("Davi"));
    printf("Raissa => %u\n", hash("Raissa"));
    printf("Rafael => %u\n", hash("Rafael"));
    printf("Isaac => %u\n", hash("Isaac"));
    */
    return 0;
}