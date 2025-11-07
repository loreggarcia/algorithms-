#include <stdio.h>

int numbers[] = {1, 23, 34, 45, 56, 67, 105, 78, 89, 100, 109, 230};
const length = sizeof(numbers) / sizeof(numbers[0]);
int h = length;
int l = 0;
int m;
int target = 105;


int main(){
	for(int i = 0; i < length; i += m){
       m = (h-l)/2;
         if(numbers[i] == target){
            printf("The index is: %d", i);
            break;
         } 

         else if(numbers[i] > target){
            l = m + 1;
         } 
         
         else {
            h = m;
         }
    }
    return 0;
}

