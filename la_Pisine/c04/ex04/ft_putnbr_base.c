/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:28:16 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/02 22:43:54 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen1(char *base)
{
	int	cnt;

	cnt = 0;
	while (*base)
	{
		cnt++;
		base++;
	}
	return (cnt);
}

int	base_error(char *base, int baselen)
{
	int	i;
	int	j;

	i = 0;
	if (baselen == 0 || baselen == 1)
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (j < baselen)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_recursive(long long nbr, char *base, int baselen)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr != 0)
	{
		ft_recursive(nbr / baselen, base, baselen);
		write(1, &base[nbr % baselen], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			baselen;
	int			i;
	long long	nbrl;

	baselen = ft_strlen1(base);
	if (base_error(base, baselen))
		return ;
	nbrl = (long long)nbr;
	i = 0;
	if (nbr == 0)
		write(1, &base[0], 1);
	ft_recursive(nbrl, base, baselen);
}
