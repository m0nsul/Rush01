#include <stdio.h>
#include <stdlib.h>

#define SIZE 4   

int	ft_int_is_in_line (int a, int *line)
{
	int	count;

	count = -1;
	while (++count < 4)
	{
		printf("\ncount: %d\tvalue: %d", count, line[count]);
		if (line[count] == a)
			return (1);
	}
	return (0);
}

int	ft_line_is_correct (int *line)
{
	int	count;

	count = 0;
	while (count++ < 4)
	{
		printf("\ncount: %d\tft_int_is_in_line: %d", count, ft_int_is_in_line (count, line));
		if (!(ft_int_is_in_line (count, line)))
			return (0);
	}
	return (1);
}

// void	ft_print_matrix (*arr)
// {

// }

int	ft_calculate_max_posibilities (void)
{
	int	size;
	int	ret;

	ret = 1;
	size = SIZE;
	while (size > 0)
		ret *= size--;
	return (ret);
}

int	ft_int_is_in_array (int c, int *arr)
{
	int	i;
	int	size_of_arr;

	size_of_arr = sizeof(arr);
	i = 0;
	while (i < sizeof(arr))
	{
		if (arr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int ft_arrays_are_equal (int *arr1, int *arr2)
{
	int	i;
	int size;

	i = 0;
	while (i < SIZE)
	{
		if (arr1[i] != arr2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_arr_is_in_posib (int *arr, int **posib)
{
	int	i;
	int	j;
	int	max_posib;

	max_posib = ft_calculate_max_posibilities();
	i = 0;
	while (i < max_posib)
	{
		j = 0;
		while (j < SIZE)
		{
			if (posib[i][j] != arr[j])
			{
				break ;
			}
			j++;
		}
		if (j == 4)
			return (1);
		i++;
	}
	return (0);
}


void	ft_generate_all_posibilities (int **arr)
{
	int	max_posib;
	int	i;
	int	j;
	int	c;

	max_posib = ft_calculate_max_posibilities();

	i = 0;
	while (i < max_posib)
	{
		j = 0;
		while (j < SIZE)
		{
			c = 0;
			while (c++ < SIZE)
			{
				if (!(ft_int_is_in_array (c, arr[i])))
				{
					arr[i][j] = c;
					break;
				}
			}
			j++;
		}
		i++;
	}

	i = 0;
	while (i < max_posib)
	{
		j = 0;
		while (j < SIZE)
		{
			printf("%d ", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


int next_comb(int comb[], int k, int n) {
	int i = k - 1;
	++comb[i];
	while ((i >= 0) && (comb[i] >= n - k + 1 + i)) {
		--i;
		++comb[i];
	}

	if (comb[0] > n - k) /* Combination (n-k, n-k+1, ..., n) reached */
		return 0; /* No more combinations can be generated */

	/* comb now looks like (..., x, n, n, n, ..., n).
	Turn it into (..., x, x + 1, x + 2, ...) */
	for (i = i + 1; i < k; ++i)
		comb[i] = comb[i - 1] + 1;

	return 1;
}

void printc(int comb[], int k) {
	printf("{");
	int i;
	for (i = 0; i < k; ++i)
		printf("%d, ", comb[i] + 1);
	printf("\b\b}\n");
}

int	main (void)
{
	int	filas;
	int	columnas;
	int	i;
	int	j;
	int	c;
	int	**arr;
	int	max_posib;


	



	max_posib = ft_calculate_max_posibilities();
	i = 0;
	arr = (int **) malloc (max_posib * sizeof (int *));
	while (i < max_posib)
	{
		arr[i] = (int *) malloc (SIZE * sizeof(int));
		i++;
	}
	i = 0;
	while (i < max_posib)
	{
		j = 0;
		while (j < SIZE)
		{
			c = 0;
			while (c++ <= SIZE)	
			{
				arr[i][j] = 0;
			}
			j++;
		}
		i++;
	}
	ft_generate_all_posibilities (arr);



	int arr1[4] = {1,2,3,4};
	int arr2[4] = {1,3,3,4};
	printf("\n--------- %d --------\n", i );
	//printf("%d", ft_arr_is_in_posib (arr2, arr));
	//printf("%d", ft_arrays_are_equal (arr1, arr2));



	while (next_comb(arr1, SIZE, SIZE))
		printc(arr1, SIZE);

	i = 0;
	// while (i < max_posib)
	// {
	// 	j = 0;
	// 	while (j < SIZE)
	// 	{
	// 		printf("%d ", arr[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	free(arr);
	return (0);
}


