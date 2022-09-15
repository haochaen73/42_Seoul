/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:43:17 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/06 21:42:26 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int			cnt;
	long long	i;
	long long	nbl;

	nbl = (long long)nb;
	cnt = 0;
	i = 2;
	if (nbl <= 1)
		return (0);
	while (i * i <= nbl)
	{
		if (nbl % i == 0)
			cnt++;
		i++;
	}
	if (cnt == 0)
		return (1);
	else
		return (0);
}
