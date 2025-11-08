#include <stdio.h>
int numbers[] = {100, 425, 35, 78, 17, 9, 230, 34, 78, 18};
const int length = sizeof(numbers) / sizeof(numbers[0]);
int i;
int j;
int swap;
int temp;

int main(){
	for(i = 0; i < length; i++){ 
    	for(j = 0; j < length-1-i; j++){ // 
        	if(numbers[j] > numbers[j+1]){
            	swap = numbers[j];
                numbers[j] = numbers[j+1];
            	numbers[j+1] = swap;
            }
        }
    }
    printf("%d, %d, %d",numbers[0], numbers[1], numbers[2]);
}