#include <unistd.h>
#include <stdlib.h>

#define SIZE 4

void rush(int **result)
{
	int i;

	i = 8;
	j = 1;
	while (i < 8)
	{
		while (i < 4)
		{
			if (result[i][0] + result[i][5] == 4)
			{
				result[i][result[i][0] - '0'] = 4;
			}
		}
	}
}
		

int main (int ac, char **av)
{
	int **result;
	int i;

	i = 0;
	result = malloc(sizeof(*int) * SIZE);
	*result = malloc(sizeof(int) * (SIZE + 2));
	if (ac == 17)
	{
		while (i < SIZE)
			result[i][0] = av[i + 1][0] - '0';
		i = 0;
		while (i < SIZE)
			result[i][5] = av[i + 5][0] - '0';
		while (i < SIZE)
			result[i + 4][0] = av[i + 9][0] - '0';
		while (i < SIZE)
			result[i + 4][5] = av[i + 13][0] - '0';
		ft_rush01();
	}
}
