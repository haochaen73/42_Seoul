/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entirelen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:22:53 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/12 23:56:01 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_entirelen(int fd, char *buf)
{
	int		byte_read;
	int		total;

	total = 0;
	while ((byte_read = read(fd, buf, 10000)) != 0)
	{
		if (byte_read == -1)
		{
			write(2, "Error!\n", 7);
			return (-1);
		}
		total += byte_read;
	}
	buf[total] = '\0';
	return (total);
}

int	ft_rowcol_check(char *buf, int *row, int *col)
{
	int	len;
	int	i;
	int	row_len;
	int	first_row;

	len = 0;
	i = 0;
	row_len = 1;
	first_row = 1;
	while (buf[i] != '\0')
	{
		if (first_row)
		{
			while (buf[i] != '\n')
			{
				(*col)++;
				i++;
			}
			i++;
			first_row = 0;
		}
		else
		{
			len = 0;
			while (buf[i] != '\n' && buf[i] != '\0')
			{
				len++;
				i++;
			}
			i++;
			row_len++;
			if (*col != len)
				return (0);
		}
	}
	if (row_len != *row)
		return (0);
	return (1);
}

int	ft_exist_in_c(char *c, char *buf, int total)
{
	int	idx;
	int	i;

	idx = 0;
	i = 0;
	while (idx < total)
	{
		if (buf[idx] != '\n' && buf[idx] != '\0')
		{
			if (!(c[0] == buf[idx] || c[1] == buf[idx]))
				return (0);
		}
		idx++;
	}
	return (1);
}

char	**ft_split_put(char *buf, int *row, int *col)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (char **)malloc(sizeof(char *) * (*row));
	if (!map)
		return (0);
	while (i < *row)
	{
		map[i] = (char *)malloc(sizeof(char) * (*col + 1));
		if (!map[i])
			return (0);
		i++;
	}
	i = 0;
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
