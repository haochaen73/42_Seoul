/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:08:27 by youngjki          #+#    #+#             */
/*   Updated: 2022/08/27 12:25:57 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp1;
	int	temp2;

	if (*b == 0)
	{
		temp1 = 0;
		temp2 = 0;
	}
	else
	{
		temp1 = *a / *b;
		temp2 = *a % *b;
	}
	*a = temp1;
	*b = temp2;
}
