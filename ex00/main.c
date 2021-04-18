#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 4

int array1[] = {1, 2, 3, 4}; //array can be {1,1,2,3} for example also
int array2[SIZE];
int fixed[SIZE];

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i++])
		;
	return (i--);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int ft_atoi(char nbr)
{
	int n;

	n = nbr - ('0');
	return (n);
}

int ft_viewscheck(char *views_str, int *views_int)
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

int ft_calculate_max_posibilities(void)
{
	int size;
	int ret;

	ret = 1;
	size = SIZE;
	while (size > 0)
		ret *= size--;
	return (ret);
}

int ft_int_is_in_array(int c, int *arr)
{
	int i;
	int size_of_arr;

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

int ft_arrays_are_equal(int *arr1, int *arr2)
{
	int i;
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

int ft_arr_is_in_posib(int *arr, int **posib)
{
	int i;
	int j;
	int max_posib;

	max_posib = ft_calculate_max_posibilities();
	i = 0;
	while (i < max_posib)
	{
		j = 0;
		while (j < SIZE)
		{
			if (posib[i][j] != arr[j])
			{
				break;
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
	for (int k = 0; k < size; k++)
		printf("%d ", array[k]);
}

int is_present_in_fixed(int array[], int size, int element)
{
	for (int k = 0; k < size; k++)
		if (element == array[k])
			return 1;
	return 0;
}

void permWithRep(int **arr, int array2[], int fixed_index[], int size, int level, int posib)
{
	int array3[SIZE];
	int i;
	int j;
	int k;
	int max_posib;

	i = -1;
	while (++i < SIZE)
		array3[i] = i + 1;

	if (level == size)
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
		return;
	}
	k = -1;
	while (++k < size)
		if (!is_present_in_fixed(fixed_index, level, k))
		{
			fixed_index[level] = k;
			array2[level] = array3[k];
			permWithRep(arr, array2, fixed_index, size, level + 1, posib);
		}
}

int ft_calculate_row_view_left(int *row)
{
	int i;
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

int ft_calculate_row_view_right(int *row)
{
	int i;
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

int check_main(int argc, char **argv)
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

void reset()
{
	printf("\033[0m");
}

void Black() { printf("\033[0;30m"); }
void Red() { printf("\033[0;31m"); }
void Green() { printf("\033[0;32m"); }
void GreenBold() { printf("\033[1;32m"); }
void Yellow() { printf("\033[0;33m"); }
void Blue() { printf("\033[0;34m"); }
void Purple() { printf("\033[0;35m"); }
void Cyan() { printf("\033[0;36m"); }
void White() { printf("\033[0;37m"); }

int ft_find_next_zero(int *arr)
{
	int i;

	i = 0;
	while (arr[i++] != -1)
		;
	return --i;
}

void ft_fill_arr_with_neg(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		arr[i++] = -1;
}

int **ft_initialize_grid()
{
	int i;
	int j;
	int **grid;

	grid = (int **)malloc(SIZE * sizeof(int *));
	i = 0;
	while (i < SIZE)
	{
		grid[i] = (int *)malloc(SIZE * sizeof(int));
		j = 0;
		while (j < SIZE)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return grid;
}

void ft_print_grid(int **grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("\n");
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			printf("%d ", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void ft_add_row_to_grid(int **grid, int *row, int pos)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		grid[pos][i] = row[i];
		i++;
	}
}

int ft_int_is_repeated_in_line(int a, int *line)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (++i < SIZE)
	{
		if (line[i] == a)
		{
			count++;
			if (count > 1)
				return (1);
		}
	}
	return (0);
}

int ft_line_is_correct(int *line)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		//printf ("\nlineI: %d intInLine: %d", line[i], ft_int_is_repeated_in_line (line[i], line));
		if (line[i] != 0 && ft_int_is_repeated_in_line(line[i], line))
			return (0);
		i++;
	}
	return (1);
}

void ft_get_column(int **grid, int *row, int colnum)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		row[i] = grid[i][colnum];
		i++;
	}
}

int ft_check_columns_repeat(int **grid)
{
	int i;
	int j;
	int *row;

	row = (int *)malloc(SIZE * sizeof(int *));

	i = 0;
	j = 0;
	while (i < SIZE) // fila
	{
		ft_get_column(grid, row, i);
		if (!(ft_line_is_correct(row)))
		{
			//print_array(row, SIZE);
			//printf("Columna %d Incorrecta\n", i);
			free(row);
			return (0);
		}
		i++;
	}
	free(row);
	return (1);
}

int ft_calculate_views(int **grid, int *int_views)
{
	int i;
	int j;
	//int	*row;

	//row = (int *) malloc (SIZE * sizeof (int *));

	i = 0;
	j = 0;
	
	while (i < SIZE && grid[i][0] != 0) // fila
	{

		print_array(grid[i], SIZE);
		printf("\tview n: %d", SIZE * 2 + i);

		//ft_get_column (grid, row, i);
		printf("\tL %d", ft_calculate_row_view_left(grid[i]));
		printf("(%d)", int_views[SIZE * 2 + i]);

		printf(" R %d", ft_calculate_row_view_right(grid[i]));
		printf("(%d)  ", int_views[SIZE * 3 + i]);
		if (!(ft_calculate_row_view_left(grid[i]) == int_views[SIZE * 2 + i] && ft_calculate_row_view_right(grid[i]) == int_views[SIZE * 3 + i]))
		{
			printf("\tNo cumple vistas laterales\n");
			return (0);
		}
		printf("\n");
		i++;
	}
	//free (row);
	return (1);
}

int ft_grid_is_valid(int **grid, int *int_views, int etapa)
{
	if (!(ft_check_columns_repeat(grid)))
		return (0);
	else if (!(ft_calculate_views(grid, int_views)))
	{
		printf("\tNo cumple\n");
		return (0);
	}
	return (1);
}

int ft_solve(int **grid, int *int_views, int **arr_rows, int etapa, int success)

{
	int row;
	int max_posib;

	max_posib = ft_calculate_max_posibilities();
	row = 0;
	while (row < max_posib && !success)
	{
		ft_add_row_to_grid(grid, arr_rows[row], etapa);
		if (ft_grid_is_valid(grid, int_views, etapa))
		{
			if (etapa != SIZE - 1)
			{
				success = ft_solve(grid, int_views, arr_rows, ++etapa, 0);
			}
			else
			{
				printf("\n--------------------------- VALIDO -----------------------\n");
				ft_print_grid(grid);
				printf("\n--------------------------- VALIDO -----------------------\n");
				success = 1;
			}
		}
		row++;
	}
	return (success);
}

int main(int argc, char **argv)
{
	int i;
	int j;
	int c;
	int **arr_rows;
	int **arr_cols;
	int candid_rows[SIZE][20];
	int candid_cols[SIZE][20];
	int **grid;
	int max_posib;
	int int_views[SIZE * SIZE];

	grid = ft_initialize_grid();
	ft_print_grid(grid);

	j = 0;
	while (j++ < SIZE)
	{
		ft_fill_arr_with_neg(candid_rows[j - 1], 20);
		ft_fill_arr_with_neg(candid_cols[j - 1], 20);
	}

	check_main(argc, argv);
	ft_viewscheck(argv[1], int_views);
	max_posib = ft_calculate_max_posibilities();
	arr_rows = (int **)malloc(max_posib * sizeof(int *));
	i = 0;
	while (i < max_posib)
	{
		arr_rows[i] = (int *)malloc(SIZE * sizeof(int));
		i++;
	}
	permWithRep(arr_rows, array1, fixed, SIZE, 0, 0);
	arr_cols = (int **)malloc(max_posib * sizeof(int *));
	i = 0;
	while (i < max_posib)
	{
		arr_cols[i] = (int *)malloc(SIZE * sizeof(int));
		i++;
	}
	permWithRep(arr_cols, array1, fixed, SIZE, 0, 0);
	i = 0;
	c = 0;
	while (i < max_posib)
	{
		// if (arr[i][0] == 1) Green();
		// else if (arr[i][0] == 2) Yellow();
		// else if (arr[i][0] == 3) Blue();
		// else if (arr[i][0] == 4) Purple();
		//print_array(arr[i], SIZE);

		printf("L %d ", ft_calculate_row_view_left(arr_rows[i]));
		printf("R %d     ", ft_calculate_row_view_right(arr_rows[i]));
		j = 0;
		while (j++ < SIZE)
		{
			if (ft_calculate_row_view_left(arr_rows[i]) == int_views[SIZE * 2 + j - 1] && ft_calculate_row_view_right(arr_rows[i]) == int_views[SIZE * 3 + j - 1])
			{
				GreenBold();
				printf("\xE2\x9C\x94 ");
				candid_rows[j - 1][ft_find_next_zero(candid_rows[j - 1])] = i;
			}
			else
				printf("  ");
			print_array(arr_rows[i], SIZE);
			printf("   L%d (%d)  ", j - 1, int_views[SIZE * 2 + j - 1]);
			printf("R%d (%d)  ", j - 1, int_views[SIZE * 3 + j - 1]);

			reset();
		}
		printf("\n");
		reset();

		i++;
	}

	j = 0;
	while (j < SIZE)
	{

		printf("\nCandidates Rows: ");
		print_array(candid_rows[j], 20);
		j++;
	}
		j = 0;

	printf("\n\n______________\n\n");
	i = 0;

	while (i < max_posib)
	{
		// if (arr[i][0] == 1) Green();
		// else if (arr[i][0] == 2) Yellow();
		// else if (arr[i][0] == 3) Blue();
		// else if (arr[i][0] == 4) Purple();
		//print_array(arr[i], SIZE);
		c = 0;
		printf("L %d ", ft_calculate_row_view_left(arr_cols[i]));
		printf("R %d     ", ft_calculate_row_view_right(arr_cols[i]));
		j = 0;
		while (j++ < SIZE)
		{
			if (ft_calculate_row_view_left(arr_cols[i]) == int_views[SIZE * 0 + j - 1] && ft_calculate_row_view_right(arr_cols[i]) == int_views[SIZE * 1 + j - 1])
			{
				GreenBold();
				printf("\xE2\x9C\x94 ");
				candid_cols[j - 1][ft_find_next_zero(candid_cols[j - 1])] = i;
			}
			else
				printf("  ");
			print_array(arr_cols[i], SIZE);
			printf("   L%d (%d)  ", j - 1, int_views[SIZE * 2 + j - 1]);
			printf("R%d (%d)  ", j - 1, int_views[SIZE * 3 + j - 1]);

			reset();
		}
		printf("\n");
		reset();
		i++;
	}

	ft_solve(grid, int_views, arr_rows, 0, 0);
	ft_print_grid(grid);

	j=0;
	while (j < SIZE)
	{

		printf("\nCandidates Cols: " );
		print_array(candid_cols[j], 20);
		j++;
	}

	// i = 0;

	// i = 0;
	// while (i < max_posib)
	// {
	// 	j=0;
	// 	while (j < SIZE)
	// 	{
	// 		c = 0;
	// 		while (c < max_posib)
	// 		{

	// 			if (arr_rows[i][j] = arr_cols[c][j] && ft_int_is_in_array (i, candid_rows)  && ft_int_is_in_array (c, candid_cols))
	// 			{
	// 				print_array(arr_rows[i], SIZE);
	// 				printf (" - i: %d j: %d <==> ", i, j);
	// 				print_array(arr_cols[c], SIZE);
	// 				printf (" - c: %d j: %d\n", c, j);

	// 			}
	// 			c++;
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }

	i = -1;
	while (++i < max_posib)
	{
		free(arr_rows[i]);
		free(arr_cols[i]);
	}
	free(arr_rows);
	free(arr_cols);

	return (0);
}
