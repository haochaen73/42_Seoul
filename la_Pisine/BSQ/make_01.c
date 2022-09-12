/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subilee <subilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:03:31 by subilee           #+#    #+#             */
/*   Updated: 2022/09/12 22:16:33 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*make_num(char *map, char *c)
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
		num[i] = make_num(map[i], c);
		i++;
	}
	return (num);
}
