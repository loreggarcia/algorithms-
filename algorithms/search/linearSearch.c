#include <stdio.h>

//array 

//sizeof() => returns the size of a type in bytes.
//each elemente in dataset one by one 
//create a function
int numbers[] = {100, 425, 35, 78, 17, 9};
int length = sizeof(numbers) / sizeof(numbers[0]);
int i;
int target = 35;

int main(){    
    for (i = 0; i < length; i++) {
          if(numbers[i] == target){	
          	 printf("\n Index:%d", i); 
             break;
      } 
    }    
    return 0;
}


