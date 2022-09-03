#include <unistd.h>
#include <stdlib.h>

#define SIZE 4

int **putValueByIdx(int **input, int **result, int idx, int value)
{
	if (idx < 4)
		result[input[idx][0] - '0' - 1][idx] = value;
	else
		result[idx % SIZE][input[idx][0] - '0' - 1] = value;
	return (result);
}

int	**putMAX(int **input, int **result, int **flag)
{
	int	i;

	i = 0;
	while (i < SIZE * SIZE)
	{
		if (input[i / SIZE][i % SIZE] - '0' == 1)
		{
			putValueByIdx(input, result, i, SIZE);
			flag[i / SIZE][i % SIZE] = 1;
		}
			
		if (!flag[i / SIZE][i % SIZE] && input[i % SIZE][0] + input[i % SIZE][1] == SIZE + 1)
			putValueByIdx(input, result, i, SIZE);
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
	if (ac == 17)
	{
		while (i < SIZE * SIZE)
			flag[i / SIZE][i % SIZE] = 0;
		while (i < 2 * SIZE)
		{
			input[i % SIZE][i / SIZE] = av[i][0] - '0';
			i++;
		}
		while (i < 4 * SIZE)
		{
			input[i % SIZE + 4][i / SIZE - 2] = av[i][0] - '0';
			i++;
		}	
		result = putMAX(input, result, flag);
	}
}
