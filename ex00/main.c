#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 4

int array1[] = {1,2,3,4}; //array can be {1,1,2,3} for example also
int array2[SIZE];
int fixed[SIZE];


int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i++])
		;
	return (i--);
}

int	ft_is_valid_argv_char(char c)
{
	if (c == ' ')
		return (1);
	else if ((c >= '1') && (c <= '4'))
		return (1);
	return (0);
}


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_atoi(char nbr)
{
	int n;

	n = nbr - ('0');
	return (n);
}


int	ft_viewscheck(char *views_str, int *views_int)
{
	int ci;
	int cs;

	ci = 1;
	cs = 1;
	views_int[0] = ft_atoi(views_str[0]);
	while (views_str[cs] != '\0')
	{
		if (views_str[cs] == ' ' &&
				views_str[cs + 1] >= '1' && views_str[cs + 1] <= '4')
		{
			views_int[ci] = ft_atoi(views_str[cs + 1]);
			cs += 2;
			ci++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}


int	ft_int_is_in_line (int a, int *line)
{
	int	count;

	count = -1;
	while (++count < SIZE)
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
	while (count++ < SIZE)
	{
		printf("\ncount: %d\tft_int_is_in_line: %d", count, ft_int_is_in_line (count, line));
		if (!(ft_int_is_in_line (count, line)))
			return (0);
	}
	return (1);
}

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
		if (j == SIZE)
			return (1);
		i++;
	}
	return (0);
}

void print_array(int array[], int size)
{
    for(int k = 0; k < size; k++) printf("%d ",array[k]);
}

int is_present_in_fixed(int array[], int size, int element )
{
    for(int k =0; k<size;k++)
        if(element == array[k]) return 1;
    return 0;
}

void permWithRep(int **arr, int array2[], int fixed_index[], int size , int level, int posib){
	int array3[SIZE];
	int i;
	int j;
	int k;
	int	max_posib;

	i = -1;
	while (++i < SIZE)
		array3[i] = i + 1;

    if(level == size) 
	{
		max_posib = ft_calculate_max_posibilities();
		i = -1;
		while (i++ < max_posib)
			if (arr[i][0] == 0)
			{
				j = -1;
				while (++j < SIZE)
					arr[i][j] = array2[j];
				break;
			}
		return ; 
	}
	k = -1;
	while (++k < size)
        if(!is_present_in_fixed(fixed_index,level,k))
		{
            fixed_index[level] = k;
            array2[level] = array3[k];
            permWithRep(arr, array2 ,fixed_index,size,level+1, posib);
        }
}

int	ft_calculate_row_view_left (int *row)
{
	int	i;
	int j;
	int views;
	int view;
	views = 1;
	i = 1;
	while (i < SIZE)
	{
		j = i - 1;
		view = 0;
		while (j >= 0)
			if (row[i] > row[j--])
				view++;
			j--;
		if (view == i)
			views++;
		i++;
	}
	return views;
}

int	ft_calculate_row_view_right (int *row)
{
	int	i;
	int j;
	int views;
	int view;
	
	views = 1;
	i = SIZE - 2;
	while (i >= 0)
	{
		j = i + 1;
		view = 0;
		while (j < SIZE)
			if (row[i] > row[j++])
				view++;
		if (view == SIZE - i - 1)
			views++;
		i--;
	}
	return views;
}



// int	*ft_validate_arg_views (char *str) 
// {

// }

int	check_main (int argc, char **argv)
{
	if (argc != 2) 
	{
        ft_putstr("Error: Wrong params number !\n");
        return (0);
    }
	else if (ft_strlen(argv[1]) != 32)
	{
        ft_putstr("Error: Wrong point of view string format !\n");
        return (0);
    }
	// else if (ft_validate_arg_views(argv[1]))
	// {
	// 	ft_putstring("Error: Wrong number of point of views  !\n");
    //     return (0);
	// }

	return (1);
}

int	main (int argc, char **argv)
{
	int	filas;
	int	columnas;
	int	i;
	int	j;
	int	c;
	int	**arr;
	int	max_posib;
	int int_views[SIZE * SIZE];


	check_main (argc, argv);
	ft_viewscheck (argv[1], int_views);
	

	//print_array(int_views, SIZE * SIZE - 1);


	max_posib = ft_calculate_max_posibilities();
	arr = (int **) malloc (max_posib * sizeof (int *));
	i = 0;
	while (i < max_posib)
	{
		arr[i] = (int *) malloc (SIZE * sizeof(int));
		i++;
	}
	permWithRep (arr, array1, fixed, SIZE, 0, 0);
	i = 0;
	while (i < max_posib)
	{
		print_array(arr[i], SIZE);
		printf ("\tL %d ", ft_calculate_row_view_left (arr[i]));
		printf ("R %d ", ft_calculate_row_view_right (arr[i]));
		j=0;
		while (j++ < SIZE)
		{
			printf ("\tL%d (%d)  ", j - 1, int_views[SIZE * 2 + j - 1]);
			printf ("R%d (%d)", j - 1, int_views[SIZE * 3 + j - 1]);
			if (ft_calculate_row_view_left (arr[i]) == int_views[SIZE * 2 + j - 1] && ft_calculate_row_view_right (arr[i]) == int_views[SIZE * 3 + j - 1])
				printf (" OK\t");
			else
				printf ("   \t");
		}
		printf ("\n");
		i++;
	}






	// i = 0;
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


