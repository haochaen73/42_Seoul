/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:07:34 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/14 12:39:29 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascending;

	i = 0;
	ascending = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) == 0)
			i++;
		else
			break ;
	}
	while (i < length - 1)
	{
		if (ascending == 0 && f(tab[i], tab[i + 1]) < 0)
			ascending = 1;
		else if (ascending == 0 && f(tab[i], tab[i + 1]) > 0)
			ascending = -1;
		else if (((ascending == 1) && f(tab[i], tab[i + 1]) > 0)
			|| ((ascending == -1) && f(tab[i], tab[i + 1]) < 0))
			return (0);
		i++;
	}
	return (1);
}
