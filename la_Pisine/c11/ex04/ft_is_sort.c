/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:07:34 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/11 21:07:35 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	ascending;
	int	descending;
	
	i = 0;
	ascendeing = 0;
	descending = 0;
	while (i < length)
	{
		if (f(tab[i]), f(tab[i + 1]) < 0)
		{
			
		}
		i++;
	}
}