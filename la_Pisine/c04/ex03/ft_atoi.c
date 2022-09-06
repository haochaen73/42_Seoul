/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:34:10 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/03 13:49:31 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_isspace(char *str)
{
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	return (str);
}

int	ft_sign(int minuscnt, int result)
{
	if (minuscnt % 2 == 0)
		return (result);
	else
		return (-result);
}

int	ft_atoi(char *str)
{
	int	minuscnt;
	int	result;

	str = ft_isspace(str);
	minuscnt = 0;
	result = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minuscnt++;
		str++;
	}
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			result = result * 10 + (*str - '0');
		else
			return (ft_sign(minuscnt, result));
		str++;
	}
	return (ft_sign(minuscnt, result));
}
