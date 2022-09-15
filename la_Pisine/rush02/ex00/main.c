/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:08:32 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/11 16:37:18 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	error_check(char *argv_i)
{
	int	i;

	i = 0;
	while (argv_i[i])
	{
		if (!(argv_i[i] >= '0' && argv_i[i] <= '9'))
		{
			write(2, "error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	power(int base, int exp)
{
	if (exp == 0)
		return (1);
	return (base * power(base, --exp));
}

int	*ft_split(int *result, char *argv_i, int digit)
{
	int	i;

	i = 0;
	while (i < digit)
	{
		result[i] = (argv_i[i] - '0') * power(10, digit - 1 - i);
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int		i;
	int		digit;
	int		*result;

	i = 0;
	digit = 0;
	if (argc == 2)
	{
		if (error_check(argv[1]))
			return (1);
		while (argv[1][i])
		{
			digit++;
			i++;
		}
		result = (int *)malloc(sizeof(int) * digit);
		result = ft_split(result, argv[1], digit);
	}
}
