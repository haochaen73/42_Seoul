/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:09:42 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/05 16:07:56 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*ft_isspace(unsigned char *str)
{
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	return (str);
}

static int	ft_sign(int minuscnt, int result)
{
	if (minuscnt % 2 == 0)
		return (result);
	else
		return (-result);
}

int	ft_atoi(const char *str)
{
	int				minuscnt;
	int				result;
	unsigned char	*new_str;

	new_str = (unsigned char *)str;
	new_str = ft_isspace(new_str);
	minuscnt = 0;
	result = 0;
	if (*new_str == '+' || *new_str == '-')
	{
		if (*new_str == '-')
			minuscnt++;
		new_str++;
	}
	while (*new_str)
	{
		if ('0' <= *new_str && *new_str <= '9')
			result = result * 10 + (*new_str - '0');
		else
			return (ft_sign(minuscnt, result));
		new_str++;
	}
	return (ft_sign(minuscnt, result));
}
