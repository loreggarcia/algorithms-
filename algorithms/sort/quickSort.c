#include <stdio.h>

void swap(int *x, int *y){ //os ponteiros vão guardar as mudanças 
    int temp = *x;
    *x = *y;
    *y = temp;
}


int partition(int array[], int lo, int hi){
    int i = lo;
    int pivotValue = array[hi]; // particionamento de Lomuto: escolhe o último pedaço - o uso do array é para garantir que os high fiquem armazenados
    //hi poderia estar como uma estrutura de ponteiro
    for (int j = lo; j < hi; j++){
        if(array[j] <= pivotValue){
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[hi]);
    return i;
}

void quicksortRecursion(int array[], int lo, int hi){
    if(lo < hi){
        int pivotIndex = partition(array, lo, hi);
        //the two sides
        quicksortRecursion(array, lo, pivotIndex - 1);
        quicksortRecursion(array, pivotIndex + 1, hi);
    }
}

void quicksort(int array[], int length){
    quicksortRecursion(array, 0, length - 1); 
}


int main(){
    int a[] = {23, 48, 5, 98, 1, 69, 24, 73};
    int length = 8;

    quicksort(a, length);

    for (int i = 0; i < length; i++){
        printf("%d \n", a[i]);
    }

    return 0;
}