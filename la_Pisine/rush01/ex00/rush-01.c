#include <unistd.h>
#include <stdlib.h>

#define SIZE 4

int **putValueByIdx(int **result, int **flag, int i, int j)
{
	if (i < 4)
	{
		if (j == 0)
		{
			flag[0][i] = 1;
			result[0][i] = 4;
		}
		else
		{
			flag[3][i] = 1;
			result[0][i] = 4;
		}
	}
	else
	{
		if (j == 0)
		{
			flag[i - 4][0] = 1;
			result[i - 4][0] = 4;
		}
		else
		{
			flag[i - 4][3] = 1;
			result[i - 4][0] = 4;
		}
	}
	return (result);
}

int	**putMAX(int **input, int **result, int **flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SIZE)
	{
		while (j < 2)
		{
			// input value is 1.
			if (input[i][j] - '0' == 1)
				putValueByIdx(result, flag, i, j);
		}  
		if (input[i][0] + input[i][1] == SIZE + 1)
			putValueByIdx(result, flag, i, j);
		i++;
	}
	return (result);
}


void rush(int **result)
{
	int i;
	int	j;

	i = 8;
	j = 1;
	while (i < 8)
	{
		while (i < 4)
		{
			if (result[i][0] + result[i][5] == 5)
			{
				result[i][result[i][0] - '0'] = 4;
			}
			i++;
		}
	}
	
}

int main (int ac, char **av)
{
	int **input;
	int **flag;
	int **result;
	int i;

	i = 1;
	
	input = malloc(sizeof(int*) * (SIZE * 2));
	*input = malloc(sizeof(int) * 2);
	flag = malloc(sizeof(int*) * SIZE);
	*flag = malloc(sizeof(int) * SIZE);	
	result = malloc(sizeof(int*) * SIZE);
	*result = malloc(sizeof(int) * SIZE);
	if (ac == 2)
	{
		while (i < SIZE * SIZE)
			flag[i / SIZE][i % SIZE] = 0;
		while (i < 2 * SIZE)
		{
			input[i % SIZE][i / SIZE] = av[1][2 * i] - '0';
			i++;
		}
		while (i < 4 * SIZE)
		{
			input[i % SIZE + 4][i / SIZE - 2] = av[1][2 * i] - '0';
			i++;
		}	
		result = putMAX(input, result, flag);
	}

	i = 0;
	while (i < 16)
	{
		result[i / SIZE][i % SIZE] += '0';
		write(1, &result[i / SIZE][i % SIZE], 1);
		write(1, " ", 1);
		i++;
		if (i % SIZE == 0)
			write(1, "\n", 1);
	}
}