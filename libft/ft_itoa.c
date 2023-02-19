/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:30:15 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/12 15:30:18 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int n)
{
	int	nbr;

	nbr = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		nbr++;
	}
	while (n != 0)
	{
		nbr++;
		n /= 10;
	}
	return (nbr);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*c;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_len((long int)n);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
