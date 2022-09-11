/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:07:30 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/11 21:07:30 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			cnt++;
		i++;
	}
	return (cnt);
}