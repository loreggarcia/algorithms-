#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool status[] = {false, false, false, false, true, true, true, true, true, true, true, true};
const int length = sizeof(status) / sizeof(status[0]);
int jump;

int main() { 
  jump = sqrt(length);
  for(int i = 0; i < length; i += jump){
  		if(status[i] == true){
            for (int j = i - jump; j < i; j++) {
              if(status[j] == true){	
                 printf("\n O estado aparece no index:%d", j); 
                 break;
              } 
            }   
        break;
        }
  }
}