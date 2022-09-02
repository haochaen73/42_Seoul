/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:06:13 by youngjki          #+#    #+#             */
/*   Updated: 2022/08/25 21:32:51 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put(int n, char *arr)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, arr + i, 1);
		i++;
	}
	if (*arr != 10 - n + '0')
	{
		write(1, ", ", 2);
	}
}

void	ft_while(int n, char *arr, int i)
{
	while (arr[i] <= 10 - (n - i) + '0')
	{
		arr[i + 1] = arr[i] + 1;
		if (i == n - 1)
			ft_put(n, arr);
		else
			ft_while(n, arr, i + 1);
		arr[i]++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];
	int		i;

	i = 0;
	arr[0] = '0';
	ft_while(n, arr, i);
}
