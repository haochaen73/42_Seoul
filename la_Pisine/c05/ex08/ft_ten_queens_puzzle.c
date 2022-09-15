/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:39:42 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/06 17:41:32 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printf(int *map)
{
	int		i;
	char	temp;

	i = 0;
	while (i < 10)
	{
		temp = map[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_check_putvalid(int *map, int idx, int col)
{
	int	idx2;

	idx2 = 0;
	while (idx2 < idx)
	{
		if ((col == map[idx2]) || (idx - col == idx2 - map[idx2])
			|| (idx + col == idx2 + map[idx2]))
			return (0);
		idx2++;
	}
	return (1);
}

int	ft_solve_puzzle(int *map, int idx, int col, int *count)
{
	while (col <= 9)
	{
		if (ft_check_putvalid(map, idx, col))
			map[idx] = col;
		else
		{
			col++;
			continue ;
		}
		if (idx < 9)
			ft_solve_puzzle(map, idx + 1, 0, count);
		else
		{
			ft_printf(map);
			(*count)++;
		}
		col++;
	}
	return (*count);
}

int	ft_ten_queens_puzzle(void)
{
	int	map[11];
	int	count;
	int	i;

	i = 0;
	while (i < 10)
		map[i++] = 200;
	count = 0;
	ft_solve_puzzle(map, 0, 0, &count);
	return (count);
}
