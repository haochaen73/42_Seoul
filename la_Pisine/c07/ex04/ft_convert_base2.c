/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:29:58 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/09 19:38:10 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *base);
void	ft_digit_baseto(long atoi_nbr, char *base_to, int *digit);
void	ft_putnbr_baseto(char *result, long atoi_nbr, char *base_to, int *i);

int	ft_base_error(char *base, int baselen)
{
	int	i;
	int	j;

	i = 0;
	if (baselen == 0 || baselen == 1)
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
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

long	ft_find_idx(char *base, char to_find)
{
	long	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	long	minus;
	long	result;
	long	baselen;

	minus = 1;
	result = 0;
	baselen = ft_strlen(base);
	if (ft_base_error(base, baselen))
		return (0);
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str && ft_find_idx(base, *str) != -1)
	{
		result = result * baselen + ft_find_idx(base, *str);
		str++;
	}
	return ((int)result * minus);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	atoi_nbr;
	char	*result;
	int		i;
	int		digit;

	i = 0;
	digit = 0;
	if (ft_base_error(base_from, ft_strlen(base_from))
		|| ft_base_error(base_to, ft_strlen(base_to)))
		return (0);
	atoi_nbr = (long)ft_atoi_base(nbr, base_from);
	if (atoi_nbr == 0)
		digit = 1;
	else
		ft_digit_baseto(atoi_nbr, base_to, &digit);
	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (atoi_nbr == 0)
		result[i++] = base_to[0];
	else
		ft_putnbr_baseto(result, atoi_nbr, base_to, &i);
	result[i] = '\0';
	return (result);
}
