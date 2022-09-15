/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:33:41 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/06 21:35:34 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime1(int nb)
{
	int			cnt;
	long long	i;

	cnt = 0;
	i = 2;
	if (nb <= 1)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			cnt++;
		i++;
	}
	if (cnt == 0)
		return (1);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 0)
		return (2);
	if (ft_is_prime1(nb))
		return (nb);
	nb++;
	while (!ft_is_prime1(nb))
		nb++;
	return (nb);
}
