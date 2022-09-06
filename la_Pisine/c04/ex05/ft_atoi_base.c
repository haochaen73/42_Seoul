/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:29:13 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/03 16:35:48 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen2(char *base)
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

int	base_error1(char *base, int baselen)
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

int	ft_find_idx(char *base, char to_find)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_sign(int minuscnt, long result)
{
	if (minuscnt % 2 == 0)
		return (result);
	else
		return (-result);
}

int	ft_atoi_base(char *str, char *base)
{
	int		minuscnt;
	long	result;
	int		baselen;

	minuscnt = 0;
	result = 0;
	baselen = ft_strlen2(base);
	if (base_error1(base, baselen))
		return (0);
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minuscnt++;
		str++;
	}
	while (*str && ft_find_idx(base, *str) != -1)
	{
		result = result * baselen + ft_find_idx(base, *str);
		str++;
	}
	return ((int)ft_sign(minuscnt, result));
}
