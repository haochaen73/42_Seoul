/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:17:21 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/15 00:17:22 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_min(int a1, int a2, int b1)
{
	int	min;

	if (a1 < a2)
		min = a1;
	else
		min = a2;
	if (b1 < min)
		min = b1;
	return (min);
}

int	*ft_find_max(int **num, int row, int col)
{
	int	i;
	int	j;
	int	*max;

	i = -1;
	max = (int *)malloc(sizeof(int) * 3);
	max[0] = 0;
	max[1] = 0;
	max[2] = 0;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (max[0] < num[i][j])
			{
				max[0] = num[i][j];
				max[1] = i;
				max[2] = j;
			}
		}
	}
	return (max);
}

void	ft_full(char **map, int *max, char *c)
{
	int	i;
	int	j;

	i = max[1] - (max[0] - 1);
	while (i <= max[1])
	{
		j = max[2] - (max[0] - 1);
		while (j <= max[2])
		{
			map[i][j] = c[2];
			j++;
		}
		i++;
	}
}

void	ft_print(char **map, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		write(1, map[i], col);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_free(char **map, int **num, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(map[i]);
		free(num[i]);
		i++;
	}
	free(map);
	free(num);
}
