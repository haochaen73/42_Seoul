/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subilee <subilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:02:40 by subilee           #+#    #+#             */
/*   Updated: 2022/09/13 00:28:13 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_entirelen(int fd, char *buf);
char	*ft_put_entire(int fd, int total);
char	*check_0th_row(char *buf, int *row, char *c);
int		ft_rowcol_check(char *buf, int *row, int *col);
char	**ft_split_put(char *buf, int *row, int *col);
int		**make_num_map(char **map, char *c, int row_len);
void	ft_save_num(int **num, int row, int col);
int	ft_find_max(int **num, int row, int col);
int	ft_find_max_row(int **num, int row, int col);
int	ft_find_max_col(int **num, int row, int col);
int	ft_exist_in_c(char *c, char *buf, int total);


char	**set_char_map(int fd, int *row, int *col, char *c)
{
	int		total;
	char	*buf;
	char	*start;
	char	**map;

	buf = (char *)malloc(sizeof(char) * 10000);
	if (!buf)
	{
		write(2, "Malloc Error!\n", 14);
		return (0);
	}
	if ((total = ft_entirelen(fd, buf)) == -1)
		return (0);
	start = check_0th_row(buf, row, c);
	if (!(ft_rowcol_check(start, row, col) && ft_exist_in_c(c, start, total)))
		return (0);
	map = ft_split_put(start, row, col);
	free(buf);
	return (map);
}

void	ft_full(char **map, int max, int max_row, int max_col, char *c)
{
	int	i;
	int	j;

	i = max_row - (max - 1);
	while (i <= max_row)
	{
		j = max_col - (max - 1);
		while (j <= max_col)
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
	write(1, "\n", 1);
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

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	int		row;
	int		col;
	char	c[3];
	int		p;
	char	**map;
	int		**num;

	i = 1;
	p = 0;
	if (ac > 1)
	{
		while (i < ac)
		{
			row = 0;
			col = 0;
			fd = open(av[i], O_RDWR);
			map = set_char_map(fd, &row, &col, &c[0]);
			if (map == 0)
			{
				i++;
				write(2, "Map Error!\n", 11);
				continue;
			}
			num = make_num_map(map, &c[0], row);
			ft_save_num(num, row, col);
			ft_full(map, ft_find_max(num, row, col), ft_find_max_row(num, row, col), ft_find_max_col(num, row, col), &c[0]);
			ft_print(map, row, col);
			ft_free(map, num, row);
			close(fd);
			i++;
		}
	}
	return (0);
}