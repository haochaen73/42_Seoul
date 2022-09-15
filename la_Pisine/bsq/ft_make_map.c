/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:17:47 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/15 00:17:48 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_min(int a1, int a2, int b1);

int	*make_num_row(char *map, char *c)
{
	int	*row;
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (map[len])
		len++;
	row = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		if (map[i] == c[0])
			row[i] = 1;
		else if (map[i] == c[1])
			row[i] = 0;
		i++;
	}
	return (row);
}

int	**make_num_map(char **map, char *c, int row_len)
{
	int	i;
	int	**num;

	i = 0;
	num = (int **)malloc(sizeof(int *) * row_len);
	while (i < row_len)
	{
		num[i] = make_num_row(map[i], c);
		i++;
	}
	return (num);
}

void	ft_save_num(int **num, int row, int col)
{
	int	min;
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < row)
	{
		j = 1;
		while (j < col)
		{
			if (num[i][j] == 0)
			{
				j++;
				continue ;
			}
			min = ft_min(num[i - 1][j - 1], num[i - 1][j], num[i][j - 1]);
			num[i][j] = min + 1;
			j++;
		}
		i++;
	}
}

char	**map_malloc(int row, int col)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (row));
	if (!map)
		return (0);
	while (i < row)
	{
		map[i] = (char *)malloc(sizeof(char) * (col + 1));
		if (!map[i])
			return (0);
		i++;
	}
	return (map);
}

char	**ft_split_put(char *buf, int *row, int *col)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = map_malloc(*row, *col);
	while (i < *row)
	{
		j = 0;
		while (j < *col)
		{
			map[i][j] = *buf;
			buf++;
			j++;
		}
		map[i][j] = '\0';
		if (i != *row - 1)
			buf++;
		i++;
	}
	return (map);
}
