/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:06:03 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/13 00:23:23 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


int	ft_find_max(int **num, int row, int col)
{
	int	i;
	int	j;
	int	max;

	i = -1;
	max = 1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (max < num[i][j])
			{
				max = num[i][j];
			}
		}
	}
	return (max);
}

int	ft_find_max_row(int **num, int row, int col)
{
	int	i;
	int	j;
	int	max;
	int	max_row;

	i = -1;
	max = 1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (max < num[i][j])
			{
				max = num[i][j];
				max_row = i;
			}
		}
	}
	return (max_row);
}

int	ft_find_max_col(int **num, int row, int col)
{
	int	i;
	int	j;
	int	max;
	int	max_col;

	i = -1;
	max = 1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (max < num[i][j])
			{
				max = num[i][j];
				max_col = j;
			}
		}
	}
	return (max_col);
}
