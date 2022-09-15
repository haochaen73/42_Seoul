/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:42:13 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/06 21:41:35 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	i;
	long long	nbl;

	nbl = (long long)nb;
	if (nbl < 0)
		return (0);
	if (nbl == 1)
		return (1);
	i = 2;
	while (i * i <= nbl)
	{
		if (i * i == nbl)
			return (i);
		i++;
	}
	return (0);
}
