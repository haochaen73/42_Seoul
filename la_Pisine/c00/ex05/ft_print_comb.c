/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:10:04 by youngjki          #+#    #+#             */
/*   Updated: 2022/08/25 19:50:25 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	a[3];

	a[0] = '0';
	a[1] = '1';
	a[2] = '2';
	while (a[0] <= '6')
	{
		a[1] = a[0] + 1;
		while (a[1] <= '8')
		{
			a[2] = a[1] + 1;
			while (a[2] <= '9')
			{
				write(1, &a, 3);
				write(1, ", ", 2);
				a[2]++;
			}
			a[1]++;
		}
		a[0]++;
	}
	write(1, "789", 3);
}
