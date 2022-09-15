/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:36:35 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/14 00:18:08 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		operator(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_calculator(int a1, int a2, int a3)
{
	if (a2 == 0)
		ft_putnbr(a1 + a3);
	if (a2 == 1)
		ft_putnbr(a1 - a3);
	if (a2 == 2)
		ft_putnbr(a1 * a3);
	if (a2 == 3)
	{
		if (a3 == 0)
		{
			write(1, "Stop : division by zero", 23);
			return ;
		}
		ft_putnbr(a1 / a3);
	}
	if (a2 == 4)
	{
		if (a3 == 0)
		{
			write(1, "Stop : modulo by zero", 21);
			return ;
		}
		ft_putnbr(a1 % a3);
	}
}

int	main(int argc, char **argv)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = 0;
	a2 = 0;
	a3 = 0;
	if (argc == 4)
	{
		a1 = ft_atoi(argv[1]);
		if (ft_strlen(argv[2]) != 1)
		{
			write(1, "0\n", 2);
			return (1);
		}
		a2 = operator(argv[2][0]);
		if (a2 == -1)
		{
			write(1, "0\n", 2);
			return (1);
		}
		a3 = ft_atoi(argv[3]);
		ft_calculator(a1, a2, a3);
		write(1, "\n", 1);
	}
}
