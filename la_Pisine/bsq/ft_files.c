/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:17:09 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/15 12:03:44 by subilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*check_0th_row(char *buf, int *row, char *c);
int		ft_rowcol_check(char *buf, int *row, int *col, int total);
int		ft_exist_in_c(char *c, char *buf, int total);
char	**ft_split_put(char *buf, int *row, int *col);
int		**make_num_map(char **map, char *c, int row_len);
void	ft_save_num(int **num, int row, int col);
int		*ft_find_max(int **num, int row, int col);
void	ft_full(char **map, int *max, char *c);
void	ft_print(char **map, int row, int col);
void	ft_free(char **map, int **num, int row);

int	ft_entirelen(char *av)
{
	int		byte_read;
	int		total;
	int		fd;
	char	buf[2];

	total = 0;
	buf[1] = '\0';
	fd = open(av, O_RDWR);
	byte_read = read(fd, buf, 1);
	while (byte_read != 0 && *buf != 0)
	{
		if (byte_read == -1)
			exit(1);
		total += byte_read;
		byte_read = read(fd, buf, 1);
	}
	close(fd);
	return (total);
}

int	ft_fill_buf(int fd, char *buf, int total)
{
	int	byte_read;

	byte_read = read(fd, buf, total);
	if (byte_read == -1)
		exit(1);
	buf[total] = '\0';
	return (1);
}

char	**set_char_map(int fd, int *rowcol, int total, char *c)
{
	char	*buf;
	char	*start;
	char	**map;

	if (total == -1 || total == 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (total + 1));
	if (!buf)
		return (0);
	if (ft_fill_buf(fd, buf, total) == -1)
		return (0);
	start = check_0th_row(buf, &rowcol[0], c);
	if (start == 0)
		return (0);
	if (!(ft_rowcol_check(start, &rowcol[0], &rowcol[1], total)
			&& ft_exist_in_c(c, start, total)))
		return (0);
	map = ft_split_put(start, &rowcol[0], &rowcol[1]);
	free(buf);
	return (map);
}

void	solvable(int fd, char **map, int **num, int total)
{
	int		rowcol[2];
	int		*max;
	char	c[4];

	rowcol[0] = 0;
	rowcol[1] = 0;
	map = set_char_map(fd, &rowcol[0], total, &c[0]);
	if (map == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	num = make_num_map(map, &c[0], rowcol[0]);
	ft_save_num(num, rowcol[0], rowcol[1]);
	max = ft_find_max(num, rowcol[0], rowcol[1]);
	ft_full(map, &max[0], &c[0]);
	ft_print(map, rowcol[0], rowcol[1]);
	ft_free(map, num, rowcol[0]);
}

void	solve_files(char *av_i)
{
	int		fd;
	char	**map;
	int		**num;
	int		total;

	map = 0;
	num = 0;
	total = ft_entirelen(av_i);
	fd = open(av_i, O_RDWR);
	solvable(fd, map, num, total);
	close(fd);
}
