#include <stdio.h>

int array1[] = {1, 2, 3, 4}; //array can be {1,1,2,3} for example also
int array2[4];
int fixed[4];

void print_array(int array[], int size){
    for(int k = 0; k < size; k++)printf("%d ",array[k]);
    printf("\n");
}

int is_present_in_fixed(int array[], int size, int element ){
    for(int k =0; k<size;k++)
        if(element == array[k]) return 1;
    return 0;
}

void permWithRep(int array1[], int array2[],int fixed_index[], int size , int level){

    if(level == size) return print_array(array2,size);

    for(int k = 0; k< size; k++){

        if(!is_present_in_fixed(fixed_index,level,k)){
            fixed_index[level] = k;
            array2[level] = array1[k];
            permWithRep(array1,array2,fixed_index,size,level+1);
        }

    }
}

int main()
{
    int len = sizeof(array1)/sizeof(int);
    permWithRep (array1, array2, fixed, len, 0);
    return 0;
}
