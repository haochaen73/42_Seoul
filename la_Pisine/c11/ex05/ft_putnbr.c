/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:59:57 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/13 21:48:23 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	digits(int nb)
{
	int	cnt;

	cnt = 0;
	while (nb > 0)
	{
		nb /= 10;
		cnt++;
	}
	return (cnt);
}

void	ft_putchars(int nb)
{
	char	num[10];
	int		digit;
	int		i;

	digit = digits(nb);
	i = digits(nb);
	while (i > 0)
	{
		num[i - 1] = nb % 10;
		nb /= 10;
		i--;
	}
	while (i < digit)
	{
		num[i] = num[i] + '0';
		write(1, num + i, 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	ft_putchars(nb);
}
