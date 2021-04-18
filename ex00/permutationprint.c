#include <stdio.h>

#define SIZE 4

int array1[] = {1,2,3,4}; //array can be {1,1,2,3} for example also
int array2[SIZE];
int fixed[SIZE];

void print_array(int array[], int size){
    for(int k = 0; k < size; k++) printf("%d ",array[k]);
    //printf("\n");
}

int is_present_in_fixed(int array[], int size, int element ){
    for(int k =0; k<size;k++)
        if(element == array[k]) return 1;
    return 0;
}

void permWithRep(int array2[], int fixed_index[], int size , int level){
	int array3[SIZE];
	int i;

	i = 0;
	while (i < SIZE)
	{
		array3[i] = i + 1;
		i++;
	}
	print_array(array3, SIZE);
	printf("\n________________________\n");
	printf("level: \t%d\t", level);
	printf("Array 1:\t");
	print_array(array3, SIZE);
	printf("Array 2:\t");
	print_array(array2, SIZE);
	printf("Fixed  :\t");
	print_array(fixed_index, SIZE);
    if(level == size) 
	{
		printf("Encontrado:\t");
		print_array(array2,size);
		return ; // print_array(array2,size);
	}
    for(int k = 0; k< size; k++){
		printf("\nisPresentInfixed: %d\tk: %d", is_present_in_fixed(fixed_index,level,k), k);
        if(!is_present_in_fixed(fixed_index,level,k)){
            fixed_index[level] = k;
            array2[level] = array3[k];
            permWithRep(array2,fixed_index,size,level+1);
        }

    }
}

int main()
{
	int	**arr;
	int max_posib;
	int	i;
	int	j;

	max_posib = ft_calculate_max_posibilities();
	i = 0;
	arr = (int **) malloc (max_posib * sizeof (int *));
	while (i < max_posib)
	{
		arr[i] = (int *) malloc (SIZE * sizeof(int));
		i++;
	}

	while (i < max_posib)
	{
		permWithRep (arr[i], fixed, SIZE, 0);
		i++;
	}

    
    permWithRep (array2, fixed, SIZE, 0);
	printf("-------Array2------\n");
	print_array(array2, sizeof(array2)/sizeof(int));
	printf("-------Fixed------\n");
	print_array(array2, sizeof(array2)/sizeof(int));
    return 0;
}
