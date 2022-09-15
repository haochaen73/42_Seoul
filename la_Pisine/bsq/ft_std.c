/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:17:25 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/15 12:02:44 by subilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_entirelen(char *av);
void	solvable(int fd, char **map, int **num, int total);
void	solve_files(char *av_i);

int	ft_write_std(void)
{
	int		byte_read;
	int		i;
	int		fd;
	char	buf[2];

	i = 0;
	fd = open("std_input", O_RDWR);
	while (1)
	{
		byte_read = read(0, buf, 1);
		if (byte_read == -1)
			exit(1);
		i++;
		if (byte_read == 0)
			break ;
		write(fd, buf, 1);
	}
	write(fd, "\0", 1);
	close(fd);
	return (1);
}

void	ft_stdinput_init(int total)
{
	int	i;
	int	fd;

	i = 0;
	fd = open("std_input", O_RDWR);
	while (i < total)
	{
		write(fd, "\0", 1);
		i++;
	}
	close(fd);
}

void	solve_std(void)
{
	int		fd;
	int		total;
	char	**map;
	int		**num;

	map = 0;
	num = 0;
	ft_write_std();
	fd = open("std_input", O_RDWR);
	total = ft_entirelen("std_input");
	solvable(fd, map, num, total);
	close(fd);
	ft_stdinput_init(total);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			solve_files(av[i]);
			if (ac != 2)
				write(1, "\n", 1);
			i++;
		}
	}
	else
		solve_std();
	exit(0);
}
